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
CMAKE_SOURCE_DIR = /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build

# Include any dependencies generated for this target.
include ch01/CMakeFiles/test01.dir/depend.make

# Include the progress variables for this target.
include ch01/CMakeFiles/test01.dir/progress.make

# Include the compile flags for this target's objects.
include ch01/CMakeFiles/test01.dir/flags.make

ch01/CMakeFiles/test01.dir/test01.cpp.o: ch01/CMakeFiles/test01.dir/flags.make
ch01/CMakeFiles/test01.dir/test01.cpp.o: ../ch01/test01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ch01/CMakeFiles/test01.dir/test01.cpp.o"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test01.dir/test01.cpp.o -c /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/ch01/test01.cpp

ch01/CMakeFiles/test01.dir/test01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test01.dir/test01.cpp.i"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/ch01/test01.cpp > CMakeFiles/test01.dir/test01.cpp.i

ch01/CMakeFiles/test01.dir/test01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test01.dir/test01.cpp.s"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/ch01/test01.cpp -o CMakeFiles/test01.dir/test01.cpp.s

ch01/CMakeFiles/test01.dir/test01.cpp.o.requires:

.PHONY : ch01/CMakeFiles/test01.dir/test01.cpp.o.requires

ch01/CMakeFiles/test01.dir/test01.cpp.o.provides: ch01/CMakeFiles/test01.dir/test01.cpp.o.requires
	$(MAKE) -f ch01/CMakeFiles/test01.dir/build.make ch01/CMakeFiles/test01.dir/test01.cpp.o.provides.build
.PHONY : ch01/CMakeFiles/test01.dir/test01.cpp.o.provides

ch01/CMakeFiles/test01.dir/test01.cpp.o.provides.build: ch01/CMakeFiles/test01.dir/test01.cpp.o


# Object files for target test01
test01_OBJECTS = \
"CMakeFiles/test01.dir/test01.cpp.o"

# External object files for target test01
test01_EXTERNAL_OBJECTS =

ch01/test01: ch01/CMakeFiles/test01.dir/test01.cpp.o
ch01/test01: ch01/CMakeFiles/test01.dir/build.make
ch01/test01: ch01/CMakeFiles/test01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test01"
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ch01/CMakeFiles/test01.dir/build: ch01/test01

.PHONY : ch01/CMakeFiles/test01.dir/build

ch01/CMakeFiles/test01.dir/requires: ch01/CMakeFiles/test01.dir/test01.cpp.o.requires

.PHONY : ch01/CMakeFiles/test01.dir/requires

ch01/CMakeFiles/test01.dir/clean:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 && $(CMAKE_COMMAND) -P CMakeFiles/test01.dir/cmake_clean.cmake
.PHONY : ch01/CMakeFiles/test01.dir/clean

ch01/CMakeFiles/test01.dir/depend:
	cd /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/ch01 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01 /home/heyjude/workspace/projects/cpp/projects/cppLearning/cppConcurrency/build/ch01/CMakeFiles/test01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ch01/CMakeFiles/test01.dir/depend

