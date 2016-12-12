#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;
Mat var,var2,img;
int r_low,r_high;
int g_low,g_high;
int b_low,b_high;
void thresh_callback(int, void *){
	var2;
	var2=Mat(var.rows,var.cols,CV_8UC3,Scalar(255,255,255));
	/*img;
	img=Mat(var.rows,var.cols,CV_8UC1);
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			img.at<uchar>(i,j)=(var.at<Vec3b>(i,j)[0]+var.at<Vec3b>(i,j)[1]+var.at<Vec3b>(i,j)[2])/3;
		}
	}*/
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			if(var.at<Vec3b>(i,j)[0]>=b_low && var.at<Vec3b>(i,j)[0]<=b_high ){
				if(var.at<Vec3b>(i,j)[1]>=g_low && var.at<Vec3b>(i,j)[1]<=g_high){
					if(var.at<Vec3b>(i,j)[2]>=r_low && var.at<Vec3b>(i,j)[2]<=r_high){
						var2.at<Vec3b>(i,j)[0]=var.at<Vec3b>(i,j)[0];
						var2.at<Vec3b>(i,j)[1]=var.at<Vec3b>(i,j)[1];
						var2.at<Vec3b>(i,j)[2]=var.at<Vec3b>(i,j)[2];
					}
				}
			}
		}
	}
	imshow("Display2",var);
	imshow("Display",var2);
	waitKey(0);
}
int main()
{
	var=imread("/home/subham/Image_Processing/dest.jpg",1);
	namedWindow("Trackbars",WINDOW_AUTOSIZE);
	createTrackbar("r_low","Trackbars",&r_low,255,thresh_callback);
	createTrackbar("r_high","Trackbars",&r_high,255,thresh_callback);
	createTrackbar("g_low","Trackbars",&g_low,255,thresh_callback);
	createTrackbar("g_high","Trackbars",&g_high,255,thresh_callback);
	createTrackbar("b_low","Trackbars",&b_low,255,thresh_callback);
	createTrackbar("b_high","Trackbars",&b_high,255,thresh_callback);
	thresh_callback(0,0);
	imshow("Display2",var);
	imshow("Display",var2);
	waitKey(0);
}
