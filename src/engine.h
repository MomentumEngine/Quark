#pragma once

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <vector>

class Engine
{
public:
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

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
};
