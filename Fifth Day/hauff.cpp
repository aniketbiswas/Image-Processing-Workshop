#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cmath>
using namespace cv;
using namespace std;

int main(){
		Mat var = imread("g.png",0);
		int r = sqrt(var.rows*var.rows + var.cols*var.cols),thresh=50;
		int d = 1;
		int m[r][360];
		for(int i=0;i<r;i++){
				for(int j=0;j<360;j++)m[i][j]=0;
		}
		for(int i=0;i<var.rows;i++){
				for(int j=0;j<var.cols;j++){
						if(var.at<uchar>(i,j)==0){
								for(int k=0;k<r;k++){
										for(int th=0;th<360;th++){
												if(fabs((float)i*cos(th) + (float)j*sin(th) - (float)(k+1))<=d){
														m[k][th]++;
												}
										}
								}
						}
				}
		}	
		Mat var1(var.rows,var.cols,CV_8UC1,Scalar(255));
		int x,y;
		for(int i=0;i<r;i++){
				for(int j=0;j<360;j++){
						if(m[i][j]>=thresh){
								for(d=-r;d<=r;d++){
										x = (int)((float)i*cos(j) + d*sin(j));
										y = (int)((float)i*sin(j) + d*cos(j));
										if(x>=0 && x<var.rows && y>=0 && y<var.cols)var1.at<uchar>(x,y) = 0;
								}
						}
				}
		}
		namedWindow("window",WINDOW_AUTOSIZE);
		imshow("window",var);
		namedWindow("window1",WINDOW_AUTOSIZE);
		imshow("window1",var1);
		waitKey(0);
}
