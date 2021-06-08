#version 410 core
// vertex shader

// per-frame data
// standard uniform block layout
layout(std140)
uniform SceneData{
    mat4 proj_from_world, world_from_proj;
    vec4 light_vector;
};

// shader settings
uniform sampler2D ColorTexture;

// input from vert shader
in vec2 texcoord;
in vec3 normal;
in vec4 position;

// output to frame buffer
out vec4 color;

void main(){
    vec3 N = normalize(normal);             // get surface normal
    vec3 L = normalize(light_vector.xyz)    // direction of light
    float intensity = max(0., dot(N,L));    // diffuse lighting
    intensity = min(1., intensity + light_vector.w) // add ambient

    // color from texture and intensity
    vec3 temp_color = intensity * texture(ColorTexture, texcoord).rgb;

    // color to return
    color = vec4(temp_color, 1);
}