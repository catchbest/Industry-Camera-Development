#include "stdafx.h"
#include "CKSJToOpencv.h"
#define MAKEWIDTHBYTES( PIXELW, BITCOUNT )      (((( BITCOUNT * PIXELW ) + 31) / 32) * 4)//计算4对齐一行的字节数

int ConvertKSJToOpencv3(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, Mat **ppcvImg)//ppcvImg在接口调用后需要释放
{
	int nLineByte = MAKEWIDTHBYTES(nWidth, nBitCount);//计算4对齐一行的字节数
	if (nBitCount == 8)//根据位图深度初始化Mat，构造函数为浅拷贝，随pImageData变化
	{
		*ppcvImg = new Mat(nHeight, nWidth, CV_8UC1, pImageData, nLineByte);
	}
	else if (nBitCount == 24)
	{
		*ppcvImg = new Mat(nHeight, nWidth, CV_8UC3, pImageData, nLineByte);
	}
	else if (nBitCount == 32)
	{
		*ppcvImg = new Mat(nHeight, nWidth, CV_8UC3, pImageData, nLineByte);
	}
	else
	{
		return -1;
	}

	flip(**ppcvImg, **ppcvImg, 0);
	**ppcvImg = (*ppcvImg)->clone();//深拷贝，ppcvImg不受pImageData影响
	return 0;
}

int ConvertOpnecv3ToKSJ(Mat cvImg, unsigned char ** ppImageData)//ppImageData在接口调用后需要释放
{
	if (cvImg.step[1] != 1 && cvImg.step[1] != 3 && cvImg.step[1] != 4)
	{
		return -1;
	}
	
	int nLineByte = MAKEWIDTHBYTES(cvImg.cols, cvImg.step[1] * 8);
	unsigned char * pTempData = new unsigned char[nLineByte * cvImg.rows];
	flip(cvImg, cvImg, 0);
	int nWidthByte = cvImg.cols * cvImg.step[1];
	for (int i = 0; i < cvImg.rows; i++)//深拷贝，ppImageData不受cvImg影响
	{
		memcpy(pTempData + i * nLineByte, cvImg.data + i * nWidthByte, nWidthByte);
	}

	*ppImageData = pTempData;
	return 0;
}