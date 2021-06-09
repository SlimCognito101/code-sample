// author: Colin Seifer
// file: Object.hpp
// description: basic functionality used by every type of object.

#include <fstream>
#include <cstdio>
#include "Object.hpp"
#include "Shaders.hpp"

Object::Object(std::string filename){
    // relative path to data folder
    const std::string Datapath = "../data/";
    // P6 denotes filetype is .ppm
    const std::string PPM = "P6";
    // combine datapath with filename
    std::string filepath = Datapath + filename;

    // create buffer objects

    // load image file into texture if filename not empty
    int width = 0;
    int height = 0;
    glm::u8vec3* image;
    if(!filename.empty()){
        std::fstream ifs;

        // open file for reading
        ifs.open(filepath, std::ifstream::in);
        if(ifs.is_open()){
            std::filebuf* inbuf = ifs.rdbuf();
            // check that file is .ppm
            if(inbuf->sbumpc() != PPM[0] || inbuf->sbumpc() != PPM[1]){
                // seek to end of header
                while(inbuf->sbumpc() != '\n'){
                    // do nothing
                }
                // get size of file
                long size = inbuf->in_avail();
                // width and height are the same for a square image file
                width = height = int(sqrt(size));
                // check that size is a multiple of 3
                if(size % 3 == 0){
                    // read image
                    image = new glm::u8vec3[size / 3];
                    for(int i = 0; i < size; i+=3){
                        image[i] = glm::u8vec3(inbuf->sbumpc(),
                        inbuf->sbumpc(), inbuf->sbumpc());
                    }
                }
                else{
                    perror("Image file size mismatch.");
                }
            }
            else{
                perror("Wrong image file type. Please use .ppm.");
            }
            // close file
            ifs.close();
        }
        else{
            perror("Failed to open image file.");
        }
    }
    // create default texture
    else{
        width = 1;
        height = 1;
        image = new glm::u8vec3[width * height];
        // fill with default values
        image[0] = {255, 255, 255};
    }

    // bind image
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
    GL_LINEAR_MIPMAP_LINEAR);

    // generate additional buffers
    glGenBuffers(NUM_BUFFERS, buffers);
    glGenVertexArrays(1, &vert_array_ID);

    // set default position to origin
    object.model_from_world = glm::mat4(1);
    object.world_from_model = glm::mat4(1);
    // bind to GL uniform buffer
    glBindBuffer(GL_UNIFORM_BUFFER, buffers[UNIFORM_BUFFER]);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(ObjectData), &object,
    GL_STREAM_DRAW);

    // create shaders and program
    shaderIDs[0] = glCreateShader(GL_VERTEX_SHADER);
    shaderIDs[1] = glCreateShader(GL_FRAGMENT_SHADER);
    programID = glCreateProgram();
}

Object::~Object(){
    for(GLuint shader : shaderIDs){
        glDeleteShader(shader);
    }
    glDeleteProgram(programID);
    glDeleteTextures(1, &textureID);
    glDeleteBuffers(NUM_BUFFERS, buffers);
    glDeleteVertexArrays(1, &vert_array_ID);
}

void Object::UpdateShaders(){
    // shaders
    const char *Vert_shader_path = "../data/object.vert";
    const char *Frag_shader_path = "../data/object.frag";
    const char *file_names[NUM_SHADERS];

    file_names[0] = Vert_shader_path;
    file_names[1] = Frag_shader_path;

    LoadShaders(programID, NUM_SHADERS, file_names, shaderIDs);
    glUseProgram(programID);

    // bind uniform blocks to names used in shader files
    glUniformBlockBinding(programID,
    glGetUniformBlockIndex(programID,"SceneData"), 0);
    glUniformBlockBinding(programID,
    glGetUniformBlockIndex(programID,"ObjectData"), 0);

    // map texture name
    glUniform1i(glGetUniformLocation(programID, "ColorTexture"), 0);

    // attributes
    glBindVertexArray(vert_array_ID);

    GLint positionAttrib = glGetAttribLocation(programID, "pos");
    glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTEX_BUFFER]);
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(positionAttrib);

    GLint normalAttrib = glGetAttribLocation(programID, "norm");
    glBindBuffer(GL_ARRAY_BUFFER, buffers[NORMAL_BUFFER]);
    glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normalAttrib);

    GLint uvAttrib = glGetAttribLocation(programID, "uv");
    glBindBuffer(GL_ARRAY_BUFFER, buffers[UV_BUFFER]);
    glVertexAttribPointer(uvAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(uvAttrib);
}

void Object::Draw(double current_time){
    // use current program
    glUseProgram(programID);

    // render current vertex array
    glBindVertexArray(vert_array_ID);

    // bind texture to active
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // draw triangles
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}