//
//  DirectionalLight.hpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#ifndef DirectionalLight_hpp
#define DirectionalLight_hpp

#include <stdio.h>
#include "light.hpp"

class DirectionalLight :
public Light
{
public:
    DirectionalLight();
    DirectionalLight(GLfloat shadowWidth, GLfloat shadowHeight,GLfloat red, GLfloat green, GLfloat blue,
                     GLfloat aIntensity, GLfloat dIntensity,
                     GLfloat xDir, GLfloat yDir, GLfloat zDir);
    
    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat directionLocation);
    
    glm::mat4 CalculateLightTransform();

    ~DirectionalLight();
    
private:
    glm::vec3 direction;
};

#endif /* DirectionalLight_hpp */
