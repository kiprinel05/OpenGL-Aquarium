#pragma once
#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm.hpp>
#include "Shader.hpp"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Model {
public:
    Model(const std::string& path);
    void Draw(Shader& shader);

private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    unsigned int VAO, VBO, EBO;

    void LoadModel(const std::string& path);
    void LoadMaterial(const std::string& mtlPath);
    void SetupMesh();
    unsigned int TextureFromFile(const std::string& path);
};
