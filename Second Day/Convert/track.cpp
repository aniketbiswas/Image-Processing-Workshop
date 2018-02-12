#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv ;
using namespace std ;

int main()
{

	int 	a=125, i,j;
	Mat var1 = imread("testing.jpg",1);
	Mat var2 (var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	
	namedWindow("wind",WINDOW_AUTOSIZE);
	//imshow("window1",var1)	;
	
	//waitKey(0);
	
	for( i=0;i<var1.rows;i++){
		for(j=0;j<var1.cols;j++)
		{
			var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var2.at<Vec3b>(i,j)[2])/3	;

		}
}

	createTrackbar("track","wind",&a,255);
	while(1)
	{
	for( i=0;i<var1.rows;i++)
	{
			for(j=0;j<var1.cols;j++)
				{
					if(var2.at<uchar>(i,j)>=a)
					var3.at<uchar>(i,j)=255;
					else
					var3.at<uchar>(i,j)=0;
				}
	// namedWindow("window3",WINDOW_AUTOSIZE);
        

	}
	imshow("wind",var3);
	if(waitKey(1)=='q')break;
		//namedWindow("window2",WINDOW_AUTOSIZE);
	//imshow("window2",var2)	;

//	namedWindow("window3",WINDOW_AUTOSIZE);
//	imshow("winodow3",var3);







}

	
	return 0;
}
