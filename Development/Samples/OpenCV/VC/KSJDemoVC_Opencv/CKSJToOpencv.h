
#include "opencv.Inc\opencv\cv.hpp"
#include "opencv.Inc\opencv\highgui.h"
#include "opencv.Inc\opencv\cxcore.hpp"
#pragma comment(lib, "opencv.Lib\\opencv_world300.lib")
using namespace std;
using namespace cv;

int ConvertKSJToOpencv3(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, Mat **ppcvImg);
int ConvertOpnecv3ToKSJ(Mat cvImg, unsigned char ** ppImageData);