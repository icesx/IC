# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /ICESX/workSpaceC/IC/workspace_vsc/ILearnC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build

# Include any dependencies generated for this target.
include src/method/CMakeFiles/method.dir/depend.make

# Include the progress variables for this target.
include src/method/CMakeFiles/method.dir/progress.make

# Include the compile flags for this target's objects.
include src/method/CMakeFiles/method.dir/flags.make

src/method/CMakeFiles/method.dir/method.c.o: src/method/CMakeFiles/method.dir/flags.make
src/method/CMakeFiles/method.dir/method.c.o: ../src/method/method.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/method/CMakeFiles/method.dir/method.c.o"
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/method.dir/method.c.o   -c /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/src/method/method.c

src/method/CMakeFiles/method.dir/method.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/method.dir/method.c.i"
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/src/method/method.c > CMakeFiles/method.dir/method.c.i

src/method/CMakeFiles/method.dir/method.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/method.dir/method.c.s"
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/src/method/method.c -o CMakeFiles/method.dir/method.c.s

# Object files for target method
method_OBJECTS = \
"CMakeFiles/method.dir/method.c.o"

# External object files for target method
method_EXTERNAL_OBJECTS =

src/method/libmethod.a: src/method/CMakeFiles/method.dir/method.c.o
src/method/libmethod.a: src/method/CMakeFiles/method.dir/build.make
src/method/libmethod.a: src/method/CMakeFiles/method.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libmethod.a"
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && $(CMAKE_COMMAND) -P CMakeFiles/method.dir/cmake_clean_target.cmake
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/method.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/method/CMakeFiles/method.dir/build: src/method/libmethod.a

.PHONY : src/method/CMakeFiles/method.dir/build

src/method/CMakeFiles/method.dir/clean:
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method && $(CMAKE_COMMAND) -P CMakeFiles/method.dir/cmake_clean.cmake
.PHONY : src/method/CMakeFiles/method.dir/clean

src/method/CMakeFiles/method.dir/depend:
	cd /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /ICESX/workSpaceC/IC/workspace_vsc/ILearnC /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/src/method /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method /ICESX/workSpaceC/IC/workspace_vsc/ILearnC/build/src/method/CMakeFiles/method.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/method/CMakeFiles/method.dir/depend

