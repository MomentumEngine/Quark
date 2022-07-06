#pragma once
#include <vulkan/vulkan.h>
#include <cstdint>

namespace Quark::Engine {

    // The VkInstance object is where all per-application state is stored.
    class Instance {
    public:
	Instance();
	~Instance();

	// Copying is disabled, because instances cannot be duplicated like this.
	// This also disabled moving, and I'm fairly sure we'll never need move ctors/assignments either,
	// but they could be written if necessary.
	Instance(Instance const&) = delete;
	Instance& operator=(Instance const&) = delete;

	// Implicit conversion to the underlying handle type, so that we can directly use objects of the
	// Instance class in Vulkan functions, instead of calling something like some_instance.get_handle() each time.
	// All Vulkan handles are either pointers or integers, so they should be passed by copy.
	// This operator is non-const, because I think it makes more sense logically - const Instances shouldn't be manipulated,
	// even if the language rules allow for it.
	operator VkInstance() noexcept;

	// Queries the version of instance-level functionality supported by the implementation.
	// This value can be compared against VK_API_VERSION_1_0, VK_API_VERSION_1_1, etc...
	static std::uint32_t enumerate_instance_version();

    private:
	// Let's keep this naming convention - this way we can later write a common base class
	// for all Vulkan object wrappers to provide additional convenience automatically.
	VkInstance object;
    };
}
