#ifndef __KSJ_API_CUSTOM_H__
#define __KSJ_API_CUSTOM_H__

// #pragma message("Include KSJApiCustom.h") 

#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"{
#endif

	//-----------------------------------------------------------------------------
    // 函数：KSJ_HelperStretchBmp
    // 功能：将pData(宽度为nWidth, 高度为nHeight, 比特位数为nBitCount)的图像数据缩放为宽度为nStretchWidh, 高度为nStretchHeight的数据并填充到用户分配的pStretchData缓冲区,比特位数不变
    // 参数：
	//       pData： 输入，输入图像的数据指针
    //       nWidth： 输入，输入图像的宽度
    //       nHeight：输入，输入图像的高度
    //       nBitCount：输入，输入图像的比特深度
	//       pStretchData： 输出，输出图像保存内存地址指针
    //       nStretchWidth： 输出，输出图像的宽度
    //       nStretchHeight：输出，输出图像的高度
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_HelperGetBmpFileHeaderSize
    // 功能：根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
    // 参数：
	//       nBitCount： 输入，图像的比特深度
    //       pnTotalBytes：输出，BMP的文件头，信息头，以及颜色表的总字节数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_HelperGetBmpFileHeader
    // 功能：得到BMP图像的文件头和信息头
    // 参数：
	//       nWidth： 输入，图像的宽度
    //       nHeight：输入，图像的高度
    //       nBitCount：输入，图像的比特深度
    //       pHeader：输出，BMP的文件头和信息头数据保存的地址指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureRgbDataToClipboard
    // 功能：采集一帧图像到系统剪贴板，从一个相机采集一帧图像并放到系统的剪切板
    // 参数：
    //       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nChannel);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_SetFlatFieldCorrectionFieldOfView
    // 功能：设置FFC校正参考视场
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       nColStart： 输入，校正视场的水平像素起始位置
    //       nRowStart：输入，校正视场的垂直行起始位置
	//       nColSize：输入，校正视场的水平像素数
    //       nRowSize：输入，校正视场的垂直像素数
    //       AmCol：输入，校正视场列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       AmRow：输入，校正视场行抽点模式（请参考“凯视佳工业相机API函数说明书-基础篇”KSJ_ADDRESSMODE的定义）
	//       wMultiFrameNum：输入，校正视场拼接帧数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFlatFieldCorrectionFieldOfView(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_GetFlatFieldCorrectionFieldOfView
    // 功能：设置FFC校正参考视场
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pnColStart： 输出，返回校正视场的水平像素起始位置
    //       pnRowStart：输出，返回校正视场的垂直行起始位置
	//       pnColSize：输出，返回校正视场的水平像素数
    //       pnRowSize：输出，返回校正视场的垂直像素数
    //       pColAddressMode：输出，返回校正视场列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       pRowAddressMode：输出，返回校正视场行抽点模式（请参考“凯视佳工业相机API函数说明书-基础篇”KSJ_ADDRESSMODE的定义）
	//       pwMultiFrameNum：输出，返回校正视场拼接帧数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_MakeDarkFrame
    // 功能：获取参考黑图
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nDarkFrames：输入，采集多少张黑图做平均
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nChannel, int nDarkFrames);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_MakeFlatFieldFrame
    // 功能：获取参考白图
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nFlatFieldFrames：输入，采集多少张白图做平均
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nChannel, int nFlatFieldFrames);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewSetFlatFieldCorrection
    // 功能：对预览流是否进行FFC校正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，为true时开启FFC校正, false时关闭FFC校正
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewGetFlatFieldCorrection
    // 功能：获取当前预览流是否进行FFC校正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回FFC对于预览的使能状态
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nChannel, bool *pbEnable);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetFlatFieldCorrection
    // 功能：对采集流是否进行FFC校正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，为true时开启FFC校正, false时关闭FFC校正
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewGetFlatFieldCorrection
    // 功能：获取采集时是否进行FFC校正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回FFC对于采集的使能状态
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_SaveFlatFieldCorrection
    // 功能：保存FFC当前的参考值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pszFilePath：输入，保存的文件名（完整路径）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nChannel, TCHAR *pszFilePath);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_LoadFlatFieldCorrection
    // 功能：用于加载由KSJ_SaveFlatFieldCorrection保存的FFC参考信息文件
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pszFilePath：输入，需要加载的FFC参考信息的文件名（完整路径）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nChannel, TCHAR *pszFilePath);


	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewSetCalibration
    // 功能：对预览流是否进行畸变矫正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，为true时时开启畸变矫正, false时关闭畸变矫正
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewGetCalibration
    // 功能：获取当前预览流是否进行畸变矫正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回畸变矫正对于预览的使能状态
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nChannel, bool *pbEnable);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetCalibration
    // 功能：对采集是否进行畸变矫正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，为true时时开启畸变矫正, false时关闭畸变矫正
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureGetCalibration
    // 功能：获取采集时是否进行畸变矫正处理
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回畸变矫正对于采集的使能状态
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_LoadCalibrationMapFile
    // 功能：用于从文件加载畸变校正参数信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pszFilePath：输入，需要加载载畸变校正参数的文件名（完整路径）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nChannel, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE //凯视佳工业相机畸变校正目标值计算方式定义
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_SetCalibrationMapMode
    // 功能：设置畸变校正目标值计算方法
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       MapMode：输入，设置畸变校正目标值计算方法
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nChannel, KSJ_MAPMODE MapMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GetCalibrationMapMode
    // 功能：获取畸变校正目标值计算方法
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pMapMode：输出，当前畸变校正目标值的计算方法
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nChannel, KSJ_MAPMODE *pMapMode);

#ifdef __cplusplus
}
#endif

#endif
