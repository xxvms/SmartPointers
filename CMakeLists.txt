cmake_minimum_required(VERSION 3.8)
project(SmartPointers)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Person.cpp Person.h Resource.cpp Resource.h)
add_executable(SmartPointers ${SOURCE_FILES})