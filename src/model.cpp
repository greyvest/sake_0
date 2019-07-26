#include "model.hpp"

/* #region Constructors/Destructor */
Model::Model(){

}

Model::~Model(){

}
/* #endregion */

/* #region ModelMap */
std::map<std::string, Model> Model::ModelMap;
/* #endregion */

/* #region Loading models functionality */

/* #region Load Model parent function */
void Model::LoadModel(const std::string & filename){
	
    Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

    if(!scene){
        printf("Model %s failed to load: %s.\n", filename.c_str(), importer.GetErrorString());
        return;
    }

    LoadNode(scene->mRootNode, scene);

    LoadMaterials(scene);

    sourceFile = filename.c_str();
    sourceInt = 1;
    
}
/* #endregion */

/* #region Load Node */
void Model::LoadNode(aiNode * node, const aiScene * scene){
    for(size_t i = 0; i < node->mNumMeshes; i++){
        LoadMesh(scene->mMeshes[node->mMeshes[i]], scene);
    }
    for(size_t i = 0; i < node->mNumChildren; i++){
        LoadNode(node->mChildren[i], scene);
    }
}
/* #endregion */

/* #region Load Mesh */
void Model::LoadMesh(aiMesh * mesh, const aiScene * scene){
    std::vector<GLfloat> vertices;
    std::vector<unsigned int> indices;
    for(size_t i = 0; i < mesh->mNumVertices; i++){
        vertices.insert(vertices.end(), {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z});
        if(mesh->mTextureCoords[0]){
            vertices.insert(vertices.end(), {mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y});
        }
        else{
            vertices.insert(vertices.end(), {0.0f, 0.0f});
        }
        vertices.insert(vertices.end(), {-mesh->mNormals[i].x, -mesh->mNormals[i].y, -mesh->mNormals[i].z});
    }

    for(size_t i = 0; i < mesh->mNumFaces;i++){
        aiFace face = mesh->mFaces[i];
        for(size_t j = 0; j < face.mNumIndices; j++){
            indices.push_back(face.mIndices[j]);

        }
    }

    Mesh * newMesh = new Mesh();
    newMesh->CreateMesh(&vertices[0], &indices[0], vertices.size(), indices.size());
    meshList.push_back(newMesh);
    meshToTex.push_back(mesh->mMaterialIndex);
}
/* #endregion */

/* #region Load Materials */
void Model::LoadMaterials(const aiScene *scene){

    textureList.resize(scene->mNumMaterials);

    for(size_t i = 0; i < scene->mNumMaterials; i++){
        aiMaterial * material = scene->mMaterials[i];

        textureList[i] = nullptr;

        if(material->GetTextureCount(aiTextureType_DIFFUSE)){
            aiString path;
            if(material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS){
                int idx = std::string(path.data).rfind("\\");
                std::string filename = std::string(path.data).substr(idx + 1);

                const std::string texPath = std::string("textures/") + filename;
                char * writable = new char[texPath.size() + 1];
                std::copy(texPath.begin(), texPath.end(), writable);
                writable[texPath.size()] = '\0';


                textureList[i] = new Texture(writable);

                if(!textureList[i]->LoadTexture()){
                    printf("FAILED TO LOAD TEXTURE AT %S\n", texPath.c_str());
                    delete(textureList[i]);
                    textureList[i] = nullptr; 
                }
            }
        }
        if(!textureList[i]){
            textureList[i] = new Texture("src/textures/plain.png");
            textureList[i]->LoadTextureA();
        }
    }
}
/* #endregion */

/* #endregion */

/* #region Render model */
void Model::RenderModel(){
    for(size_t i = 0; i < meshList.size(); i++){
        unsigned int materialIndex = meshToTex[i];


        if(materialIndex < textureList.size() && textureList[materialIndex]){
            textureList[materialIndex]->UseTexture();
        }

        meshList[i]->RenderMesh();
    }
}
/* #endregion */

/* #region Clear Model */
void Model::ClearModel(){
    for(size_t i = 0; i < meshList.size(); i++){
        if(meshList[i]){
            delete meshList[i];
            meshList[i] = nullptr;
        }
    }
    for(size_t i = 0; i < textureList.size(); i++){
        delete textureList[i];
        textureList[i] = nullptr;
    }
}
/* #endregion */
