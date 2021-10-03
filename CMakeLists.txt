cmake_minimum_required(VERSION 3.13.4)
project(looperver C)
add_executable(loopever loopever.c loopever.h)
install(TARGETS loopever)