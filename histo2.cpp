#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",1);
	Mat img;
	int red[256],blue[256],green[256];
	int count_b,count_g,count_r,max_b=0,max_g=0,max_r=0,count;
	for(int k=0;k<256;k++){
		count_b=0,count_g=0,count_r=0;
		red[k]=0,blue[k]=0,green[k]=0;
		for(int i=0;i<var.rows;i++){
			for(int j=0;j<var.cols;j++){
				if(var.at<Vec3b>(i,j)[0]==k)
					count_b++;
				if(var.at<Vec3b>(i,j)[1]==k)
					count_g++;
				if(var.at<Vec3b>(i,j)[2]==k)
					count_r++;
			}
		}
		if(count_b>max_b)
			max_b=count_b;
		if(count_g>max_g)
			max_g=count_g;
		if(count_r>max_r)
			max_r=count_r;
		red[k]=count_r;
		blue[k]=count_b;
		green[k]=count_g;
	}
	int tot=max(max(max_r,max_b),max_g);
	tot=tot/4;
	img=Mat(tot+2,256,CV_8UC3,Scalar(255,255,255));
	/*imshow("Display Test",img);
	waitKey(0);*/
	count=0;
	while(count<256){
		img.at<Vec3b>((tot+2)-red[count]/4,count)[0]=0;
		img.at<Vec3b>((tot+2)-red[count]/4,count)[1]=0;
		count++;
	}
	count=0;
	while(count<256){
		img.at<Vec3b>((tot+2)-blue[count]/4,count)[1]=0;
		img.at<Vec3b>((tot+2)-blue[count]/4,count)[2]=0;
		count++;
	}
	count=0;
	while(count<256){
		img.at<Vec3b>((tot+2)-green[count]/4,count)[2]=0;
		img.at<Vec3b>((tot+2)-green[count]/4,count)[0]=0;
		count++;
	} 
	for(int i=0;i<256;i++){
		cout<<red[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<256;i++){
		cout<<green[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<256;i++){
		cout<<blue[i]<<" ";
	}
	cout<<endl;
	imshow("Display",img);
	waitKey(0);
	return 0;
}