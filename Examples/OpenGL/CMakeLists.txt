add_executable(Windows Windows.cpp)


target_include_directories(Windows PUBLIC Runtime)
# 添加头文件搜索路径
target_link_libraries(Windows PUBLIC RaceEngineRuntime)

