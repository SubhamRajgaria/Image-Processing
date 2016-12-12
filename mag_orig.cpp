#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int main(){
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	Mat var2;
	float magni;
	cout<< "Enter maginification\n";
	cin>>magni;
	int mg=int(sqrt(abs(magni)));
	var2=Mat(abs(mg)*var.rows,abs(mg)*var.cols,CV_8UC3);
	if(magni>=0){
		for(int i=0;i<var2.rows;i++)
		{
			for(int j=0;j<var2.cols;j++){
					var2.at<Vec3b>(i,j)[0]=var.at<Vec3b>(i/(mg),j/(mg))[0];
					var2.at<Vec3b>(i,j)[1]=var.at<Vec3b>(i/(mg),j/(mg))[1];
					var2.at<Vec3b>(i,j)[2]=var.at<Vec3b>(i/(mg),j/(mg))[2];
			}
				
		}
	}
	else{
		for(int i=0;i<var2.rows;i++){
			for(int j=0;j<var2.cols;j++){
				var2.at<Vec3b>(i,j)[0]=var.at<Vec3b>((var2.rows-1-i)/abs(mg),(var2.cols-1-j)/abs(mg))[0];
				var2.at<Vec3b>(i,j)[1]=var.at<Vec3b>((var2.rows-1-i)/abs(mg),(var2.cols-1-j)/abs(mg))[1];
				var2.at<Vec3b>(i,j)[2]=var.at<Vec3b>((var2.rows-1-i)/abs(mg),(var2.cols-1-j)/abs(mg))[2];
			}
		}
	}
	imshow("Display",var2);
	waitKey(0);
}