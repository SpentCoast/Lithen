cmake_minimum_required(VERSION 3.20)

# Define the path to the GLFW folder relative to this file
set(GLFW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/GLFW")

# Create the library target
# GLOBAL is required so that 'src/engine' (a sibling directory) can see this target
add_library(GLFW SHARED IMPORTED GLOBAL)

# Set the properties (Paths to lib, dll, and include)
set_target_properties(GLFW PROPERTIES
    IMPORTED_IMPLIB "${GLFW_PATH}/lib-vc2022/glfw3dll.lib"
    IMPORTED_LOCATION "${GLFW_PATH}/lib-vc2022/glfw3.dll"
    INTERFACE_INCLUDE_DIRECTORIES "${GLFW_PATH}/include"
)