#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int main()
{
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	Mat var2;
	var2=Mat(var.rows*2,var.cols*2,CV_8UC3);
	int count=0;
	/*for(int i=0;i<var.rows;i++)
	{
		for(int j=0;j<var.cols;j++){
			var2.at<Vec3b>(i*2,j*2)[0]=var.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(i*2+1,j*2)[0]=var.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(i*2,j*2+1)[0]=var.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(i*2+1,j*2+1)[0]=var.at<Vec3b>(i,j)[0];
			var2.at<Vec3b>(i*2,j*2)[1]=var.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(i*2+1,j*2)[1]=var.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(i*2,j*2+1)[1]=var.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(i*2+1,j*2+1)[1]=var.at<Vec3b>(i,j)[1];
			var2.at<Vec3b>(i*2,j*2)[2]=var.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(i*2+1,j*2)[2]=var.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(i*2,j*2+1)[2]=var.at<Vec3b>(i,j)[2];
			var2.at<Vec3b>(i*2+1,j*2+1)[2]=var.at<Vec3b>(i,j)[2];
		}
	}*/
	for(int i=0;i<2*var.rows;i++)
	{
		for(int j=0;j<2*var.cols;j++){
			var2.at<Vec3b>(i,j)[0]=var.at<Vec3b>(i/2,j/2)[0];
			var2.at<Vec3b>(i,j)[1]=var.at<Vec3b>(i/2,j/2)[1];
			var2.at<Vec3b>(i,j)[2]=var.at<Vec3b>(i/2,j/2)[2];
		}
	}
	imshow("Display",var);
	imshow("Display2",var2);
	waitKey(0);
}