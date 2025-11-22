cmake_minimum_required(VERSION 3.20)

# 1. Project Definitions
project(Lithen 
    VERSION 0.1.0 
    LANGUAGES CXX
)

# 2. Global Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Output Directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 4. Find Vulkan Package (Global search)
find_package(Vulkan REQUIRED)

# 5. Add Subdirectories
add_subdirectory(Lithen/engine)
add_subdirectory(Lithen/game)
