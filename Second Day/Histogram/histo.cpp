#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int main()
{
	int z , a[256]={0};
	Mat var1 =imread("testing.jpg");
	Mat var2(500,256,CV_8UC3,Scalar(255,255,255));
	
	namedWindow("wind",WINDOW_AUTOSIZE);
	
	for(int i=0;i<var1.rows;i++)
	{
		for(int j=0;j<var1.cols;j++)
		{
			z=var1.at<Vec3b>(i,j)[2];
			a[z]+=1;
		}
	}
	
	
	for(int i=0;i<256;i++)
	{
		for(int j=499;j>499-(a[i]/100);j--)
		{
			var2.at<Vec3b>(j,i)[0]=0;
			var2.at<Vec3b>(j,i)[1]=0;
			
		}
	}
	
	imshow("wind",var2);
	waitKey(0);
}
