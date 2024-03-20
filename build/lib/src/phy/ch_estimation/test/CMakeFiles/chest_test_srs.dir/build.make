# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cjb/srsRAN_4G

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cjb/srsRAN_4G/build

# Include any dependencies generated for this target.
include lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/progress.make

# Include the compile flags for this target's objects.
include lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/flags.make

lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o: lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/flags.make
lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o: /home/cjb/srsRAN_4G/lib/src/phy/ch_estimation/test/chest_test_srs.c
lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o: lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o"
	cd /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o -MF CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o.d -o CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o -c /home/cjb/srsRAN_4G/lib/src/phy/ch_estimation/test/chest_test_srs.c

lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chest_test_srs.dir/chest_test_srs.c.i"
	cd /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cjb/srsRAN_4G/lib/src/phy/ch_estimation/test/chest_test_srs.c > CMakeFiles/chest_test_srs.dir/chest_test_srs.c.i

lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chest_test_srs.dir/chest_test_srs.c.s"
	cd /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cjb/srsRAN_4G/lib/src/phy/ch_estimation/test/chest_test_srs.c -o CMakeFiles/chest_test_srs.dir/chest_test_srs.c.s

# Object files for target chest_test_srs
chest_test_srs_OBJECTS = \
"CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o"

# External object files for target chest_test_srs
chest_test_srs_EXTERNAL_OBJECTS =

lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/chest_test_srs.c.o
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/build.make
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/phy/libsrsran_phy.a
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/common/libsrsran_common.a
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/phy/libsrsran_phy.a
lib/src/phy/ch_estimation/test/chest_test_srs: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/support/libsupport.a
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/srslog/libsrslog.a
lib/src/phy/ch_estimation/test/chest_test_srs: /usr/lib/x86_64-linux-gnu/libmbedcrypto.so
lib/src/phy/ch_estimation/test/chest_test_srs: /usr/lib/x86_64-linux-gnu/libsctp.so
lib/src/phy/ch_estimation/test/chest_test_srs: lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chest_test_srs"
	cd /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chest_test_srs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/build: lib/src/phy/ch_estimation/test/chest_test_srs
.PHONY : lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/build

lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/clean:
	cd /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test && $(CMAKE_COMMAND) -P CMakeFiles/chest_test_srs.dir/cmake_clean.cmake
.PHONY : lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/clean

lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/depend:
	cd /home/cjb/srsRAN_4G/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cjb/srsRAN_4G /home/cjb/srsRAN_4G/lib/src/phy/ch_estimation/test /home/cjb/srsRAN_4G/build /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test /home/cjb/srsRAN_4G/build/lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/src/phy/ch_estimation/test/CMakeFiles/chest_test_srs.dir/depend

