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
include CMakeFiles/long_palindr_by_concat.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/long_palindr_by_concat.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/long_palindr_by_concat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/long_palindr_by_concat.dir/flags.make

CMakeFiles/long_palindr_by_concat.dir/codegen:
.PHONY : CMakeFiles/long_palindr_by_concat.dir/codegen

CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o: CMakeFiles/long_palindr_by_concat.dir/flags.make
CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o: /home/lesi-nedo/Desktop/leet-code/daily_q/2131.\ Longest\ Palindrome\ by\ Concatenating\ Two\ Letter\ Words.cpp
CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o: CMakeFiles/long_palindr_by_concat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o -MF CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o.d -o CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o -c "/home/lesi-nedo/Desktop/leet-code/daily_q/2131. Longest Palindrome by Concatenating Two Letter Words.cpp"

CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lesi-nedo/Desktop/leet-code/daily_q/2131. Longest Palindrome by Concatenating Two Letter Words.cpp" > CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.i

CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lesi-nedo/Desktop/leet-code/daily_q/2131. Longest Palindrome by Concatenating Two Letter Words.cpp" -o CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.s

# Object files for target long_palindr_by_concat
long_palindr_by_concat_OBJECTS = \
"CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o"

# External object files for target long_palindr_by_concat
long_palindr_by_concat_EXTERNAL_OBJECTS =

bin/long_palindr_by_concat: CMakeFiles/long_palindr_by_concat.dir/daily_q/2131._Longest_Palindrome_by_Concatenating_Two_Letter_Words.cpp.o
bin/long_palindr_by_concat: CMakeFiles/long_palindr_by_concat.dir/build.make
bin/long_palindr_by_concat: CMakeFiles/long_palindr_by_concat.dir/compiler_depend.ts
bin/long_palindr_by_concat: CMakeFiles/long_palindr_by_concat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/long_palindr_by_concat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/long_palindr_by_concat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/long_palindr_by_concat.dir/build: bin/long_palindr_by_concat
.PHONY : CMakeFiles/long_palindr_by_concat.dir/build

CMakeFiles/long_palindr_by_concat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/long_palindr_by_concat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/long_palindr_by_concat.dir/clean

CMakeFiles/long_palindr_by_concat.dir/depend:
	cd /home/lesi-nedo/Desktop/leet-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles/long_palindr_by_concat.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/long_palindr_by_concat.dir/depend

