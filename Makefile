# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Git-Clones\Sean Spagt"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Git-Clones\Sean Spagt"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "E:\Git-Clones\Sean Spagt\CMakeFiles" "E:\Git-Clones\Sean Spagt\CMakeFiles\progress.marks"
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "E:\Git-Clones\Sean Spagt\CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named testProject

# Build rule for target.
testProject: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 testProject
.PHONY : testProject

# fast build rule for target.
testProject/fast:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/build
.PHONY : testProject/fast

CPPRPG/Character.obj: CPPRPG/Character.cpp.obj

.PHONY : CPPRPG/Character.obj

# target to build an object file
CPPRPG/Character.cpp.obj:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Character.cpp.obj
.PHONY : CPPRPG/Character.cpp.obj

CPPRPG/Character.i: CPPRPG/Character.cpp.i

.PHONY : CPPRPG/Character.i

# target to preprocess a source file
CPPRPG/Character.cpp.i:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Character.cpp.i
.PHONY : CPPRPG/Character.cpp.i

CPPRPG/Character.s: CPPRPG/Character.cpp.s

.PHONY : CPPRPG/Character.s

# target to generate assembly for a file
CPPRPG/Character.cpp.s:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Character.cpp.s
.PHONY : CPPRPG/Character.cpp.s

CPPRPG/Inventory.obj: CPPRPG/Inventory.cpp.obj

.PHONY : CPPRPG/Inventory.obj

# target to build an object file
CPPRPG/Inventory.cpp.obj:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Inventory.cpp.obj
.PHONY : CPPRPG/Inventory.cpp.obj

CPPRPG/Inventory.i: CPPRPG/Inventory.cpp.i

.PHONY : CPPRPG/Inventory.i

# target to preprocess a source file
CPPRPG/Inventory.cpp.i:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Inventory.cpp.i
.PHONY : CPPRPG/Inventory.cpp.i

CPPRPG/Inventory.s: CPPRPG/Inventory.cpp.s

.PHONY : CPPRPG/Inventory.s

# target to generate assembly for a file
CPPRPG/Inventory.cpp.s:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Inventory.cpp.s
.PHONY : CPPRPG/Inventory.cpp.s

CPPRPG/Item.obj: CPPRPG/Item.cpp.obj

.PHONY : CPPRPG/Item.obj

# target to build an object file
CPPRPG/Item.cpp.obj:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Item.cpp.obj
.PHONY : CPPRPG/Item.cpp.obj

CPPRPG/Item.i: CPPRPG/Item.cpp.i

.PHONY : CPPRPG/Item.i

# target to preprocess a source file
CPPRPG/Item.cpp.i:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Item.cpp.i
.PHONY : CPPRPG/Item.cpp.i

CPPRPG/Item.s: CPPRPG/Item.cpp.s

.PHONY : CPPRPG/Item.s

# target to generate assembly for a file
CPPRPG/Item.cpp.s:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Item.cpp.s
.PHONY : CPPRPG/Item.cpp.s

CPPRPG/Main.obj: CPPRPG/Main.cpp.obj

.PHONY : CPPRPG/Main.obj

# target to build an object file
CPPRPG/Main.cpp.obj:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Main.cpp.obj
.PHONY : CPPRPG/Main.cpp.obj

CPPRPG/Main.i: CPPRPG/Main.cpp.i

.PHONY : CPPRPG/Main.i

# target to preprocess a source file
CPPRPG/Main.cpp.i:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Main.cpp.i
.PHONY : CPPRPG/Main.cpp.i

CPPRPG/Main.s: CPPRPG/Main.cpp.s

.PHONY : CPPRPG/Main.s

# target to generate assembly for a file
CPPRPG/Main.cpp.s:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Main.cpp.s
.PHONY : CPPRPG/Main.cpp.s

CPPRPG/Weapon.obj: CPPRPG/Weapon.cpp.obj

.PHONY : CPPRPG/Weapon.obj

# target to build an object file
CPPRPG/Weapon.cpp.obj:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Weapon.cpp.obj
.PHONY : CPPRPG/Weapon.cpp.obj

CPPRPG/Weapon.i: CPPRPG/Weapon.cpp.i

.PHONY : CPPRPG/Weapon.i

# target to preprocess a source file
CPPRPG/Weapon.cpp.i:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Weapon.cpp.i
.PHONY : CPPRPG/Weapon.cpp.i

CPPRPG/Weapon.s: CPPRPG/Weapon.cpp.s

.PHONY : CPPRPG/Weapon.s

# target to generate assembly for a file
CPPRPG/Weapon.cpp.s:
	$(MAKE) -f CMakeFiles\testProject.dir\build.make CMakeFiles/testProject.dir/CPPRPG/Weapon.cpp.s
.PHONY : CPPRPG/Weapon.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... testProject
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... CPPRPG/Character.obj
	@echo ... CPPRPG/Character.i
	@echo ... CPPRPG/Character.s
	@echo ... CPPRPG/Inventory.obj
	@echo ... CPPRPG/Inventory.i
	@echo ... CPPRPG/Inventory.s
	@echo ... CPPRPG/Item.obj
	@echo ... CPPRPG/Item.i
	@echo ... CPPRPG/Item.s
	@echo ... CPPRPG/Main.obj
	@echo ... CPPRPG/Main.i
	@echo ... CPPRPG/Main.s
	@echo ... CPPRPG/Weapon.obj
	@echo ... CPPRPG/Weapon.i
	@echo ... CPPRPG/Weapon.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system
