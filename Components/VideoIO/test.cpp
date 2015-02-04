/*
	Author:  Vincent Paratore
	Date:	 1/18/2015
	Purpose: Senior Design
	Team:	 DT08 
	Project: Virtual CoPilot

	Last Updated: 1/18/2015

	Test item for videoFeed component
*/
#include "videoFeed.hpp"
#include "algorithmLib.hpp"
#include "opencv2/highgui/highgui.hpp"

int main()
{
	videoFeed feed(1);
	Mat bgrImg;
	Mat hsvImg;
	Mat thresh;
	int	t=1;
	char c;
	cvNamedWindow("Test", CV_WINDOW_AUTOSIZE); 
	cvNamedWindow("Thresh", CV_WINDOW_AUTOSIZE); 
	cvNamedWindow("Control-HSV", CV_WINDOW_AUTOSIZE); 
	cvNamedWindow("Control-RGB", CV_WINDOW_AUTOSIZE); 
	int LowH = 0;
	int LowS = 0; 
	int LowV = 0;
	int HighH = 360;
	int HighS = 100;
	int HighV = 100;
	int LowR = 0;
	int LowG = 0; 
	int LowB = 0;
	int HighR = 360;
	int HighG = 100;
	int HighB = 100;

	//Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control-HSV", &LowH, 360); //Hue (0 - 179)
	cvCreateTrackbar("LowS", "Control-HSV", &LowS, 100); //Saturation (0 - 255)
	cvCreateTrackbar("LowV", "Control-HSV", &LowV, 100); //Value (0 - 255)
	cvCreateTrackbar("HighH", "Control-HSV", &HighH, 360);
	cvCreateTrackbar("HighS", "Control-HSV", &HighS, 100);
	cvCreateTrackbar("HighV", "Control-HSV", &HighV, 100);
	
	//Create trackbars in "Control" window
	cvCreateTrackbar("LowR", "Control-RGB", &LowR, 255); //Hue (0 - 179)
	cvCreateTrackbar("LowG", "Control-RGB", &LowG, 255); //Saturation (0 - 255)
	cvCreateTrackbar("LowB", "Control-RGB", &LowB, 255); //Value (0 - 255)
	cvCreateTrackbar("HighR", "Control-RGB", &HighR, 255);
	cvCreateTrackbar("HighG", "Control-RGB", &HighG, 255);
	cvCreateTrackbar("HighB", "Control-RGB", &HighB, 255);

	while(1)
	{
		c = cvWaitKey(1);

	    if(c=='a') // If pressed, break out of the loop
	        break;
	    if(c=='w') //Select Next Camera
	    	feed.selectCam(feed.getCurCam()+1);
	    if(c=='s') //Select Previous Camera
	    	feed.selectCam(feed.getCurCam()-1);
	    if(c=='e')
	    	t=std::min(t+1,1);
	    if(c=='d')
	    	t=std::max(t-1,0);

	    hsvImg = feed.getFrame();
	    if(feed.isConnected())
	    {
		    cv::imshow("Test",hsvImg);
		    switch(t)
		    {
		    	case 1:
		    		thresh = getThresholdImageHSV(hsvImg,LowH*255/360,LowS*255/100,LowV*255/100,HighH*255/360,HighS*255/100,HighV*255/100);
			    	cv::imshow("Thresh",thresh);
			    	break;
			   /* case 2:
			   	 	thresh = getThresholdImageRGB(hsvImg,LowR,LowG,LowB,HighR,HighG,HighB);
			    	cvtColor(thresh,thresh,CV_GRAY2RGB);
			    	cv::imshow("Thresh",thresh);
			    	break;*/
			}
		}
	}
	return 0;
}