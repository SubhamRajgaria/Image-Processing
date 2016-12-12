#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	Mat var2(var.rows, var.cols, CV_8UC3, Scalar(0, 0, 0));
	imshow("Display",var);
	for(int i=0;i<var.rows;i++){
		for(int j=0;j<var.cols;j++){
			var2.at<Vec3b>(i,j)[0]=(1.5*var.at<Vec3b>(i,j)[0]);
			var2.at<Vec3b>(i,j)[1]=(1.5*var.at<Vec3b>(i,j)[1]);
			var2.at<Vec3b>(i,j)[2]=(1.5*var.at<Vec3b>(i,j)[2]);
		}
	}
	imshow("Display2",var2);
	waitKey(2000);
}