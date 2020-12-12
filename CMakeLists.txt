cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(untitled)

set(CMAKE_CXX_STANDARD 89)
##set(CMAKE_MAKE_PROGRAM C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/mingw32-make.exe)
#[[add_definitions( -DCURL_STATICLIB )
set(libcurl_INCLUDE_DIR "D:/curl-7.73.0_5-win64-mingw/include")
include_directories(${libcurl_INCLUDE_DIR})
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)]]
#include_directories(${PROJECT_SOURCE_DIR})


add_executable(untitled main.cpp employee.cpp employee.h)

target_link_libraries(untitled -lwinmm)