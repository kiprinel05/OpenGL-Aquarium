#pragma once
#include <GLM.hpp>
#include <gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Vertex.h"

#include <string>
#include <vector>

using namespace std;

class Mesh
{
public:
    // mesh Data
    unsigned int numVertices;
    std::shared_ptr <Vertex> vertices;

    unsigned int numIndexes;
    std::shared_ptr <unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;

    Mesh(const vector<Vertex>& vertices, const vector<unsigned int>& indices, const vector<Texture>& textures);
    Mesh(const vector<Vertex>& vertices, const vector<unsigned int>& indices);
    Mesh(unsigned int numVertices, std::shared_ptr <Vertex> vertices, unsigned int numIndexes, std::shared_ptr <unsigned int> indices, const vector<Texture>& textures);
    void RenderMesh(Shader& shader, const glm::mat4& model = glm::mat4(1));
    void RenderTerrain(Shader& shader, const glm::mat4& model = glm::mat4(1));
protected:
    void setupMesh();
private:
    // render data 
    unsigned int VBO, EBO;
};

