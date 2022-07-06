#include "physical_device.hpp"
#include "instance.hpp"
#include <stdexcept>


Quark::Engine::Physical_device::Physical_device(VkPhysicalDevice physical_device): 
    object{physical_device}
{ 
    vkGetPhysicalDeviceProperties(*this, &properties);
}

Quark::Engine::Physical_device::~Physical_device() = default;

Quark::Engine::Physical_device::operator VkPhysicalDevice() noexcept {
    return object;
}

VkPhysicalDeviceProperties const& Quark::Engine::Physical_device::get_properties() const noexcept {
    return properties;
}

Quark::Span<Quark::Engine::Physical_device> Quark::Engine::Physical_device::enumerate_physical_devices(Instance& instance) {
    // Cache the devices to avoid recreating this list every time
    // This object is initialised the first time enumerate_physical_devices() is called,
    // and destroyed at program termination
    static std::vector<Physical_device> devices = [&]() -> auto {
	// Get Vulkan handles for physical devices
	std::uint32_t device_count = 0;

	if(vkEnumeratePhysicalDevices(instance, &device_count, nullptr) != VK_SUCCESS) 
	    throw std::runtime_error("Quark::Engine::enumerate_physical_devices() error");

	std::vector<VkPhysicalDevice> device_handles{device_count};

	if(vkEnumeratePhysicalDevices(instance, &device_count, device_handles.data()) != VK_SUCCESS) 
	    throw std::runtime_error("Quark::Engine::enumerate_physical_devices() error");

	// Transform the handles into Physical_device objects and return them
	return std::vector<Physical_device>{std::begin(device_handles), std::end(device_handles)};
    }();

    return { devices.data(), devices.size() };
}



