#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int kernel[3][3] = { 	{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 } };
int main(){
	Mat var1 = imread("testing.jpg",1);
	Mat var2(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
	imshow("R", var1);
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < var1.rows; i++)
	{
		for (int j = 0; j < var1.cols; j++)
		{
			//float temp = 0.0;
			int count = 0;
			r = 0, g = 0, b = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if (i + k  < 0 || i + k  >= var2.rows || j+h < 0 || j+h >= var2.cols)
						continue;
					else{
						count++;
						r += var1.at<Vec3b>(i + k, j + h)[2] * kernel[k + 1][h + 1];
						g += var1.at<Vec3b>(i + k, j + h)[1] * kernel[k + 1][h + 1];
						b += var1.at<Vec3b>(i + k, j + h)[0] * kernel[k + 1][h + 1];
					}
				}
			}
			var2.at<Vec3b>(i, j)[0] = b/count;
			var2.at<Vec3b>(i, j)[1] = g/count;
			var2.at<Vec3b>(i, j)[2] = r/count;
		}
	}
	imshow("window", var2);
	cv::waitKey(0);
	return 0;
}
