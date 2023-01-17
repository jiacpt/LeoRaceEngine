add_library(Race SHARED  Race.cpp)


target_include_directories(Race PUBLIC ./include)
target_include_directories(Race PUBLIC )

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(Race PUBLIC spdlog::spdlog spdlog::spdlog_header_only)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Race PUBLIC glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(Race PUBLIC glm::glm)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Race PUBLIC glad::glad)
