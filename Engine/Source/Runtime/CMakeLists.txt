# 将列表文件添加到源代码库当中
macro(RUNTIME_ADD_SOURCE)
	set(SOURCE_FILES "")
    foreach(SOURCE_FILE ${ARGN})
        if(SOURCE_FILE MATCHES "^/.*")
            list(APPEND SOURCE_FILES ${SOURCE_FILE})
        else()
            list(APPEND SOURCE_FILES
                 "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}")
        endif()
    endforeach()
    set(RuntimeSourceFiles ${RuntimeSourceFiles} ${SOURCE_FILES} PARENT_SCOPE)
endmacro(RUNTIME_ADD_SOURCE)

# 将列表文件添加到头文件库当中方便导入
set(RuntimeSourceFiles "${CMAKE_CURRENT_SOURCE_DIR}/RaceEngine.h" "${CMAKE_CURRENT_SOURCE_DIR}/hepch.h" "${CMAKE_CURRENT_SOURCE_DIR}/hepch.cpp")

add_subdirectory(Core)
add_subdirectory(Events)

add_library(RaceEngineRuntime STATIC ${RuntimeSourceFiles})

target_include_directories(RaceEngineRuntime 
    PUBLIC "${EngineSourceDir}"
    PUBLIC "${EngineRuntimeDir}" # make sure we can directly include "hepch.h"
)

##########################################################################################
find_package(fmt CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC fmt::fmt)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC fmt::fmt-header-only)

find_package(glad CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC glm::glm)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(RaceEngineRuntime PUBLIC spdlog::spdlog spdlog::spdlog_header_only)

# target_precompile_headers(RaceEngineRuntime PUBLIC "hepch.h")

# sometime will have bugs, why?
# if (DirectX11_FOUND)
#     target_link_libraries(RaceEngineRuntime PUBLIC ${DirectX11_LIBRARIES})
#     target_include_directories(RaceEngineRuntime PUBLIC ${DirectX11_INCLUDE_DIRS})
# endif()

