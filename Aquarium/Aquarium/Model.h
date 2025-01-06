#pragma once
#include <vector>
#include <iostream>
#include "Texture.h"
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);

class Model
{
public:
    // model data 
    vector<Texture> textures_loaded;
    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;

    Model(string const& path, bool bSmoothNormals, glm::vec3 position, std::string texturePath, bool gamma = false);
    Model(string const& path, bool bSmoothNormals, bool gamma = false);

    void RenderModel(Shader& shader, const glm::mat4& model = glm::mat4(1));
    void RenderModelMesh(Shader& shader, glm::mat4& model, int meshID, glm::mat4& meshModel);

private:
    void loadModel(string const& path, bool bSmoothNormals);

    void processNode(aiNode* node, const aiScene* scene);

    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

    glm::vec3 position;
};

