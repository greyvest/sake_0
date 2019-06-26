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

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.14.5/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\" \"assimp-dev\" \"libassimp4.1.0\" \"libassimp4.1.0-dev\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

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
# Target rules for targets named imgui

# Build rule for target.
imgui: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 imgui
.PHONY : imgui

# fast build rule for target.
imgui/fast:
	$(MAKE) -f src/imgui/CMakeFiles/imgui.dir/build.make src/imgui/CMakeFiles/imgui.dir/build
.PHONY : imgui/fast

#=============================================================================
# Target rules for targets named uninstall

# Build rule for target.
uninstall: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uninstall
.PHONY : uninstall

# fast build rule for target.
uninstall/fast:
	$(MAKE) -f libs/assimp/CMakeFiles/uninstall.dir/build.make libs/assimp/CMakeFiles/uninstall.dir/build
.PHONY : uninstall/fast

#=============================================================================
# Target rules for targets named IrrXML

# Build rule for target.
IrrXML: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 IrrXML
.PHONY : IrrXML

# fast build rule for target.
IrrXML/fast:
	$(MAKE) -f libs/assimp/contrib/irrXML/CMakeFiles/IrrXML.dir/build.make libs/assimp/contrib/irrXML/CMakeFiles/IrrXML.dir/build
.PHONY : IrrXML/fast

#=============================================================================
# Target rules for targets named assimp

# Build rule for target.
assimp: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 assimp
.PHONY : assimp

# fast build rule for target.
assimp/fast:
	$(MAKE) -f libs/assimp/code/CMakeFiles/assimp.dir/build.make libs/assimp/code/CMakeFiles/assimp.dir/build
.PHONY : assimp/fast

#=============================================================================
# Target rules for targets named unit

# Build rule for target.
unit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 unit
.PHONY : unit

# fast build rule for target.
unit/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/unit.dir/build.make libs/assimp/test/CMakeFiles/unit.dir/build
.PHONY : unit/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousCoverage.dir/build.make libs/assimp/test/CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousTest.dir/build.make libs/assimp/test/CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousBuild.dir/build.make libs/assimp/test/CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousStart.dir/build.make libs/assimp/test/CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalBuild.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalCoverage.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalSubmit.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousUpdate.dir/build.make libs/assimp/test/CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalUpdate.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalStart.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousSubmit.dir/build.make libs/assimp/test/CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalTest.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlySubmit.dir/build.make libs/assimp/test/CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyMemCheck.dir/build.make libs/assimp/test/CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalConfigure.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyCoverage.dir/build.make libs/assimp/test/CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyTest.dir/build.make libs/assimp/test/CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousMemCheck.dir/build.make libs/assimp/test/CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyBuild.dir/build.make libs/assimp/test/CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyConfigure.dir/build.make libs/assimp/test/CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyUpdate.dir/build.make libs/assimp/test/CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyMemoryCheck.dir/build.make libs/assimp/test/CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ContinuousConfigure.dir/build.make libs/assimp/test/CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/Nightly.dir/build.make libs/assimp/test/CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/NightlyStart.dir/build.make libs/assimp/test/CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/ExperimentalMemCheck.dir/build.make libs/assimp/test/CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/Continuous.dir/build.make libs/assimp/test/CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) -f libs/assimp/test/CMakeFiles/Experimental.dir/build.make libs/assimp/test/CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

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

src/model.o: src/model.cpp.o

.PHONY : src/model.o

# target to build an object file
src/model.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/model.cpp.o
.PHONY : src/model.cpp.o

src/model.i: src/model.cpp.i

.PHONY : src/model.i

# target to preprocess a source file
src/model.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/model.cpp.i
.PHONY : src/model.cpp.i

src/model.s: src/model.cpp.s

.PHONY : src/model.s

# target to generate assembly for a file
src/model.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/model.cpp.s
.PHONY : src/model.cpp.s

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

src/shadowMap.o: src/shadowMap.cpp.o

.PHONY : src/shadowMap.o

# target to build an object file
src/shadowMap.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shadowMap.cpp.o
.PHONY : src/shadowMap.cpp.o

src/shadowMap.i: src/shadowMap.cpp.i

.PHONY : src/shadowMap.i

# target to preprocess a source file
src/shadowMap.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shadowMap.cpp.i
.PHONY : src/shadowMap.cpp.i

src/shadowMap.s: src/shadowMap.cpp.s

.PHONY : src/shadowMap.s

# target to generate assembly for a file
src/shadowMap.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/shadowMap.cpp.s
.PHONY : src/shadowMap.cpp.s

src/spotLight.o: src/spotLight.cpp.o

.PHONY : src/spotLight.o

# target to build an object file
src/spotLight.cpp.o:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/spotLight.cpp.o
.PHONY : src/spotLight.cpp.o

src/spotLight.i: src/spotLight.cpp.i

.PHONY : src/spotLight.i

# target to preprocess a source file
src/spotLight.cpp.i:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/spotLight.cpp.i
.PHONY : src/spotLight.cpp.i

src/spotLight.s: src/spotLight.cpp.s

.PHONY : src/spotLight.s

# target to generate assembly for a file
src/spotLight.cpp.s:
	$(MAKE) -f CMakeFiles/sake.dir/build.make CMakeFiles/sake.dir/src/spotLight.cpp.s
.PHONY : src/spotLight.cpp.s

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
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... sake"
	@echo "... edit_cache"
	@echo "... run"
	@echo "... imgui"
	@echo "... uninstall"
	@echo "... IrrXML"
	@echo "... assimp"
	@echo "... unit"
	@echo "... ContinuousCoverage"
	@echo "... ContinuousTest"
	@echo "... ContinuousBuild"
	@echo "... ContinuousStart"
	@echo "... ExperimentalBuild"
	@echo "... ExperimentalCoverage"
	@echo "... ExperimentalSubmit"
	@echo "... ContinuousUpdate"
	@echo "... ExperimentalUpdate"
	@echo "... ExperimentalStart"
	@echo "... ContinuousSubmit"
	@echo "... ExperimentalTest"
	@echo "... NightlySubmit"
	@echo "... NightlyMemCheck"
	@echo "... ExperimentalConfigure"
	@echo "... NightlyCoverage"
	@echo "... NightlyTest"
	@echo "... ContinuousMemCheck"
	@echo "... NightlyBuild"
	@echo "... NightlyConfigure"
	@echo "... NightlyUpdate"
	@echo "... NightlyMemoryCheck"
	@echo "... ContinuousConfigure"
	@echo "... Nightly"
	@echo "... NightlyStart"
	@echo "... ExperimentalMemCheck"
	@echo "... Continuous"
	@echo "... Experimental"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/directionalLight.o"
	@echo "... src/directionalLight.i"
	@echo "... src/directionalLight.s"
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
	@echo "... src/model.o"
	@echo "... src/model.i"
	@echo "... src/model.s"
	@echo "... src/object.o"
	@echo "... src/object.i"
	@echo "... src/object.s"
	@echo "... src/pointLight.o"
	@echo "... src/pointLight.i"
	@echo "... src/pointLight.s"
	@echo "... src/shader.o"
	@echo "... src/shader.i"
	@echo "... src/shader.s"
	@echo "... src/shadowMap.o"
	@echo "... src/shadowMap.i"
	@echo "... src/shadowMap.s"
	@echo "... src/spotLight.o"
	@echo "... src/spotLight.i"
	@echo "... src/spotLight.s"
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

