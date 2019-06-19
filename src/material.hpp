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

class Material
{
public:
    Material();
    Material(GLfloat sIntensity, GLfloat shine);
    
    void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);
    
    ~Material();
    
private:
    GLfloat specularIntensity;
    GLfloat shininess;
};

#endif /* Material_hpp */
