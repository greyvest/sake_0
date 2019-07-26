#include "object.hpp"

/* #region Constructors/Destructor */
Object::Object(){};

Object::Object(char * fileName){
    //create a file buffer
	std::filebuf fb;
	//Open desired file
	fb.open(fileName, std::ios::out);
	//Create instream
	std::istream fs(&fb);
	//Deserialize objects
	fs >> objectName >> pos->x >> pos->y >> pos->z >> scale->x >> scale->y >> scale->z >> matName >> texName >> modelName;
	fb.close();
}

//TODO: this isn't gonna be useful, probably remove once you remove simpleobjects
Object::Object(glm::vec3 * inPos, std::string inMatName, std::string inTexName){
    pos = inPos;
    matName = inMatName;
    texName = inTexName;
}

Object::Object(glm::vec3 * inPos, glm::vec3 * inScale,std::string inMatName, std::string inTexName, std::string inName, std::string inModelName){
    pos = inPos;
    scale = inScale;
    //material = &Material::MaterialMap[inMatName];
    matName = inMatName;
    texName = inTexName;
    //texture = &Texture::TextureMap[inTexName];
    objectName = inName;
    //model = &Model::ModelMap[modelName];
    modelName = inModelName;
}

Object::~Object(){};

/* #endregion */

std::map<std::string, Object> Object::ObjectMap;

bool Object::Serialize(std::ostream& stream){
    printf("Serializing object\n");

    if(stream << objectName << '\n' << (pos->x) << '\n' << (pos->y) << '\n' << (pos->z)<< '\n' << (scale->x) << '\n' << (scale->y) << '\n' << (scale->z) << '\n' << matName << '\n' << texName << '\n' << modelName << '\n'){
        return true;
    }


}

bool Object::deSerialize(std::istream&){
    //DO NOTHING AT THE MOMENT
    return true;
}