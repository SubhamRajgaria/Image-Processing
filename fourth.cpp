#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int make_white(Mat img, int i, int j)
{
	for(int k=64*i;k<64*(i+1);k++)
	{
		for(int l=j;l<j+64;l++){
			img.at<Vec3b>(k,l)[0]=255;
			img.at<Vec3b>(k,l)[1]=255;
			img.at<Vec3b>(k,l)[2]=255;
		}
	}
}
/*int make_black(Mat img, int i, int j)
{
	for(int k=4*i;k<4*(i+1);k++)
	{
		for(int l=j;l<j+4;l++){
			img.at<Vec3b>(k,l)[0]=255;
			img.at<Vec3b>(k,l)[1]=255;
			img.at<Vec3b>(k,l)[2]=255;
		}
	}
}*/


int main(int argc, char **argv){
	Mat img;
	img=Mat(512,512,CV_8UC3,Scalar(0,0,0));
	int count=0;
	for(int i=0;i<8;i++){
			for(int j=0;j<512;j=j+64){
				if(count%2==1){
					make_white(img,i,j);
				}
				count++;
			}
			count++;
	}
	imshow("Checker",img);
	waitKey(0);
}
