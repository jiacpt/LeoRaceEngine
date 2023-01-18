add_executable(Logger Logger.cpp)


target_include_directories(Logger PUBLIC Race)
# 添加头文件搜索路径
target_link_libraries(Logger PUBLIC Race)

