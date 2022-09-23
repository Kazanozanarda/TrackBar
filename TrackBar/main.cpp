#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int a = 0;
int mavi, yesil, kirmizi;
void kirmizirenk(int,void*)
{
	kirmizi++;
}
void yesilrenk(int, void*)
{
	yesil++;
}
void mavirenk(int, void*)
{
	mavi++;
}
void goster()
{
	namedWindow("Track", WINDOW_AUTOSIZE);
	createTrackbar("M", "Track", &mavi, 255, mavirenk);
	createTrackbar("Y", "Track", &yesil, 255, yesilrenk);
		createTrackbar("K", "Track", &kirmizi, 255, kirmizirenk);
	Mat x(400, 400, CV_8UC3, Scalar(mavi, yesil, kirmizi));
	imshow("Goruntu", x);
}
void yenile(int, void*)
{
	cout << a << endl;
	if (a == 1)
	{
		goster();
	}
	else if (a == 0) destroyWindow("Goruntu");

	a++;
}

int main()
{
	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	createTrackbar("Yenile", "Trackbars", &a, 1, yenile);
	waitKey(0);
	
}
