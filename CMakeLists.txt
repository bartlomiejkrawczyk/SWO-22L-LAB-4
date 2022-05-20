# Project meta-data
cmake_minimum_required(VERSION 3.0.0)
project(cpp)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compiler options
# add_compile_options(-Wall -Wextra -Werror)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release build")
    add_compile_options(-O3)
else()
    message("Debug build")
    add_compile_options(-ggdb)
endif()

# Ensure we have a threading library

# CMake FindThreads is broken until 3.1
set(CMAKE_THREAD_LIBS_INIT pthread)

# Source files

set(WHITE_BEAR_SOURCE_FILES
    src/WhiteBear.cc
    src/WhiteBear.h)

set(WHITE_BEAR_UNIT_TESTS_SOURCE_FILES
    ${WHITE_BEAR_SOURCE_FILES}
    tests/WhiteBearUnitTests.cc)

set(WHITE_BEAR_CHARACHTERIZATION_TESTS_SOURCE_FILES
    ${WHITE_BEAR_SOURCE_FILES}
    tests/WhiteBearCharacterizationTests.cc)

set(WHITE_BEAR_MAIN_SOURCE_FILES
    ${WHITE_BEAR_SOURCE_FILES}
    src/WhiteBearMain.cc)

# Add the main executable

add_executable(WhiteBear ${WHITE_BEAR_MAIN_SOURCE_FILES})

# Testing

enable_testing()
include(GoogleTest)

# Unit tests

add_executable(WhiteBearUnitTests ${WHITE_BEAR_UNIT_TESTS_SOURCE_FILES})
target_include_directories(WhiteBearUnitTests PRIVATE src/)
target_link_libraries(WhiteBearUnitTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
gtest_discover_tests(WhiteBearUnitTests)

# Charachterization tests

add_executable(WhiteBearCharacterizationTests ${WHITE_BEAR_CHARACHTERIZATION_TESTS_SOURCE_FILES})
target_include_directories(WhiteBearCharacterizationTests PRIVATE src/)
target_link_libraries(WhiteBearCharacterizationTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
gtest_discover_tests(WhiteBearCharacterizationTests)

configure_file(ExpectedTestOutput.txt ExpectedTestOutput.txt COPYONLY)