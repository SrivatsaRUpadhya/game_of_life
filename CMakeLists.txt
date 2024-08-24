cmake_minimum_required(VERSION 3.10)

project(game_of_life)

set(SOURCES
    main.cpp
    defs.h
)

add_executable(gol ${SOURCES})
