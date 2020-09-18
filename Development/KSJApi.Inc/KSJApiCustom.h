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

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置全局复位滚动快门
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bGlobalReset [in] 设置全局复位滚动快门生效
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterSet(int nIndex, bool bGlobalReset);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到全局复位滚动快门状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbGlobalReset[out] 返回全局复位滚动快门状态指针
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterGet(int nIndex, bool* pbGlobalReset);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperStretchBmp
    /// @brief     将pData(宽度为nWidth, 高度为nHeight, 比特位数为nBitCount)的图像数据缩放为宽度为nStretchWidh, 高度为nStretchHeight的数据并填充到用户分配的pStretchData缓冲区,比特位数不变
    /// 参数：
	/// @param     pData [in] 输入图像的数据指针
    /// @param     nWidth [in] 输入图像的宽度
    /// @param     nHeight [in] 输入图像的高度
    /// @param     nBitCount [in] 输入图像的比特深度
	/// @param     pStretchData [out] 输出图像保存内存地址指针
    /// @param     nStretchWidth [out] 输出图像的宽度
    /// @param     nStretchHeight [out] 输出图像的高度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeaderSize
    /// @brief     根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
    /// 参数：
	/// @param     nBitCount [in] 图像的比特深度
    /// @param     pnTotalBytes [out] BMP的文件头，信息头，以及颜色表的总字节数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeader
    /// @brief     得到BMP图像的文件头和信息头
    /// 参数：
	/// @param     nWidth [in] 图像的宽度
    /// @param     nHeight [in] 图像的高度
    /// @param     nBitCount [in] 图像的比特深度
    /// @param     pHeader [out] BMP的文件头和信息头数据保存的地址指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataToClipboard
    /// @brief     采集一帧图像到系统剪贴板，从一个相机采集一帧图像并放到系统的剪切板
    /// 参数：
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nIndex);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SetFlatFieldCorrectionFieldOfView
    /// @brief     设置FFC校正参考视场
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nColStart [in] 校正视场的水平像素起始位置
    /// @param     nRowStart [in] 校正视场的垂直行起始位置
	/// @param     nColSize [in] 校正视场的水平像素数
    /// @param     nRowSize [in] 校正视场的垂直像素数
    /// @param     AmCol [in] 校正视场列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     AmRow [in] 校正视场行抽点模式（请参考“凯视佳工业相机API函数说明书-基础篇”KSJ_ADDRESSMODE的定义）
	/// @param     wMultiFrameNum [in] 校正视场拼接帧数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFlatFieldCorrectionFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetFlatFieldCorrectionFieldOfView
    /// @brief     设置FFC校正参考视场
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返回校正视场的水平像素起始位置
    /// @param     pnRowStart [out] 返回校正视场的垂直行起始位置
	/// @param     pnColSize [out] 返回校正视场的水平像素数
    /// @param     pnRowSize [out] 返回校正视场的垂直像素数
    /// @param     pColAddressMode [out] 返回校正视场列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pRowAddressMode [out] 返回校正视场行抽点模式（请参考“凯视佳工业相机API函数说明书-基础篇”KSJ_ADDRESSMODE的定义）
	/// @param     pwMultiFrameNum [out] 返回校正视场拼接帧数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeDarkFrame
    /// @brief     获取参考黑图
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nDarkFrames [in] 采集多少张黑图做平均
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nIndex, int nDarkFrames);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeFlatFieldFrame
    /// @brief     获取参考白图
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nFlatFieldFrames [in] 采集多少张白图做平均
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nIndex, int nFlatFieldFrames);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetFlatFieldCorrection
    /// @brief     对预览流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时开启FFC校正, false时关闭FFC校正
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     获取当前预览流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回FFC对于预览的使能状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetFlatFieldCorrection
    /// @brief     对采集流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时开启FFC校正, false时关闭FFC校正
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     获取采集时是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回FFC对于采集的使能状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SaveFlatFieldCorrection
    /// @brief     保存FFC当前的参考值
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 保存的文件名（完整路径）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadFlatFieldCorrection
    /// @brief     用于加载由KSJ_SaveFlatFieldCorrection保存的FFC参考信息文件
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 需要加载的FFC参考信息的文件名（完整路径）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);


	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetCalibration
    /// @brief     对预览流是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetCalibration
    /// @brief     获取当前预览流是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回畸变矫正对于预览的使能状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetCalibration
    /// @brief     对采集是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureGetCalibration
    /// @brief     获取采集时是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回畸变矫正对于采集的使能状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadCalibrationMapFile
    /// @brief     用于从文件加载畸变校正参数信息
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 需要加载载畸变校正参数的文件名（完整路径）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nIndex, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE ///凯视佳工业相机畸变校正目标值计算方式定义
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SetCalibrationMapMode
    /// @brief     设置畸变校正目标值计算方法
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     MapMode [in] 设置畸变校正目标值计算方法
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetCalibrationMapMode
    /// @brief     获取畸变校正目标值计算方法
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pMapMode [out] 当前畸变校正目标值的计算方法
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nIndex, KSJ_MAPMODE *pMapMode);


	enum KSJ_SNAPBUTTONSTATUS ///Snap功能引脚状态
	{
		KSJ_UP, 	///按键处于闭合状态
		KSJ_DOWN 	///按键处于开启状态
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     读取Snap功能引脚状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pSnapButtonStatus [out] 返回Snap功能引脚状态, KSJ_SNAPBUTTONSTATUS类型
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus(int nIndex, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到预曝光时间范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinValue[out] 设置预曝光时间最小值指针，单位为曝光行
	/// @param     pnMaxValue[out] 设置预曝光时间最大值指针，单位为曝光行
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置预曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fPreExpTimeMs [in] 设置的预曝光时间
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取预曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfPreExpTimeMs[out] 返回预曝光时间的指针
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置预曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nPreExpLines [in] 设置的预曝光行
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取预曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnPreExpLines[out] 返回预曝光时间的指针
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);

#ifdef __cplusplus
}
#endif

#endif
