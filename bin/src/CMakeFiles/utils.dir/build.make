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
include src/CMakeFiles/utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/utils.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/utils.dir/flags.make

src/CMakeFiles/utils.dir/utils/window.cpp.o: src/CMakeFiles/utils.dir/flags.make
src/CMakeFiles/utils.dir/utils/window.cpp.o: /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/window.cpp
src/CMakeFiles/utils.dir/utils/window.cpp.o: src/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/utils.dir/utils/window.cpp.o"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/utils.dir/utils/window.cpp.o -MF CMakeFiles/utils.dir/utils/window.cpp.o.d -o CMakeFiles/utils.dir/utils/window.cpp.o -c /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/window.cpp

src/CMakeFiles/utils.dir/utils/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/window.cpp.i"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/window.cpp > CMakeFiles/utils.dir/utils/window.cpp.i

src/CMakeFiles/utils.dir/utils/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/window.cpp.s"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/window.cpp -o CMakeFiles/utils.dir/utils/window.cpp.s

src/CMakeFiles/utils.dir/utils/gameobject.cpp.o: src/CMakeFiles/utils.dir/flags.make
src/CMakeFiles/utils.dir/utils/gameobject.cpp.o: /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/gameobject.cpp
src/CMakeFiles/utils.dir/utils/gameobject.cpp.o: src/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/utils.dir/utils/gameobject.cpp.o"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/utils.dir/utils/gameobject.cpp.o -MF CMakeFiles/utils.dir/utils/gameobject.cpp.o.d -o CMakeFiles/utils.dir/utils/gameobject.cpp.o -c /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/gameobject.cpp

src/CMakeFiles/utils.dir/utils/gameobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/gameobject.cpp.i"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/gameobject.cpp > CMakeFiles/utils.dir/utils/gameobject.cpp.i

src/CMakeFiles/utils.dir/utils/gameobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/gameobject.cpp.s"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/gameobject.cpp -o CMakeFiles/utils.dir/utils/gameobject.cpp.s

src/CMakeFiles/utils.dir/utils/shader.cpp.o: src/CMakeFiles/utils.dir/flags.make
src/CMakeFiles/utils.dir/utils/shader.cpp.o: /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/shader.cpp
src/CMakeFiles/utils.dir/utils/shader.cpp.o: src/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/utils.dir/utils/shader.cpp.o"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/utils.dir/utils/shader.cpp.o -MF CMakeFiles/utils.dir/utils/shader.cpp.o.d -o CMakeFiles/utils.dir/utils/shader.cpp.o -c /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/shader.cpp

src/CMakeFiles/utils.dir/utils/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/shader.cpp.i"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/shader.cpp > CMakeFiles/utils.dir/utils/shader.cpp.i

src/CMakeFiles/utils.dir/utils/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/shader.cpp.s"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/shader.cpp -o CMakeFiles/utils.dir/utils/shader.cpp.s

src/CMakeFiles/utils.dir/utils/Camera.cpp.o: src/CMakeFiles/utils.dir/flags.make
src/CMakeFiles/utils.dir/utils/Camera.cpp.o: /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/Camera.cpp
src/CMakeFiles/utils.dir/utils/Camera.cpp.o: src/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/utils.dir/utils/Camera.cpp.o"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/utils.dir/utils/Camera.cpp.o -MF CMakeFiles/utils.dir/utils/Camera.cpp.o.d -o CMakeFiles/utils.dir/utils/Camera.cpp.o -c /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/Camera.cpp

src/CMakeFiles/utils.dir/utils/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/Camera.cpp.i"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/Camera.cpp > CMakeFiles/utils.dir/utils/Camera.cpp.i

src/CMakeFiles/utils.dir/utils/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/Camera.cpp.s"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pashaaliabadi/Desktop/cpp/testGL/src/utils/Camera.cpp -o CMakeFiles/utils.dir/utils/Camera.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/utils/window.cpp.o" \
"CMakeFiles/utils.dir/utils/gameobject.cpp.o" \
"CMakeFiles/utils.dir/utils/shader.cpp.o" \
"CMakeFiles/utils.dir/utils/Camera.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

src/libutils.a: src/CMakeFiles/utils.dir/utils/window.cpp.o
src/libutils.a: src/CMakeFiles/utils.dir/utils/gameobject.cpp.o
src/libutils.a: src/CMakeFiles/utils.dir/utils/shader.cpp.o
src/libutils.a: src/CMakeFiles/utils.dir/utils/Camera.cpp.o
src/libutils.a: src/CMakeFiles/utils.dir/build.make
src/libutils.a: src/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/pashaaliabadi/Desktop/cpp/testGL/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libutils.a"
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/utils.dir/build: src/libutils.a
.PHONY : src/CMakeFiles/utils.dir/build

src/CMakeFiles/utils.dir/clean:
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/utils.dir/clean

src/CMakeFiles/utils.dir/depend:
	cd /Users/pashaaliabadi/Desktop/cpp/testGL/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pashaaliabadi/Desktop/cpp/testGL /Users/pashaaliabadi/Desktop/cpp/testGL/src /Users/pashaaliabadi/Desktop/cpp/testGL/bin /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src /Users/pashaaliabadi/Desktop/cpp/testGL/bin/src/CMakeFiles/utils.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/utils.dir/depend
