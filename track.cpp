#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;
Mat var,var2,img;
int threshold;
void thresh_callback(int, void *){
	var2;
	var2=Mat(var.rows,var.cols,CV_8UC1);
	img;
	img=Mat(var.rows,var.cols,CV_8UC1);
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			img.at<uchar>(i,j)=(var.at<Vec3b>(i,j)[0]+var.at<Vec3b>(i,j)[1]+var.at<Vec3b>(i,j)[2])/3;
		}
	}
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			if(img.at<uchar>(i,j)<threshold)
				var2.at<uchar>(i,j)=0;
			else
				var2.at<uchar>(i,j)=255;
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
	createTrackbar("threshold","Trackbars",&threshold,255,thresh_callback);
	thresh_callback(0,0);
	/*imshow("Display2",var);
	imshow("Display",var2);*/
	//waitKey(0);
}
