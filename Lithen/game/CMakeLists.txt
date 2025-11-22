add_executable(Sandbox
    main.cpp
)

target_link_libraries(Sandbox 
    PRIVATE 
        Lithen
)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:GLFW>
    $<TARGET_FILE_DIR:Sandbox>
)
