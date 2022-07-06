#pragma once
#include <vulkan/vulkan.h>
#include <type_traits>
#include <stdexcept>
#include "instance.hpp"

namespace Quark::Engine {
    // I don't know if we'll ever need these functions, I'm not sure why they're needed if we're
    // linking against a Vulkan library. But I'm including them for completeness.
    
    
    // Implementation details:
    namespace Detail::Function_loader {
	template<typename T>
	inline constexpr bool is_function_pointer = 
	    std::conjunction<
		std::is_pointer<T>,
		std::is_function<typename std::remove_pointer<T>::type>
	    >::value;
    } // Detail::Function_loader



    struct Function_loader {
	// In the future, some kind of caching can be added
	
	
	// Some commands may be loaded without specifying an instance or device,
	// some require a valid instance to be loaded, and in other cases,
	// it's more efficient to provide a device.
	// For details, see: https://stackoverflow.com/questions/35504545/vulkan-difference-between-vkgetinstanceprocaddress-and-vkgetdeviceprocaddress
	// and the docs, I don't know if this is of any importance to us at all.


	// Function_ptr must be a function pointer type. The obtained function pointer
	// is automatically cast to Function_ptr.
	template<
	    typename Function_ptr, 
	    typename std::enable_if<Detail::Function_loader::is_function_pointer<Function_ptr>, int>::type = 0
	>
	// name is a valid null-terminated string
	static Function_ptr load(char const* name) {
	    //vkGetInstanceProcAddr itself is obtained in a platform- and loader- specific manner.
	    PFN_vkVoidFunction function = vkGetInstanceProcAddr(nullptr, name);
	    if(!function) throw std::runtime_error("Quark::Engine::Function_loader::load() error");
	    return reinterpret_cast<Function_ptr>(function);
	}

	// Same as the above, but takes an Instance
	template<
	    typename Function_ptr, 
	    typename std::enable_if<Detail::Function_loader::is_function_pointer<Function_ptr>, int>::type = 0
	>
	static Function_ptr load(char const* name, class Instance& instance) {
	    PFN_vkVoidFunction function = vkGetInstanceProcAddr(instance, name);
	    if(!function) throw std::runtime_error("Quark::Engine::Function_loader::load() error");
	    return reinterpret_cast<Function_ptr>(function);
	}

	// Same as the above, but takes a Logical_device
	template<
	    typename Function_ptr, 
	    typename std::enable_if<Detail::Function_loader::is_function_pointer<Function_ptr>, int>::type = 0
	>
	static Function_ptr load(char const* name, class Logical_device& logical_device) {
	    return nullptr;

	    // TODO: uncomment when we implement devices
	    //PFN_vkVoidFunction function = vkGetDeviceProcAddr(logical_device, name);
	    //if(!function) throw std::runtime_error("Quark::Engine::Function_loader::load() error");
	    //return reinterpret_cast<Function_ptr>(function);
	}

    };
}
