//
//  Light.hpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shadowMap.hpp"

class Light{
public:
    Light();
    
    Light(GLfloat shadowWidth, GLfloat shadowHeight, GLfloat red,GLfloat green, GLfloat blue, GLfloat aIntensity,  GLfloat dIntensity);

    ShadowMap * GetShadowMap(){return shadowMap;}
    
    ~Light();
    
protected:
    glm::vec3 colour;
    GLfloat ambientIntensity;
    
    glm::vec3 direction;
    GLfloat diffuseIntensity;
    
    glm::mat4 lightProj;

    ShadowMap * shadowMap;
};
#endif /* Light_hpp */
