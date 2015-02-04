#
#	Author:  Vincent Paratore
#	Date:	 1/18/2015
#	Purpose: Senior Design
#	Team:	 DT08 
#	Project: Virtual CoPilot
#
# 	Last Updated: 1/20/2015
#

cmake_minimum_required(VERSION 2.8)
project( VideoIO )
find_package( OpenCV REQUIRED )
add_executable( videoTest test.cpp videoFeed.cpp videoFeed.hpp targetLocator.cpp targetLocator.hpp algorithmLib.hpp)
target_link_libraries( videoTest ${OpenCV_LIBS} )