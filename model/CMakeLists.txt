cmake_minimum_required(VERSION 3.22)
project(model)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(model carte.c joueur.c main_model.c main_model.h test.c test.h)
