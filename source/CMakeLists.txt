cmake_minimum_required(VERSION 3.30)
project(HippOutGameEngine-cpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(HippOutGameEngine-cpp main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
