add_executable(DEMO main.cpp)

add_subdirectory(MyMath)

target_link_libraries(DEMO
  PRIVATE
    MyMath
  )