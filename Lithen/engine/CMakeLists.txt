# Define the Engine as a library
add_library(Lithen
    src/renderer.cpp
    include/engine/renderer.h
)

# Setup include directories
# PUBLIC = Available to the engine AND the game
# PRIVATE = Available only to the engine
target_include_directories(Lithen 
    PUBLIC 
        include
)

# Link Vulkan
target_link_libraries(Lithen 
    PUBLIC 
        Vulkan::Vulkan
)

# Compiler warnings (Optional but recommended)
if(MSVC)
    target_compile_options(Lithen PRIVATE /W4 /WX)
else()
    target_compile_options(Lithen PRIVATE -Wall -Wextra -Wpedantic)
endif()