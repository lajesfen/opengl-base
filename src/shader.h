#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct Shader {
private:
    unsigned int id;

    static int CheckCompileErrors(const unsigned int& id, const std::string& type);
public:
    Shader() = default;
    ~Shader();

    void Create(const char* vertexSource, const char* fragmentSource);
    Shader& Use();

    [[nodiscard]] unsigned int getId() const;
};