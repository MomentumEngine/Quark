#include <iostream>

#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan.h>

#include "engine.h"
#include "vulkan/instance.hpp"
#include "vulkan/physical_device.hpp"

int main() {
    Quark::Engine::Instance instance;
    {
	int i = 0;
	for(auto const& device : Quark::Engine::Physical_device::enumerate_physical_devices(instance)) {
	    std::cout << "Device#" << i++ << ": " << device.get_properties().deviceName << "\n";
	}
    }

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
