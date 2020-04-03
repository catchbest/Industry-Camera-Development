#include "stdafx.h"
#include "CKSJToOpencv.h"
#define MAKEWIDTHBYTES( PIXELW, BITCOUNT )      (((( BITCOUNT * PIXELW ) + 31) / 32) * 4)//����4����һ�е��ֽ���

int ConvertKSJToOpencv3(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, Mat **ppcvImg)//ppcvImg�ڽӿڵ��ú���Ҫ�ͷ�
{
	int nLineByte = MAKEWIDTHBYTES(nWidth, nBitCount);//����4����һ�е��ֽ���
	if (nBitCount == 8)//����λͼ��ȳ�ʼ��Mat�����캯��Ϊǳ��������pImageData�仯
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
	**ppcvImg = (*ppcvImg)->clone();//�����ppcvImg����pImageDataӰ��
	return 0;
}

int ConvertOpnecv3ToKSJ(Mat cvImg, unsigned char ** ppImageData)//ppImageData�ڽӿڵ��ú���Ҫ�ͷ�
{
	if (cvImg.step[1] != 1 && cvImg.step[1] != 3 && cvImg.step[1] != 4)
	{
		return -1;
	}
	
	int nLineByte = MAKEWIDTHBYTES(cvImg.cols, cvImg.step[1] * 8);
	unsigned char * pTempData = new unsigned char[nLineByte * cvImg.rows];
	flip(cvImg, cvImg, 0);
	int nWidthByte = cvImg.cols * cvImg.step[1];
	for (int i = 0; i < cvImg.rows; i++)//�����ppImageData����cvImgӰ��
	{
		memcpy(pTempData + i * nLineByte, cvImg.data + i * nWidthByte, nWidthByte);
	}

	*ppImageData = pTempData;
	return 0;
}