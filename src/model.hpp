#ifndef Model_h
#define Model_h

#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include "texture.hpp"
#include "material.hpp"
#include "mesh.hpp"

#include <assimp/importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model{
public:
    Model();
    ~Model();

    void LoadModel(const std::string & fileName);
    void RenderModel();
    void ClearModel();

    Texture * returnTexture(){return textureList[0];}
    int sourceInt = 0;

    static std::map<std::string, Model> ModelMap;
private:

    void LoadNode(aiNode * node, const aiScene * scene);
    void LoadMesh(aiMesh * mesh, const aiScene * scene);
    void LoadMaterials(const aiScene *scene);

    std::vector<Mesh *> meshList;
    std::vector<Texture *> textureList;
    std::vector<unsigned int> meshToTex;

    std::string sourceFile = "default";
    

    friend std::ostream& operator<<(std::ostream& os, const Model& dt)
    {

        printf("Writing Sourcefile string %d\n", dt.sourceFile.c_str());
        /*os << dt.meshList.size() << dt.textureList.size() << dt.meshToTex.size();
        for(int i = 0; i < dt.meshList.size(); i++){
            os << *dt.meshList[i];
        }
        for(int i = 0; i < dt.textureList.size(); i++){
            os << *dt.textureList[i];
        }
        for(int i = 0; i < dt.meshToTex.size(); i++){
            os << dt.meshToTex[i];
        }*/
        os << dt.sourceFile.c_str();
        return os;
    }

    friend std::istream & operator>>(std::istream &in, Model &c){
        int temp1, temp2, temp3;
        in >> temp1 >> temp2 >> temp3;
        for(int i = 0; i < temp1; i++){
            Mesh y;
            in >> y;
            c.meshList[i] = &y;
        }
        for(int i = 0; i < temp2; i++){
            Texture x;
            in >> x;
            c.textureList[i] = &x;
        }
        for(int i = 0; i < temp3; i++){
            in >> c.meshToTex[i];
        }
        in >> c.sourceFile;
        return in;
    }
};

#endif