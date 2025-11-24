cmake_minimum_required(VERSION 3.31)
project(1124aip)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        Planar.h
        Point.h
        Vector.h
        extra.h
        )

set(PROJECT_SOURCES
        main.cpp
        Planar.cpp
        Point.cpp
        Vector.cpp
        extra.cpp
        )

add_executable(1124aip ${PROJECT_SOURCES} ${PROJECT_HEADERS})
