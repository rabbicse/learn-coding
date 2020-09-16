# cmake for OpenCV2 Cookbook
# your opencv/build directory should be in your system PATH

# set minimum required version for cmake
cmake_minimum_required(VERSION 3.1)

# define the project name
set(project_name "OpenCV4Cookbook")
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

# set the project name
project("${project_name}")

# this is a C++11 project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# set opencv project
set(OpenCV_DIR /mnt/8A785D25785D10F5/opencv_src/opencv/build/installation/OpenCV-/lib/cmake/opencv4)

# add opencv package to the project
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} ) 
SET(OpenCV_LIBRARIES ${OpenCV_LIBS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# add Chapter projects
add_subdirectory(ch_01)
add_subdirectory(ch_02)
#add_subdirectory(Chapter03)
#add_subdirectory(Chapter04)
#add_subdirectory(Chapter05)
#add_subdirectory(Chapter06)
#add_subdirectory(Chapter07)
#add_subdirectory(Chapter08)
#add_subdirectory(Chapter09)
#add_subdirectory(Chapter10)
#add_subdirectory(Chapter11)
#add_subdirectory(Chapter12)
#add_subdirectory(Chapter13)
#add_subdirectory(Chapter14)
#add_subdirectory(Chapter15)
