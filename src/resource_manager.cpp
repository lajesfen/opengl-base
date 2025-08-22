#include "resource_manager.h"

std::map<std::string, Texture> ResourceManager::Textures;
std::map<std::string, Shader> ResourceManager::Shaders;

Shader ResourceManager::LoadShader(const std::string &vertex, const std::string &fragment, const std::string &name) {
    Shader shader{};
    shader.Create(vertex.c_str(), fragment.c_str());

    Shaders[name] = shader;
    return Shaders[name];
}

Texture ResourceManager::LoadTexture(const std::string &file, const std::string &name) {
    return Texture();
}

Texture ResourceManager::getTexture(const std::string &name) {
    return Textures[name];
}

Shader ResourceManager::getShader(const std::string &name) {
    return Shaders[name];
}
