#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

class Engine
{
public:

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* m_Window;
    VkInstance instance;
    uint32_t glfwExtensionCount;

    const char** glfwExtensions;

    std::vector<const char*> getRequiredExtensions();
    std::vector<VkLayerProperties> availableLayers();

    VkDebugUtilsMessengerEXT debugMessenger;

    bool checkValidationLayerSupport();

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    void setupDebugMessaging();
};
