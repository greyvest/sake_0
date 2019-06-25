cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
project (sake)

add_subdirectory(src/imgui)
add_subdirectory(libs/assimp)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SRC_FILES src/*.cpp)

add_executable(sake ${SRC_FILES})

target_link_libraries(sake imgui)
target_link_libraries(sake assimp)


# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(assimp REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIR})

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
endif (APPLE)

target_link_libraries(
        sake
        glfw
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${EXTRA_LIBS}
)

add_custom_target(run
    COMMAND ./sake
    DEPENDS sake
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)