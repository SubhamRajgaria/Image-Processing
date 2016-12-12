#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	imshow("Display",var);
	waitKey(2000);
	Mat img;
	img=Mat(var.rows,var.cols,CV_8UC1);
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			img.at<uchar>(i,j)=(var.at<Vec3b>(i,j)[0]+var.at<Vec3b>(i,j)[1]+var.at<Vec3b>(i,j)[2])/3;
		}
	}
	imshow("Display",img);
	waitKey(10000);
}