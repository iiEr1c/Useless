include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://gitee.com/iiEric/spdlog.git
  GIT_TAG        v1.8.5)

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
  message("Cloning spdlod")
  FetchContent_Populate(spdlog)
  add_subdirectory(
    ${spdlog_SOURCE_DIR}
    ${spdlog_BINARY_DIR})
endif()
