#include "object.hpp"

/* #region Constructors/Destructor */
Object::Object(){};

Object::Object(char * fileName){
  std::fstream f1(fileName);
    std::string line;
    //TODO: Pretty sure this will mess with multiple objects for file, so for now 1 object per file
    while (getline(f1,line) ) {
        std::string temp1, temp2, temp3, temp4, temp5, temp6;
        if (std::istringstream(line) >> objectName >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> matName >> texName >> modelName)
        {
            double px, py, pz, sx, sy, sz;
            std::size_t offset = 0;
            px = std::stod(temp1);
            py = std::stod(temp2);
            pz = std::stod(temp3);
            sx = std::stod(temp4);
            sy = std::stod(temp5);
            sz = std::stod(temp6);
            //TODO: certainly I can figure out a way to not have to put these values on the stack, right?
            glm::vec3 *newPos = new glm::vec3(px, py,pz);
            glm::vec3 *newScale = new glm::vec3(sx, sy, sz);
            pos = newPos;
            scale = newScale;
        }
        else{
            printf("Error creating object\n");
        }
    }
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

//TODO: Should this require an inputed level directory (i.e. src/levels) or just know it automatically?
void Object::saveLevelObject(std::string oName, std::string levelName, Object * o){
    std::string levelDirectoryCopy = levelName;
    levelDirectoryCopy.append("/");
    levelDirectoryCopy.append(oName);
    
    //create a file buffer
    std::filebuf fb;
    //Open desired file
    fb.open(levelDirectoryCopy, std::ios::out);
    //Create instream
    std::ostream fs(&fb);
    //Deserialize objects
    o->Serialize(fs);
    fb.close();
}

bool Object::Serialize(std::ostream& stream){
    printf("Serializing object\n");

    if(stream << objectName << ' ' << (pos->x) << ' ' << (pos->y) << ' ' << (pos->z)<< ' ' << (scale->x) << ' ' << (scale->y) << ' ' << (scale->z) << ' ' << matName << ' ' << texName << ' ' << modelName << ' '){
        return true;
    }

    return false;
}

bool Object::deSerialize(std::istream& fs){
    /*if(fs >> objectName >> pos->x >> pos->y >> pos->z >> scale->x >> scale->y >> scale->z >> matName >> texName >> modelName){
        return true;
    }
    else
    {
        return false;
    }*/
    
}


void Object::getNamesOfAllObjects(const char ** outArr){

}