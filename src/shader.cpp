#include "shader.h"

void Shader::Create(const char* vertexSource, const char* fragmentSource) {
    unsigned const int vertexId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexId, 1, &vertexSource, nullptr);
    glCompileShader(vertexId);
    CheckCompileErrors(vertexId, "VERTEX");

    unsigned const int fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentId, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentId);
    CheckCompileErrors(fragmentId, "FRAGMENT");

    this->id = glCreateProgram();

    glAttachShader(this->id, vertexId);
    glAttachShader(this->id, fragmentId);
    glLinkProgram(this->id);
    glValidateProgram(this->id);

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
}

void Shader::setBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), (float)value);
}

Shader& Shader::Use() {
    glUseProgram(this->id);
    return *this;
}

int Shader::CheckCompileErrors(const unsigned int& id, const std::string& type) {
    int success;
    if (type != "PROGRAM") {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*) alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);

            std::cout << "Failed to compile Shader (Compile-time error): " << '\n';
            std::cout << message << '\n';

            glDeleteShader(id);
            return success;
        }
    } else {
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            int length;
            glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*) alloca(length * sizeof(char));
            glGetProgramInfoLog(id, length, &length, message);

            std::cout << "Failed to compile Shader (Link-time error): " << '\n';
            std::cout << message << '\n';

            glDeleteProgram(id);
            return success;
        }
    }

    return success;
}

unsigned int Shader::getId() const {
    return id;
}
