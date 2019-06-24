# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/u0964759/sake_0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/u0964759/sake_0

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.14.5/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/u0964759/sake_0/CMakeFiles /Users/u0964759/sake_0/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/u0964759/sake_0/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named run

# Build rule for target.
run: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 run
.PHONY : run

# fast build rule for target.
run/fast:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/build
.PHONY : run/fast

#=============================================================================
# Target rules for targets named sake

# Build rule for target.
sake: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sake
.PHONY : sake

# fast build rule for target.
sake/fast:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/build
.PHONY : sake/fast

#=============================================================================
# Target rules for targets named imgui

# Build rule for target.
imgui: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 imgui
.PHONY : imgui

# fast build rule for target.
imgui/fast:
	$(MAKE) -f src/imgui/CMakeFiles/imgui.dir/build.make src/imgui/CMakeFiles/imgui.dir/build
.PHONY : imgui/fast

src/camera.o: src/camera.cpp.o

.PHONY : src/camera.o

# target to build an object file
src/camera.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/camera.cpp.o
.PHONY : src/camera.cpp.o

src/camera.i: src/camera.cpp.i

.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s

.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/directionalLight.o: src/directionalLight.cpp.o

.PHONY : src/directionalLight.o

# target to build an object file
src/directionalLight.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/directionalLight.cpp.o
.PHONY : src/directionalLight.cpp.o

src/directionalLight.i: src/directionalLight.cpp.i

.PHONY : src/directionalLight.i

# target to preprocess a source file
src/directionalLight.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/directionalLight.cpp.i
.PHONY : src/directionalLight.cpp.i

src/directionalLight.s: src/directionalLight.cpp.s

.PHONY : src/directionalLight.s

# target to generate assembly for a file
src/directionalLight.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/directionalLight.cpp.s
.PHONY : src/directionalLight.cpp.s

src/level.o: src/level.cpp.o

.PHONY : src/level.o

# target to build an object file
src/level.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/level.cpp.o
.PHONY : src/level.cpp.o

src/level.i: src/level.cpp.i

.PHONY : src/level.i

# target to preprocess a source file
src/level.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/level.cpp.i
.PHONY : src/level.cpp.i

src/level.s: src/level.cpp.s

.PHONY : src/level.s

# target to generate assembly for a file
src/level.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/level.cpp.s
.PHONY : src/level.cpp.s

src/light.o: src/light.cpp.o

.PHONY : src/light.o

# target to build an object file
src/light.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/light.cpp.o
.PHONY : src/light.cpp.o

src/light.i: src/light.cpp.i

.PHONY : src/light.i

# target to preprocess a source file
src/light.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/light.cpp.i
.PHONY : src/light.cpp.i

src/light.s: src/light.cpp.s

.PHONY : src/light.s

# target to generate assembly for a file
src/light.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/light.cpp.s
.PHONY : src/light.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/material.o: src/material.cpp.o

.PHONY : src/material.o

# target to build an object file
src/material.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/material.cpp.o
.PHONY : src/material.cpp.o

src/material.i: src/material.cpp.i

.PHONY : src/material.i

# target to preprocess a source file
src/material.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/material.cpp.i
.PHONY : src/material.cpp.i

src/material.s: src/material.cpp.s

.PHONY : src/material.s

# target to generate assembly for a file
src/material.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/material.cpp.s
.PHONY : src/material.cpp.s

src/mesh.o: src/mesh.cpp.o

.PHONY : src/mesh.o

# target to build an object file
src/mesh.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/mesh.cpp.o
.PHONY : src/mesh.cpp.o

src/mesh.i: src/mesh.cpp.i

.PHONY : src/mesh.i

# target to preprocess a source file
src/mesh.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/mesh.cpp.i
.PHONY : src/mesh.cpp.i

src/mesh.s: src/mesh.cpp.s

.PHONY : src/mesh.s

# target to generate assembly for a file
src/mesh.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/mesh.cpp.s
.PHONY : src/mesh.cpp.s

src/object.o: src/object.cpp.o

.PHONY : src/object.o

# target to build an object file
src/object.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/object.cpp.o
.PHONY : src/object.cpp.o

src/object.i: src/object.cpp.i

.PHONY : src/object.i

# target to preprocess a source file
src/object.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/object.cpp.i
.PHONY : src/object.cpp.i

src/object.s: src/object.cpp.s

.PHONY : src/object.s

# target to generate assembly for a file
src/object.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/object.cpp.s
.PHONY : src/object.cpp.s

src/pointLight.o: src/pointLight.cpp.o

.PHONY : src/pointLight.o

# target to build an object file
src/pointLight.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/pointLight.cpp.o
.PHONY : src/pointLight.cpp.o

src/pointLight.i: src/pointLight.cpp.i

.PHONY : src/pointLight.i

# target to preprocess a source file
src/pointLight.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/pointLight.cpp.i
.PHONY : src/pointLight.cpp.i

src/pointLight.s: src/pointLight.cpp.s

.PHONY : src/pointLight.s

# target to generate assembly for a file
src/pointLight.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/pointLight.cpp.s
.PHONY : src/pointLight.cpp.s

src/shader.o: src/shader.cpp.o

.PHONY : src/shader.o

# target to build an object file
src/shader.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shader.cpp.o
.PHONY : src/shader.cpp.o

src/shader.i: src/shader.cpp.i

.PHONY : src/shader.i

# target to preprocess a source file
src/shader.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shader.cpp.i
.PHONY : src/shader.cpp.i

src/shader.s: src/shader.cpp.s

.PHONY : src/shader.s

# target to generate assembly for a file
src/shader.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shader.cpp.s
.PHONY : src/shader.cpp.s

src/texture.o: src/texture.cpp.o

.PHONY : src/texture.o

# target to build an object file
src/texture.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/texture.cpp.o
.PHONY : src/texture.cpp.o

src/texture.i: src/texture.cpp.i

.PHONY : src/texture.i

# target to preprocess a source file
src/texture.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/texture.cpp.i
.PHONY : src/texture.cpp.i

src/texture.s: src/texture.cpp.s

.PHONY : src/texture.s

# target to generate assembly for a file
src/texture.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/texture.cpp.s
.PHONY : src/texture.cpp.s

src/window.o: src/window.cpp.o

.PHONY : src/window.o

# target to build an object file
src/window.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/window.cpp.o
.PHONY : src/window.cpp.o

src/window.i: src/window.cpp.i

.PHONY : src/window.i

# target to preprocess a source file
src/window.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/window.cpp.i
.PHONY : src/window.cpp.i

src/window.s: src/window.cpp.s

.PHONY : src/window.s

# target to generate assembly for a file
src/window.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/window.cpp.s
.PHONY : src/window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... run"
	@echo "... sake"
	@echo "... imgui"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/directionalLight.o"
	@echo "... src/directionalLight.i"
	@echo "... src/directionalLight.s"
	@echo "... src/level.o"
	@echo "... src/level.i"
	@echo "... src/level.s"
	@echo "... src/light.o"
	@echo "... src/light.i"
	@echo "... src/light.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/material.o"
	@echo "... src/material.i"
	@echo "... src/material.s"
	@echo "... src/mesh.o"
	@echo "... src/mesh.i"
	@echo "... src/mesh.s"
	@echo "... src/object.o"
	@echo "... src/object.i"
	@echo "... src/object.s"
	@echo "... src/pointLight.o"
	@echo "... src/pointLight.i"
	@echo "... src/pointLight.s"
	@echo "... src/shader.o"
	@echo "... src/shader.i"
	@echo "... src/shader.s"
	@echo "... src/texture.o"
	@echo "... src/texture.i"
	@echo "... src/texture.s"
	@echo "... src/window.o"
	@echo "... src/window.i"
	@echo "... src/window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

