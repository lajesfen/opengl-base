#include "resource_manager.h"

std::unordered_map<std::string, Texture> ResourceManager::Textures;
std::unordered_map<std::string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const std::string &vertex, const std::string &fragment, const std::string &name) {
    Shaders[name] = ResourceManager::LoadShaderFromFile(vertex, fragment);
    return Shaders[name];
}

Texture ResourceManager::LoadTexture(const std::string &file, const std::string &name) {
    return {};
}

Shader ResourceManager::LoadShaderFromFile(const std::string &vertexFile, const std::string &fragmentFile) {
    std::string vertCode;
    std::string fragCode;

    std::ifstream vertexShaderFile(vertexFile);
    std::ifstream fragmentShaderFile(fragmentFile);

    if (!vertexShaderFile.is_open()) {
        std::cerr << "ERROR::SHADER: Failed to open vertex file: " << vertexFile << '\n';
        return Shader{};
    }
    if (!fragmentShaderFile.is_open()) {
        std::cerr << "ERROR::SHADER: Failed to open fragment file: " << fragmentFile << '\n';
        return Shader{};
    }

    try {
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertCode = vShaderStream.str();
        fragCode = fShaderStream.str();
    } catch(std::exception& err) {
        std::cerr << "ERROR::SHADER: " << err.what() << '\n';
    }

    const char *vShaderCode = vertCode.c_str();
    const char *fShaderCode = fragCode.c_str();

    Shader shader{};
    shader.Create(vShaderCode, fShaderCode);

    return shader;
}

void ResourceManager::Clear() {
    for (const auto& i : Shaders) {
        glDeleteProgram(i.second.getId());
    }
}

Texture ResourceManager::getTexture(const std::string &name) {
    return Textures[name];
}

Shader ResourceManager::getShader(const std::string &name) {
    return Shaders[name];
}
