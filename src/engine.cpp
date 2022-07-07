#include <iostream>
#include <stdexcept>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "engine.h"

void Quark::Engine::mainLoop() {
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
    }
}

void Quark::Engine::cleanup() {
    // commented for validation testing, currently not showing errors and needs fixing
    /*
    if (enableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
    }
    */
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
