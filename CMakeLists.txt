cmake_minimum_required(VERSION 2.8)

project(engine)
include_directories("${CMAKE_SOURCE_DIR}")

file(GLOB SOURCE_FILES
    "*.hpp"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
