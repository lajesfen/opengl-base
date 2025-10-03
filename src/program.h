#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "config.h"
#include "window.h"
#include "resource_manager.h"

#include "glm/glm.hpp"
#include "glm/ext/matrix_clip_space.hpp"

enum ProgramState {
    ACTIVE,
    INACTIVE
};

class Program {
private:
    Window m_window;
    ProgramState state = ProgramState::ACTIVE;
    unsigned int VAO, VBO;

public:
    Program();
    ~Program();

    void Init();
    void Run();
    void Update(float deltaTime);
    void Render();
};