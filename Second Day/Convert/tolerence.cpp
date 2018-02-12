#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int main()
{

	int 	a,b,c,d,e,f, i,j;
	Mat var1 = imread("testing.jpg",1);
	Mat var2 (var1.rows,var1.cols,CV_8UC3,Scalar(255,255,255));
	a=b=c=d=e=f=125;
	
	namedWindow("wind",WINDOW_AUTOSIZE);
	
	
	createTrackbar("RED","wind",&a,255);
	createTrackbar("BLUE","wind",&b,255);
	createTrackbar("GREEN","wind",&c,255);
	createTrackbar("del RED","wind",&d,255);
	createTrackbar("del BLUE","wind",&e,255);	
	createTrackbar("del GREEN","wind",&f,255);	
	while(1)
	{
		for(i=0;i<var1.rows;i++)
		{
			for(j=0;j<var2.rows;j++)
			{
				
				if((var1.at<Vec3b>(i,j)[0]>=b-e)&&(var1.at<Vec3b>(i,j)[0]<=b+e)&&(var1.at<Vec3b>(i,j)[1]>=c-f)&&(var1.at<Vec3b>(i,j)[1]<=c+f)&&(var1.at<Vec3b>(i,j)[2]>=a-d)&&(var1.at<Vec3b>(i,j)[2]<=a+d))
					{
						var2.at<Vec3b>(i,j)[0]=var1.at<Vec3b>(i,j)[0];
						var2.at<Vec3b>(i,j)[1]=var1.at<Vec3b>(i,j)[1];
						var2.at<Vec3b>(i,j)[2]=var1.at<Vec3b>(i,j)[2];
					}
				else
				{
					var2.at<Vec3b>(i,j)[0]=255;
					var2.at<Vec3b>(i,j)[1]=255;
					var2.at<Vec3b>(i,j)[2]=255;
				}
			}
		}
		
		imshow("wind",var2);
		if(waitKey(1)=='q')break;
}

	return 0;
}

