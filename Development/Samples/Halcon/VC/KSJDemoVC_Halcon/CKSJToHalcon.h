#ifndef CKSJTOHANCON_H
#define CKSJTOHANCON_H
#define HALCON11

#ifdef HALCON11
#define HCPP_LEGACY_API
#include "HalconCpp.h"
#pragma comment( lib, "halconcpp.lib" )
using namespace HalconCpp;
int  ConvertKSJToHalcon11(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, HObject *Halcon_Image);
int  ConvertHalcon11ToKSJ(HObject Image, unsigned char ** ppImageData);

#else
#define HCPP_LEGACY_API
#include "HalconCpp.h"
#pragma comment( lib, "halconcpp.lib" )
using namespace Halcon;
int  ConvertKSJToHalcon10(unsigned char * pImageData, int nWidth, int nHeight, int nBitCount, Hobject *Halcon_Image);
int  ConvertHalcon10ToKSJ(Hobject Image, unsigned char ** ppImageData);
#endif



#endif // CKSJTOHANCON_H