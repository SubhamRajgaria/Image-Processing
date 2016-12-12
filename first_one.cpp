#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
	/*if(argc !=2)
	{
		cout<< "Usage:display_image ImageToLoadAndDisplay"<<endl;
		return -1;
	}*/
	Mat var;
	var=imread("/home/subham/Image_Processing/index.jpeg",2);
	if(!var.data)
	{
		cout<< "COuld not open or find the image";
		return -1;
	}
	cout<< var.rows<<endl;
	cout << var.cols<<endl;
	namedWindow("Display Window",WINDOW_AUTOSIZE);
	imshow("Display Window",var);
	waitKey(0);
	return 0;
}
