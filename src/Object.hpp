// author: Colin Seifer
// file: Object.hpp
// description: base class to hold data used by every type of object.

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#ifndef NUM_SHADERS
// number of shaders used
#define NUM_SHADERS 2
#endif

class Object{
protected:
    // uniform data defining object position
    // must match vec4 for shaders
    struct ObjectData{
        glm::mat4 world_from_model, model_from_world;
    } object;

    GLuint vert_array_ID;        // ID for vertex array object
    std::vector<float> vert;     // vertex data
    std::vector<float> norm;     // normal data
    std::vector<float> uv;       // texture coordinates
    std::vector<int> indices;    // indices to create triangles

    // buffers for our vectors
    enum{ UNIFORM_BUFFER, VERTEX_BUFFER, NORMAL_BUFFER, UV_BUFFER, 
    INDEX_BUFFER, NUM_BUFFERS};
    GLuint buffers[NUM_BUFFERS];

    GLuint shaderIDs[NUM_SHADERS]; // array of shader IDs

    GLuint textureID; // ID used for texture mapped to object
    GLuint programID; // ID for current program

public:
    // create object and map square .ppm image file to texture
    Object(std::string filename = "");
    // destroy object
    ~Object();

    // bind buffers
    virtual void Draw(double current_time = glfwGetTime());
    
    // load and reload shaders
    virtual void UpdateShaders();
};

#endif