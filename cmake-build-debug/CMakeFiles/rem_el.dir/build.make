# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /home/lesi-nedo/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/lesi-nedo/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lesi-nedo/Desktop/leet-code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lesi-nedo/Desktop/leet-code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rem_el.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rem_el.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rem_el.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rem_el.dir/flags.make

CMakeFiles/rem_el.dir/codegen:
.PHONY : CMakeFiles/rem_el.dir/codegen

CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o: CMakeFiles/rem_el.dir/flags.make
CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o: /home/lesi-nedo/Desktop/leet-code/top_interview_150/rem_el.cpp
CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o: CMakeFiles/rem_el.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o -MF CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o.d -o CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o -c /home/lesi-nedo/Desktop/leet-code/top_interview_150/rem_el.cpp

CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lesi-nedo/Desktop/leet-code/top_interview_150/rem_el.cpp > CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.i

CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lesi-nedo/Desktop/leet-code/top_interview_150/rem_el.cpp -o CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.s

# Object files for target rem_el
rem_el_OBJECTS = \
"CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o"

# External object files for target rem_el
rem_el_EXTERNAL_OBJECTS =

bin/rem_el: CMakeFiles/rem_el.dir/top_interview_150/rem_el.cpp.o
bin/rem_el: CMakeFiles/rem_el.dir/build.make
bin/rem_el: CMakeFiles/rem_el.dir/compiler_depend.ts
bin/rem_el: CMakeFiles/rem_el.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/rem_el"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rem_el.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rem_el.dir/build: bin/rem_el
.PHONY : CMakeFiles/rem_el.dir/build

CMakeFiles/rem_el.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rem_el.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rem_el.dir/clean

CMakeFiles/rem_el.dir/depend:
	cd /home/lesi-nedo/Desktop/leet-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles/rem_el.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rem_el.dir/depend

