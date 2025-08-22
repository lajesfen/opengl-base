#pragma once

#include <iostream>
#include <string>
#include <map>

#include "shader.h"
#include "texture.h"

// ToDo: Make Texture (2D) class

class ResourceManager {
private:
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture> Textures;

public:
    ResourceManager() = default;

    static Shader LoadShader(const std::string &vertex, const std::string &fragment, const std::string& name);
    static Texture LoadTexture(const std::string &file, const std::string& name);

    [[nodiscard]] static Texture getTexture(const std::string& name);
    [[nodiscard]] static Shader getShader(const std::string& name);
};