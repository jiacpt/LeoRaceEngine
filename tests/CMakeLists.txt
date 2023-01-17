find_package(GTest REQUIRED)

macro(add_cache_test test_name)
  add_executable(${test_name} ${test_name}.cpp)
  target_link_libraries(${test_name}
    PRIVATE
    GTest::GTest 
    caches
  )
  add_test(NAME cache_${test_name} COMMAND ${test_name})

endmacro()
