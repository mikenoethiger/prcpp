cmake_minimum_required(VERSION 3.10)

project(prcpp_workspace)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# predefined compile flags
set(cxxflags -Werror -Wall -Wextra -Wconversion -Wpedantic -Wno-psabi -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-function)

# use C++17 standard with gcc extensions
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

enable_testing()

add_subdirectory(example)
add_subdirectory(uebungen)
add_subdirectory(build_system)
add_subdirectory(preprocessor)