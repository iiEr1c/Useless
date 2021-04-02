add_executable(cpp_test "")
target_sources(cpp_test
  PRIVATE
    test.cpp
  )
target_link_libraries(cpp_test
  PRIVATE
    MyMath
    gtest_main
  )