cmake_minimum_required(VERSION 3.10)
project(ft C)

# Debug the current directory to verify paths
message(STATUS "CMake source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

# Use more explicit paths with ${CMAKE_CURRENT_SOURCE_DIR}
file(GLOB_RECURSE LIBFT_CORE_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/libft_core/*.c")
file(GLOB_RECURSE LIBFT_EXTRA_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/libft_extra/*.c")
file(GLOB_RECURSE FT_PRINTF_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/ft_printf/src/*.c")
file(GLOB_RECURSE GET_NEXT_LINE_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/get_next_line/src/*.c")

# Combine all source files
set(LIBFT_SOURCES
    ${LIBFT_CORE_SOURCES}
    ${LIBFT_EXTRA_SOURCES}
    ${FT_PRINTF_SOURCES}
    ${GET_NEXT_LINE_SOURCES}
)

# Add a safety check
if(NOT LIBFT_SOURCES)
    message(FATAL_ERROR "No source files found! Check your directory structure.")
endif()

# Remove test files if present
list(FILTER LIBFT_SOURCES EXCLUDE REGEX "test[s]?\.c$")

# Display components being built
message(STATUS "Building libft core with: ${LIBFT_CORE_SOURCES}")
message(STATUS "Building libft extras with: ${LIBFT_EXTRA_SOURCES}")
message(STATUS "Building ft_printf with: ${FT_PRINTF_SOURCES}")
message(STATUS "Building get_next_line with: ${GET_NEXT_LINE_SOURCES}")

# Create the static library
add_library(ft STATIC ${LIBFT_SOURCES})

# Specify include directories
target_include_directories(ft PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
