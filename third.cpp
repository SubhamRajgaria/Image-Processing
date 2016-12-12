#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
	Mat img,img2,img3;
	img=imread("/home/subham/Image_Processing/index.jpeg",1);
	img2=Mat(img.rows*2,img.cols*2,CV_8UC3);
	img3=Mat(img.rows,img.cols,CV_8UC3);
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
			img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
		}
	}
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			img2.at<Vec3b>(i,img.cols+j)[0]=img.at<Vec3b>(i,img.cols-1-j)[0];
			img2.at<Vec3b>(i,img.cols+j)[1]=img.at<Vec3b>(i,img.cols-1-j)[1];
			img2.at<Vec3b>(i,img.cols+j)[2]=img.at<Vec3b>(i,img.cols-1-j)[2];
		}
	}
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols/2;j++){
			img3.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			img3.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
			img3.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
		}
	}
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols/2;j++){
			img3.at<Vec3b>(i,img.cols/2+j)[0]=img.at<Vec3b>(i,img.cols/2-1-j)[0];
			img3.at<Vec3b>(i,img.cols/2+j)[1]=img.at<Vec3b>(i,img.cols/2-1-j)[1];
			img3.at<Vec3b>(i,img.cols/2+j)[2]=img.at<Vec3b>(i,img.cols/2-1-j)[2];
		}
	}
	imshow("Display Window",img3);
	waitKey(0);
}