#pragma once
#include <cstddef>

namespace Quark {
    
    // A replacement for std::span (available with C++20) that represents a contiguous range of objects.
    template<typename T>
    struct Span {
	T* data;
	std::size_t count;

	// Iteration support
	T* begin() noexcept { return data; }
	T const* begin() const noexcept { return data; }
	T* end() noexcept { return data + count; }
	T const* end() const noexcept { return data + count; }
    };


} // Quark
