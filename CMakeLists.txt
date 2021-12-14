cmake_minimum_required(VERSION 3.16)
project(linal-assessment)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include_directories(src)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

add_custom_target(copy_resources COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp tests/*.hpp src/*.cpp)
list(REMOVE_ITEM TEST_SOURCES src/main.cpp)

set(PROJECT_SOURCE_LIBS SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_ttf)
set(PROJECT_TEST_LIBS GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_executable(${PROJECT_NAME} ${SOURCES})
add_dependencies(${PROJECT_NAME} copy_resources)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_LIBS})

set(PROJECT_NAME_TESTS ${PROJECT_NAME}-tests)
add_executable(${PROJECT_NAME_TESTS} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME_TESTS} PRIVATE ${PROJECT_SOURCE_LIBS} ${PROJECT_TEST_LIBS})
gtest_discover_tests(${PROJECT_NAME_TESTS})
