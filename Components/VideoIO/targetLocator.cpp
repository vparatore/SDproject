/*
	Author:  Vincent Paratore
	Date:	 1/19/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/18/2015
*/

#include "targetLocator.hpp"

using namespace cv;

targetLocator::targetLocator():image(0),HSVRangeHi(179,255,255),HSVRangeLow(0,0,0), RGBRangeHi(255,255,255), RGBRangeLow(0,0,0)
{

}


targetLocator::targetLocator(Mat& img):HSVRangeHi(179,255,255),HSVRangeLow(0,0,0), RGBRangeHi(255,255,255), RGBRangeLow(0,0,0)
{
	image = &img;
}


targetLocator::~targetLocator()
{

}

Vec2d targetLocator::findTargetHSV(Mat&, int hlow,int slow,int vlow,int hhigh,int shigh,int vhigh)
{
	return findTargetHSV(*image,Vec3d(hlow,slow,vlow), Vec3d(hhigh,shigh,vhigh));
}


Vec2d targetLocator::findTargetHSV(Mat&, Vec3d, Vec3d)
{
	Vec2d coord;
	coord = Vec2d(10,10);
	return coord;
}



Vec2d targetLocator::findTargetRGB(Mat&, int rlow,int glow,int blow,int rhigh,int ghigh,int bhigh)
{
	return findTargetRGB(*image,Vec3d(rlow,glow,blow),Vec3d(rhigh,ghigh,bhigh));
}


Vec2d targetLocator::findTargetRGB(Mat&, Vec3d, Vec3d)
{
	Vec2d coord;
	coord = Vec2d(10,10);
	return coord;
}

void targetLocator::setTargetColorHSV(int hue,int sat,int val)
{
	HSVColor = Vec3d(hue,sat,val);
}


void targetLocator::setTargetColorHSV(Vec3d hsv)
{
	HSVColor = hsv;
}


void targetLocator::setTargetColorRGB(int red,int green,int blue)
{
	RGBColor = Vec3d(red,green,blue);
}


void targetLocator::setTargetColorRGB(Vec3d rgb)
{
	RGBColor = rgb;
}

