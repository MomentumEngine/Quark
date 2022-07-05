cmake_minimum_required(VERSION 3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SOURCE_FILES
        entryPoint.cpp
        engine.cpp
        engine.h
        window.cpp
        vulkanInit.cpp
        vulkanInstance.cpp
        vulkanValidation.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
