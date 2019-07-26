#include "object.hpp"

Object::Object(){};

Object::~Object(){};

Object::Object(glm::vec3 * inPos, std::string matName, std::string texName){
    pos = inPos;
    material = &Material::MaterialMap[matName];
    texture = &Texture::TextureMap[texName];    
}

Object::Object(glm::vec3 * inPos, glm::vec3 * inScale,std::string inMatName, std::string inTexName, std::string inName, Model * inModel){
    pos = inPos;
    scale = inScale;
    material = &Material::MaterialMap[inMatName];
    texture = &Texture::TextureMap[inTexName];
    ObjectName = inName;
    model = inModel;
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