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
include srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.make

# Include the progress variables for this target.
include srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/progress.make

# Include the compile flags for this target's objects.
include srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o -MF CMakeFiles/srsue_upper.dir/nas.cc.o.d -o CMakeFiles/srsue_upper.dir/nas.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas.cc > CMakeFiles/srsue_upper.dir/nas.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas.cc -o CMakeFiles/srsue_upper.dir/nas.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_emm_state.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o -MF CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_emm_state.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_emm_state.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_emm_state.cc > CMakeFiles/srsue_upper.dir/nas_emm_state.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_emm_state.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_emm_state.cc -o CMakeFiles/srsue_upper.dir/nas_emm_state.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_idle_procedures.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o -MF CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_idle_procedures.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_idle_procedures.cc > CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_idle_procedures.cc -o CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/gw.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o -MF CMakeFiles/srsue_upper.dir/gw.cc.o.d -o CMakeFiles/srsue_upper.dir/gw.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/gw.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/gw.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/gw.cc > CMakeFiles/srsue_upper.dir/gw.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/gw.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/gw.cc -o CMakeFiles/srsue_upper.dir/gw.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim_base.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o -MF CMakeFiles/srsue_upper.dir/usim_base.cc.o.d -o CMakeFiles/srsue_upper.dir/usim_base.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim_base.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/usim_base.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim_base.cc > CMakeFiles/srsue_upper.dir/usim_base.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/usim_base.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim_base.cc -o CMakeFiles/srsue_upper.dir/usim_base.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o -MF CMakeFiles/srsue_upper.dir/usim.cc.o.d -o CMakeFiles/srsue_upper.dir/usim.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/usim.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim.cc > CMakeFiles/srsue_upper.dir/usim.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/usim.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/usim.cc -o CMakeFiles/srsue_upper.dir/usim.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/tft_packet_filter.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o -MF CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o.d -o CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/tft_packet_filter.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/tft_packet_filter.cc > CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/tft_packet_filter.cc -o CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_base.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o -MF CMakeFiles/srsue_upper.dir/nas_base.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_base.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_base.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_base.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_base.cc > CMakeFiles/srsue_upper.dir/nas_base.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_base.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_base.cc -o CMakeFiles/srsue_upper.dir/nas_base.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g_procedures.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o -MF CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g_procedures.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g_procedures.cc > CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g_procedures.cc -o CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o -MF CMakeFiles/srsue_upper.dir/nas_5g.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_5g.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_5g.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g.cc > CMakeFiles/srsue_upper.dir/nas_5g.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_5g.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5g.cc -o CMakeFiles/srsue_upper.dir/nas_5g.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5gmm_state.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o -MF CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o.d -o CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5gmm_state.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5gmm_state.cc > CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/nas_5gmm_state.cc -o CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.s

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/flags.make
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o: /home/cjb/srsRAN_4G/srsue/src/stack/upper/sdap.cc
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o -MF CMakeFiles/srsue_upper.dir/sdap.cc.o.d -o CMakeFiles/srsue_upper.dir/sdap.cc.o -c /home/cjb/srsRAN_4G/srsue/src/stack/upper/sdap.cc

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srsue_upper.dir/sdap.cc.i"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cjb/srsRAN_4G/srsue/src/stack/upper/sdap.cc > CMakeFiles/srsue_upper.dir/sdap.cc.i

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srsue_upper.dir/sdap.cc.s"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cjb/srsRAN_4G/srsue/src/stack/upper/sdap.cc -o CMakeFiles/srsue_upper.dir/sdap.cc.s

# Object files for target srsue_upper
srsue_upper_OBJECTS = \
"CMakeFiles/srsue_upper.dir/nas.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o" \
"CMakeFiles/srsue_upper.dir/gw.cc.o" \
"CMakeFiles/srsue_upper.dir/usim_base.cc.o" \
"CMakeFiles/srsue_upper.dir/usim.cc.o" \
"CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_base.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_5g.cc.o" \
"CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o" \
"CMakeFiles/srsue_upper.dir/sdap.cc.o"

# External object files for target srsue_upper
srsue_upper_EXTERNAL_OBJECTS =

srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_emm_state.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_idle_procedures.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/gw.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim_base.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/usim.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/tft_packet_filter.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_base.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g_procedures.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5g.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/nas_5gmm_state.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/sdap.cc.o
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/build.make
srsue/src/stack/upper/libsrsue_upper.a: srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cjb/srsRAN_4G/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library libsrsue_upper.a"
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && $(CMAKE_COMMAND) -P CMakeFiles/srsue_upper.dir/cmake_clean_target.cmake
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/srsue_upper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/build: srsue/src/stack/upper/libsrsue_upper.a
.PHONY : srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/build

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/clean:
	cd /home/cjb/srsRAN_4G/build/srsue/src/stack/upper && $(CMAKE_COMMAND) -P CMakeFiles/srsue_upper.dir/cmake_clean.cmake
.PHONY : srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/clean

srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/depend:
	cd /home/cjb/srsRAN_4G/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cjb/srsRAN_4G /home/cjb/srsRAN_4G/srsue/src/stack/upper /home/cjb/srsRAN_4G/build /home/cjb/srsRAN_4G/build/srsue/src/stack/upper /home/cjb/srsRAN_4G/build/srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srsue/src/stack/upper/CMakeFiles/srsue_upper.dir/depend

