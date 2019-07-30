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

/*
    //create a file buffer
    std::filebuf fb;
    //Open desired file
    fb.open("src/levels/test_level/deer.txt", std::ios::in);
    //Create instream
    std::istream fs(&fb);
    //Deserialize objects
    deSerialize(fs);
    fb.close();
*/
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
    
    fs >> objectName;
    std::string tempx, tempy, tempz, stempx, stempy, stempz;
    fs >> tempx;
    fs >> tempy;
    fs >> tempz;
    fs >> stempx;
    fs >> stempy;
    fs >> stempz;
    
    double fx = std::stod(tempx);
    pos->x = fx;
    printf("Here\n");
    double fy = std::stod(tempy);
    pos->y = fy;
    double fz = std::stod(tempz);
    pos->z = fz;
    double sfx = std::stod(stempx);
    scale->x = sfx;
    double sfy = std::stod(stempy);
    scale->y = fy;
    double sfz = std::stod(stempz);
    scale->z = sfz;
    fs >> matName;
    fs >> texName;
    fs >> modelName;
    
    
    
}