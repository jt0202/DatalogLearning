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
CMAKE_SOURCE_DIR = /home/johannes/test2/popl2020-artifact/prosynth/souffle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johannes/test2/popl2020-artifact/prosynth/souffle/build

# Include any dependencies generated for this target.
include src/tests/CMakeFiles/test_parallel_utils.dir/depend.make

# Include the progress variables for this target.
include src/tests/CMakeFiles/test_parallel_utils.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/CMakeFiles/test_parallel_utils.dir/flags.make

src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o: src/tests/CMakeFiles/test_parallel_utils.dir/flags.make
src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o: ../src/tests/parallel_utils_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o -c /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/tests/parallel_utils_test.cpp

src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.i"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/tests/parallel_utils_test.cpp > CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.i

src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.s"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/tests/parallel_utils_test.cpp -o CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.s

# Object files for target test_parallel_utils
test_parallel_utils_OBJECTS = \
"CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o"

# External object files for target test_parallel_utils
test_parallel_utils_EXTERNAL_OBJECTS =

src/tests/test_parallel_utils: src/tests/CMakeFiles/test_parallel_utils.dir/parallel_utils_test.cpp.o
src/tests/test_parallel_utils: src/tests/CMakeFiles/test_parallel_utils.dir/build.make
src/tests/test_parallel_utils: /usr/lib/gcc/x86_64-linux-gnu/9/libgomp.so
src/tests/test_parallel_utils: /usr/lib/x86_64-linux-gnu/libpthread.so
src/tests/test_parallel_utils: src/tests/CMakeFiles/test_parallel_utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_parallel_utils"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_parallel_utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/CMakeFiles/test_parallel_utils.dir/build: src/tests/test_parallel_utils

.PHONY : src/tests/CMakeFiles/test_parallel_utils.dir/build

src/tests/CMakeFiles/test_parallel_utils.dir/clean:
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_parallel_utils.dir/cmake_clean.cmake
.PHONY : src/tests/CMakeFiles/test_parallel_utils.dir/clean

src/tests/CMakeFiles/test_parallel_utils.dir/depend:
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johannes/test2/popl2020-artifact/prosynth/souffle /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/tests /home/johannes/test2/popl2020-artifact/prosynth/souffle/build /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/tests/CMakeFiles/test_parallel_utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/CMakeFiles/test_parallel_utils.dir/depend

