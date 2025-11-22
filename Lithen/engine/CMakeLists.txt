add_library(Lithen
    "include/engine/renderer.h" "src/renderer.cpp"
    "include/engine/window.h" "src/window.cpp"
)

set(GLFW_PATH "${CMAKE_SOURCE_DIR}/vendor/GLFW")

target_include_directories(Lithen 
    PUBLIC 
        include
)

target_link_libraries(Lithen 
    PUBLIC 
        Vulkan::Vulkan
        GLFW
)

if(MSVC)
    target_compile_options(Lithen PRIVATE /W4 /WX)
else()
    target_compile_options(Lithen PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_custom_command(TARGET Lithen POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GLFW_PATH}/lib-vc2022/glfw3.dll"
    $<TARGET_FILE_DIR:Lithen>
)