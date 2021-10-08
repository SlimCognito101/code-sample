// author: Colin Seifer
// file: Object.hpp
// description: basic functionality used by every type of object.

#include <stdio.h>
#include "Object.hpp"
#include "Shaders.hpp"
#include "image_loader.hpp"

Object::Object(std::string filename, const char *fn){
    // relative path to data folder
    const std::string Datapath = "../data/";
    // P6 denotes filetype is .jpg
    const std::string JPG = "JFIF";
    // combine datapath with filename
    std::string filepath = Datapath + filename;

    // load image file into texture if filename not empty

    // width and height of image
    int width = 0;
    int height = 0;
    unsigned char *image;
    if(!filename.empty()){
        // open file for reading
        FILE *fp = fopen(filepath.c_str(), "rb");
        if(fp != nullptr){
            // load image
            image = Image_Loader::Load_Image(fn, &width, &height);
            // close file
            fclose(fp);
        }
        else{
            perror("Failed to open image file.\n");
        }
    }
    // create default texture
    else{
        width = 4;
        height = 4;
        image = new unsigned char[width * height * 3];
        // fill with default values
        for(int i = 0; i < width * height * 3; i++){
            image[i] = 255;
        }
    }

    // bind image
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

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

    Image_Loader::Free_Image(image);
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

void Object::Draw(GLuint sceneID){
    // use current program
    glUseProgram(programID);

    // render current vertex array
    glBindVertexArray(vert_array_ID);

    // bind texture to active
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // bind uniform buffers
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, sceneID);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, buffers[UNIFORM_BUFFER]);

    // draw triangles
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}