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

	VideoCapture cap(0);
	Mat var1,var2;
		
	int b=100;
	namedWindow("Canny",WINDOW_AUTOSIZE);


	createTrackbar("Thresh","Canny",&b,255);
	while(cap.isOpened())
	{
		cap>>var1;

		Mat var3(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
		Mat var4(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
		Mat var5(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
		Mat var6(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));

		for(int i=0;i<var1.rows;i++)
			for(int j=0;j<var1.cols;j++)
			{
				var3.at<Vec3b>(i,j)[0]=var1.at<Vec3b>(i,var1.cols-1-j)[0];
				var3.at<Vec3b>(i,j)[1]=var1.at<Vec3b>(i,var1.cols-1-j)[1];
				var3.at<Vec3b>(i,j)[2]=var1.at<Vec3b>(i,var1.cols-1-j)[2];
			}

		for(int i=0;i<var1.rows;i++)
			for(int j=0;j<var1.cols;j++)
			{	
				if(var1.at<Vec3b>(i,j)[0]<30&&var1.at<Vec3b>(i,j)[1]<30&&var1.at<Vec3b>(i,j)[2]<30)
				{
					var4.at<Vec3b>(i,j)[0]=200;
					var4.at<Vec3b>(i,j)[1]=200;
					var4.at<Vec3b>(i,j)[2]=25;
				}
				else
				{
					var4.at<Vec3b>(i,j)[0]=var1.at<Vec3b>(i,j)[0];
					var4.at<Vec3b>(i,j)[1]=var1.at<Vec3b>(i,j)[1];
					var4.at<Vec3b>(i,j)[2]=var1.at<Vec3b>(i,j)[2];
				}
			}

		cvtColor(var1,var5,CV_RGB2HSV);
		cvtColor(var1,var6,CV_BGR2HSV);
			

		Canny(var1,var2,0.4*b,b);
		imshow("original",var1);
		imshow("Canny",var2);
		imshow("flip",var3);
		imshow("af",var4);
		imshow("aa",var5);
		imshow("ab",var6);
		if(waitKey(10)=='q')
			{	imwrite("pic.jpg",var3);
				break;
			}
	}
	imshow("capture",var2);
	waitKey(0);
	return 0;
}