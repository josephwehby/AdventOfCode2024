# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/wehby/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/wehby/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wehby/Programming/AdventOfCode2024/Day11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wehby/Programming/AdventOfCode2024/Day11

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/solution_b.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/solution_b.cpp.o: solution_b.cpp
CMakeFiles/main.dir/solution_b.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wehby/Programming/AdventOfCode2024/Day11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/solution_b.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/solution_b.cpp.o -MF CMakeFiles/main.dir/solution_b.cpp.o.d -o CMakeFiles/main.dir/solution_b.cpp.o -c /home/wehby/Programming/AdventOfCode2024/Day11/solution_b.cpp

CMakeFiles/main.dir/solution_b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/solution_b.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wehby/Programming/AdventOfCode2024/Day11/solution_b.cpp > CMakeFiles/main.dir/solution_b.cpp.i

CMakeFiles/main.dir/solution_b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/solution_b.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wehby/Programming/AdventOfCode2024/Day11/solution_b.cpp -o CMakeFiles/main.dir/solution_b.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/solution_b.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/solution_b.cpp.o
main: CMakeFiles/main.dir/build.make
main: /home/wehby/C++Libs/BigInteger/libBigInteger.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wehby/Programming/AdventOfCode2024/Day11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/wehby/Programming/AdventOfCode2024/Day11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wehby/Programming/AdventOfCode2024/Day11 /home/wehby/Programming/AdventOfCode2024/Day11 /home/wehby/Programming/AdventOfCode2024/Day11 /home/wehby/Programming/AdventOfCode2024/Day11 /home/wehby/Programming/AdventOfCode2024/Day11/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

