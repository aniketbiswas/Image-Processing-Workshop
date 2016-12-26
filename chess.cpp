#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

int main(){
    Mat var(800, 800, CV_8UC1, Scalar(255));
    int i, j, x, y;
    x = y = 0;

   for(x = 0; x < var.rows; x += var.rows/5)
        for(y = 0; y < var.cols; y += var.cols/5)
            for(i = 0; i < 80; i++)
                for(j = 0; j < 80; j++)
                {
			var.at<uchar>(x + i, y + j) = 0;
			var.at<uchar>(x + i+80, y + j+80) = 0;
			
			
		}
		

 

    namedWindow("Chess Board", WINDOW_AUTOSIZE);
    imshow("Chess Board", var);
    waitKey(0);

    return 0;
}
