#pragma once

#include "config.h"
#include "window.h"
#include "assets_manager.h"

enum ProgramState {
    ACTIVE,
    INACTIVE
};

class Program {
private:
    Window window;
    ProgramState state = ProgramState::ACTIVE;
    unsigned int VAO{}, VBO{}, EBO{};

public:
    Program();
    ~Program();

    void Init();
    void Run();
    void Update(float deltaTime);
    void Render();
};