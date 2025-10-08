#include "assets_manager.h"

std::unordered_map<std::string, std::shared_ptr<Texture>> AssetsManager::textures;
std::unordered_map<std::string, std::shared_ptr<Shader>> AssetsManager::shaders;

std::shared_ptr<Shader> AssetsManager::LoadShaderFromFile(const std::string& vertPath, const std::string& fragPath) {
    std::string vertCode, fragCode;
    try {
        vertCode = FileSystem::ParseFile(vertPath);
        fragCode = FileSystem::ParseFile(fragPath);
    } catch(std::exception& err) {
        std::cerr << "ERROR::SHADER: " << err.what() << '\n';
        return nullptr;
    }

    auto shader = std::make_shared<Shader>();
    shader->Create(vertCode.c_str(), fragCode.c_str());
    return shader;
}

template<>
std::shared_ptr<Shader> AssetsManager::Load(const std::string& name, const std::string& vertPath, const std::string& fragPath) {
    shaders[name] = AssetsManager::LoadShaderFromFile(vertPath, fragPath);
    return shaders[name];
}

template<>
std::shared_ptr<Texture> AssetsManager::Load(const std::string& name, const std::string& file) {
    return {};
}

template<>
std::shared_ptr<Shader> AssetsManager::Get(const std::string& name) {
    return shaders.at(name);
}

template<>
std::shared_ptr<Texture> AssetsManager::Get(const std::string& name) {
    return textures.at(name);
}

void AssetsManager::Clear() {
    for (const auto& i : shaders)
        glDeleteProgram(i.second->getId());
    shaders.clear();

    // for (const auto& i : textures)
    //     glDeleteTextures(1, &i.second->getId());
    textures.clear();
}