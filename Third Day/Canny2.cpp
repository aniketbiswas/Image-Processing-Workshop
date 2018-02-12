#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include <Windows.h>
#include <iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{
	float i, j, x, y, a, k, z;
	Mat var1 = imread("testing.jpg", 0);
	namedWindow("window1", WINDOW_AUTOSIZE);
	namedWindow("window2", WINDOW_AUTOSIZE);
	imshow("window1", var1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC1, Scalar(0));

	for (i = 1; i < var1.rows - 1; i++)
	{
		for (j = 1; j < var1.cols - 1; j++)
		{
			var2.at<uchar>(i, j) = ((var1.at<uchar>(i - 1, j) + var1.at<uchar>(i + 1, j) + var1.at<uchar>(i, j - 1) + var1.at<uchar>(i, j + 1)) * 2 + (var1.at<uchar>(i - 1, j - 1) + var1.at<uchar>(i - 1, j + 1) + var1.at<uchar>(i + 1, j - 1) + var1.at<uchar>(i + 1, j + 1)) + var1.at<uchar>(i, j) * 4) / 16;
		}
	}

	for (i = 1; i < var1.rows - 1; i++)
	{
		for (j = 1; j < var1.cols - 1; j++)
		{
			x = (var2.at<uchar>(i - 1, j - 1) * (-1) + var2.at<uchar>(i - 1, j + 1) * 1 + var2.at<uchar>(i, j - 1) * (-2) + var2.at<uchar>(i, j + 1) * 2 + var2.at<uchar>(i + 1, j - 1) * (-1) + var2.at<uchar>(i + 1, j + 1) * 1);
			y = (var2.at<uchar>(i - 1, j - 1) * (1) + var2.at<uchar>(i - 1, j) * (2) + var2.at<uchar>(i - 1, j + 1) * (1) + var2.at<uchar>(i + 1, j - 1) * (-1) + var2.at<uchar>(i + 1, j) * (-2) + var2.at<uchar>(i + 1, j + 1) * (-1));
			if (x == 0) k = 90;
			else
			{
				k = atan(y / x);
				k = 180 * k / 3.14 + 90;
			}
			z = sqrt(x*x + y*y);

			if (k >= 0 && k < 22.5)
			{
				if (z > var2.at<uchar>(i, j - 1) && z>var2.at<uchar>(i, j + 1))
					var3.at<uchar>(i, j) = 255;
				else
					var3.at<uchar>(i, j) = 0;

			}
			if (k >= 22.5 && k < 67.5)
			{
				if (z > var2.at<uchar>(i - 1, j + 1) && z>var2.at<uchar>(i + 1, j - 1))
					var3.at<uchar>(i, j) = 255;
				else
					var3.at<uchar>(i, j) = 0;
			}
			if (k >= 67.5 && k < 112.5)
			{
				if (z > var2.at<uchar>(i - 1, j) && z>var2.at<uchar>(i + 1, j))
					var3.at<uchar>(i, j) = 255;
				else
					var3.at<uchar>(i, j) = 0;

			}
			if (k >= 122.5 && k <= 180)
			{
				if (z > var2.at<uchar>(i - 1, j - 1) && z>var2.at<uchar>(i + 1, j + 1))
					var3.at<uchar>(i, j) = 255;
				else
					var3.at<uchar>(i, j) = 0;
			}

		}
	}
	imshow("windows2", var3);
	waitKey(0);
	return 0;


}









