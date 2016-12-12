//#include <opencv2/opencv2.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int main()
{
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	Mat var2;
	var2=Mat(var.rows,var.cols,CV_8UC1);
	Mat img,img2;
	img=Mat(var.rows,var.cols,CV_8UC1);
	cvtColor(var,img2,CV_BGR2GRAY);
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			img.at<uchar>(i,j)=(var.at<Vec3b>(i,j)[0]+var.at<Vec3b>(i,j)[1]+var.at<Vec3b>(i,j)[2])/3;
		}
	}
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			if(img.at<uchar>(i,j)<100)
				var2.at<uchar>(i,j)=0;
			else
				var2.at<uchar>(i,j)=255;
		}
	}
	imshow("Display2",var);
	imshow("Display",var2);
	imshow("Display 3",img2);
	waitKey(0);
}