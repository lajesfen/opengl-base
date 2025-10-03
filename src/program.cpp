#include "program.h"

Program::Program(): m_window(Config::TITLE, Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT) {

}

Program::~Program() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Program::Init() {
    ResourceManager::LoadShader(static_cast<std::string>(RESOURCES) + "/shaders/texture.vert", static_cast<std::string>(RESOURCES) + "/shaders/texture.frag", "texture");

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr); // x, y, z
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Program::Run() {
    Init();
    auto shader = ResourceManager::getShader("texture");

    if (shader.getId() == 0) {
        std::cerr << "ERROR::PROGRAM: Failed to load shader!" << std::endl;
        return;
    }

    std::cout << "Shader loaded successfully with ID: " << shader.getId() << std::endl;

    float lastFrame = 0.0f;
    while (!m_window.ShouldClose()) {
        // auto currentFrame = (float)glfwGetTime();
        // float deltaTime = currentFrame - lastFrame;
        // lastFrame = currentFrame;
        // Update(deltaTime);
        //
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        m_window.SwapBuffers();
        m_window.PollEvents();
    }

    ResourceManager::Clear();
}

void Program::Update(float deltaTime) {

}

void Program::Render() {

}