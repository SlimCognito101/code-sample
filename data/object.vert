#version 410 core
// vertex shader

// per-frame data
// standard uniform block layout
layout(std140)
uniform SceneData{
    mat4 proj_from_world, world_from_proj;
    vec4 light_vector;
};

// per-object data
// standard uniform block layout
layout(std140)
uniform ObjectData{
    mat4 world_from_model, model_from_world;
};

// per-vertex input
in vec2 uv;
in vec3 pos;
in vec3 norm;

// output to fragment shader
out vec2 texcoord;
out vec3 normal;
out vec4 position;

void main(){
    texcoord = uv;
    position = world_from_model * vec4(pos, 1);
    normal = normalize(norm * mat3(model_from_world));
    gl_Position = proj_from_world * position;
}