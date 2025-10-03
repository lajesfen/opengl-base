#include "window.h"

#include <resource_manager.h>

Window::Window(const char *title, unsigned int width, unsigned int height): m_title(title), m_width(width), m_height(height) {
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

    m_handle = glfwCreateWindow((int)m_width, (int)m_height, m_title, nullptr, nullptr);
    if (!m_handle) {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_handle);
    glfwSwapInterval(1);

    if (!gladLoadGL(glfwGetProcAddress)) {
        return;
    }

    std::cout << "Using " << glGetString(GL_VERSION) << '\n';
}

Window::~Window() {
    std::cout << "Destroying window..." << '\n';
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(m_handle);
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::SwapBuffers() {
    glfwSwapBuffers(m_handle);
}

GLFWwindow* Window::GetHandle() const {
    return m_handle;
}

unsigned int Window::GetWidth() const {
    return m_width;
}

unsigned int Window::GetHeight() const {
    return m_height;
}

const char* Window::GetTitle() const {
    return m_title;
}
