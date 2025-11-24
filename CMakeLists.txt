cmake_minimum_required(VERSION 3.31)
project(1124aip)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        bah.h
        )

set(PROJECT_SOURCES
        main.cpp
        bah.cpp
        )

add_executable(1124aip ${PROJECT_SOURCES} ${PROJECT_HEADERS})
