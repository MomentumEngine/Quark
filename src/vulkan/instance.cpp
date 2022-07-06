// TODO: it might be better to use include paths relative to the root of the source tree (#include "vulkan/instance.hpp"),
// but that's a CMake thing.
#include "instance.hpp"
#include <stdexcept>

// TODO: unified error handling across the entire program, 
// for now, exceptions are fine, but we'll have to discuss it.


Quark::Engine::Instance::Instance() {
    VkApplicationInfo application_info = {
	.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
	.pNext = nullptr,
	// These fields can be changed if we want, I don't know what difference it would make
	.pApplicationName = nullptr,
	.applicationVersion = 0,
	.pEngineName = nullptr,
	.engineVersion = 0,
	.apiVersion = VK_API_VERSION_1_0
    };

    VkInstanceCreateInfo instance_create_info = {
	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	.pNext = nullptr,
	.flags = 0,
	.pApplicationInfo = &application_info,
	// TODO: change this when we implement validation layers
	.enabledLayerCount = 0,
	.ppEnabledLayerNames = nullptr,
	// TODO: change this when we implement extensions
	.enabledExtensionCount = 0,
	.ppEnabledExtensionNames = nullptr
    };

    if(vkCreateInstance(&instance_create_info, nullptr, &object) != VK_SUCCESS) 
	throw std::runtime_error("Quark::Engine::Instance::Instance() error");
}

Quark::Engine::Instance::~Instance() {
    vkDestroyInstance(object, nullptr);
}

Quark::Engine::Instance::operator VkInstance() noexcept {
    return object;
}

std::uint32_t Quark::Engine::Instance::enumerate_instance_version() {
    std::uint32_t api_version{};
    if(vkEnumerateInstanceVersion(&api_version) != VK_SUCCESS) 
	throw std::runtime_error("Quark::Engine::enumerate_instance_version() error");
    return api_version;
}




