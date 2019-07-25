//
//  Material.hpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <string>
#include <map>
#include <fstream>

class Material
{
public:
    Material();
    Material(char *);
    Material(std::string, GLfloat sIntensity, GLfloat shine);
    
    static std::map<std::string, Material> MaterialMap;

    void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);
    
    void serializeMaterial(char*);

    std::string matName;

    ~Material();

    friend std::ostream& operator<<(std::ostream& os, const Material& dt)
    {
        os <<  dt.matName << '\n' << dt.specularIntensity << '\n' << dt.shininess;
        return os;
    }

    friend std::istream & operator >> (std::istream &in, Material& c){
        in >> c.matName >> c.specularIntensity >> c.shininess;
        return in;
    }
private:
    GLfloat specularIntensity;
    GLfloat shininess;
};

#endif /* Material_hpp */
