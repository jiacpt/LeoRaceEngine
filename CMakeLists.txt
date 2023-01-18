cmake_minimum_required(VERSION 3.2.0)
project(RaceEngine VERSION 0.1.0)


enable_testing()

# 配置可执行文件位置和库文件位置  CMAKE_LIBRARY_OUTPUT_DIRECTORY[动态库] CMAKE_ARCHIVE_OUTPUT_DIRECTORY[静态库]
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

message(${CMAKE_BINARY_DIR})
set(ProjectRootDir "${CMAKE_CURRENT_SOURCE_DIR}")


add_subdirectory(Engine)
add_subdirectory(tests)
add_subdirectory(examples)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
