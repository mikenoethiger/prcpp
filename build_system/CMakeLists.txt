cmake_minimum_required(VERSION 3.10)

set(project_name build_system)
project(${project_name})

add_executable(${project_name}_app
        src/main.cpp
        src/module.cpp
        src/student.cpp)

target_include_directories(${project_name}_app PRIVATE src)
# does not work with me if following line is active
#target_compile_options(${project_name}_app PRIVATE ${cxxflags})