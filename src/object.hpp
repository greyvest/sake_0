#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include "serializable.hpp"
#include "model.hpp"
#include <glm/glm.hpp>

class Object : public Serializable{
public:
    /* #region Contstructors & Destructor */
    Object();
    Object(glm::vec3 * , Model *);
    Object(glm::vec3 * invec, Material * inMat, Texture * inTex);
    ~Object();
    /* #endregion */
    
    /* Instance variables */
    Model * model;
    glm::vec3 * pos;
    Material * material;
    Texture * texture;
    /* Serializable overloads */
    //Implementations
	virtual bool Serialize(std::ostream&);
	virtual bool deSerialize(std::istream&);
	//Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Object& dt)
    {
        os << dt.pos->x << dt.pos->y << dt.pos->z << *dt.model;
        return os;
    }

    friend std::istream & operator >> (std::istream &in, Object& c){
        in >> c.pos->x >> c.pos->y >> c.pos->z >> *c.model;
        return in;
    }
private:
    
};