# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pashaaliabadi/Desktop/cpp/testGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pashaaliabadi/Desktop/cpp/testGL/bin

# Include any dependencies generated for this target.
include CMakeFiles/MainExec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MainExec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainExec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainExec.dir/flags.make

CMakeFiles/MainExec.dir/src/main.cpp.o: CMakeFiles/MainExec.dir/flags.make
CMakeFiles/MainExec.dir/src/main.cpp.o: /Users/pashaaliabadi/Desktop/cpp/testGL/src/main.cpp
CMakeFiles/MainExec.dir/src/main.cpp.o: CMakeFiles/MainExec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainExec.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainExec.dir/src/main.cpp.o -MF CMakeFiles/MainExec.dir/src/main.cpp.o.d -o CMakeFiles/MainExec.dir/src/main.cpp.o -c /Users/pashaaliabadi/Desktop/cpp/testGL/src/main.cpp

CMakeFiles/MainExec.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainExec.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pashaaliabadi/Desktop/cpp/testGL/src/main.cpp > CMakeFiles/MainExec.dir/src/main.cpp.i

CMakeFiles/MainExec.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainExec.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pashaaliabadi/Desktop/cpp/testGL/src/main.cpp -o CMakeFiles/MainExec.dir/src/main.cpp.s

# Object files for target MainExec
MainExec_OBJECTS = \
"CMakeFiles/MainExec.dir/src/main.cpp.o"

# External object files for target MainExec
MainExec_EXTERNAL_OBJECTS =

MainExec: CMakeFiles/MainExec.dir/src/main.cpp.o
MainExec: CMakeFiles/MainExec.dir/build.make
MainExec: src/libutils.a
MainExec: /opt/homebrew/lib/libglfw.3.3.dylib
MainExec: include/glad/libglad.a
MainExec: /opt/homebrew/Cellar/assimp/5.3.1/lib/libassimp.dylib
MainExec: CMakeFiles/MainExec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MainExec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainExec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainExec.dir/build: MainExec
.PHONY : CMakeFiles/MainExec.dir/build

CMakeFiles/MainExec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainExec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainExec.dir/clean

CMakeFiles/MainExec.dir/depend:
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pashaaliabadi/Desktop/cpp/testGL /Users/pashaaliabadi/Desktop/cpp/testGL /Users/pashaaliabadi/Desktop/cpp/testGL/bin /Users/pashaaliabadi/Desktop/cpp/testGL/bin /Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles/MainExec.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MainExec.dir/depend

