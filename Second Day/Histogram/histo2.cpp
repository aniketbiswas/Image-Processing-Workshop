#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int main()
{

	int z,a[256];
	Mat var1 = imread("testing.jpg",1);
	Mat var2(1000,256 ,CV_8UC3,Scalar(0,0,0));
	
	namedWindow("wind",WINDOW_AUTOSIZE);
	for(int k=0;k<255 ; k++)
		a[k]=0;	
	for(int i=0;i<var1.rows;i++)
		{
		for(int j=0;j<var1.cols;j++)
		{
			z=var1.at<Vec3b>(i,j)[2];
			a[z]+=1;
					
		}
		}

	for(int k=0;k<255 ; k++)
		a[k]=a[k]/10000;

	for(int i=0;i<256 ; i++)
		for(int j=0;j<a[i]/10;j++)
		
		var2.at<Vec3b>(j,i)[2]=255;

	imshow("wind",var2);
	waitKey(0);
}
