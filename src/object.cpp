#include "object.hpp"

Object::Object(){};

Object::~Object(){};

Object::Object(glm::vec3 * invec, Model * inMod){
    pos = invec;
    model = inMod;
}

Object::Object(glm::vec3 * invec, Material * inMat, Texture * inTex){
    pos = invec;
    material = inMat;
    texture = inTex;
}

bool Object::Serialize(std::ostream& stream){
    printf("Serializing object\n");
    if(model != nullptr){
        printf("Serializing a model object\n");
        if(stream << (pos->x) << (pos->y) << (pos->z) << *model  << '\n'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("Serializing a nonmodel object");
        if(stream << (pos->x) << (pos->y) << (pos->z)  << '\n'){
            return true;
        }
        else{
            return false;
        }
    }

}

bool Object::deSerialize(std::istream& stream){
    int x = (pos->x);
    int y = pos->y;
    int z = pos->z;
    if(stream >> x >> y >> z >> *model){
		return true;
	}
	else{
		return false;
	}
}