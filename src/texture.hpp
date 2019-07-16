#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glew.h>
#include <iostream>
#include <stdio.h>
#include <vector>


class Texture
{
public:
    Texture();
    Texture(char* fileLoc);
    
    bool LoadTexture();
    bool LoadTextureA();



    static std::vector<Texture> textureList;
    static bool LoadTexturelistFromFile();

    void UseTexture();
    void ClearTexture();
    
    ~Texture();
    
    friend std::ostream& operator<<(std::ostream& os, const Texture& dt)
    {
        os << dt.textureID << dt.width << dt.height << dt.bitDepth << dt.fileLocation;
        return os;
    }

    friend std::istream & operator >> (std::istream &in, Texture& c){
        in >> c.textureID >> c.width >> c.height >> c.bitDepth >> c.fileLocation;
        return in;
    }

private:
    GLuint textureID;
    int width, height, bitDepth;
    
    char* fileLocation;
    char* textureName;
};

#endif /*TEXTURE_H */