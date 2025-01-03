#define STB_IMAGE_IMPLEMENTATION
#include "Model.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <stb_image.h>

namespace fs = std::filesystem;

Model::Model(const std::string& path) {
    std::cout << "Current Path: " << fs::current_path() << std::endl;
    LoadModel(path);
    SetupMesh();
}

void Model::Draw(Shader& shader) {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Model::LoadModel(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open model file: " << path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            glm::vec3 position;
            iss >> position.x >> position.y >> position.z;
            vertices.push_back({ position });
        }
        else if (prefix == "f") {
            unsigned int idx1, idx2, idx3;
            iss >> idx1 >> idx2 >> idx3;
            indices.push_back(idx1 - 1);
            indices.push_back(idx2 - 1);
            indices.push_back(idx3 - 1);
        }
        else if (prefix == "mtllib") {
            std::string mtlFile;
            iss >> mtlFile;
            LoadMaterial(mtlFile);
        }
    }
}

void Model::LoadMaterial(const std::string& mtlPath) {
    std::ifstream file(mtlPath);
    if (!file.is_open()) {
        std::cerr << "Failed to open material file: " << mtlPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "map_Kd") {
            std::string texturePath;
            iss >> texturePath;
            textures.push_back({ TextureFromFile(texturePath), "texture_diffuse", texturePath });
        }
    }
}

void Model::SetupMesh() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glBindVertexArray(0);
}

unsigned int Model::TextureFromFile(const std::string& path) {
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format = (nrComponents == 3) ? GL_RGB : GL_RGBA;
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
    else {
        std::cerr << "Failed to load texture: " << path << std::endl;
    }

    return textureID;
}
