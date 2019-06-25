//
//  spotLight.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#pragma once
#include "pointLight.hpp"

class SpotLight: public PointLight{
public:
    SpotLight();

    
    SpotLight(GLfloat red, GLfloat green, GLfloat blue,
                       GLfloat aIntensity, GLfloat dIntensity,
                       GLfloat xPos, GLfloat yPos, GLfloat zPos,
                       GLfloat xDir, GLfloat yDir, GLfloat zDir,
                       GLfloat con, GLfloat lin, GLfloat exp, GLfloat edge);
    
    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation, GLfloat directionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation, GLfloat edgeLocation);

    void SetFlash(glm::vec3 pos, glm::vec3 dir);

    ~SpotLight();
private:
    glm::vec3 direction;

    GLfloat edge, procEdge;
};