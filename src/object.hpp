#include <vector>
#include <stdio.h>

#include "texture.hpp"
#include "mesh.hpp"
#include "material.hpp"

#include <glm/glm.hpp>

class Object{
public:
    Object();

    Object(glm::vec3 *, Texture * , Material *);

    glm::vec3 * pos;
    Texture * texture;
    Material * material;
    Mesh * mesh;

    ~Object();

private:
    
};