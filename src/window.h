#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
    GLFWwindow* handle;
    unsigned int width;
    unsigned int height;
    const char* title;

public:
    Window(const char* title, unsigned int width, unsigned int height);
    ~Window();

    bool ShouldClose();
    void PollEvents();
    void SwapBuffers();

    [[nodiscard]] GLFWwindow* GetHandle() const;
    [[nodiscard]] unsigned int GetWidth() const;
    [[nodiscard]] unsigned int GetHeight() const;
    [[nodiscard]] const char* GetTitle() const;
};