# set minimum required version for cmake
cmake_minimum_required(VERSION 3.1)

# set environments
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(OpenCV_DIR /mnt/8A785D25785D10F5/opencv_updated/opencv/build/install/lib/cmake/opencv4)

# find package opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# add executeable
add_executable( loadDisplaySave loadDisplaySave.cpp)
add_executable( mat mat.cpp)

# add link libraries
target_link_libraries( loadDisplaySave ${OpenCV_LIBS} )
target_link_libraries( mat ${OpenCV_LIBS} )