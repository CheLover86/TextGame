cmake_minimum_required(VERSION 3.15)
project(AdventureGame VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(GameExecutable 
    main.c
    inventory.c
    location.c
    misc.c
    move.c
    noun.c
    object.c
    parsexec.c
)

target_include_directories(GameExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
