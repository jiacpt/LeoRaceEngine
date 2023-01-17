add_executable(Logger Logger.cpp)

# 添加头文件搜索路径
target_link_libraries(Logger PRIVATE Race)