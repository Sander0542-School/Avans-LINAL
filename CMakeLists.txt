cmake_minimum_required(VERSION 3.16)
project(linal-assessment)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

include(GoogleTest)

include_directories(src)

add_custom_target(copy_resources COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SIM_SOURCES sim/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

set(PROJECT_SOURCE_LIBS SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_ttf)
set(PROJECT_TEST_LIBS GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_executable(${PROJECT_NAME} ${SIM_SOURCES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_LIBS})
add_dependencies(${PROJECT_NAME} copy_resources)

set(PROJECT_NAME_TESTS ${PROJECT_NAME}-tests)
add_executable(${PROJECT_NAME_TESTS} ${TEST_SOURCES} ${SOURCES})
target_link_libraries(${PROJECT_NAME_TESTS} PRIVATE ${PROJECT_SOURCE_LIBS} ${PROJECT_TEST_LIBS})
add_dependencies(${PROJECT_NAME_TESTS} copy_resources)
gtest_discover_tests(${PROJECT_NAME_TESTS})
