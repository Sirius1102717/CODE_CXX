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
CMAKE_SOURCE_DIR = /home/freaver/CODE_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/freaver/CODE_C

# Utility rule file for ExperimentalBuild.

# Include the progress variables for this target.
include practice/CMakeFiles/ExperimentalBuild.dir/progress.make

practice/CMakeFiles/ExperimentalBuild:
	cd /home/freaver/CODE_C/practice && /usr/bin/ctest -D ExperimentalBuild

ExperimentalBuild: practice/CMakeFiles/ExperimentalBuild
ExperimentalBuild: practice/CMakeFiles/ExperimentalBuild.dir/build.make

.PHONY : ExperimentalBuild

# Rule to build all files generated by this target.
practice/CMakeFiles/ExperimentalBuild.dir/build: ExperimentalBuild

.PHONY : practice/CMakeFiles/ExperimentalBuild.dir/build

practice/CMakeFiles/ExperimentalBuild.dir/clean:
	cd /home/freaver/CODE_C/practice && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalBuild.dir/cmake_clean.cmake
.PHONY : practice/CMakeFiles/ExperimentalBuild.dir/clean

practice/CMakeFiles/ExperimentalBuild.dir/depend:
	cd /home/freaver/CODE_C && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/freaver/CODE_C /home/freaver/CODE_C/practice /home/freaver/CODE_C /home/freaver/CODE_C/practice /home/freaver/CODE_C/practice/CMakeFiles/ExperimentalBuild.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : practice/CMakeFiles/ExperimentalBuild.dir/depend

