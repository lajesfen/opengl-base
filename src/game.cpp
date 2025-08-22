#include "game.h"

Game::Game(): m_window(Config::GAME_TITLE, Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT) {

}

Game::~Game() {

}

void Game::Init() {

}

void Game::Run() {
    Init();

    float lastFrame = 0.0f;
    while (!m_window.ShouldClose()) {
        auto currentFrame = (float)glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        m_window.PollEvents();

        Update(deltaTime);
        Render();

        m_window.SwapBuffers();
    }
}

void Game::Update(float deltaTime) {

}

void Game::Render() {

}