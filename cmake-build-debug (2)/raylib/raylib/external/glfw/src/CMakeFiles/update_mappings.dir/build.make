# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/progress.make

raylib/raylib/external/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\raylib\src\external\glfw\src && "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -P C:/Users/hugov/CLionProjects/projet-labyrinte-ECE-dernier/raylib/src/external/glfw/CMake/GenerateMappings.cmake mappings.h.in mappings.h

update_mappings: raylib/raylib/external/glfw/src/CMakeFiles/update_mappings
update_mappings: raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/build

raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug\raylib\raylib\external\glfw\src && $(CMAKE_COMMAND) -P CMakeFiles\update_mappings.dir\cmake_clean.cmake
.PHONY : raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/clean

raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\raylib\src\external\glfw\src C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug\raylib\raylib\external\glfw\src C:\Users\hugov\CLionProjects\projet-labyrinte-ECE-dernier\cmake-build-debug\raylib\raylib\external\glfw\src\CMakeFiles\update_mappings.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : raylib/raylib/external/glfw/src/CMakeFiles/update_mappings.dir/depend

