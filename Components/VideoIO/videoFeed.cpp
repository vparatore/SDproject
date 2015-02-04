/*
	Author:  Vincent Paratore
	Date:	 1/18/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/18/2015
*/

#include "videoFeed.hpp"

using namespace cv;

videoFeed::videoFeed(): cap(),cam(-1)
{
	init();
}

videoFeed::videoFeed(int camera): cap()
{
	cam = camera;
	init();
}

videoFeed::~videoFeed()
{
	deInit();
}

bool videoFeed::selectCam(int camera)
{
	if(!active)
	{
		std::cout<<"Video Feed not yet initialized!\n";
		return false;
	}

	if(camera == cam)
	{
		std::cout<<"Currently using "<<camera<<"\n";
		return true;
	}

	if(checkForCam(camera))
	{
		std::cout<<"Old camera deselected. Old camera "<<cam<<" now released.\n";
		cam = camera;
		cap.open(cam);
		std::cout<<"New camera selected! Now using camera "<<cam<<".\n";
	}
	else
	{
		std::cout<<"Failed to select camera! Camera "<<camera<<" not found!\n";
		return false;
	}
	return true;
}

bool videoFeed::init()
{
	if(cam<0||!checkForCam(cam))
	{
		cam = findFirstCam();
	}

	if(cam<0)
	{
		std::cout<<"Failed to initialize! No camera found!\n";
		active = false;
	}
	else
	{
		cap.open(cam);
		active = true;
		std::cout<<"Video feed initialized. Using camera "<<cam<<".\n";
	}
	return active;
}

void videoFeed::deInit()
{
	active = false;
	std::cout<<"Video feed de-initialized. Camera "<<cam<<" released.\n";
	return;
}

bool videoFeed::isConnected()
{
	return active;
}

int videoFeed::getCurCam()
{
	return cam;
}

Mat videoFeed::getFrame()
{
	if(active)
	{
		Mat ret;
		cap.read(ret);
		return ret;
	}
}

int videoFeed::findFirstCam()
{
	for(int i=0; i<10; i++)
	{
		if(checkForCam(i))
		{
			return i;
		}
	}
	return -1; //As "camera not found"
}

bool videoFeed::checkForCam(int sel)
{
	if(sel>=0)
	{
		VideoCapture camTest;
		camTest.open(sel);
		if(camTest.isOpened())
		{
			return true;
		}
	}
	return false;
}