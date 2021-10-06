// author: Colin Seifer
// file: Plane.hpp
// description: creates plane from object.

#ifndef PLANE_HPP
#define PLANE_HPP

#include "Object.hpp"

class Plane : public Object{
public:
    // create plane object given size and texture filename
    // size given as xyz
    Plane(glm::vec3 size, std::string filename, const char *fn);
};

#endif