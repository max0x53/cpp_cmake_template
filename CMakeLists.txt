cmake_minimum_required(VERSION 3.21)

project(cpp_cmake_template)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)
add_subdirectory(src)

