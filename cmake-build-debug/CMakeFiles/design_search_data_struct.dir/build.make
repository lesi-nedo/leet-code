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
include CMakeFiles/design_search_data_struct.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/design_search_data_struct.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/design_search_data_struct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/design_search_data_struct.dir/flags.make

CMakeFiles/design_search_data_struct.dir/codegen:
.PHONY : CMakeFiles/design_search_data_struct.dir/codegen

CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o: CMakeFiles/design_search_data_struct.dir/flags.make
CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o: /home/lesi-nedo/Desktop/leet-code/top_interview_150/211.\ Design\ Add\ and\ Search\ Words\ Data\ Structure.cpp
CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o: CMakeFiles/design_search_data_struct.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o -MF CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o.d -o CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o -c "/home/lesi-nedo/Desktop/leet-code/top_interview_150/211. Design Add and Search Words Data Structure.cpp"

CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lesi-nedo/Desktop/leet-code/top_interview_150/211. Design Add and Search Words Data Structure.cpp" > CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.i

CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lesi-nedo/Desktop/leet-code/top_interview_150/211. Design Add and Search Words Data Structure.cpp" -o CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.s

# Object files for target design_search_data_struct
design_search_data_struct_OBJECTS = \
"CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o"

# External object files for target design_search_data_struct
design_search_data_struct_EXTERNAL_OBJECTS =

bin/design_search_data_struct: CMakeFiles/design_search_data_struct.dir/top_interview_150/211._Design_Add_and_Search_Words_Data_Structure.cpp.o
bin/design_search_data_struct: CMakeFiles/design_search_data_struct.dir/build.make
bin/design_search_data_struct: CMakeFiles/design_search_data_struct.dir/compiler_depend.ts
bin/design_search_data_struct: CMakeFiles/design_search_data_struct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/design_search_data_struct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/design_search_data_struct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/design_search_data_struct.dir/build: bin/design_search_data_struct
.PHONY : CMakeFiles/design_search_data_struct.dir/build

CMakeFiles/design_search_data_struct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/design_search_data_struct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/design_search_data_struct.dir/clean

CMakeFiles/design_search_data_struct.dir/depend:
	cd /home/lesi-nedo/Desktop/leet-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug /home/lesi-nedo/Desktop/leet-code/cmake-build-debug/CMakeFiles/design_search_data_struct.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/design_search_data_struct.dir/depend

