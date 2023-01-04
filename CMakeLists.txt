
cmake_minimum_required(VERSION 3.20)
project(projet_labyrinte_ECE)

set(CMAKE_C_STANDARD 99)

include_directories(.)
add_executable(projet_labyrinte_ECE MenuGraphique.c MenuGraphique.h README.md main.c)
add_subdirectory(raylib)
target_link_libraries(projet_labyrinte_ECE raylib)