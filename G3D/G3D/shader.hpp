#pragma once
#include <string>
#include <GL/glew.h>
#include <glm.hpp>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Use() const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetMat4(const std::string& name, const glm::mat4& mat) const;

private:
    void CheckCompileErrors(GLuint shader, std::string type);
    GLuint ID;
};
