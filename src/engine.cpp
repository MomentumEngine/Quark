#include <iostream>
#include <stdexcept>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "engine.h"

void Engine::mainLoop() {
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
    }
}
