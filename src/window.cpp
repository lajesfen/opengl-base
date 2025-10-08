#include "window.h"

Window::Window(const char *title, unsigned int width, unsigned int height): title(title), width(width), height(height) {
    if (!glfwInit()) {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    std::cout << "Context: (Apple Device)" << '\n';
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    handle = glfwCreateWindow((int)width, (int)height, title, nullptr, nullptr);
    if (!handle) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(handle);
    glfwSwapInterval(1);

    if (!gladLoadGL(glfwGetProcAddress)) {
        return;
    }

    std::cout << "Using " << glGetString(GL_VERSION) << '\n';
}

Window::~Window() {
    std::cout << "Destroying window..." << '\n';
    glfwDestroyWindow(handle);
    glfwTerminate();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(handle);
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::SwapBuffers() {
    glfwSwapBuffers(handle);
}

GLFWwindow* Window::GetHandle() const {
    return handle;
}

unsigned int Window::GetWidth() const {
    return width;
}

unsigned int Window::GetHeight() const {
    return height;
}

const char* Window::GetTitle() const {
    return title;
}
