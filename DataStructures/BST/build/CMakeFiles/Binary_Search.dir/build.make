# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build

# Include any dependencies generated for this target.
include CMakeFiles/Binary_Search.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Binary_Search.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Binary_Search.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Binary_Search.dir/flags.make

CMakeFiles/Binary_Search.dir/main.cpp.o: CMakeFiles/Binary_Search.dir/flags.make
CMakeFiles/Binary_Search.dir/main.cpp.o: /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/main.cpp
CMakeFiles/Binary_Search.dir/main.cpp.o: CMakeFiles/Binary_Search.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Binary_Search.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Binary_Search.dir/main.cpp.o -MF CMakeFiles/Binary_Search.dir/main.cpp.o.d -o CMakeFiles/Binary_Search.dir/main.cpp.o -c /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/main.cpp

CMakeFiles/Binary_Search.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Binary_Search.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/main.cpp > CMakeFiles/Binary_Search.dir/main.cpp.i

CMakeFiles/Binary_Search.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Binary_Search.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/main.cpp -o CMakeFiles/Binary_Search.dir/main.cpp.s

# Object files for target Binary_Search
Binary_Search_OBJECTS = \
"CMakeFiles/Binary_Search.dir/main.cpp.o"

# External object files for target Binary_Search
Binary_Search_EXTERNAL_OBJECTS =

Binary_Search: CMakeFiles/Binary_Search.dir/main.cpp.o
Binary_Search: CMakeFiles/Binary_Search.dir/build.make
Binary_Search: CMakeFiles/Binary_Search.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Binary_Search"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Binary_Search.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Binary_Search.dir/build: Binary_Search
.PHONY : CMakeFiles/Binary_Search.dir/build

CMakeFiles/Binary_Search.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Binary_Search.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Binary_Search.dir/clean

CMakeFiles/Binary_Search.dir/depend:
	cd /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build /Users/ONLYPROGRAMMING/Desktop/Algorithms/DataStructures/BST/build/CMakeFiles/Binary_Search.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Binary_Search.dir/depend
