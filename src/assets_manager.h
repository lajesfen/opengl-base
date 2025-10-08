#pragma once

#include <string>
#include <unordered_map>

#include "shader.h"
#include "texture.h"
#include "utils/filesystem.h"

class AssetsManager {
private:
    static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
    static std::unordered_map<std::string, std::shared_ptr<Texture>> textures;

    static std::shared_ptr<Shader> LoadShaderFromFile(const std::string& vertPath, const std::string& fragPath);

public:
    AssetsManager() = default;
    ~AssetsManager() = default;

    template <typename T, typename... Args>
    static std::shared_ptr<T> Load(const std::string& name, Args&... args);

    template <typename T>
    static std::shared_ptr<T> Get(const std::string& name);

    static void Clear();
};