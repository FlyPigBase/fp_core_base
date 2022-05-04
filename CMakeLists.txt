#cmake version
cmake_minimum_required(VERSION 3.2)

#enable verbose output from Makefile builds
set(CMAKE_VERBOSE_MAKEFILE on)

#platform
set(PLATFORM_TYPE ${1})
message( STATUS "platform is ${PLATFORM_TYPE}")

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
elseif(WIN32)
message(STATUS "This platform is windows and now supported")
else()
  message(FATAL_ERROR "${PLATFORM_TYPE} platform is not supported")
endif()

#define include search path
include_directories("${PROJECT_SOURCE_DIR}/src/base_module")
include_directories("${PROJECT_SOURCE_DIR}/src/logs")
include_directories("${PROJECT_SOURCE_DIR}/third_party/include")

#add source 
list(APPEND FG_BASE_CORE "${PROJECT_SOURCE_DIR}/src/main.cc")
list(APPEND FG_BASE_CORE "${PROJECT_SOURCE_DIR}/src/base_module/fp_log/fp_log.cc")
list(APPEND FG_BASE_CORE "${PROJECT_SOURCE_DIR}/src/base_module/fp_log/log_wrapper.cc")


if(UNIX) 
  list(APPEND THIRD_PARTY_LIBS libspdlog.a libcurl.a libssl.a libcrypto.a dl pthread)
elseif(WIN32)

endif()

# define library search path
#link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/linux/spdlog")
#link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/linux/curl")

add_executable(${PROJECT_NAME} ${FG_BASE_CORE})

target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_LIBS})