cmake_minimum_required(VERSION 3.4)
project(webcam)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(SRCS 	myVideoClass.h
			myVideoClass.cpp
	)
add_executable(webcam webcam.cpp ${SRCS})
target_link_libraries(webcam ${OpenCV_LIBS} )