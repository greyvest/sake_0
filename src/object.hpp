#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include "serializable.hpp"
#include "model.hpp"
#include <glm/glm.hpp>
#include <sstream>

class Object : public Serializable{
public:
    /* #region Contstructors & Destructor */
    Object();
    Object(char *);
    Object(glm::vec3 * inPos, std::string matName, std::string texName);
    Object(glm::vec3 * pos, glm::vec3 * scale, std::string inMatName, std::string inTexName, std::string inName, std::string modelName);
    ~Object();
    /* #endregion */
    
    static std::map<std::string, Object> ObjectMap;

    /* Instance variables */

    glm::vec3 * pos;
    glm::vec3 * scale;
    std::string matName;
    std::string texName;
    std::string modelName;
    std::string objectName;
    // Material * material;
    // Texture * texture;
    // Model * model;
    
    /* Debug Gui variables */
    bool isSelected = false;
    
    
    /* Serializable overloads */
    //Implementations



    void saveLevelObject(std::string, std::string, Object *);
	virtual bool Serialize(std::ostream&);
	virtual bool deSerialize(std::istream&);
	
    static void getNamesOfAllObjects(const char **);



    //Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Object& dt)
    {
        os << dt.objectName << ' ' << dt.pos->x << ' ' << dt.pos->y << ' ' << dt.pos->z << ' ' << dt.scale->x << ' ' << dt.scale->y << ' ' << dt.scale->z << ' ' << dt.matName << ' ' << dt.texName << ' ' << dt.modelName << ' ' ;
        return os;
    }

    friend std::istream & operator >> (std::istream &in, Object& c){
        in >> c.objectName >> c.pos->x >> c.pos->y >> c.pos->z >> c.scale->x >> c.scale->y >> c.scale->z >> c.matName >> c.texName >> c.modelName;
    }
private:
    
};