# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_SOURCE_DIR = /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build

# Include any dependencies generated for this target.
include ch06/CMakeFiles/example6_20.dir/depend.make

# Include the progress variables for this target.
include ch06/CMakeFiles/example6_20.dir/progress.make

# Include the compile flags for this target's objects.
include ch06/CMakeFiles/example6_20.dir/flags.make

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o: ch06/CMakeFiles/example6_20.dir/flags.make
ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o: ../ch06/example6_20.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example6_20.dir/example6_20.cpp.o -c /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch06/example6_20.cpp

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example6_20.dir/example6_20.cpp.i"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch06/example6_20.cpp > CMakeFiles/example6_20.dir/example6_20.cpp.i

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example6_20.dir/example6_20.cpp.s"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch06/example6_20.cpp -o CMakeFiles/example6_20.dir/example6_20.cpp.s

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.requires:

.PHONY : ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.requires

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.provides: ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.requires
	$(MAKE) -f ch06/CMakeFiles/example6_20.dir/build.make ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.provides.build
.PHONY : ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.provides

ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.provides.build: ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o


# Object files for target example6_20
example6_20_OBJECTS = \
"CMakeFiles/example6_20.dir/example6_20.cpp.o"

# External object files for target example6_20
example6_20_EXTERNAL_OBJECTS =

ch06/example6_20: ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o
ch06/example6_20: ch06/CMakeFiles/example6_20.dir/build.make
ch06/example6_20: ch06/CMakeFiles/example6_20.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example6_20"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example6_20.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ch06/CMakeFiles/example6_20.dir/build: ch06/example6_20

.PHONY : ch06/CMakeFiles/example6_20.dir/build

ch06/CMakeFiles/example6_20.dir/requires: ch06/CMakeFiles/example6_20.dir/example6_20.cpp.o.requires

.PHONY : ch06/CMakeFiles/example6_20.dir/requires

ch06/CMakeFiles/example6_20.dir/clean:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 && $(CMAKE_COMMAND) -P CMakeFiles/example6_20.dir/cmake_clean.cmake
.PHONY : ch06/CMakeFiles/example6_20.dir/clean

ch06/CMakeFiles/example6_20.dir/depend:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch06 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch06/CMakeFiles/example6_20.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ch06/CMakeFiles/example6_20.dir/depend

