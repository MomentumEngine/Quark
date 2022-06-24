#include "engine.h"

void Engine::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_Window = glfwCreateWindow(WIDTH, HEIGHT, "Quark", nullptr, nullptr);
    if (!m_Window)
            glfwTerminate();
}

void Engine::initVulkan() {

}

void Engine::mainLoop() {
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
    }
}

void Engine::cleanup() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
