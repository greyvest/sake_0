#include "object.hpp"

Object::Object(){};

Object::~Object(){};

Object::Object(glm::vec3 * invec, Texture * intex, Material * inmat){
    pos = invec;
    texture = intex;
    material = inmat;
}