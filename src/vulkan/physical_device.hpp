#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include "utility/span.hpp"

namespace Quark::Engine {

    // A physical device represents a single complete implementation of Vulkan. 
    // A logical device represents an instance of that implementation with its own state and resources 
    // independent of other logical devices.

    class Physical_device {
    public:
	// Physical devices may only be created in enumerate_physical_devices(), this constructor
	// should *never* be called manually.
	Physical_device(VkPhysicalDevice physical_device);

	~Physical_device();

	Physical_device(Physical_device const&) = delete;
	Physical_device& operator=(Physical_device const&) = delete;

	operator VkPhysicalDevice() noexcept;

	VkPhysicalDeviceProperties const& get_properties() const noexcept;

	// Retrieves a list of physical device objects representing the physical devices installed in the system.
	static Span<Physical_device> enumerate_physical_devices(class Instance& instance);

    private:
	VkPhysicalDevice object;
	VkPhysicalDeviceProperties properties;

    };

} // Quark::Engine
