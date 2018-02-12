#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int Gx[3][3] = {	{ -1, 0, 1 },
			{ -2, 0, 2 },
			{ -1, 0, 1 } };
int Gy[3][3] = {{ -1, -2, -1 },		
		{ 0, 0, 0 },
		{ 1, 2, 1 } };
int main()
{
	Mat var1 = imread("testing.jpg", 1);
	Mat var2(var1.rows, var1.cols, CV_8UC3, Scalar(0, 0, 0));
	imshow("R", var1);
	int gxr = 0, gxg = 0, gxb = 0, gyr = 0, gyg = 0, gyb = 0;
	for (int i = 0; i < var1.rows; i++)
	{
		for (int j = 0; j < var1.cols; j++)
		{
			//float temp = 0.0;
			//int count = 0;
			gxr = 0, gxg = 0, gxb = 0, gyr = 0, gyg = 0, gyb = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if (i + k  < 0 || i + k >= var2.rows || j + h < 0 || j + h >= var2.cols)
						continue;
					else{
						//count++;
						gxr += var1.at<Vec3b>(i + k, j + h)[2] * Gx[k + 1][h + 1];
						gxg += var1.at<Vec3b>(i + k, j + h)[1] * Gx[k + 1][h + 1];
						gxb += var1.at<Vec3b>(i + k, j + h)[0] * Gx[k + 1][h + 1];
						gyr += var1.at<Vec3b>(i + k, j + h)[2] * Gy[k + 1][h + 1];
						gyg += var1.at<Vec3b>(i + k, j + h)[1] * Gy[k + 1][h + 1];
						gyb += var1.at<Vec3b>(i + k, j + h)[0] * Gy[k + 1][h + 1];
					}
				}
			}
			int Gxr = gxr*gxr;
			int Gxg = gxg*gxg;
			int Gxb = gxb*gxb;
			int Gyr = gyr*gyr;
			int Gyg = gyg*gyg;
			int Gyb = gyb*gyb;
			var2.at<Vec3b>(i, j)[0] = (int)sqrt(Gxb + Gyb);
			var2.at<Vec3b>(i, j)[1] = (int)sqrt(Gxg + Gyg);
			var2.at<Vec3b>(i, j)[2] = (int)sqrt(Gxr + Gyr);
		}
	}
	imwrite("testimgsobel.png",var2);
	imshow("window3", var1 - var2);
	imshow("window", var2);
	cv::waitKey(0);
	return 0;
}
