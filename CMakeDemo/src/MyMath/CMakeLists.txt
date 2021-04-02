add_library(MyMath "")

target_sources(MyMath
  PRIVATE
    MyMath.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/MyMath.hpp
  )

target_include_directories(MyMath
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

option(ENABLE_ASAN "Enable AddressSanitizer" ON)
  if(ENABLE_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
      message(STATUS "sanitizer address/leak enabled")
      target_compile_options(MyMath
        PUBLIC
          -g -O1 -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer
        )
      target_link_libraries(MyMath
        PUBLIC
          asan
        )
    else()
      message(WARNING "Sanitizer not supported for this compiler")
    endif()
  endif()