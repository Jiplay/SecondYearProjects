# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build

# Include any dependencies generated for this target.
include CMakeFiles/_arcade_sdl2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_arcade_sdl2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_arcade_sdl2.dir/flags.make

CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o: CMakeFiles/_arcade_sdl2.dir/flags.make
CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o: ../lib/SLD2/SDL2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o -c /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/lib/SLD2/SDL2.cpp

CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/lib/SLD2/SDL2.cpp > CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.i

CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/lib/SLD2/SDL2.cpp -o CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.s

# Object files for target _arcade_sdl2
_arcade_sdl2_OBJECTS = \
"CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o"

# External object files for target _arcade_sdl2
_arcade_sdl2_EXTERNAL_OBJECTS =

../libs/lib_arcade_sdl2.so: CMakeFiles/_arcade_sdl2.dir/lib/SLD2/SDL2.cpp.o
../libs/lib_arcade_sdl2.so: CMakeFiles/_arcade_sdl2.dir/build.make
../libs/lib_arcade_sdl2.so: CMakeFiles/_arcade_sdl2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../libs/lib_arcade_sdl2.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_arcade_sdl2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_arcade_sdl2.dir/build: ../libs/lib_arcade_sdl2.so

.PHONY : CMakeFiles/_arcade_sdl2.dir/build

CMakeFiles/_arcade_sdl2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_arcade_sdl2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_arcade_sdl2.dir/clean

CMakeFiles/_arcade_sdl2.dir/depend:
	cd /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build /workspace/EPITECH/Delivery/2yearbis/OOP/B-OOP-400-PAR-4-1-arcade-ibrahim.zafar/build/CMakeFiles/_arcade_sdl2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_arcade_sdl2.dir/depend

