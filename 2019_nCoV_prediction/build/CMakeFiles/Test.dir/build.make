# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/src/main.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/main.cpp.o -c /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/src/main.cpp

CMakeFiles/Test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/src/main.cpp > CMakeFiles/Test.dir/src/main.cpp.i

CMakeFiles/Test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/src/main.cpp -o CMakeFiles/Test.dir/src/main.cpp.s

CMakeFiles/Test.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/src/main.cpp.o.requires

CMakeFiles/Test.dir/src/main.cpp.o.provides: CMakeFiles/Test.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/src/main.cpp.o.provides

CMakeFiles/Test.dir/src/main.cpp.o.provides.build: CMakeFiles/Test.dir/src/main.cpp.o


# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/src/main.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/src/main.cpp.o
Test: CMakeFiles/Test.dir/build.make
Test: /usr/local/lib/libceres.a
Test: /usr/local/lib/libglog.so
Test: /usr/local/lib/libgflags.so.2.2.2
Test: /usr/lib/x86_64-linux-gnu/libspqr.so
Test: /usr/lib/x86_64-linux-gnu/libtbbmalloc.so
Test: /usr/lib/x86_64-linux-gnu/libtbb.so
Test: /usr/lib/x86_64-linux-gnu/libcholmod.so
Test: /usr/lib/x86_64-linux-gnu/libccolamd.so
Test: /usr/lib/x86_64-linux-gnu/libcamd.so
Test: /usr/lib/x86_64-linux-gnu/libcolamd.so
Test: /usr/lib/x86_64-linux-gnu/libamd.so
Test: /usr/lib/liblapack.so
Test: /usr/lib/libblas.so
Test: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
Test: /usr/lib/x86_64-linux-gnu/librt.so
Test: /usr/lib/x86_64-linux-gnu/libcxsparse.so
Test: /usr/lib/liblapack.so
Test: /usr/lib/libblas.so
Test: /usr/lib/x86_64-linux-gnu/libsuitesparseconfig.so
Test: /usr/lib/x86_64-linux-gnu/librt.so
Test: /usr/lib/x86_64-linux-gnu/libcxsparse.so
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test

.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Test.dir/requires

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build /home/zhangzhihong/zhihong_dev_ws/cplusplus_dev_ws/2019_nCoV_prediction/build/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend

