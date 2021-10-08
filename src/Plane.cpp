// author: Colin Seifer
// file: Plane.cpp
// description: handles plane object creation

#include <math.h>
#include "Plane.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifndef F_PI
#define F_PI 3.1415926f
#endif

Plane::Plane(glm::vec3 size, std::string filename, const char *fn, glm::vec2 offset) : Object(filename, fn){
    const int Square = 4; // vertices in a square

    // build texture coordinate, normal, and vertex arrays
    // our plane will have 4 vertices ranging from 0 to 1
    // the 4 vertices will make up 2 triangles
    glm::vec2 uv_vert;
    glm::vec3 norm_vert;
    glm::vec3 pos_vert;
    for(int vertex = 0; vertex < Square; vertex++){
        // populate uv
        // unecessarily complex way to fill in 0s and 1s.
        float x = (0.5f + cosf(F_PI * int((vertex + 1) / 2)) / 2.f);
        float y = (0.5f + sinf(F_PI * int(vertex / 2) + F_PI / 2.f) / 2.f);
        uv_vert = glm::vec2(x, y);
        uv.push_back(uv_vert);

        // populate norm. Will be the same for all vertices since it's a plane.
        norm_vert = glm::vec3(0.f, 0.f, 1.f);
        norm.push_back(norm_vert);

        // populate position
        x = ((x - 0.5f) * size.x + offset.x);
        y = ((y - 0.5f) * size.y + offset.y);
        float z = size.z;
        size_x = x;
        size_y = y;
        pos_vert = glm::vec3(x, y, z);
        vert.push_back(pos_vert);
    }

    // populate indices with triangles
    indices = {2, 3, 0,
               2, 0, 1};

    // load arrays into GPU
    glBindBuffer(GL_ARRAY_BUFFER, buffers[VERTEX_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, vert.size() * sizeof(vert[0]), &vert[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[NORMAL_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, norm.size() * sizeof(norm[0]), &norm[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[UV_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(uv[0]), &uv[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

    UpdateShaders();
}