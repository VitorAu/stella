cmake_minimum_required(VERSION 4.1.2)
project(stella VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(engine)
add_subdirectory(game)
