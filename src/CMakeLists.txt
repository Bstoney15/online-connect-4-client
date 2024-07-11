add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp "game.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

# Add SDL-specific definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_STATIC)
