//
//  Shader.hpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "commonValues.h"

#include "directionalLight.hpp"
#include "pointLight.hpp"
#include "spotLight.hpp"

class Shader
{
public:
    Shader();
    
    void CreateFromString(const char* vertexCode, const char* fragmentCode);
    void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
    void CreateFromFiles(const char* vertexLocation, const char* geometryLocation, const char* fragmentLocation);

    void Validate();

    std::string ReadFile(const char* fileLocation);
    
    GLuint GetProjectionLocation();
    GLuint GetModelLocation();
    GLuint GetViewLocation();
    GLuint GetAmbientIntensityLocation();
    GLuint GetAmbientColourLocation();
    GLuint GetDiffuseIntensityLocation();
    GLuint GetDirectionLocation();
    GLuint GetSpecularIntensityLocation();
    GLuint GetShininessLocation();
    GLuint GetEyePositionLocation();
	GLuint GetOmniLightPosLocation();
	GLuint GetFarPlaneLocation();

    void SetDirectionalLight(DirectionalLight * dLight);
    void SetPointLights(PointLight * pLight, unsigned int lightCount);
    void SetSpotLights(SpotLight * sLight, unsigned int lightCount);
    void SetTexture(GLuint textureUnit);
    void SetDirectionalShadowMap(GLuint textureUnit);
    void SetDirectionalLightTransform(glm::mat4 * lTransform);

    void UseShader();
    void ClearShader();
    
    ~Shader();
    
private:
    int pointLightCount;
    int spotLightCount;

    GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
    uniformSpecularIntensity, uniformShininess, uniformTexture, uniformDirectionalLightTransform, uniformDirectionalShadowMap, uniformOmniLightPos, uniformFarPlane;

    GLuint uniformLightMatrices[6];
    
    struct {
        GLuint uniformColour;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;
        
        GLuint uniformDirection;
    } uniformDirectionalLight;
    
    GLuint uniformPointLightCount;
    
    struct {
        GLuint uniformColour;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;
        
        GLuint uniformPosition;
        GLuint uniformConstant;
        GLuint uniformLinear;
        GLuint uniformExponent;
    } uniformPointLight[MAX_POINT_LIGHTS];
    
    GLuint uniformSpotLightCount;

    struct {
        GLuint uniformColour;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;
        
        GLuint uniformPosition;
        GLuint uniformConstant;
        GLuint uniformLinear;
        GLuint uniformExponent;

        GLuint uniformDirection;
        GLuint uniformEdge;
    } uniformSpotLight[MAX_SPOT_LIGHTS];

    struct {
		GLuint uniformShadowMap;
		GLuint uniformFarPlane;
	} uniformOmniShadowMap[MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS];

    void CompileShader(const char* vertexCode, const char* fragmentCode);
	void CompileShader(const char* vertexCode, const char* geometryCode, const char* fragmentCode);
    void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);

    void CompileProgram();
};



#endif /* Shader_hpp */
