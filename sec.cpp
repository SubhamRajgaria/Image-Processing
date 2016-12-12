#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	Mat img;
	img=Mat(50,50,CV_8UC3);
	for(int i=0;i<img.rows/3;i++){
		for(int j=0;j<img.cols;j++){
			img.at<Vec3b>(i,j)[0]=0;
			img.at<Vec3b>(i,j)[1]=69;
			img.at<Vec3b>(i,j)[2]=255;
		}
	}
	for(int i=img.rows/3;i<img.rows*2/3;i++){
		for(int j=0;j<img.cols;j++){
			img.at<Vec3b>(i,j)[0]=255;
			img.at<Vec3b>(i,j)[1]=255;
			img.at<Vec3b>(i,j)[2]=255;
		}
	}
	for(int i=img.rows*2/3;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			img.at<Vec3b>(i,j)[0]=0;
			img.at<Vec3b>(i,j)[1]=100;
			img.at<Vec3b>(i,j)[2]=0;
		}
	}
	imshow("Display Window",img);
	waitKey(0);
}
