# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/colin/Documents/Coding/codeSample/code-sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/colin/Documents/Coding/codeSample/code-sample/build

# Include any dependencies generated for this target.
include CMakeFiles/CodeSample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CodeSample.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CodeSample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CodeSample.dir/flags.make

CMakeFiles/CodeSample.dir/src/Object.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/Object.cpp.o: ../src/Object.cpp
CMakeFiles/CodeSample.dir/src/Object.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CodeSample.dir/src/Object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/Object.cpp.o -MF CMakeFiles/CodeSample.dir/src/Object.cpp.o.d -o CMakeFiles/CodeSample.dir/src/Object.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/Object.cpp

CMakeFiles/CodeSample.dir/src/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/Object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/Object.cpp > CMakeFiles/CodeSample.dir/src/Object.cpp.i

CMakeFiles/CodeSample.dir/src/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/Object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/Object.cpp -o CMakeFiles/CodeSample.dir/src/Object.cpp.s

CMakeFiles/CodeSample.dir/src/Plane.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/Plane.cpp.o: ../src/Plane.cpp
CMakeFiles/CodeSample.dir/src/Plane.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CodeSample.dir/src/Plane.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/Plane.cpp.o -MF CMakeFiles/CodeSample.dir/src/Plane.cpp.o.d -o CMakeFiles/CodeSample.dir/src/Plane.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/Plane.cpp

CMakeFiles/CodeSample.dir/src/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/Plane.cpp > CMakeFiles/CodeSample.dir/src/Plane.cpp.i

CMakeFiles/CodeSample.dir/src/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/Plane.cpp -o CMakeFiles/CodeSample.dir/src/Plane.cpp.s

CMakeFiles/CodeSample.dir/src/Scene.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/Scene.cpp.o: ../src/Scene.cpp
CMakeFiles/CodeSample.dir/src/Scene.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CodeSample.dir/src/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/Scene.cpp.o -MF CMakeFiles/CodeSample.dir/src/Scene.cpp.o.d -o CMakeFiles/CodeSample.dir/src/Scene.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/Scene.cpp

CMakeFiles/CodeSample.dir/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/Scene.cpp > CMakeFiles/CodeSample.dir/src/Scene.cpp.i

CMakeFiles/CodeSample.dir/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/Scene.cpp -o CMakeFiles/CodeSample.dir/src/Scene.cpp.s

CMakeFiles/CodeSample.dir/src/Shaders.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/Shaders.cpp.o: ../src/Shaders.cpp
CMakeFiles/CodeSample.dir/src/Shaders.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CodeSample.dir/src/Shaders.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/Shaders.cpp.o -MF CMakeFiles/CodeSample.dir/src/Shaders.cpp.o.d -o CMakeFiles/CodeSample.dir/src/Shaders.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/Shaders.cpp

CMakeFiles/CodeSample.dir/src/Shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/Shaders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/Shaders.cpp > CMakeFiles/CodeSample.dir/src/Shaders.cpp.i

CMakeFiles/CodeSample.dir/src/Shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/Shaders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/Shaders.cpp -o CMakeFiles/CodeSample.dir/src/Shaders.cpp.s

CMakeFiles/CodeSample.dir/src/Window.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/Window.cpp.o: ../src/Window.cpp
CMakeFiles/CodeSample.dir/src/Window.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CodeSample.dir/src/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/Window.cpp.o -MF CMakeFiles/CodeSample.dir/src/Window.cpp.o.d -o CMakeFiles/CodeSample.dir/src/Window.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/Window.cpp

CMakeFiles/CodeSample.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/Window.cpp > CMakeFiles/CodeSample.dir/src/Window.cpp.i

CMakeFiles/CodeSample.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/Window.cpp -o CMakeFiles/CodeSample.dir/src/Window.cpp.s

CMakeFiles/CodeSample.dir/src/driver.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/driver.cpp.o: ../src/driver.cpp
CMakeFiles/CodeSample.dir/src/driver.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CodeSample.dir/src/driver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/driver.cpp.o -MF CMakeFiles/CodeSample.dir/src/driver.cpp.o.d -o CMakeFiles/CodeSample.dir/src/driver.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/driver.cpp

CMakeFiles/CodeSample.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/driver.cpp > CMakeFiles/CodeSample.dir/src/driver.cpp.i

CMakeFiles/CodeSample.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/driver.cpp -o CMakeFiles/CodeSample.dir/src/driver.cpp.s

CMakeFiles/CodeSample.dir/src/image_loader.cpp.o: CMakeFiles/CodeSample.dir/flags.make
CMakeFiles/CodeSample.dir/src/image_loader.cpp.o: ../src/image_loader.cpp
CMakeFiles/CodeSample.dir/src/image_loader.cpp.o: CMakeFiles/CodeSample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CodeSample.dir/src/image_loader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CodeSample.dir/src/image_loader.cpp.o -MF CMakeFiles/CodeSample.dir/src/image_loader.cpp.o.d -o CMakeFiles/CodeSample.dir/src/image_loader.cpp.o -c /home/colin/Documents/Coding/codeSample/code-sample/src/image_loader.cpp

CMakeFiles/CodeSample.dir/src/image_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CodeSample.dir/src/image_loader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colin/Documents/Coding/codeSample/code-sample/src/image_loader.cpp > CMakeFiles/CodeSample.dir/src/image_loader.cpp.i

CMakeFiles/CodeSample.dir/src/image_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CodeSample.dir/src/image_loader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colin/Documents/Coding/codeSample/code-sample/src/image_loader.cpp -o CMakeFiles/CodeSample.dir/src/image_loader.cpp.s

# Object files for target CodeSample
CodeSample_OBJECTS = \
"CMakeFiles/CodeSample.dir/src/Object.cpp.o" \
"CMakeFiles/CodeSample.dir/src/Plane.cpp.o" \
"CMakeFiles/CodeSample.dir/src/Scene.cpp.o" \
"CMakeFiles/CodeSample.dir/src/Shaders.cpp.o" \
"CMakeFiles/CodeSample.dir/src/Window.cpp.o" \
"CMakeFiles/CodeSample.dir/src/driver.cpp.o" \
"CMakeFiles/CodeSample.dir/src/image_loader.cpp.o"

# External object files for target CodeSample
CodeSample_EXTERNAL_OBJECTS =

CodeSample: CMakeFiles/CodeSample.dir/src/Object.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/Plane.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/Scene.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/Shaders.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/Window.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/driver.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/src/image_loader.cpp.o
CodeSample: CMakeFiles/CodeSample.dir/build.make
CodeSample: /usr/lib/x86_64-linux-gnu/libglfw.so
CodeSample: /usr/lib/x86_64-linux-gnu/libXrandr.so
CodeSample: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
CodeSample: /usr/lib/x86_64-linux-gnu/libXcursor.so
CodeSample: /usr/lib/x86_64-linux-gnu/libXinerama.so
CodeSample: /usr/lib/x86_64-linux-gnu/libGLEW.so
CodeSample: /usr/lib/x86_64-linux-gnu/libOpenGL.so
CodeSample: /usr/lib/x86_64-linux-gnu/libGLX.so
CodeSample: /usr/lib/x86_64-linux-gnu/libGLU.so
CodeSample: CMakeFiles/CodeSample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable CodeSample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CodeSample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CodeSample.dir/build: CodeSample
.PHONY : CMakeFiles/CodeSample.dir/build

CMakeFiles/CodeSample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CodeSample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CodeSample.dir/clean

CMakeFiles/CodeSample.dir/depend:
	cd /home/colin/Documents/Coding/codeSample/code-sample/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/colin/Documents/Coding/codeSample/code-sample /home/colin/Documents/Coding/codeSample/code-sample /home/colin/Documents/Coding/codeSample/code-sample/build /home/colin/Documents/Coding/codeSample/code-sample/build /home/colin/Documents/Coding/codeSample/code-sample/build/CMakeFiles/CodeSample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CodeSample.dir/depend

