#include "object.hpp"

/* #region Constructors/Destructor */
Object::Object(){};

//TODO: this isn't gonna be useful, probably remove once you remove simpleobjects
Object::Object(glm::vec3 * inPos, std::string matName, std::string texName){
    pos = inPos;
    material = &Material::MaterialMap[matName];
    texture = &Texture::TextureMap[texName];    
}

Object::Object(glm::vec3 * inPos, glm::vec3 * inScale,std::string inMatName, std::string inTexName, std::string inName, std::string inModelName){
    pos = inPos;
    scale = inScale;
    material = &Material::MaterialMap[inMatName];
    matName = inMatName;
    texName = inTexName;
    texture = &Texture::TextureMap[inTexName];
    ObjectName = inName;
    model = &Model::ModelMap[modelName];
    modelName = inModelName;
}

Object::~Object(){};

/* #endregion */

bool Object::Serialize(std::ostream& stream){
    printf("Serializing object\n");
    if(model != nullptr){
        printf("Serializing a model object\n");
        if(stream << ObjectName << '\n' << (pos->x) << '\n' << (pos->y) << '\n' << (pos->z)<< '\n' << (scale->x) << '\n' << (scale->y) << '\n' << (scale->z) << '\n' << *material << '\n' << *texture << '\n' << *model  << '\n'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("Serializing a nonmodel object");
        if(stream << ObjectName << '\n' << (pos->x) << '\n' << (pos->y) << '\n' << (pos->z)  << '\n'){
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