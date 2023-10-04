cmake_minimum_required(VERSION 3.27)

project(head_of_group_fork)

enable_testing()

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE gtest)

include(GoogleTest)

gtest_discover_tests(tests)