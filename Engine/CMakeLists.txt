set(EngineRootDir "${ProjectRootDir}/Engine")
set(EngineAssetsDir "${EngineRootDir}/Assets")
set(EngineConfigDir "${EngineRootDir}/Config")
set(EngineResourcesDir "${EngineRootDir}/Resources")
set(EngineShadersDir "${EngineRootDir}/Shaders")
set(EngineSourceDir "${EngineRootDir}/Source")




# 拷贝默认资产到运行目录
file(COPY ${EngineAssetsDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${EngineShadersDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${EngineConfigDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${EngineResourcesDir} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(Source)
