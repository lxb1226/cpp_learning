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
include ch08/CMakeFiles/example8_14.dir/depend.make

# Include the progress variables for this target.
include ch08/CMakeFiles/example8_14.dir/progress.make

# Include the compile flags for this target's objects.
include ch08/CMakeFiles/example8_14.dir/flags.make

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o: ch08/CMakeFiles/example8_14.dir/flags.make
ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o: ../ch08/example8_14.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example8_14.dir/example8_14.cpp.o -c /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch08/example8_14.cpp

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example8_14.dir/example8_14.cpp.i"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch08/example8_14.cpp > CMakeFiles/example8_14.dir/example8_14.cpp.i

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example8_14.dir/example8_14.cpp.s"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch08/example8_14.cpp -o CMakeFiles/example8_14.dir/example8_14.cpp.s

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.requires:

.PHONY : ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.requires

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.provides: ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.requires
	$(MAKE) -f ch08/CMakeFiles/example8_14.dir/build.make ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.provides.build
.PHONY : ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.provides

ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.provides.build: ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o


# Object files for target example8_14
example8_14_OBJECTS = \
"CMakeFiles/example8_14.dir/example8_14.cpp.o"

# External object files for target example8_14
example8_14_EXTERNAL_OBJECTS =

ch08/example8_14: ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o
ch08/example8_14: ch08/CMakeFiles/example8_14.dir/build.make
ch08/example8_14: ch08/CMakeFiles/example8_14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example8_14"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example8_14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ch08/CMakeFiles/example8_14.dir/build: ch08/example8_14

.PHONY : ch08/CMakeFiles/example8_14.dir/build

ch08/CMakeFiles/example8_14.dir/requires: ch08/CMakeFiles/example8_14.dir/example8_14.cpp.o.requires

.PHONY : ch08/CMakeFiles/example8_14.dir/requires

ch08/CMakeFiles/example8_14.dir/clean:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 && $(CMAKE_COMMAND) -P CMakeFiles/example8_14.dir/cmake_clean.cmake
.PHONY : ch08/CMakeFiles/example8_14.dir/clean

ch08/CMakeFiles/example8_14.dir/depend:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/ch08 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cpp11Learning/build/ch08/CMakeFiles/example8_14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ch08/CMakeFiles/example8_14.dir/depend

