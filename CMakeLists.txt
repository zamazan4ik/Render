cmake_minimum_required(VERSION 3.12)
project(graph_drawer)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(graph_drawer src/main.cpp)
target_link_libraries(graph_drawer ${Conan_LIBS})