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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\nirma\Desktop\Computer Graphics"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nirma\Desktop\Computer Graphics\build"

# Include any dependencies generated for this target.
include glfw-3.3.8/tests/CMakeFiles/events.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw-3.3.8/tests/CMakeFiles/events.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.8/tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.8/tests/CMakeFiles/events.dir/flags.make

glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/flags.make
glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/includes_C.rsp
glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj: C:/Users/nirma/Desktop/Computer\ Graphics/glfw-3.3.8/tests/events.c
glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nirma\Desktop\Computer Graphics\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj -MF CMakeFiles\events.dir\events.c.obj.d -o CMakeFiles\events.dir\events.c.obj -c "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\tests\events.c"

glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\tests\events.c" > CMakeFiles\events.dir\events.c.i

glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\tests\events.c" -o CMakeFiles\events.dir\events.c.s

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/flags.make
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/includes_C.rsp
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: C:/Users/nirma/Desktop/Computer\ Graphics/glfw-3.3.8/deps/getopt.c
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nirma\Desktop\Computer Graphics\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj -MF CMakeFiles\events.dir\__\deps\getopt.c.obj.d -o CMakeFiles\events.dir\__\deps\getopt.c.obj -c "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\getopt.c"

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\getopt.c" > CMakeFiles\events.dir\__\deps\getopt.c.i

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\getopt.c" -o CMakeFiles\events.dir\__\deps\getopt.c.s

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/flags.make
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/includes_C.rsp
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj: C:/Users/nirma/Desktop/Computer\ Graphics/glfw-3.3.8/deps/glad_gl.c
glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj: glfw-3.3.8/tests/CMakeFiles/events.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nirma\Desktop\Computer Graphics\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\events.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\events.dir\__\deps\glad_gl.c.obj -c "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\glad_gl.c"

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\glad_gl.c" > CMakeFiles\events.dir\__\deps\glad_gl.c.i

glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\deps\glad_gl.c" -o CMakeFiles\events.dir\__\deps\glad_gl.c.s

# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.obj" \
"CMakeFiles/events.dir/__/deps/getopt.c.obj" \
"CMakeFiles/events.dir/__/deps/glad_gl.c.obj"

# External object files for target events
events_EXTERNAL_OBJECTS =

glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/events.c.obj
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/__/deps/glad_gl.c.obj
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/build.make
glfw-3.3.8/tests/events.exe: glfw-3.3.8/src/libglfw3.a
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/linklibs.rsp
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/objects1.rsp
glfw-3.3.8/tests/events.exe: glfw-3.3.8/tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nirma\Desktop\Computer Graphics\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable events.exe"
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\events.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.8/tests/CMakeFiles/events.dir/build: glfw-3.3.8/tests/events.exe
.PHONY : glfw-3.3.8/tests/CMakeFiles/events.dir/build

glfw-3.3.8/tests/CMakeFiles/events.dir/clean:
	cd /d C:\Users\nirma\Desktop\COMPUT~1\build\GLFW-3~1.8\tests && $(CMAKE_COMMAND) -P CMakeFiles\events.dir\cmake_clean.cmake
.PHONY : glfw-3.3.8/tests/CMakeFiles/events.dir/clean

glfw-3.3.8/tests/CMakeFiles/events.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nirma\Desktop\Computer Graphics" "C:\Users\nirma\Desktop\Computer Graphics\glfw-3.3.8\tests" "C:\Users\nirma\Desktop\Computer Graphics\build" "C:\Users\nirma\Desktop\Computer Graphics\build\glfw-3.3.8\tests" "C:\Users\nirma\Desktop\Computer Graphics\build\glfw-3.3.8\tests\CMakeFiles\events.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : glfw-3.3.8/tests/CMakeFiles/events.dir/depend

