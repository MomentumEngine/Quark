#include <iostream>

#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan.h>

#include "engine.h"

int main() {
    Engine firstTriangle{};
    try {
        firstTriangle.run();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return -1;
        }
    return 0;
}
