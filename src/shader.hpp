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
    /* #region Constructor/Destructor */
    Shader();    
    ~Shader();
    /* #endregion */

    /* #region Create Shaders */
    void CreateFromString(const char* vertexCode, const char* fragmentCode);
    void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
    void CreateFromFiles(const char* vertexLocation, const char* geometryLocation, const char* fragmentLocation);
    std::string ReadFile(const char* fileLocation);
    /* #endregion Create Shaders */

    /* #region Validation */
    void Validate();
    /* #endregion Validation */

    /* #region Getter functions */
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
    /* #endregion */

    /* #region Setter functions */
    void SetDirectionalLight(DirectionalLight * dLight);
    void SetPointLights(PointLight * pLight, unsigned int lightCount, unsigned int textureUnit, unsigned int offset);
    void SetSpotLights(SpotLight * sLight, unsigned int lightCount,unsigned int textureUnit, unsigned int offset);
    void SetTexture(GLuint textureUnit);
    void SetDirectionalShadowMap(GLuint textureUnit);
    void SetDirectionalLightTransform(glm::mat4 * lTransform);
    void SetOmniLightMatrices(std::vector<glm::mat4> lightMatrices);
    /* #endregion */

    /* #region Key Shader Functions */
    void UseShader();
    void ClearShader();
    /* #endregion */

    
private:
    /* Light Count Variables */
    int pointLightCount;
    int spotLightCount;

    /* uniform variables */
    GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
    uniformSpecularIntensity, uniformShininess, uniformTexture, uniformDirectionalLightTransform, uniformDirectionalShadowMap, uniformOmniLightPos, uniformFarPlane;

    /* Light matrice array for omni directional shaodw maps */
    GLuint uniformLightMatrices[6];
    
    /* Directional light struct */
    struct {
        GLuint uniformColour;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;
        GLuint uniformDirection;
    } uniformDirectionalLight;

    /* Point light count */    
    GLuint uniformPointLightCount;
    /* Point light struct */
    struct {
        GLuint uniformColour;
        GLuint uniformAmbientIntensity;
        GLuint uniformDiffuseIntensity;
        
        GLuint uniformPosition;
        GLuint uniformConstant;
        GLuint uniformLinear;
        GLuint uniformExponent;
    } uniformPointLight[MAX_POINT_LIGHTS];
    
    /* Spot light count */
    GLuint uniformSpotLightCount;
    /* Spot light struct */
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

    /* Omni directional shadow map struct */
    struct {
		GLuint uniformShadowMap;
		GLuint uniformFarPlane;
	} uniformOmniShadowMap[MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS];

    /*Shader compilation functions */
    void CompileShader(const char* vertexCode, const char* fragmentCode);
	void CompileShader(const char* vertexCode, const char* geometryCode, const char* fragmentCode);
    void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
    void CompileProgram();
};



#endif /* Shader_hpp */
