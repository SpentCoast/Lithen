add_executable(Sandbox
    main.cpp
)

# Link the Game to the Engine
target_link_libraries(Sandbox 
    PRIVATE 
        Lithen
)