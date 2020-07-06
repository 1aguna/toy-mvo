cmake_minimum_required(VERSION 3.15)
project(mvo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package( OpenCV REQUIRED )
add_executable(mvo src/main.cpp src/features.cpp src/loadData.cpp include/loadData.h include/constants.h src/processing.cpp include/processing.h)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )