#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "engine.h"

void Engine::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_Window = glfwCreateWindow(WIDTH, HEIGHT, "Quark", nullptr, nullptr);
    if (!m_Window)
            glfwTerminate();
}

void Engine::cleanup() {
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
