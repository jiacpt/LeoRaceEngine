cmake_minimum_required(VERSION 3.2.0)
project(RaceEngine VERSION 0.1.0)


enable_testing()



if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/Debug")
    set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib/Debug")
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/Release")
    set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib/Release")
else()
    message("else:${CMAKE_BUILD_TYPE}")
    message("else:${CMAKE_C_FLAGS_RELEASE}")
    add_executable(test_release ${src_dirs})
endif()


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
