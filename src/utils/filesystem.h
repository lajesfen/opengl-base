#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class FileSystem {
public:
    static std::string ParseFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};