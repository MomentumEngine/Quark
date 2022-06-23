cmake_minimum_required(VERSION 3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(quark LANGUAGES CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
add_compile_options(-Wall -Wextra -Wpedantic -O3 -fsanitize=address -fsanitize=undefined)
add_link_options(-Wall -Wextra -Wpedantic -O3 -fsanitize=address -fsanitize=undefined)
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(src/)
