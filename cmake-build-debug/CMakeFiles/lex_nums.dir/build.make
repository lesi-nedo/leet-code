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
include CMakeFiles/lex_nums.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lex_nums.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lex_nums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lex_nums.dir/flags.make

CMakeFiles/lex_nums.dir/codegen:
.PHONY : CMakeFiles/lex_nums.dir/codegen

CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o: CMakeFiles/lex_nums.dir/flags.make
CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o: /home/lesi-nedo/Desktop/leet-code/daily_q/386.\ Lexicographical\ Numbers.cpp
CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o: CMakeFiles/lex_nums.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o -MF CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o.d -o CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o -c "/home/lesi-nedo/Desktop/leet-code/daily_q/386. Lexicographical Numbers.cpp"

CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lesi-nedo/Desktop/leet-code/daily_q/386. Lexicographical Numbers.cpp" > CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.i

CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lesi-nedo/Desktop/leet-code/daily_q/386. Lexicographical Numbers.cpp" -o CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.s

# Object files for target lex_nums
lex_nums_OBJECTS = \
"CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o"

# External object files for target lex_nums
lex_nums_EXTERNAL_OBJECTS =

bin/lex_nums: CMakeFiles/lex_nums.dir/daily_q/386._Lexicographical_Numbers.cpp.o
bin/lex_nums: CMakeFiles/lex_nums.dir/build.make
bin/lex_nums: CMakeFiles/lex_nums.dir/compiler_depend.ts
bin/lex_nums: CMakeFiles/lex_nums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/lex_nums"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lex_nums.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lex_nums.dir/build: bin/lex_nums
.PHONY : CMakeFiles/lex_nums.dir/build

CMakeFiles/lex_nums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lex_nums.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lex_nums.dir/clean

CMakeFiles/lex_nums.dir/depend:
	cd /home/lesi-nedo/Desktop/leet-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles/lex_nums.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lex_nums.dir/depend

