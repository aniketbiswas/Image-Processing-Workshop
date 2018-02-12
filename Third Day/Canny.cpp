#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int kernel[3][3] = { { 1, 2, 1 },
{ 2, 4, 2 },
{ 1, 2, 1 } };

int Gx[3][3] = { { -1, 0, 1 },
{ -2, 0, 2 },
{ -1, 0, 1 } };
int Gy[3][3] = { { -1, -2, -1 },
{ 0, 0, 0 },
{ 1, 2, 1 } };

int main()
{
	Mat var1=imread("testimg.png",1);
	Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var3(var2.rows, var2.cols, CV_8UC1, Scalar(0));
	Mat var4(var3.rows, var3.cols, CV_8UC1, Scalar(0));
	Mat var5(var3.rows, var3.cols, CV_8UC1, Scalar(0));
	int a=0,b=0;
	imshow("Original",var1);
	cvtColor(var1,var2,CV_RGB2GRAY);
	imshow("Gray",var2);
	for (int i = 0; i < var3.rows; i++)
	{
		for(int j=0;j<var3.cols;j++)
		{
			a = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if (i + k  < 0 || i + k >= var2.rows || j + h < 0 || j + h >= var2.cols)
						continue;
					else{
						//count++;
						a += var2.at<uchar>(i + k, j + h) * kernel[k + 1][h + 1];
					}
				}
			}
			var3.at<uchar>(i, j) = a / 16;
		}
	}
	imshow("Gaussian 1",var3);
	for (int i = 0; i < var3.rows; i++)
	{
		for(int j=0;j<var3.cols;j++)
		{
			b = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if (i + k  < 0 || i + k >= var2.rows || j + h < 0 || j + h >= var2.cols)
						continue;
					else{
						//count++;
						b += var3.at<uchar>(i + k, j + h) * kernel[k + 1][h + 1];
					}
				}
			}
			var4.at<uchar>(i, j) = b / 16;
		}
	}
	imshow("Gaussian 2",var4);
	int gxr = 0, gyb = 0;
	for (int i = 0; i < var4.rows; i++)
	{
		for (int j = 0; j < var4.cols; j++)
		{
			//float temp = 0.0;
			//int count = 0;
			gxr = 0, gyb = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if (i + k  < 0 || i + k >= var2.rows || j + h < 0 || j + h >= var2.cols)
						continue;
					else{
						//count++;
						gxr += var4.at<uchar>(i + k, j + h) * Gx[k + 1][h + 1];
						
						gyb += var4.at<uchar>(i + k, j + h) * Gy[k + 1][h + 1];
					}
				}
			}
			int Gxr = gxr*gxr;
			int Gyb = gyb*gyb;
			var5.at<uchar>(i, j) = (int)sqrt(Gxr + Gyb);
			
			
		}
	}
	imshow("Sobel",var5);
	waitKey(0);

	return 0;
}