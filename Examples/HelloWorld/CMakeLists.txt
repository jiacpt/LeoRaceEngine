

add_executable(HelloWorld HelloWorld.cpp)

# 添加头文件搜索路径
target_link_libraries(HelloWorld PRIVATE RaceEngineRuntime)
