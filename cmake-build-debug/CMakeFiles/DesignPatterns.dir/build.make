# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dbogacz\CLionProjects\DesignPatterns

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DesignPatterns.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DesignPatterns.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DesignPatterns.dir/flags.make

CMakeFiles/DesignPatterns.dir/Prototype.cpp.obj: CMakeFiles/DesignPatterns.dir/flags.make
CMakeFiles/DesignPatterns.dir/Prototype.cpp.obj: ../Prototype.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DesignPatterns.dir/Prototype.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DesignPatterns.dir\Prototype.cpp.obj -c C:\Users\dbogacz\CLionProjects\DesignPatterns\Prototype.cpp

CMakeFiles/DesignPatterns.dir/Prototype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignPatterns.dir/Prototype.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbogacz\CLionProjects\DesignPatterns\Prototype.cpp > CMakeFiles\DesignPatterns.dir\Prototype.cpp.i

CMakeFiles/DesignPatterns.dir/Prototype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignPatterns.dir/Prototype.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\dbogacz\CLionProjects\DesignPatterns\Prototype.cpp -o CMakeFiles\DesignPatterns.dir\Prototype.cpp.s

# Object files for target DesignPatterns
DesignPatterns_OBJECTS = \
"CMakeFiles/DesignPatterns.dir/Prototype.cpp.obj"

# External object files for target DesignPatterns
DesignPatterns_EXTERNAL_OBJECTS =

DesignPatterns.exe: CMakeFiles/DesignPatterns.dir/Prototype.cpp.obj
DesignPatterns.exe: CMakeFiles/DesignPatterns.dir/build.make
DesignPatterns.exe: CMakeFiles/DesignPatterns.dir/linklibs.rsp
DesignPatterns.exe: CMakeFiles/DesignPatterns.dir/objects1.rsp
DesignPatterns.exe: CMakeFiles/DesignPatterns.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DesignPatterns.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DesignPatterns.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DesignPatterns.dir/build: DesignPatterns.exe

.PHONY : CMakeFiles/DesignPatterns.dir/build

CMakeFiles/DesignPatterns.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DesignPatterns.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DesignPatterns.dir/clean

CMakeFiles/DesignPatterns.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dbogacz\CLionProjects\DesignPatterns C:\Users\dbogacz\CLionProjects\DesignPatterns C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug C:\Users\dbogacz\CLionProjects\DesignPatterns\cmake-build-debug\CMakeFiles\DesignPatterns.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DesignPatterns.dir/depend

