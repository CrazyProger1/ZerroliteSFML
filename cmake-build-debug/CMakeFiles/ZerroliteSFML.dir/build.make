# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\Programs\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\C++\Projects\ZerroliteSFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZerroliteSFML.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ZerroliteSFML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZerroliteSFML.dir/flags.make

CMakeFiles/ZerroliteSFML.dir/main.cpp.obj: CMakeFiles/ZerroliteSFML.dir/flags.make
CMakeFiles/ZerroliteSFML.dir/main.cpp.obj: CMakeFiles/ZerroliteSFML.dir/includes_CXX.rsp
CMakeFiles/ZerroliteSFML.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZerroliteSFML.dir/main.cpp.obj"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ZerroliteSFML.dir\main.cpp.obj -c D:\Programming\C++\Projects\ZerroliteSFML\main.cpp

CMakeFiles/ZerroliteSFML.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZerroliteSFML.dir/main.cpp.i"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\C++\Projects\ZerroliteSFML\main.cpp > CMakeFiles\ZerroliteSFML.dir\main.cpp.i

CMakeFiles/ZerroliteSFML.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZerroliteSFML.dir/main.cpp.s"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\C++\Projects\ZerroliteSFML\main.cpp -o CMakeFiles\ZerroliteSFML.dir\main.cpp.s

CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj: CMakeFiles/ZerroliteSFML.dir/flags.make
CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj: CMakeFiles/ZerroliteSFML.dir/includes_CXX.rsp
CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj: ../zerrolite/srcs/GameCore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ZerroliteSFML.dir\zerrolite\srcs\GameCore.cpp.obj -c D:\Programming\C++\Projects\ZerroliteSFML\zerrolite\srcs\GameCore.cpp

CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.i"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\C++\Projects\ZerroliteSFML\zerrolite\srcs\GameCore.cpp > CMakeFiles\ZerroliteSFML.dir\zerrolite\srcs\GameCore.cpp.i

CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.s"
	D:\Programming\C++\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\C++\Projects\ZerroliteSFML\zerrolite\srcs\GameCore.cpp -o CMakeFiles\ZerroliteSFML.dir\zerrolite\srcs\GameCore.cpp.s

# Object files for target ZerroliteSFML
ZerroliteSFML_OBJECTS = \
"CMakeFiles/ZerroliteSFML.dir/main.cpp.obj" \
"CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj"

# External object files for target ZerroliteSFML
ZerroliteSFML_EXTERNAL_OBJECTS =

ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/main.cpp.obj
ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/zerrolite/srcs/GameCore.cpp.obj
ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/build.make
ZerroliteSFML.exe: ../libs/SFML-2.5.1/lib/libsfml-graphics-s-d.a
ZerroliteSFML.exe: ../libs/SFML-2.5.1/lib/libsfml-window-s-d.a
ZerroliteSFML.exe: ../libs/SFML-2.5.1/lib/libsfml-system-s-d.a
ZerroliteSFML.exe: ../libs/SFML-2.5.1/lib/libfreetype.a
ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/linklibs.rsp
ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/objects1.rsp
ZerroliteSFML.exe: CMakeFiles/ZerroliteSFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ZerroliteSFML.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ZerroliteSFML.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZerroliteSFML.dir/build: ZerroliteSFML.exe
.PHONY : CMakeFiles/ZerroliteSFML.dir/build

CMakeFiles/ZerroliteSFML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ZerroliteSFML.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ZerroliteSFML.dir/clean

CMakeFiles/ZerroliteSFML.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\C++\Projects\ZerroliteSFML D:\Programming\C++\Projects\ZerroliteSFML D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug D:\Programming\C++\Projects\ZerroliteSFML\cmake-build-debug\CMakeFiles\ZerroliteSFML.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZerroliteSFML.dir/depend

