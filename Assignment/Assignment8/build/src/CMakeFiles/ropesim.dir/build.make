# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/cs18/Desktop/Homework/Assignment8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs18/Desktop/Homework/Assignment8/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ropesim.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ropesim.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ropesim.dir/flags.make

src/CMakeFiles/ropesim.dir/rope.cpp.o: src/CMakeFiles/ropesim.dir/flags.make
src/CMakeFiles/ropesim.dir/rope.cpp.o: ../src/rope.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ropesim.dir/rope.cpp.o"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ropesim.dir/rope.cpp.o -c /home/cs18/Desktop/Homework/Assignment8/src/rope.cpp

src/CMakeFiles/ropesim.dir/rope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ropesim.dir/rope.cpp.i"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment8/src/rope.cpp > CMakeFiles/ropesim.dir/rope.cpp.i

src/CMakeFiles/ropesim.dir/rope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ropesim.dir/rope.cpp.s"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment8/src/rope.cpp -o CMakeFiles/ropesim.dir/rope.cpp.s

src/CMakeFiles/ropesim.dir/rope.cpp.o.requires:

.PHONY : src/CMakeFiles/ropesim.dir/rope.cpp.o.requires

src/CMakeFiles/ropesim.dir/rope.cpp.o.provides: src/CMakeFiles/ropesim.dir/rope.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ropesim.dir/build.make src/CMakeFiles/ropesim.dir/rope.cpp.o.provides.build
.PHONY : src/CMakeFiles/ropesim.dir/rope.cpp.o.provides

src/CMakeFiles/ropesim.dir/rope.cpp.o.provides.build: src/CMakeFiles/ropesim.dir/rope.cpp.o


src/CMakeFiles/ropesim.dir/application.cpp.o: src/CMakeFiles/ropesim.dir/flags.make
src/CMakeFiles/ropesim.dir/application.cpp.o: ../src/application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ropesim.dir/application.cpp.o"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ropesim.dir/application.cpp.o -c /home/cs18/Desktop/Homework/Assignment8/src/application.cpp

src/CMakeFiles/ropesim.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ropesim.dir/application.cpp.i"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment8/src/application.cpp > CMakeFiles/ropesim.dir/application.cpp.i

src/CMakeFiles/ropesim.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ropesim.dir/application.cpp.s"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment8/src/application.cpp -o CMakeFiles/ropesim.dir/application.cpp.s

src/CMakeFiles/ropesim.dir/application.cpp.o.requires:

.PHONY : src/CMakeFiles/ropesim.dir/application.cpp.o.requires

src/CMakeFiles/ropesim.dir/application.cpp.o.provides: src/CMakeFiles/ropesim.dir/application.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ropesim.dir/build.make src/CMakeFiles/ropesim.dir/application.cpp.o.provides.build
.PHONY : src/CMakeFiles/ropesim.dir/application.cpp.o.provides

src/CMakeFiles/ropesim.dir/application.cpp.o.provides.build: src/CMakeFiles/ropesim.dir/application.cpp.o


src/CMakeFiles/ropesim.dir/main.cpp.o: src/CMakeFiles/ropesim.dir/flags.make
src/CMakeFiles/ropesim.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ropesim.dir/main.cpp.o"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ropesim.dir/main.cpp.o -c /home/cs18/Desktop/Homework/Assignment8/src/main.cpp

src/CMakeFiles/ropesim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ropesim.dir/main.cpp.i"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment8/src/main.cpp > CMakeFiles/ropesim.dir/main.cpp.i

src/CMakeFiles/ropesim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ropesim.dir/main.cpp.s"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment8/src/main.cpp -o CMakeFiles/ropesim.dir/main.cpp.s

src/CMakeFiles/ropesim.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/ropesim.dir/main.cpp.o.requires

src/CMakeFiles/ropesim.dir/main.cpp.o.provides: src/CMakeFiles/ropesim.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ropesim.dir/build.make src/CMakeFiles/ropesim.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/ropesim.dir/main.cpp.o.provides

src/CMakeFiles/ropesim.dir/main.cpp.o.provides.build: src/CMakeFiles/ropesim.dir/main.cpp.o


# Object files for target ropesim
ropesim_OBJECTS = \
"CMakeFiles/ropesim.dir/rope.cpp.o" \
"CMakeFiles/ropesim.dir/application.cpp.o" \
"CMakeFiles/ropesim.dir/main.cpp.o"

# External object files for target ropesim
ropesim_EXTERNAL_OBJECTS =

ropesim: src/CMakeFiles/ropesim.dir/rope.cpp.o
ropesim: src/CMakeFiles/ropesim.dir/application.cpp.o
ropesim: src/CMakeFiles/ropesim.dir/main.cpp.o
ropesim: src/CMakeFiles/ropesim.dir/build.make
ropesim: CGL/src/libCGL.a
ropesim: CGL/deps/glew/libglew.a
ropesim: CGL/deps/glfw/src/libglfw3.a
ropesim: /usr/lib/x86_64-linux-gnu/libX11.so
ropesim: /usr/lib/x86_64-linux-gnu/libXrandr.so
ropesim: /usr/lib/x86_64-linux-gnu/libXinerama.so
ropesim: /usr/lib/x86_64-linux-gnu/libXi.so
ropesim: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
ropesim: /usr/lib/x86_64-linux-gnu/librt.so
ropesim: /usr/lib/x86_64-linux-gnu/libm.so
ropesim: /usr/lib/x86_64-linux-gnu/libXcursor.so
ropesim: /usr/lib/x86_64-linux-gnu/libGL.so
ropesim: /usr/lib/x86_64-linux-gnu/libGL.so
ropesim: /usr/lib/x86_64-linux-gnu/libGLU.so
ropesim: /usr/lib/x86_64-linux-gnu/libfreetype.so
ropesim: src/CMakeFiles/ropesim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs18/Desktop/Homework/Assignment8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../ropesim"
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ropesim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ropesim.dir/build: ropesim

.PHONY : src/CMakeFiles/ropesim.dir/build

src/CMakeFiles/ropesim.dir/requires: src/CMakeFiles/ropesim.dir/rope.cpp.o.requires
src/CMakeFiles/ropesim.dir/requires: src/CMakeFiles/ropesim.dir/application.cpp.o.requires
src/CMakeFiles/ropesim.dir/requires: src/CMakeFiles/ropesim.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/ropesim.dir/requires

src/CMakeFiles/ropesim.dir/clean:
	cd /home/cs18/Desktop/Homework/Assignment8/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ropesim.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ropesim.dir/clean

src/CMakeFiles/ropesim.dir/depend:
	cd /home/cs18/Desktop/Homework/Assignment8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs18/Desktop/Homework/Assignment8 /home/cs18/Desktop/Homework/Assignment8/src /home/cs18/Desktop/Homework/Assignment8/build /home/cs18/Desktop/Homework/Assignment8/build/src /home/cs18/Desktop/Homework/Assignment8/build/src/CMakeFiles/ropesim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ropesim.dir/depend

