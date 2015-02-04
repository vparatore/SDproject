/*
	Author:  Vincent Paratore
	Date:	 1/19/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/20/2015
*/

#include <highgui.h>
#include <cv.h>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

Mat getThresholdImageHSV(Mat img, int hl, int sl, int vl, int hh, int sh, int vh)
{
	Mat thresh;// = cvCreateImage(cvGetSize(&img), IPL_DEPTH_8U, 1);
	thresh = img;
	inRange(img, Scalar(hl,sl,vl), Scalar(hh,sh,vh), thresh);
	return thresh;
};

/*Mat getThresholdImageRGB(Mat img, int rl, int gl, int bl, int rh, int gh, int bh)
{
	Mat thresh, ret;
	thresh = img;
	if(!img.empty())
	{
		cvtColor(img,thresh,CV_HSV2RGB);
		//addWeighted(thresh,0.5,img,1,0.0,ret);
		inRange(img, Scalar(rl,gl, bl), Scalar(rh,gh,bh), thresh);
		//cvtColor(ret,thresh,CV_GRAY2RGB);
		//cvtColor(ret,ret,CV_RGB2HSV);
	}
	return thresh;
};*/