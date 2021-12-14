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
file(GLOB_RECURSE SIM_SOURCES sim/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_ttf)
add_dependencies(${PROJECT_NAME} copy_resources)

set(PROJECT_NAME_SIM ${PROJECT_NAME}-sim)
add_executable(${PROJECT_NAME_SIM} ${SIM_SOURCES})
add_dependencies(${PROJECT_NAME_SIM} ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME_SIM} PRIVATE ${PROJECT_NAME})

set(PROJECT_NAME_TESTS ${PROJECT_NAME}-tests)
add_executable(${PROJECT_NAME_TESTS} ${TEST_SOURCES})
add_dependencies(${PROJECT_NAME_TESTS} ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME_TESTS} PRIVATE ${PROJECT_NAME} GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
gtest_discover_tests(${PROJECT_NAME_TESTS})
