#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.hpp"
#include "material.hpp"
#include "texture.hpp"
#include "directionalLight.hpp"
#include "pointLight.hpp"

class Object{
public:
    Object();
    Object(glm::vec3 * , Texture * , Material *);

    glm::vec3 * pos;

    //Visual components
    Mesh * mesh;
    Texture * texture;
    Material * material;
private:

};

#endif /*OBJECT_H */