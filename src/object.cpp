#include "object.hpp"

Object::Object(glm::vec3 * inPos, Texture * inTexture, Material * inMaterial){
    pos = inPos;
    texture = inTexture;
    material = inMaterial;
}