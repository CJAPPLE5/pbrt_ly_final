cmake_minimum_required(VERSION 3.25)
project(pbrt_ly)

set(CMAKE_CXX_STANDARD 17)

find_package(glog REQUIRED)


include(CheckCXXSourceCompiles)


set(PBRT_CORE src/core)

file(GLOB_RECURSE PBRT_SOURCES_CORE "${PBRT_CORE}/*.cpp" "${PBRT_CORE}/*.h")

include_directories(${CMAKE_SOURCE_DIR}/src/core)

add_executable(pbrt_ly main.cpp ${PBRT_SOURCES_CORE})
target_link_libraries(pbrt_ly glog::glog)