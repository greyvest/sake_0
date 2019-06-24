#pragma once
#include "pointLight.hpp"

class SpotLight: public PointLight{
public:
    SpotLight();

    
    SpotLight(GLfloat red, GLfloat green, GLfloat blue,
               GLfloat aIntensity, GLfloat dIntensity,
               GLfloat xPos, GLfloat yPos, GLfloat zPos,
               GLfloat con, GLfloat lin, GLfloat exp);
    
    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);

    ~SpotLight();
private:
    glm::vec3 direction;

    GLfloat edge, procEdge;
};