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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chanukaabeysinghe/CLionProjects/PokerCardGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PokerCardGame.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PokerCardGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PokerCardGame.dir/flags.make

CMakeFiles/PokerCardGame.dir/main.cpp.o: CMakeFiles/PokerCardGame.dir/flags.make
CMakeFiles/PokerCardGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PokerCardGame.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PokerCardGame.dir/main.cpp.o -c /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/main.cpp

CMakeFiles/PokerCardGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PokerCardGame.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/main.cpp > CMakeFiles/PokerCardGame.dir/main.cpp.i

CMakeFiles/PokerCardGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PokerCardGame.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/main.cpp -o CMakeFiles/PokerCardGame.dir/main.cpp.s

# Object files for target PokerCardGame
PokerCardGame_OBJECTS = \
"CMakeFiles/PokerCardGame.dir/main.cpp.o"

# External object files for target PokerCardGame
PokerCardGame_EXTERNAL_OBJECTS =

PokerCardGame: CMakeFiles/PokerCardGame.dir/main.cpp.o
PokerCardGame: CMakeFiles/PokerCardGame.dir/build.make
PokerCardGame: CMakeFiles/PokerCardGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PokerCardGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PokerCardGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PokerCardGame.dir/build: PokerCardGame
.PHONY : CMakeFiles/PokerCardGame.dir/build

CMakeFiles/PokerCardGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PokerCardGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PokerCardGame.dir/clean

CMakeFiles/PokerCardGame.dir/depend:
	cd /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chanukaabeysinghe/CLionProjects/PokerCardGame /Users/chanukaabeysinghe/CLionProjects/PokerCardGame /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug /Users/chanukaabeysinghe/CLionProjects/PokerCardGame/cmake-build-debug/CMakeFiles/PokerCardGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PokerCardGame.dir/depend

