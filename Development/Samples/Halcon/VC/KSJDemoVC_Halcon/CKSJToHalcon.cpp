#include "CKSJToHalcon.h"
#define MAKEWIDTHBYTES( PIXELW, BITCOUNT )      (((( BITCOUNT * PIXELW ) + 31) / 32) * 4)//计算4对齐一行的字节数

#ifdef HALCON11
int ConvertKSJToHalcon11(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, HObject *Halcon_Image)
{
	HObject  Halcon_Image_Convert;
#else
int ConvertKSJToHalcon10(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, Hobject *Halcon_Image)
{
	Hobject Halcon_Image_Convert;
#endif

	int nLineByte = MAKEWIDTHBYTES(nWidth, nBitCount);
	int nPixel = nBitCount / 8;
	if (nBitCount == 8)//根据位图深度调用相应接口
	{
		gen_image1(&Halcon_Image_Convert, "byte", nLineByte, nHeight, (long)pImageData);//深拷贝
	}
	else if (nBitCount == 24 || nBitCount == 32)
	{
		unsigned char  *pImage_red   = new unsigned char[nWidth * nHeight];
		unsigned char  *pImage_green = new unsigned char[nWidth * nHeight];
		unsigned char  *pImage_blue  = new unsigned char[nWidth * nHeight];

		for (int i = 0; i < nHeight; i++)//将像素中的红、绿、蓝分开保存
		{
			int nOffset = i * nWidth;
			int nRealOffset = i * nLineByte;
			for (int j = 0; j < nWidth; j++)
			{
				int nPixelOffset = j * nPixel;
				pImage_red[nOffset + j]   = pImageData[nRealOffset + nPixelOffset + 2];
				pImage_green[nOffset + j] = pImageData[nRealOffset + nPixelOffset + 1];
				pImage_blue[nOffset + j]  = pImageData[nRealOffset + nPixelOffset];
			}
		}

		gen_image3(&Halcon_Image_Convert, "byte", nWidth, nHeight, (long)pImage_red, (long)pImage_green, (long)pImage_blue);//深拷贝

		delete[]pImage_red;
		delete[]pImage_green;
		delete[]pImage_blue;
	}
	else
	{
		return -1;
	}

	//mirror_image(Halcon_Image_Convert, &Halcon_Image_Convert, "row");//上下反转图片
	*Halcon_Image = Halcon_Image_Convert;
	return 0;
}

#ifdef HALCON11
int ConvertHalcon11ToKSJ(HObject Image, unsigned char ** ppImageData)//ppImageData在接口调用后需要释放
{
#else
int ConvertHalcon10ToKSJ(Hobject Image, unsigned char ** ppImageData)
{
#endif

	mirror_image(Image, &Image, "row");//上下反转图片
	HTuple     Hchannels;
	count_channels(Image, &Hchannels);
	int nChannels = Hchannels[0].I();
	HTuple     Htype;
	HTuple     Hwidth, Hheight;
	unsigned char * pTempData = NULL;
	if (nChannels == 1)//根据位图深度调用相应接口
	{
		HTuple hpoint;
		get_image_pointer1(Image, &hpoint, &Htype, &Hwidth, &Hheight);
		int nLineByte = MAKEWIDTHBYTES(Hwidth[0].I(), 8);
		pTempData = new unsigned char[nLineByte * Hheight[0].I()];
		unsigned char *  ptr = (unsigned char *)hpoint[0].L();
		for (int i = 0; i < Hheight[0].I(); i++)//深拷贝
		{
			memcpy(pTempData + i * nLineByte, ptr + i * Hwidth[0].I(), Hwidth[0].I());
		}
	}
	else if (nChannels == 3 || nChannels == 4)
	{
		HTuple Hred;
		HTuple Hgreen;
		HTuple Hblue;
		get_image_pointer3(Image, &Hred, &Hgreen, &Hblue, &Htype, &Hwidth, &Hheight);
		int nLineByte = MAKEWIDTHBYTES(Hwidth[0].I(), nChannels * 8);
		pTempData = new unsigned char[nLineByte * Hheight[0].I()];
		unsigned char *  ptr_red   = (unsigned char *)Hred[0].L();
		unsigned char *  ptr_green = (unsigned char *)Hgreen[0].L();
		unsigned char *  ptr_blue  = (unsigned char *)Hblue[0].L();
		for (int i = 0; i < Hheight[0].I(); i++)//将红、绿、蓝保存到像素中
		{
			int nOffset     = i * Hwidth[0].I();
			int nRealOffset = i * nLineByte;
			for (int j = 0; j < Hwidth[0].I(); j++)//深拷贝
			{
				int nPixelOffset = j * nChannels;
				pTempData[nRealOffset + nPixelOffset + 2] = ptr_red[nOffset + j];
				pTempData[nRealOffset + nPixelOffset + 1] = ptr_green[nOffset + j];
				pTempData[nRealOffset + nPixelOffset]	  = ptr_blue[nOffset + j];
			}
		}
	}
	else
	{
		return -1;
	}

	*ppImageData = pTempData;
	return 0;
}