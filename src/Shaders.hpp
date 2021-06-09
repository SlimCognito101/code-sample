// author: Colin Seifer
// file: Shaders.hpp
// description: loads shaders

#ifndef SHADERS_HPP
#define SHADERS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// the order the shaders will be interpreted in
enum shaders{VERT_SHADER, FRAG_SHADER, COMPUTE_SHADER, TESS_CTL_SHADER,
TESS_EVAL_SHADER, GEOMETRY_SHADER};

/*
load shaders
file names will be interpreted in the following order:
vertex shader, fragment shader, compute shader, tess control shader,
tess evaluation shader, geometry shader
ids is a GLuint array of size num_file that will be filled with shader ids 
returns false on error
*/
bool LoadShaders(GLuint programID, int num_files, const char **file_names,
                 GLuint *ids);

#endif