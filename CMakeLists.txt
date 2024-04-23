cmake_minimum_required(VERSION 3.16)
project(pthread_pool)

set(CMAKE_CXX_STANDARD 14)

add_executable(pthread_pool main.cpp Threadpool.c)