set(EngineRuntimeDir "${EngineSourceDir}/Runtime")
set(EngineEditorDir "${EngineSourceDir}/Editor")
set(EngineScriptsDir "${EngineSourceDir}/Scripts")

file(COPY ${EngineScriptsDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


add_subdirectory(Runtime)
add_subdirectory(Editor)
