//
//  spotlight.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//


#include "spotLight.hpp"

SpotLight::SpotLight() : PointLight(){
    direction = glm::vec3(0.0f, -1.0f, 0.0f);
    edge = 0;
    procEdge = cosf(glm::radians(edge));
}

SpotLight::SpotLight(GLfloat shadowWidth, GLfloat shadowHeight, GLfloat near, GLfloat far, GLfloat red, GLfloat green, GLfloat blue,
                       GLfloat aIntensity, GLfloat dIntensity,
                       GLfloat xPos, GLfloat yPos, GLfloat zPos,
                       GLfloat xDir, GLfloat yDir, GLfloat zDir,
                       GLfloat con, GLfloat lin, GLfloat exp, GLfloat edge) : PointLight(shadowWidth, shadowHeight, near,far, red, green, blue, aIntensity, dIntensity, xPos, yPos, zPos, con, lin, exp)
{
    direction = glm::vec3(xDir, yDir, zDir);
    edge = edge;
    procEdge = cos(glm::radians(edge));
}

void SpotLight::UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation, GLfloat directionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation, GLfloat edgeLocation)
{
    glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);
    
    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);

    glUniform3f(directionLocation, direction.x, direction.y, direction.z);
    glUniform1f(edgeLocation, procEdge);
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir)
{
	position = pos;
	direction = dir;
}

SpotLight::~SpotLight(){
    
}