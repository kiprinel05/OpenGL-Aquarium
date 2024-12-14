#include "model_loader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool ModelLoader::LoadOBJ(const std::string& path,
    std::vector<Vertex>& vertices,
    std::vector<unsigned int>& indices) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open OBJ file " << path << std::endl;
        return false;
    }

    std::vector<glm::vec3> temp_positions;
    std::vector<glm::vec3> temp_normals;
    std::vector<glm::vec2> temp_texcoords;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            glm::vec3 position;
            iss >> position.x >> position.y >> position.z;
            temp_positions.push_back(position);
        }
        else if (prefix == "vt") {
            glm::vec2 texcoord;
            iss >> texcoord.x >> texcoord.y;
            temp_texcoords.push_back(texcoord);
        }
        else if (prefix == "vn") {
            glm::vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            temp_normals.push_back(normal);
        }
        else if (prefix == "f") {
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            char slash;

            for (int i = 0; i < 3; i++) {
                iss >> vertexIndex[i] >> slash >> uvIndex[i] >> slash >> normalIndex[i];
                Vertex vertex;
                vertex.Position = temp_positions[vertexIndex[i] - 1];
                vertex.TexCoords = temp_texcoords[uvIndex[i] - 1];
                vertex.Normal = temp_normals[normalIndex[i] - 1];
                vertices.push_back(vertex);
                indices.push_back(indices.size());
            }
        }
    }
    file.close();
    return true;
}
