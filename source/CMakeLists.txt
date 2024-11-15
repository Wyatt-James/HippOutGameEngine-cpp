cmake_minimum_required(VERSION 3.30)
project(HippOutGameEngine
        VERSION 0.1.0
        DESCRIPTION "HippOutGameEngine in C/C++"
        HOMEPAGE_URL https://github.com/wyatt-James/hippOutGameEngine-cpp
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

# Engine Configuration

set(ENGINE_BASEDIR engine)
set(ENGINE_PUBLIC_INCLUDE ${ENGINE_BASEDIR}/public)
set(ENGINE_PRIVATE_INCLUDE ${ENGINE_BASEDIR}/private)
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        ${ENGINE_BASEDIR}/*.c
        ${ENGINE_BASEDIR}/*.cpp
        ${ENGINE_BASEDIR}/*.h
        )
message("ENGINE_SOURCES: ${ENGINE_SOURCES}")

add_library(engine SHARED ${ENGINE_SOURCES})
target_include_directories(engine PUBLIC ${ENGINE_PUBLIC_INCLUDE})
target_include_directories(engine PRIVATE ${ENGINE_PRIVATE_INCLUDE})
set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(engine PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# Test Game Configuration

set(TESTGAME_BASEDIR testgame)
file(GLOB_RECURSE TESTGAME_SOURCES CONFIGURE_DEPENDS
        ${TESTGAME_BASEDIR}/*.c
        ${TESTGAME_BASEDIR}/*.cpp
        ${TESTGAME_BASEDIR}/*.h
        )
message("TESTGAME_SOURCES: ${TESTGAME_SOURCES}")

add_executable(testgame ${TESTGAME_SOURCES})
target_include_directories(testgame PRIVATE ${TESTGAME_BASEDIR})
target_link_libraries(testgame PUBLIC engine)
set_target_properties(testgame PROPERTIES LINKER_LANGUAGE CXX)

# Misc

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
