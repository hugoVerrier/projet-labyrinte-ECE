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
CMAKE_SOURCE_DIR = C:\Users\hugov\CLionProjects\projet-labyrinte-ECE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug

# Include any dependencies generated for this target.
include raylib/raylib/CMakeFiles/raylib.dir/depend.make
# Include the progress variables for this target.
include raylib/raylib/CMakeFiles/raylib.dir/progress.make

# Include the compile flags for this target's objects.
include raylib/raylib/CMakeFiles/raylib.dir/flags.make

raylib/raylib/CMakeFiles/raylib.dir/rcore.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/rcore.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/rcore.c.obj: ../raylib/src/rcore.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object raylib/raylib/CMakeFiles/raylib.dir/rcore.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\rcore.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rcore.c

raylib/raylib/CMakeFiles/raylib.dir/rcore.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/rcore.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rcore.c > CMakeFiles\raylib.dir\rcore.c.i

raylib/raylib/CMakeFiles/raylib.dir/rcore.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/rcore.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rcore.c -o CMakeFiles\raylib.dir\rcore.c.s

raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.obj: ../raylib/src/rmodels.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\rmodels.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rmodels.c

raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/rmodels.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rmodels.c > CMakeFiles\raylib.dir\rmodels.c.i

raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/rmodels.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rmodels.c -o CMakeFiles\raylib.dir\rmodels.c.s

raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.obj: ../raylib/src/rshapes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\rshapes.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rshapes.c

raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/rshapes.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rshapes.c > CMakeFiles\raylib.dir\rshapes.c.i

raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/rshapes.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rshapes.c -o CMakeFiles\raylib.dir\rshapes.c.s

raylib/raylib/CMakeFiles/raylib.dir/rtext.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/rtext.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/rtext.c.obj: ../raylib/src/rtext.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object raylib/raylib/CMakeFiles/raylib.dir/rtext.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\rtext.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtext.c

raylib/raylib/CMakeFiles/raylib.dir/rtext.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/rtext.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtext.c > CMakeFiles\raylib.dir\rtext.c.i

raylib/raylib/CMakeFiles/raylib.dir/rtext.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/rtext.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtext.c -o CMakeFiles\raylib.dir\rtext.c.s

raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.obj: ../raylib/src/rtextures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\rtextures.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtextures.c

raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/rtextures.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtextures.c > CMakeFiles\raylib.dir\rtextures.c.i

raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/rtextures.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\rtextures.c -o CMakeFiles\raylib.dir\rtextures.c.s

raylib/raylib/CMakeFiles/raylib.dir/utils.c.obj: raylib/raylib/CMakeFiles/raylib.dir/flags.make
raylib/raylib/CMakeFiles/raylib.dir/utils.c.obj: raylib/raylib/CMakeFiles/raylib.dir/includes_C.rsp
raylib/raylib/CMakeFiles/raylib.dir/utils.c.obj: ../raylib/src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object raylib/raylib/CMakeFiles/raylib.dir/utils.c.obj"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\raylib.dir\utils.c.obj -c C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\utils.c

raylib/raylib/CMakeFiles/raylib.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raylib.dir/utils.c.i"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\utils.c > CMakeFiles\raylib.dir\utils.c.i

raylib/raylib/CMakeFiles/raylib.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raylib.dir/utils.c.s"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src\utils.c -o CMakeFiles\raylib.dir\utils.c.s

# Object files for target raylib
raylib_OBJECTS = \
"CMakeFiles/raylib.dir/rcore.c.obj" \
"CMakeFiles/raylib.dir/rmodels.c.obj" \
"CMakeFiles/raylib.dir/rshapes.c.obj" \
"CMakeFiles/raylib.dir/rtext.c.obj" \
"CMakeFiles/raylib.dir/rtextures.c.obj" \
"CMakeFiles/raylib.dir/utils.c.obj"

# External object files for target raylib
raylib_EXTERNAL_OBJECTS =

raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/rcore.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/rmodels.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/rshapes.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/rtext.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/rtextures.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/utils.c.obj
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/build.make
raylib/raylib/libraylib.a: raylib/raylib/CMakeFiles/raylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libraylib.a"
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && $(CMAKE_COMMAND) -P CMakeFiles\raylib.dir\cmake_clean_target.cmake
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\raylib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
raylib/raylib/CMakeFiles/raylib.dir/build: raylib/raylib/libraylib.a
.PHONY : raylib/raylib/CMakeFiles/raylib.dir/build

raylib/raylib/CMakeFiles/raylib.dir/clean:
	cd /d C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib && $(CMAKE_COMMAND) -P CMakeFiles\raylib.dir\cmake_clean.cmake
.PHONY : raylib/raylib/CMakeFiles/raylib.dir/clean

raylib/raylib/CMakeFiles/raylib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hugov\CLionProjects\projet-labyrinte-ECE C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\raylib\src C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib C:\Users\hugov\CLionProjects\projet-labyrinte-ECE\cmake-build-debug\raylib\raylib\CMakeFiles\raylib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : raylib/raylib/CMakeFiles/raylib.dir/depend
