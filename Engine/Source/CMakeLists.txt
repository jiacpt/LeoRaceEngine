set(EngineRuntimeDir "${EngineSourceDir}/Runtime")
set(EngineEditorDir "${EngineSourceDir}/Editor")
set(EngineScriptsDir "${EngineSourceDir}/Scripts")

# 复制脚本到运行目录
file(COPY ${EngineScriptsDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


add_subdirectory(Runtime)
add_subdirectory(Editor)
