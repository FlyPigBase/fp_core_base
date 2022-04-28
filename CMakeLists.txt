#cmake version
cmake_minimum_required(VERSION 3.2)

#enable verbose output from Makefile builds
set(CMAKE_VERBOSE_MAKEFILE on)

#project name
project(fp_base_core)
message( STATUS "fp_base_core source dir is ${fp_base_core_SOURCE_DIR} bin dir is ${fp_base_core_BINARY_DIR}")

#c++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -Wall -std=c++14")

if(UNIX)
  if(APPLE)
    message(FATAL_ERROR "This platform is OSX and now not supported")
  else()
    message(STATUS "This platform is Linux and now supported")
  endif()
else()
 message(FATAL_ERROR "This platform is not supported")
endif()

#define include search path
include_directories("${PROJECT_SOURCE_DIR}/src/common")
include_directories("${PROJECT_SOURCE_DIR}/src/logs")
include_directories("${PROJECT_SOURCE_DIR}/third_party/include")

#add source 
list(APPEND FG_BASE_CORE "${PROJECT_SOURCE_DIR}/src/main.cc")
list(APPEND FG_BASE_CORE "${PROJECT_SOURCE_DIR}/src/logs/log_wrapper.cc")

list(APPEND THIRD_PARTY_LIBS libspdlog.a libcurl.a libssl.a libcrypto.a dl pthread)

# define library search path
link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/linux/spdlog")
link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/linux/curl")

add_executable(${PROJECT_NAME} ${FG_BASE_CORE})

target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_LIBS})