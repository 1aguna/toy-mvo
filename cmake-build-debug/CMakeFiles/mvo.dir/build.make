# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/laguna/CLionProjects/mvo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laguna/CLionProjects/mvo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mvo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mvo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mvo.dir/flags.make

CMakeFiles/mvo.dir/src/main.cpp.o: CMakeFiles/mvo.dir/flags.make
CMakeFiles/mvo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mvo.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mvo.dir/src/main.cpp.o -c /home/laguna/CLionProjects/mvo/src/main.cpp

CMakeFiles/mvo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laguna/CLionProjects/mvo/src/main.cpp > CMakeFiles/mvo.dir/src/main.cpp.i

CMakeFiles/mvo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laguna/CLionProjects/mvo/src/main.cpp -o CMakeFiles/mvo.dir/src/main.cpp.s

CMakeFiles/mvo.dir/src/features.cpp.o: CMakeFiles/mvo.dir/flags.make
CMakeFiles/mvo.dir/src/features.cpp.o: ../src/features.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mvo.dir/src/features.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mvo.dir/src/features.cpp.o -c /home/laguna/CLionProjects/mvo/src/features.cpp

CMakeFiles/mvo.dir/src/features.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvo.dir/src/features.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laguna/CLionProjects/mvo/src/features.cpp > CMakeFiles/mvo.dir/src/features.cpp.i

CMakeFiles/mvo.dir/src/features.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvo.dir/src/features.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laguna/CLionProjects/mvo/src/features.cpp -o CMakeFiles/mvo.dir/src/features.cpp.s

CMakeFiles/mvo.dir/src/loadData.cpp.o: CMakeFiles/mvo.dir/flags.make
CMakeFiles/mvo.dir/src/loadData.cpp.o: ../src/loadData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mvo.dir/src/loadData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mvo.dir/src/loadData.cpp.o -c /home/laguna/CLionProjects/mvo/src/loadData.cpp

CMakeFiles/mvo.dir/src/loadData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvo.dir/src/loadData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laguna/CLionProjects/mvo/src/loadData.cpp > CMakeFiles/mvo.dir/src/loadData.cpp.i

CMakeFiles/mvo.dir/src/loadData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvo.dir/src/loadData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laguna/CLionProjects/mvo/src/loadData.cpp -o CMakeFiles/mvo.dir/src/loadData.cpp.s

CMakeFiles/mvo.dir/src/processing.cpp.o: CMakeFiles/mvo.dir/flags.make
CMakeFiles/mvo.dir/src/processing.cpp.o: ../src/processing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mvo.dir/src/processing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mvo.dir/src/processing.cpp.o -c /home/laguna/CLionProjects/mvo/src/processing.cpp

CMakeFiles/mvo.dir/src/processing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvo.dir/src/processing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laguna/CLionProjects/mvo/src/processing.cpp > CMakeFiles/mvo.dir/src/processing.cpp.i

CMakeFiles/mvo.dir/src/processing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvo.dir/src/processing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laguna/CLionProjects/mvo/src/processing.cpp -o CMakeFiles/mvo.dir/src/processing.cpp.s

# Object files for target mvo
mvo_OBJECTS = \
"CMakeFiles/mvo.dir/src/main.cpp.o" \
"CMakeFiles/mvo.dir/src/features.cpp.o" \
"CMakeFiles/mvo.dir/src/loadData.cpp.o" \
"CMakeFiles/mvo.dir/src/processing.cpp.o"

# External object files for target mvo
mvo_EXTERNAL_OBJECTS =

mvo: CMakeFiles/mvo.dir/src/main.cpp.o
mvo: CMakeFiles/mvo.dir/src/features.cpp.o
mvo: CMakeFiles/mvo.dir/src/loadData.cpp.o
mvo: CMakeFiles/mvo.dir/src/processing.cpp.o
mvo: CMakeFiles/mvo.dir/build.make
mvo: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
mvo: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
mvo: CMakeFiles/mvo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mvo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mvo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mvo.dir/build: mvo

.PHONY : CMakeFiles/mvo.dir/build

CMakeFiles/mvo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mvo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mvo.dir/clean

CMakeFiles/mvo.dir/depend:
	cd /home/laguna/CLionProjects/mvo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laguna/CLionProjects/mvo /home/laguna/CLionProjects/mvo /home/laguna/CLionProjects/mvo/cmake-build-debug /home/laguna/CLionProjects/mvo/cmake-build-debug /home/laguna/CLionProjects/mvo/cmake-build-debug/CMakeFiles/mvo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mvo.dir/depend

