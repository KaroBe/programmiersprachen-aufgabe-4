# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build

# Include any dependencies generated for this target.
include source/CMakeFiles/aufg_1.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/aufg_1.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/aufg_1.dir/flags.make

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o: source/CMakeFiles/aufg_1.dir/flags.make
source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o: ../source/aufg_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o"
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aufg_1.dir/aufg_1.cpp.o -c /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/source/aufg_1.cpp

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aufg_1.dir/aufg_1.cpp.i"
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/source/aufg_1.cpp > CMakeFiles/aufg_1.dir/aufg_1.cpp.i

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aufg_1.dir/aufg_1.cpp.s"
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/source/aufg_1.cpp -o CMakeFiles/aufg_1.dir/aufg_1.cpp.s

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.requires:

.PHONY : source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.requires

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.provides: source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/aufg_1.dir/build.make source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.provides.build
.PHONY : source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.provides

source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.provides.build: source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o


# Object files for target aufg_1
aufg_1_OBJECTS = \
"CMakeFiles/aufg_1.dir/aufg_1.cpp.o"

# External object files for target aufg_1
aufg_1_EXTERNAL_OBJECTS =

source/aufg_1: source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o
source/aufg_1: source/CMakeFiles/aufg_1.dir/build.make
source/aufg_1: source/CMakeFiles/aufg_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aufg_1"
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aufg_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/aufg_1.dir/build: source/aufg_1

.PHONY : source/CMakeFiles/aufg_1.dir/build

source/CMakeFiles/aufg_1.dir/requires: source/CMakeFiles/aufg_1.dir/aufg_1.cpp.o.requires

.PHONY : source/CMakeFiles/aufg_1.dir/requires

source/CMakeFiles/aufg_1.dir/clean:
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source && $(CMAKE_COMMAND) -P CMakeFiles/aufg_1.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/aufg_1.dir/clean

source/CMakeFiles/aufg_1.dir/depend:
	cd /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4 /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/source /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source /home/karoline/Documents/studium/17_sose/programmiersprachen/programmiersprachen-aufgabenblatt-4/build/source/CMakeFiles/aufg_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/aufg_1.dir/depend

