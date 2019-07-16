//
//  Light.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#include "light.hpp"

/* #region Constructors/Destructor */
Light::Light(){
    colour = glm::vec3(0.0f, 0.0f, 0.0f);
    ambientIntensity = 0.0f;
    diffuseIntensity = 0.0f;
}

Light::Light(GLfloat shadowWidth, GLfloat shadowheight, GLfloat red,GLfloat green, GLfloat blue, GLfloat aIntensity,GLfloat dIntensity){
    colour = glm::vec3(red, green, blue);
    ambientIntensity = aIntensity;
    diffuseIntensity = dIntensity;

    shadowMap = new ShadowMap();
    shadowMap->Init(shadowWidth, shadowheight);
}

Light::~Light(){
    
}
/* #endregion */