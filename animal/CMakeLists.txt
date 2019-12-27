cmake_minimum_required(VERSION 3.15)
project(animal C)

set(CMAKE_C_STANDARD 11)

add_executable(animal main.c animal.c animal.h cat.c cat.h)