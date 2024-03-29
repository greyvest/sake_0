//
//  Texture.cpp
//  OGL
//
//  Created by u0964759 on 6/10/19.
//  Copyright © 2019 u0964759. All rights reserved.
//

#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

char * empty = "";

/* #region Constructor/Destructor */
Texture::Texture()
{
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = empty;
}

Texture::Texture(char* fileLoc)
{
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = fileLoc;
}

Texture::~Texture()
{
    ClearTexture();
}
/* #endregion */

/* #region TextureMap */
std::map<std::string, Texture> Texture::TextureMap;
/* #endregion */

/* #region Load Texture Functions */
bool Texture::LoadTextureA()
{
    unsigned char *texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
    if (!texData)
    {
        printf("Failed to find: %s\n", fileLocation);
        return false;
    }
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    stbi_image_free(texData);

    return true;
}

bool Texture::LoadTexture()
{
    unsigned char *texData = stbi_load(fileLocation, &width, &height, &bitDepth, 0);
    if (!texData)
    {
        printf("Failed to find: %s\n", fileLocation);
        return false;
    }
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    stbi_image_free(texData);

    return true;
}

bool Texture::LoadTexturelistFromFile(){
    

    return true;
}

/* #endregion */

/* #region Use texture */
void Texture::UseTexture()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
}
/* #endregion */

/* #region Clear texture */
void Texture::ClearTexture()
{
    glDeleteTextures(1, &textureID);
    textureID = 0;
    width = 0;
    height = 0;
    bitDepth = 0;
    fileLocation = empty;
}

/* #endregion */

