//
//  PointLight.hpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#ifndef PointLight_hpp
#define PointLight_hpp

#include <stdio.h>
#include <iostream>
#include "light.hpp"

class PointLight :
public Light
{
public:
    PointLight();
    PointLight(GLfloat red, GLfloat green, GLfloat blue,
               GLfloat aIntensity, GLfloat dIntensity,
               GLfloat xPos, GLfloat yPos, GLfloat zPos,
               GLfloat con, GLfloat lin, GLfloat exp);
    
    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);
    
    ~PointLight();
    
private:
    glm::vec3 position;
    
    GLfloat constant, linear, exponent;
};


#endif /* PointLight_hpp */
