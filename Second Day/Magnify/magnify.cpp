#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int main()
{

	int i,j;
	Mat var1 = imread("testing.jpg",1);
	Mat var2(2*(var1.rows),2*(var1.cols),CV_8UC3,Scalar(0,0,0));
	namedWindow("window1",WINDOW_AUTOSIZE);
	
	for(int i=0;i<var1.rows;i++)
		for(int j=0;j<var1.cols;j++)
		{
			var2.at<Vec3b>(2*i,2*j)[0]=var1.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(2*i+1,2*j)[0]=var1.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(2*i,2*j)[0]=var1.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(2*i,2*j+1)[0]=var1.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(2*i,2*j)[1]=var1.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(2*i+1,2*j)[1]=var1.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(2*i,2*j+1)[1]=var1.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(2*i,2*j)[1]=var1.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(2*i,2*j)[2]=var1.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(2*i+1,2*j)[2]=var1.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(2*i,2*j)[2]=var1.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(2*i,2*j+1)[2]=var1.at<Vec3b>(i,j)[2];
		}

		imshow("window1",var2);
		waitKey(0);
		return 0;
	}

			



