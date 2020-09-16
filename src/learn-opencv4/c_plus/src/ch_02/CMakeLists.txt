# set minimum required version for cmake
cmake_minimum_required(VERSION 3.1)

# set environments
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(OpenCV_DIR /mnt/8A785D25785D10F5/opencv_src/opencv/build/installation/OpenCV-/lib/cmake/opencv4)

# find package opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# add executeable
add_executable( salt salt.cpp)
add_executable(colorReduce colorReduce.cpp)

# add link libraries
target_link_libraries( salt ${OpenCV_LIBS} )
target_link_libraries( colorReduce ${OpenCV_LIBS} )