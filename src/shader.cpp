//
//  Shader.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#include "shader.hpp"

/* #region Constructor/Destructor */
Shader::Shader()
{
    shaderID = 0;
    uniformModel = 0;
    uniformProjection = 0;
    
    pointLightCount = 0;
    spotLightCount = 0;
}

Shader::~Shader()
{
    ClearShader();
}
/* #endregion */

/* #region Create from Files */
void Shader::CreateFromString(const char* vertexCode, const char* fragmentCode)
{
    CompileShader(vertexCode, fragmentCode);
}

void Shader::CreateFromFiles(const char* vertexLocation, const char* fragmentLocation)
{
    std::string vertexString = ReadFile(vertexLocation);
    std::string fragmentString = ReadFile(fragmentLocation);
    
    const char* vertexCode = vertexString.c_str();
    const char* fragmentCode = fragmentString.c_str();
    
    CompileShader(vertexCode, fragmentCode);
}

void Shader::CreateFromFiles(const char* vertexLocation, const char* geometryLocation, const char* fragmentLocation)
{
	std::string vertexString = ReadFile(vertexLocation);
	std::string geometryString = ReadFile(geometryLocation);
	std::string fragmentString = ReadFile(fragmentLocation);
	const char* vertexCode = vertexString.c_str();
	const char* geometryCode = geometryString.c_str();
	const char* fragmentCode = fragmentString.c_str();

	CompileShader(vertexCode, geometryCode, fragmentCode);
}

std::string Shader::ReadFile(const char* fileLocation)
{
    std::string content;
    std::ifstream fileStream(fileLocation, std::ios::in);
    
    if (!fileStream.is_open()) {
        printf("Failed to read %s! File doesn't exist.\n", fileLocation);
        return "";
    }
    
    std::string line = "";
    while (!fileStream.eof())
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }
    
    fileStream.close();
    
    return content;
}

/* #endregion */

/* #region Validation */
void Shader::Validate()
{
	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glValidateProgram(shaderID);
	glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
	}
}
/* #endregion */

/* #region Shader compilation functions */

/* #region Compile vertex/frag shader */
void Shader::CompileShader(const char* vertexCode, const char* fragmentCode)
{
    shaderID = glCreateProgram();
    
    if (!shaderID)
    {
        printf("Error creating shader program!\n");
        return;
    }
    
    AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
    AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);
    
    CompileProgram();
}
/* #endregion */

/* #region Compile Vertext/Geom/Frag shaders */
void Shader::CompileShader(const char* vertexCode, const char* geometryCode, const char* fragmentCode)
{
	shaderID = glCreateProgram();

	if (!shaderID)
	{
		printf("Error creating shader program!\n");
		return;
	}

	AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
	AddShader(shaderID, geometryCode, GL_GEOMETRY_SHADER);
	AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);

	CompileProgram();
}
/* #endregion */

/* #region Compile shader programs */
void Shader::CompileProgram(){

    /* #region link program */
    GLint result = 0;
    GLchar eLog[1024] = { 0 };

    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }
    /* #endregion */
    
    /* #region set directional light uniform values */
    uniformProjection = glGetUniformLocation(shaderID, "projection");
    //printf("Uniform Project: %d \n", uniformProjection);
    uniformModel = glGetUniformLocation(shaderID, "model");
    uniformView = glGetUniformLocation(shaderID, "view");
    uniformDirectionalLight.uniformColour = glGetUniformLocation(shaderID, "directionalLight.base.colour");
    uniformDirectionalLight.uniformAmbientIntensity = glGetUniformLocation(shaderID, "directionalLight.base.ambientIntensity");
    uniformDirectionalLight.uniformDirection = glGetUniformLocation(shaderID, "directionalLight.direction");
    uniformDirectionalLight.uniformDiffuseIntensity = glGetUniformLocation(shaderID, "directionalLight.base.diffuseIntensity");
    uniformSpecularIntensity = glGetUniformLocation(shaderID, "material.specularIntensity");
    uniformShininess = glGetUniformLocation(shaderID, "material.shininess");
    uniformEyePosition = glGetUniformLocation(shaderID, "eyePosition");
    /* #endregion */
    
    /* #region set point light uniform values */
    uniformPointLightCount = glGetUniformLocation(shaderID, "pointLightCount");
    
    for(size_t i = 0; i < MAX_POINT_LIGHTS; i++){
        char locBuff[100] = {'\0'};
        //set color of point light i
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.colour", i);
        uniformPointLight[i].uniformColour = glGetUniformLocation(shaderID, locBuff);
        //set intensity of point light i
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.ambientIntensity", i);
        uniformPointLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderID, locBuff);
        //set diffuseIntensity of point light i
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.diffuseIntensity", i);
        uniformPointLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].position", i);
        uniformPointLight[i].uniformPosition = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].constant", i);
        uniformPointLight[i].uniformConstant = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].linear", i);
        uniformPointLight[i].uniformLinear = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "pointLights[%d].base.exponent", i);
        uniformPointLight[i].uniformExponent = glGetUniformLocation(shaderID, locBuff);
        
    }
    /* #endregion */

    /* #region set spot light uniform values */
    uniformSpotLightCount = glGetUniformLocation(shaderID, "spotLightCount");
    
    for(size_t i = 0; i < MAX_SPOT_LIGHTS; i++){
        char locBuff[100] = {'\0'};
        //set color of point light i
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.colour", i);
        uniformSpotLight[i].uniformColour = glGetUniformLocation(shaderID, locBuff);
        
        //set intensity of point light i
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.ambientIntensity", i);
        uniformSpotLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderID, locBuff);
        //set diffuseIntensity of point light i
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.base.diffuseIntensity", i);
        uniformSpotLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.position", i);
        uniformSpotLight[i].uniformPosition = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.constant", i);
        uniformSpotLight[i].uniformConstant = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.linear", i);
        uniformSpotLight[i].uniformLinear = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].base.exponent", i);
        uniformSpotLight[i].uniformExponent = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].direction", i);
        uniformSpotLight[i].uniformDirection = glGetUniformLocation(shaderID, locBuff);
        
        snprintf(locBuff, sizeof(locBuff), "spotLights[%d].edge", i);
        uniformSpotLight[i].uniformEdge = glGetUniformLocation(shaderID, locBuff);
        
    }
    /* #endregion */

    /* #region set omnidirectional shadow map values */
    for (size_t i = 0; i < MAX_SPOT_LIGHTS + MAX_POINT_LIGHTS; i++)
    {
        char locBuff[100] = { '\0' };

        snprintf(locBuff, sizeof(locBuff), "omniShadowMaps[%d].shadowMap", i);
        uniformOmniShadowMap[i].uniformShadowMap = glGetUniformLocation(shaderID, locBuff);
        //printf("Uniform Shadow Map %d\n", uniformOmniShadowMap[i].uniformShadowMap);

        snprintf(locBuff, sizeof(locBuff), "omniShadowMaps[%d].farPlane", i);
        uniformOmniShadowMap[i].uniformFarPlane = glGetUniformLocation(shaderID, locBuff);
        //printf("Uniform Far Plane %d\n", uniformOmniShadowMap[i].uniformFarPlane);
    }

    /* #endregion */

    /* #region set directional shadowmap uniform values */
    uniformDirectionalLightTransform = glGetUniformLocation(shaderID, "directionalLightTransform");
    uniformTexture = glGetUniformLocation(shaderID, "theTexture");
    uniformDirectionalShadowMap = glGetUniformLocation(shaderID, "directionalShadowMap");

    uniformOmniLightPos = glGetUniformLocation(shaderID, "lightPos");
    uniformFarPlane = glGetUniformLocation(shaderID, "farPlane");
    //printf("Uniform Far Plane X : %d \n", uniformFarPlane);
    /* #endregion */

    /* #region set light matrice values */
    for (size_t i = 0; i < 6; i++)
    {
        char locBuff[100] = { '\0' };

        snprintf(locBuff, sizeof(locBuff), "lightMatrices[%d]", i);
        uniformLightMatrices[i] = glGetUniformLocation(shaderID, locBuff);
    }
    /* #endregion */
}
/* #endregion */

/* #endregion shader compliation functions*/

/* #region Value Getters */
GLuint Shader::GetProjectionLocation()
{
    return uniformProjection;
}
GLuint Shader::GetModelLocation()
{
    return uniformModel;
}
GLuint Shader::GetViewLocation()
{
    return uniformView;
}
GLuint Shader::GetAmbientColourLocation()
{
    return uniformDirectionalLight.uniformColour;
}
GLuint Shader::GetAmbientIntensityLocation()
{
    return uniformDirectionalLight.uniformAmbientIntensity;
}
GLuint Shader::GetDiffuseIntensityLocation()
{
    return uniformDirectionalLight.uniformDiffuseIntensity;
}
GLuint Shader::GetDirectionLocation()
{
    return uniformDirectionalLight.uniformDirection;
}
GLuint Shader::GetSpecularIntensityLocation()
{
    return uniformSpecularIntensity;
}
GLuint Shader::GetShininessLocation()
{
    return uniformShininess;
}
GLuint Shader::GetEyePositionLocation()
{
    return uniformEyePosition;
}
GLuint Shader::GetOmniLightPosLocation()
{
	return uniformOmniLightPos;
}
GLuint Shader::GetFarPlaneLocation()
{
	return uniformFarPlane;
}
/* #endregion */

/* #region Set Light Value functions */

/* #region Set Directional Lights */
void Shader::SetDirectionalLight(DirectionalLight * dLight)
{
    dLight->UseLight(uniformDirectionalLight.uniformAmbientIntensity, uniformDirectionalLight.uniformColour,
                     uniformDirectionalLight.uniformDiffuseIntensity, uniformDirectionalLight.uniformDirection);
}
/* #endregion */

/* #region Set Point Lights */
void Shader::SetPointLights(PointLight * pLight, unsigned int lightCount, unsigned int textureUnit, unsigned int offset)
{
    if (lightCount > MAX_POINT_LIGHTS) lightCount = MAX_POINT_LIGHTS;
    
    glUniform1i(uniformPointLightCount, lightCount);
    
    for (size_t i = 0; i < lightCount; i++)
    {
        //printf("Settin a point light: %d \n", i);
        pLight[i].UseLight(uniformPointLight[i].uniformAmbientIntensity, uniformPointLight[i].uniformColour,
                           uniformPointLight[i].uniformDiffuseIntensity, uniformPointLight[i].uniformPosition,
                           uniformPointLight[i].uniformConstant, uniformPointLight[i].uniformLinear, uniformPointLight[i].uniformExponent);
        
        pLight[i].GetShadowMap()->Read(GL_TEXTURE0 + textureUnit + i);
		glUniform1i(uniformOmniShadowMap[i + offset].uniformShadowMap, textureUnit + i);
		glUniform1f(uniformOmniShadowMap[i + offset].uniformFarPlane, pLight[i].GetFarPlane());
    }
}
/* #endregion */

/* #region Set Spot Lights */
void Shader::SetSpotLights(SpotLight * sLight, unsigned int lightCount, unsigned int textureUnit, unsigned int offset){
    if (lightCount > MAX_SPOT_LIGHTS) lightCount = MAX_SPOT_LIGHTS;
    
    glUniform1i(uniformSpotLightCount, lightCount);
    
    for (size_t i = 0; i < lightCount; i++)
    {
        //printf("Settin a point light: %d \n", i);
		sLight[i].UseLight(uniformSpotLight[i].uniformAmbientIntensity, uniformSpotLight[i].uniformColour,
			uniformSpotLight[i].uniformDiffuseIntensity, uniformSpotLight[i].uniformPosition, uniformSpotLight[i].uniformDirection,
			uniformSpotLight[i].uniformConstant, uniformSpotLight[i].uniformLinear, uniformSpotLight[i].uniformExponent,
			uniformSpotLight[i].uniformEdge);
        
        printf("Texture unit: %u\n", GL_TEXTURE0 + textureUnit + i);
        printf("Far Plane: %u\n", sLight[i].GetFarPlane());

        sLight[i].GetShadowMap()->Read(GL_TEXTURE0 + textureUnit + i);
		glUniform1i(uniformOmniShadowMap[i + offset].uniformShadowMap, textureUnit + i);
		glUniform1f(uniformOmniShadowMap[i + offset].uniformFarPlane, sLight[i].GetFarPlane());
    }
}
/* #endregion */


void Shader::SetTexture(GLuint textureUnit){
    glUniform1i(uniformTexture, textureUnit);
}

void Shader::SetDirectionalShadowMap(GLuint textureUnit){
    glUniform1i(uniformDirectionalShadowMap, textureUnit);
}

void Shader::SetDirectionalLightTransform(glm::mat4 * lTransform){
    glUniformMatrix4fv(uniformDirectionalLightTransform, 1, GL_FALSE, glm::value_ptr(*lTransform));
}

/* #region Set Omni Light Matrices */
void Shader::SetOmniLightMatrices(std::vector<glm::mat4> lightMatrices)
{
	for (size_t i = 0; i < 6; i++)
	{
		glUniformMatrix4fv(uniformLightMatrices[i], 1, GL_FALSE, glm::value_ptr(lightMatrices[i]));
	}
}
/* #endregion */

/* #endregion */

/* #region Key Shader Functions */
void Shader::UseShader()
{
    glUseProgram(shaderID);
}

void Shader::ClearShader()
{
    if (shaderID != 0)
    {
        glDeleteProgram(shaderID);
        shaderID = 0;
    }
    
    uniformModel = 0;
    uniformProjection = 0;
}
/* #endregion */

/* #region Add Shader */
void Shader::AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
    GLuint theShader = glCreateShader(shaderType);
    
    const GLchar* theCode[1];
    theCode[0] = shaderCode;
    
    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);
    
    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);
    
    GLint result = 0;
    GLchar eLog[1024] = { 0 };
    
    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
        printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
        return;
    }
    
    glAttachShader(theProgram, theShader);
}
/* #endregion  */


