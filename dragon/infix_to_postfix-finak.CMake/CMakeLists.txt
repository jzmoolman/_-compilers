cmake_minimum_required(VERSION 3.24)
project(test C)

set(CMAKE_C_STANDARD 11)

add_executable(test main.c global.h init.c symbol.c error.c parser.c lexer.c emitter.c)
