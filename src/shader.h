#pragma once

#include <glad/gl.h>
#include <iostream>

struct Shader {
private:
    unsigned int id;

    static int CheckCompileErrors(const unsigned int& id, const std::string& type);

public:
    Shader() = default;
    ~Shader() = default;

    void Create(const char* vertexSource, const char* fragmentSource);
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    Shader& Use();

    [[nodiscard]] unsigned int getId() const;
};