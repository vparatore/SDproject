/*
	Author:  Vincent Paratore
	Date:	 1/19/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/18/2015
*/

#include <iostream>
#include <highgui.h>
#include <cv.h>

using namespace cv;

struct targetLocator
{
	targetLocator();
	targetLocator(Mat&);
	~targetLocator();

	Vec2d findTargetHSV(Mat&, int,int,int,int,int,int);
	Vec2d findTargetHSV(Mat&, Vec3d, Vec3d);

	Vec2d findTargetRGB(Mat&, int,int,int,int,int,int);
	Vec2d findTargetRGB(Mat&, Vec3d, Vec3d);

	void setTargetColorHSV(int,int,int);
	void setTargetColorHSV(Vec3d);
	void setTargetColorRGB(int,int,int);
	void setTargetColorRGB(Vec3d);

	Mat* getThresholdImageHSV();
	Mat* getThresholdImageHSV(Vec3d, Vec3d);
	Mat* getThresholdImageHSV(Mat, Vec3d, Vec3d);
	Mat* getThresholdImageHSV(Mat);

	Mat* getThresholdImageRGB();
	Mat* getThresholdImageRGB(Vec3d, Vec3d);
	Mat* getThresholdImageRGB(Mat, Vec3d, Vec3d);
	Mat* getThresholdImageRGB(Mat);

private:
	Mat* image;

	Vec3d HSVColor;
	Vec3d HSVRangeHi;
	Vec3d HSVRangeLow;

	Vec3d RGBColor;
	Vec3d RGBRangeHi;
	Vec3d RGBRangeLow;

};