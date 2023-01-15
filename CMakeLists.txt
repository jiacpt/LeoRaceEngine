cmake_minimum_required(VERSION 3.2.0)
project(exe_test VERSION 0.1.0)


enable_testing()


set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

add_executable(exe_test src/main.cpp)  # 将哪些源文件 构建成 什么名字的可执行文件

add_subdirectory(src)
add_subdirectory(tests)


find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(exe_test PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(exe_test PRIVATE glm::glm)

find_package(glad CONFIG REQUIRED)
target_link_libraries(exe_test PRIVATE glad::glad)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
