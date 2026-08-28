cmake_minimum_required(VERSION 3.24)

project(the_unwritten_road
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 REQUIRED CONFIG)

add_executable(the_unwritten_road
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
)

target_include_directories(the_unwritten_road
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(the_unwritten_road
    PRIVATE
    SDL3::SDL3
)