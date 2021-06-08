// author: Colin Seifer
// file: Shaders.cpp
// description: loads vertex and fragment shaders from project.

#include <string>
#include <fstream>
#include <sstream>
#include "Shaders.hpp"

bool LoadShaders(GLuint programID, int num_files, const char** file_names,
                 GLuint* &ids){
    // create shaders
    // make sure we have at least vertex and fragment shader
    if(num_files < 2){
        return false;
    }
    ids[VERT_SHADER] = glCreateShader(GL_VERTEX_SHADER);
    ids[FRAG_SHADER] = glCreateShader(GL_FRAGMENT_SHADER);

    // continue loading shaders if there are more to load
    if(num_files > COMPUTE_SHADER){
        ids[COMPUTE_SHADER] = glCreateShader(GL_COMPUTE_SHADER);
    }
    if(num_files > TESS_CTL_SHADER){
        ids[TESS_CTL_SHADER] = glCreateShader(GL_TESS_CONTROL_SHADER);
    }
    if(num_files > TESS_EVAL_SHADER){
        ids[TESS_EVAL_SHADER] = glCreateShader(GL_TESS_EVALUATION_SHADER);
    }
    if(num_files > GEOMETRY_SHADER){
        ids[GEOMETRY_SHADER] = glCreateShader(GL_GEOMETRY_SHADER);
    }

    // load shader code into strings
    std::string shader_code[num_files];
    for(int i = 0; i < num_files; i++){
        std::ifstream ifs;
        // open file for input
        ifs.open(file_names[i], std::ifstream::in);
        if(ifs.is_open()){
            // get code from stringstream
            std::stringstream sstr;
            sstr << ifs.rdbuf();
            shader_code[i] = sstr.str();
            ifs.close();
        }
        else{
            perror("Failed to open shader file.");
            return false;
        }
    }

    // compile and check shaders
    GLint res = GL_FALSE;
    int info_log_len;
    for(int i = 0; i < num_files; i++){
        // shader compilation
        const char* code_ptr = shader_code[i].c_str();
        glShaderSource(ids[i], 1, &code_ptr, NULL);
        glCompileShader(ids[i]);
        // check shader
        glGetShaderiv(ids[i], GL_COMPILE_STATUS, &res);
        glGetShaderiv(ids[i], GL_INFO_LOG_LENGTH, &info_log_len);
        if(info_log_len > 0){
            perror("There was an error compiling a shader.");
            return false;
        }
    }

    // attach shaders to program and link
    for(int i = 0; i < num_files; i++){
        glAttachShader(programID, ids[i]);
    }
    glLinkProgram(programID);
    // check program
    glGetProgramiv(programID, GL_LINK_STATUS, &res);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &info_log_len);
    if(info_log_len > 0){
        perror("There was an error attaching and linking shaders.");
        return false;
    }

    return true;
}