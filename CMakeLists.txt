
cmake_minimum_required(VERSION 3.20)
project(projet_labyrinte_ECE)

set(CMAKE_C_STANDARD 99)

include_directories(.)
add_executable(projet_labyrinte_ECE  plateau.h  MenuGraphique.c MenuGraphique.h plateau.c   VrmtVrmtTriste.c VrmtVrmtTriste.h main.c ".h de gestion /Bibliotheques.h" ".h de gestion /Enum.h" ".h de gestion /Structures.h" ".h de gestion /Macro.h")
add_subdirectory(raylib)
target_link_libraries(projet_labyrinte_ECE raylib)