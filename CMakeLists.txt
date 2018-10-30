cmake_minimum_required(VERSION 2.8)
SET("OpenCV_DIR" "D:/Education/C++/opencv/opencv_3.4.3-winrar/build")
project(webcam)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(SRCS 	myVideoClass.h
			myVideoClass.cpp
	)
add_executable(webcam webcam.cpp ${SRCS})
target_link_libraries(webcam ${OpenCV_LIBS} )