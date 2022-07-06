#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "engine.h"

void Engine::mainLoop() {
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
    }
}
