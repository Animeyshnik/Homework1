# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/animeyshnik/Documents/Homework1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/animeyshnik/Documents/Homework1/build

# Include any dependencies generated for this target.
include CMakeFiles/HomeHello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HomeHello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HomeHello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HomeHello.dir/flags.make

CMakeFiles/HomeHello.dir/project.cpp.o: CMakeFiles/HomeHello.dir/flags.make
CMakeFiles/HomeHello.dir/project.cpp.o: project.cpp
CMakeFiles/HomeHello.dir/project.cpp.o: CMakeFiles/HomeHello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/animeyshnik/Documents/Homework1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HomeHello.dir/project.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HomeHello.dir/project.cpp.o -MF CMakeFiles/HomeHello.dir/project.cpp.o.d -o CMakeFiles/HomeHello.dir/project.cpp.o -c /home/animeyshnik/Documents/Homework1/build/project.cpp

CMakeFiles/HomeHello.dir/project.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HomeHello.dir/project.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/animeyshnik/Documents/Homework1/build/project.cpp > CMakeFiles/HomeHello.dir/project.cpp.i

CMakeFiles/HomeHello.dir/project.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HomeHello.dir/project.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/animeyshnik/Documents/Homework1/build/project.cpp -o CMakeFiles/HomeHello.dir/project.cpp.s

# Object files for target HomeHello
HomeHello_OBJECTS = \
"CMakeFiles/HomeHello.dir/project.cpp.o"

# External object files for target HomeHello
HomeHello_EXTERNAL_OBJECTS =

HomeHello: CMakeFiles/HomeHello.dir/project.cpp.o
HomeHello: CMakeFiles/HomeHello.dir/build.make
HomeHello: CMakeFiles/HomeHello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/animeyshnik/Documents/Homework1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HomeHello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HomeHello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HomeHello.dir/build: HomeHello
.PHONY : CMakeFiles/HomeHello.dir/build

CMakeFiles/HomeHello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HomeHello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HomeHello.dir/clean

CMakeFiles/HomeHello.dir/depend:
	cd /home/animeyshnik/Documents/Homework1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/animeyshnik/Documents/Homework1 /home/animeyshnik/Documents/Homework1 /home/animeyshnik/Documents/Homework1/build /home/animeyshnik/Documents/Homework1/build /home/animeyshnik/Documents/Homework1/build/CMakeFiles/HomeHello.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HomeHello.dir/depend

