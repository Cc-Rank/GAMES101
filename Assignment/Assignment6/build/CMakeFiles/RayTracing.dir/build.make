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
CMAKE_SOURCE_DIR = /home/cs18/Desktop/Homework/Assignment6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs18/Desktop/Homework/Assignment6/build

# Include any dependencies generated for this target.
include CMakeFiles/RayTracing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracing.dir/flags.make

CMakeFiles/RayTracing.dir/main.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracing.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/main.cpp.o -c /home/cs18/Desktop/Homework/Assignment6/main.cpp

CMakeFiles/RayTracing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment6/main.cpp > CMakeFiles/RayTracing.dir/main.cpp.i

CMakeFiles/RayTracing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment6/main.cpp -o CMakeFiles/RayTracing.dir/main.cpp.s

CMakeFiles/RayTracing.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.requires

CMakeFiles/RayTracing.dir/main.cpp.o.provides: CMakeFiles/RayTracing.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/main.cpp.o.provides

CMakeFiles/RayTracing.dir/main.cpp.o.provides.build: CMakeFiles/RayTracing.dir/main.cpp.o


CMakeFiles/RayTracing.dir/Vector.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Vector.cpp.o: ../Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RayTracing.dir/Vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Vector.cpp.o -c /home/cs18/Desktop/Homework/Assignment6/Vector.cpp

CMakeFiles/RayTracing.dir/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment6/Vector.cpp > CMakeFiles/RayTracing.dir/Vector.cpp.i

CMakeFiles/RayTracing.dir/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment6/Vector.cpp -o CMakeFiles/RayTracing.dir/Vector.cpp.s

CMakeFiles/RayTracing.dir/Vector.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Vector.cpp.o.requires

CMakeFiles/RayTracing.dir/Vector.cpp.o.provides: CMakeFiles/RayTracing.dir/Vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Vector.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Vector.cpp.o.provides

CMakeFiles/RayTracing.dir/Vector.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Vector.cpp.o


CMakeFiles/RayTracing.dir/Scene.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Scene.cpp.o: ../Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RayTracing.dir/Scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Scene.cpp.o -c /home/cs18/Desktop/Homework/Assignment6/Scene.cpp

CMakeFiles/RayTracing.dir/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment6/Scene.cpp > CMakeFiles/RayTracing.dir/Scene.cpp.i

CMakeFiles/RayTracing.dir/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment6/Scene.cpp -o CMakeFiles/RayTracing.dir/Scene.cpp.s

CMakeFiles/RayTracing.dir/Scene.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Scene.cpp.o.requires

CMakeFiles/RayTracing.dir/Scene.cpp.o.provides: CMakeFiles/RayTracing.dir/Scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Scene.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Scene.cpp.o.provides

CMakeFiles/RayTracing.dir/Scene.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Scene.cpp.o


CMakeFiles/RayTracing.dir/BVH.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/BVH.cpp.o: ../BVH.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RayTracing.dir/BVH.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/BVH.cpp.o -c /home/cs18/Desktop/Homework/Assignment6/BVH.cpp

CMakeFiles/RayTracing.dir/BVH.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/BVH.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment6/BVH.cpp > CMakeFiles/RayTracing.dir/BVH.cpp.i

CMakeFiles/RayTracing.dir/BVH.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/BVH.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment6/BVH.cpp -o CMakeFiles/RayTracing.dir/BVH.cpp.s

CMakeFiles/RayTracing.dir/BVH.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/BVH.cpp.o.requires

CMakeFiles/RayTracing.dir/BVH.cpp.o.provides: CMakeFiles/RayTracing.dir/BVH.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/BVH.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/BVH.cpp.o.provides

CMakeFiles/RayTracing.dir/BVH.cpp.o.provides.build: CMakeFiles/RayTracing.dir/BVH.cpp.o


CMakeFiles/RayTracing.dir/Renderer.cpp.o: CMakeFiles/RayTracing.dir/flags.make
CMakeFiles/RayTracing.dir/Renderer.cpp.o: ../Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RayTracing.dir/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracing.dir/Renderer.cpp.o -c /home/cs18/Desktop/Homework/Assignment6/Renderer.cpp

CMakeFiles/RayTracing.dir/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracing.dir/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs18/Desktop/Homework/Assignment6/Renderer.cpp > CMakeFiles/RayTracing.dir/Renderer.cpp.i

CMakeFiles/RayTracing.dir/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracing.dir/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs18/Desktop/Homework/Assignment6/Renderer.cpp -o CMakeFiles/RayTracing.dir/Renderer.cpp.s

CMakeFiles/RayTracing.dir/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/RayTracing.dir/Renderer.cpp.o.requires

CMakeFiles/RayTracing.dir/Renderer.cpp.o.provides: CMakeFiles/RayTracing.dir/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracing.dir/build.make CMakeFiles/RayTracing.dir/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracing.dir/Renderer.cpp.o.provides

CMakeFiles/RayTracing.dir/Renderer.cpp.o.provides.build: CMakeFiles/RayTracing.dir/Renderer.cpp.o


# Object files for target RayTracing
RayTracing_OBJECTS = \
"CMakeFiles/RayTracing.dir/main.cpp.o" \
"CMakeFiles/RayTracing.dir/Vector.cpp.o" \
"CMakeFiles/RayTracing.dir/Scene.cpp.o" \
"CMakeFiles/RayTracing.dir/BVH.cpp.o" \
"CMakeFiles/RayTracing.dir/Renderer.cpp.o"

# External object files for target RayTracing
RayTracing_EXTERNAL_OBJECTS =

RayTracing: CMakeFiles/RayTracing.dir/main.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Vector.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Scene.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/BVH.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/Renderer.cpp.o
RayTracing: CMakeFiles/RayTracing.dir/build.make
RayTracing: CMakeFiles/RayTracing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable RayTracing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracing.dir/build: RayTracing

.PHONY : CMakeFiles/RayTracing.dir/build

CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/main.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Vector.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Scene.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/BVH.cpp.o.requires
CMakeFiles/RayTracing.dir/requires: CMakeFiles/RayTracing.dir/Renderer.cpp.o.requires

.PHONY : CMakeFiles/RayTracing.dir/requires

CMakeFiles/RayTracing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracing.dir/clean

CMakeFiles/RayTracing.dir/depend:
	cd /home/cs18/Desktop/Homework/Assignment6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs18/Desktop/Homework/Assignment6 /home/cs18/Desktop/Homework/Assignment6 /home/cs18/Desktop/Homework/Assignment6/build /home/cs18/Desktop/Homework/Assignment6/build /home/cs18/Desktop/Homework/Assignment6/build/CMakeFiles/RayTracing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracing.dir/depend

