cmake_minimum_required(VERSION 3.20)
project(projet_labyrinte_ECE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projet_labyrinte_ECE MenuGraphique.c MenuGraphique.h README.md)



INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/raylib/4.2.0/include)
LINK_DIRECTORIES(/opt/homebrew/Cellar/raylib/4.2.0/lib)
file(GLOB LIBRARIES "/opt/homebrew/Cellar/raylib/4.2.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")



