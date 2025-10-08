#include "program.h"

Program::Program(): window(Config::TITLE, Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT) {};

Program::~Program() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Program::Init() {
    const std::string& vertPath = static_cast<std::string>(RESOURCES) + "/shaders/texture.vert";
    const std::string& fragPath = static_cast<std::string>(RESOURCES) + "/shaders/texture.frag";
    AssetsManager::Load<Shader>("texture", vertPath, fragPath);

    float vertices[] = {
         0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 0.0f,
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr); // x, y, z
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // r, g, b
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Program::Run() {
    Init();
    auto const shader = AssetsManager::Get<Shader>("texture");

    if (shader->getId() == 0) {
        std::cerr << "ERROR::PROGRAM: Failed to load shader!" << std::endl;
        return;
    }

    float lastFrame = 0.0f;
    while (!window.ShouldClose()) {
        // auto currentFrame = (float)glfwGetTime();
        // float deltaTime = currentFrame - lastFrame;
        // lastFrame = currentFrame;
        // Update(deltaTime);
        //
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->Use();

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);

        window.SwapBuffers();
        window.PollEvents();
    }

    AssetsManager::Clear();
}

void Program::Update(float deltaTime) {

}

void Program::Render() {

}