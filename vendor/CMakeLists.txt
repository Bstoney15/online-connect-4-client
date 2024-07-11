# Set these options before adding the SDL subdirectory
set(SDL_STATIC ON CACHE BOOL "Build SDL as a static library" FORCE)
set(SDL_SHARED OFF CACHE BOOL "Build SDL as a shared library" FORCE)

# Add SDL3 subdirectory
add_subdirectory(SDL EXCLUDE_FROM_ALL)

# Create the vendor interface library
add_library(vendor INTERFACE)

# Link SDL3 to the vendor interface
target_link_libraries(vendor INTERFACE SDL3::SDL3-static)

# Include SDL3 headers
target_include_directories(vendor INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/SDL/include>
    $<INSTALL_INTERFACE:include>
)

# Additional system libraries for Windows
if(WIN32)
    target_link_libraries(vendor INTERFACE winmm imm32 setupapi version)
endif()