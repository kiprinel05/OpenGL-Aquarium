#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <vector>
#include <string>
#include "vertex.hpp"

class ModelLoader {
public:
    static bool LoadOBJ(const std::string& path,
        std::vector<Vertex>& vertices,
        std::vector<unsigned int>& indices);
};

#endif
