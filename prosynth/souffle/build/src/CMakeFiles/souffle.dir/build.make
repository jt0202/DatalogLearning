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
include src/CMakeFiles/souffle.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/souffle.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/souffle.dir/flags.make

src/CMakeFiles/souffle.dir/main.cpp.o: src/CMakeFiles/souffle.dir/flags.make
src/CMakeFiles/souffle.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/souffle.dir/main.cpp.o"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/souffle.dir/main.cpp.o -c /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/main.cpp

src/CMakeFiles/souffle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/souffle.dir/main.cpp.i"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/main.cpp > CMakeFiles/souffle.dir/main.cpp.i

src/CMakeFiles/souffle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/souffle.dir/main.cpp.s"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johannes/test2/popl2020-artifact/prosynth/souffle/src/main.cpp -o CMakeFiles/souffle.dir/main.cpp.s

# Object files for target souffle
souffle_OBJECTS = \
"CMakeFiles/souffle.dir/main.cpp.o"

# External object files for target souffle
souffle_EXTERNAL_OBJECTS =

src/souffle: src/CMakeFiles/souffle.dir/main.cpp.o
src/souffle: src/CMakeFiles/souffle.dir/build.make
src/souffle: src/libsouffle.a
src/souffle: /usr/lib/x86_64-linux-gnu/libffi.so
src/souffle: /usr/lib/gcc/x86_64-linux-gnu/9/libgomp.so
src/souffle: /usr/lib/x86_64-linux-gnu/libpthread.so
src/souffle: /usr/lib/x86_64-linux-gnu/libz.so
src/souffle: /usr/lib/x86_64-linux-gnu/libsqlite3.so
src/souffle: src/CMakeFiles/souffle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable souffle"
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/souffle.dir/link.txt --verbose=$(VERBOSE)
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && /usr/bin/cmake -E copy_if_different /usr/lib/x86_64-linux-gnu/libsqlite3.so /usr/lib/x86_64-linux-gnu/libz.so /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && /usr/bin/cmake -E copy_if_different /usr/lib/x86_64-linux-gnu/libsqlite3.so /usr/lib/x86_64-linux-gnu/libz.so /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src

# Rule to build all files generated by this target.
src/CMakeFiles/souffle.dir/build: src/souffle

.PHONY : src/CMakeFiles/souffle.dir/build

src/CMakeFiles/souffle.dir/clean:
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src && $(CMAKE_COMMAND) -P CMakeFiles/souffle.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/souffle.dir/clean

src/CMakeFiles/souffle.dir/depend:
	cd /home/johannes/test2/popl2020-artifact/prosynth/souffle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johannes/test2/popl2020-artifact/prosynth/souffle /home/johannes/test2/popl2020-artifact/prosynth/souffle/src /home/johannes/test2/popl2020-artifact/prosynth/souffle/build /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/CMakeFiles/souffle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/souffle.dir/depend

