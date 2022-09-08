cmake_minimum_required(VERSION 3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Quark LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED FATAL_ERROR)

set(SOURCE_FILES
        vulkan_init.cpp
        vulkan_instance.cpp
        vulkan_validation.cpp
    )

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

add_library(Quark SHARED {$SOURCE_FILES})
