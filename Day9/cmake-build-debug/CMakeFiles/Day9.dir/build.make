# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\AdventOfCode2022\Day9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\AdventOfCode2022\Day9\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Day9.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Day9.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Day9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Day9.dir/flags.make

CMakeFiles/Day9.dir/Day9.c.obj: CMakeFiles/Day9.dir/flags.make
CMakeFiles/Day9.dir/Day9.c.obj: D:/Projects/AdventOfCode2022/Day9/Day9.c
CMakeFiles/Day9.dir/Day9.c.obj: CMakeFiles/Day9.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\AdventOfCode2022\Day9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Day9.dir/Day9.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Day9.dir/Day9.c.obj -MF CMakeFiles\Day9.dir\Day9.c.obj.d -o CMakeFiles\Day9.dir\Day9.c.obj -c D:\Projects\AdventOfCode2022\Day9\Day9.c

CMakeFiles/Day9.dir/Day9.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Day9.dir/Day9.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projects\AdventOfCode2022\Day9\Day9.c > CMakeFiles\Day9.dir\Day9.c.i

CMakeFiles/Day9.dir/Day9.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Day9.dir/Day9.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projects\AdventOfCode2022\Day9\Day9.c -o CMakeFiles\Day9.dir\Day9.c.s

# Object files for target Day9
Day9_OBJECTS = \
"CMakeFiles/Day9.dir/Day9.c.obj"

# External object files for target Day9
Day9_EXTERNAL_OBJECTS =

Day9.exe: CMakeFiles/Day9.dir/Day9.c.obj
Day9.exe: CMakeFiles/Day9.dir/build.make
Day9.exe: CMakeFiles/Day9.dir/linklibs.rsp
Day9.exe: CMakeFiles/Day9.dir/objects1.rsp
Day9.exe: CMakeFiles/Day9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\AdventOfCode2022\Day9\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Day9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Day9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Day9.dir/build: Day9.exe
.PHONY : CMakeFiles/Day9.dir/build

CMakeFiles/Day9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Day9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Day9.dir/clean

CMakeFiles/Day9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\AdventOfCode2022\Day9 D:\Projects\AdventOfCode2022\Day9 D:\Projects\AdventOfCode2022\Day9\cmake-build-debug D:\Projects\AdventOfCode2022\Day9\cmake-build-debug D:\Projects\AdventOfCode2022\Day9\cmake-build-debug\CMakeFiles\Day9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Day9.dir/depend

