#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <stack>
using namespace std;
using namespace cv;
Mat var1 = imread("shapes.jpg", 1);
stack<Point2d> st;
Point2d z;
void CallBackFunc(int event, int y, int x, int flags, void* userdata)
{
	int m, n, a, b;
	if (event == EVENT_LBUTTONDOWN)
	{
		st.push(Point2d(x, y));
		var1.at<Vec3b>(x, y)[1] = 0;
		var1.at<Vec3b>(x, y)[2] = 255;
		var1.at<Vec3b>(x, y)[0] = 0;
		while (st.empty() == 0)
		{
			a = st.top().x;
			b = st.top().y;
			st.pop();
			for (m = a - 1; m < a + 2; m++)
			{
				for (n = b - 1; n < b + 2; n++)
				{
					if (m>-1 && n>-1 && m<var1.rows && n<var1.cols && var1.at<Vec3b>(m, n)[0] == 255 && var1.at<Vec3b>(m, n)[1] == 255 && var1.at<Vec3b>(m, n)[2] == 255){
						st.push(Point2d(m, n));
						var1.at<Vec3b>(m, n)[2] = 255;
						var1.at<Vec3b>(m, n)[1] = 0;
						var1.at<Vec3b>(m, n)[0] = 0;
					}
				}
			}
		}
	}
	imshow("window1", var1);
}
int main()
{
	namedWindow("window1", WINDOW_AUTOSIZE);
	//set the callback function for any mouse event
	setMouseCallback("window1", CallBackFunc, NULL);
	waitKey(0);
	return 0;
}
