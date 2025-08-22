#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "config.h"
#include "window.h"

enum GameState {
    MENU,
    ACTIVE,
    INACTIVE
};

class Game {
private:
    Window m_window;
    GameState state = GameState::MENU;

public:
    Game();
    ~Game();

    void Init();
    void Run();
    void Update(float deltaTime);
    void Render();
};