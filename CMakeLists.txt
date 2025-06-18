cmake_minimum_required(VERSION 4.0)

find_package(SDL3 REQUIRED)

add_executable(meow main.cpp) # Replace with your project's source files
target_link_libraries(meow PRIVATE SDL3::SDL3)