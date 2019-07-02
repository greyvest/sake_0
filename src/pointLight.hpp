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
#include <vector>
#include "light.hpp"
#include "omniShadowMap.hpp"


class PointLight :
public Light
{
public:
    PointLight();
    PointLight(GLfloat shadowWidth, GLfloat shadowHeight,
               GLfloat near, GLfloat far,
               GLfloat red, GLfloat green, GLfloat blue,
               GLfloat aIntensity, GLfloat dIntensity,
               GLfloat xPos, GLfloat yPos, GLfloat zPos,
               GLfloat con, GLfloat lin, GLfloat exp);
    
    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);
    
    std::vector<glm::mat4> CalculateLightTransform();

    glm::vec3 GetPosition();
    GLfloat GetFarPlane();

    ~PointLight();
    
protected:
    glm::vec3 position;
    
    GLfloat constant, linear, exponent;
    GLfloat farPlane;
};


#endif /* PointLight_hpp */
