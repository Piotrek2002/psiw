cmake_minimum_required(VERSION 3.21)
project(psiw C)

set(CMAKE_C_STANDARD 99)

add_executable(psiw main.c validation.h printer.h logLibrary.h configuration.h staticData.h)