// DIP_Sudoku_VS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

typedef struct Pixel {
	int blue;
	int green;
	int red;
};

Pixel getPixelColor(Mat img, int x, int y) {
	Vec3b intensity = img.at<Vec3b>(y, x);
	Pixel pixel;
	pixel.blue = (int)intensity.val[0];
	pixel.green = (int)intensity.val[1];
	pixel.red = (int)intensity.val[2];
	return pixel;
}

void setPixelColor(Mat img, int x, int y, Pixel pixel) {
	Vec3b intensity;
	intensity.val[0] = (uchar)pixel.blue;
	intensity.val[1] = (uchar)pixel.green;
	intensity.val[2] = (uchar)pixel.red;
	img.at<Vec3b>(y, x) = intensity;
}

bool sudokuDetector(Mat img, int sudoku[9][9]) {
	// code here
	return true;
}

void sudokuResolver(int sudoku[9][9]) {
	// code here
}

void showSudokuInCommandLine(int sudoku[9][9]) {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << " " << sudoku[y][x];
		}
		cout << endl;
	}
}


int main()
{
	Mat img = imread("Test.png", CV_LOAD_IMAGE_UNCHANGED); 

	// Example sudoku
	int sudoku[9][9] = {
		{ 5,3,0,0,7,0,0,0,0 },
		{ 6,0,0,1,9,5,0,0,0 },
		{ 0,9,8,0,0,0,0,6,0 },
		{ 8,0,0,0,6,0,0,0,3 },
		{ 4,0,0,8,0,3,0,0,1 },
		{ 7,0,0,0,2,0,0,0,6 },
		{ 0,6,0,0,0,0,2,8,0 },
		{ 0,0,0,4,1,9,0,0,5 },
		{ 0,0,0,0,8,0,0,7,9 }
	};

	if (img.empty())
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		return -1;
	}

	// Shows sudoku in the command line terminal , for debug use
	showSudokuInCommandLine(sudoku);



	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); 
	imshow("MyWindow", img); 

	waitKey(0); 

	destroyWindow("MyWindow"); 

	return 0;
}

