cmake_minimum_required(VERSION 3.16)

project(Orderbook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

add_executable(orderbook
    src/main.cpp
    src/Orderbook.cpp
)

target_include_directories(orderbook PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

