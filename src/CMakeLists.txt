cmake_minimum_required(VERSION 3.15)

project(MatrixTests)

find_package(GTest REQUIRED)

set(SOURCES
        matrix.h
        matrix.inl
        tests.cpp)

add_executable(MatrixTests ${SOURCES})

target_link_libraries(MatrixTests GTest::gtest)
