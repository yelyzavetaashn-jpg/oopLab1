
cmake_minimum_required(VERSION 3.21)

project(oopLab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(oopLab1
    main.cpp
    mainwindow.cpp
    module1.cpp
    module2.cpp
    mainwindow.h
    module1.h
    module2.h
)

target_link_libraries(oopLab1 PRIVATE Qt6::Widgets)
