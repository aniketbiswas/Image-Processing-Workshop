#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
using namespace std;
using namespace cv;

int main()
{
	Mat org=imread("hough.png",1);
	namedWindow("original",WINDOW_AUTOSIZE);
	Mat imgOutput;

	if (org.data==NULL)
	{
		printf("Hey! Can't read image");
		system("PAUSE");
		return 1;
	}	
	cvtColor(org,org,CV_BGR2GRAY);

	Mat imgContours;
	int thresh = 150,max=150;
	createTrackbar("Low Thresh","original",&thresh,255);
	createTrackbar("Max Thresh","original",&max,255);
	while(1)
		{
			Canny(org,imgContours,thresh, max);
			vector<Vec2f> lines;
			HoughLines(imgContours,lines,1,CV_PI/180,50);
	
			cvtColor( imgContours, imgOutput, CV_GRAY2BGR );
			for(int  i = 0; i < lines.size(); i++ )
			{	
				float theta = lines[i][1];
				float rho = lines[i][0];
				double a = cos(theta), b = sin(theta);
				double x = a*rho, y = b*rho;
				Point pt1(cvRound(x-(1000*b)),cvRound(y+(1000*a)));
				Point pt2(cvRound(x+(1000*b)),cvRound(y-(1000*a)));
				line( imgOutput, pt1, pt2, Scalar(0,0,255), 1, 8 );
			}		
			imshow("original",imgContours);
			imshow("wind",imgOutput);
			if(waitKey(10)=='q');

		}
//	waitKey(0);


}