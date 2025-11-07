cmake_minimum_required(VERSION 3.16)
project(FigureManagement)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)


add_library(figures_lib
    src/Figure.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Array.cpp
)


add_executable(figure_management src/main.cpp)
target_link_libraries(figure_management figures_lib)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    include(FetchContent)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_executable(tests tests/test.cpp)
    target_link_libraries(tests PRIVATE figures_lib GTest::gtest GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(tests)
endif()
