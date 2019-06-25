#include <vector>
#include <stdio.h>
#include <string>

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
private:

    void LoadNode(aiNode * node, const aiScene * scene);
    void LoadMesh(aiMesh * mesh, const aiScene * scene);
    void LoadMaterials(const aiScene *scene);

    std::vector<Mesh *> meshList;
    std::vector<Texture *> textureList;
    std::vector<unsigned int> meshToTex;
};