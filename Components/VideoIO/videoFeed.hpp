/*
	Author:  Vincent Paratore
	Date:	 1/18/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/18/2015
*/
	
#include <iostream>
#include <highgui.h>
#include <cv.h>

using namespace cv;

struct videoFeed
{
	videoFeed();
	videoFeed(int);
	~videoFeed();

	bool		selectCam(int);
	bool		isConnected();
	int 		getCurCam();
	Mat 		getFrame();
	bool		checkForCam(int);

	private:
		bool			init();
		void			deInit();
		int 			findFirstCam();
		VideoCapture	cap;
		int 			cam;
		bool			active;


};