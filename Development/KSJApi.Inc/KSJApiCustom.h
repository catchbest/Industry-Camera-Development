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

	enum KSJ_IMAGE_FORMAT
	{
		KSJ_IF_RAW8 = 0,
		KSJ_IF_GRAY8,
		KSJ_IF_RGB24,
		KSJ_IF_RGB32,
		KSJ_IF_BGR24,
		KSJ_IF_BGR32,
		KSJ_IF_RAW16,
		KSJ_IF_GRAY16,
		KSJ_IF_RGB48,
		KSJ_IF_RGB64,
		KSJ_IF_BGR48,
		KSJ_IF_BGR64,
	};

	KSJ_API  int __stdcall KSJ_SetImageFormat(IN int nIndex, IN KSJ_IMAGE_FORMAT ImageFormat);
	KSJ_API  int __stdcall KSJ_GetImageFormat(IN int nIndex, OUT KSJ_IMAGE_FORMAT *pImageFormat);

	////////////////////////////////////////////Capture/////////////////////////////////
	///-----------------------------------------------------------------------------
	///
	/// @brief     检测输入的视场参数与相机是否匹配
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [in] 要检测的水平像素起始位置
	/// @param     pnRowStart [in] 要检测的垂直行起始位置
	/// @param     pnColSize [in] 要检测的水平像素数
	/// @param     pnRowSize [in] 要检测的垂直行数
	/// @param     AmCol [in] 要检测的有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     AmRow [in] 要检测的有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    参考返回1表示匹配，否则不匹配
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置全局复位滚动快门
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bGlobalReset [in] 设置全局复位滚动快门生效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterSet(int nIndex, bool bGlobalReset);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到全局复位滚动快门状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbGlobalReset[out] 返回全局复位滚动快门状态指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeaderSize
    /// @brief     根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
    /// 参数：
	/// @param     nBitCount [in] 图像的比特深度
    /// @param     pnTotalBytes [out] BMP的文件头，信息头，以及颜色表的总字节数
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataToClipboard
    /// @brief     采集一帧图像到系统剪贴板，从一个相机采集一帧图像并放到系统的剪切板
    /// 参数：
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeDarkFrame
    /// @brief     获取参考黑图
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nDarkFrames [in] 采集多少张黑图做平均
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nIndex, int nDarkFrames);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeFlatFieldFrame
    /// @brief     获取参考白图
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nFlatFieldFrames [in] 采集多少张白图做平均
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nIndex, int nFlatFieldFrames);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetFlatFieldCorrection
    /// @brief     对预览流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时开启FFC校正, false时关闭FFC校正
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     获取当前预览流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回FFC对于预览的使能状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetFlatFieldCorrection
    /// @brief     对采集流是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时开启FFC校正, false时关闭FFC校正
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     获取采集时是否进行FFC校正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回FFC对于采集的使能状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SaveFlatFieldCorrection
    /// @brief     保存FFC当前的参考值
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 保存的文件名（完整路径）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadFlatFieldCorrection
    /// @brief     用于加载由KSJ_SaveFlatFieldCorrection保存的FFC参考信息文件
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 需要加载的FFC参考信息的文件名（完整路径）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);


	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetCalibration
    /// @brief     对预览流是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetCalibration
    /// @brief     获取当前预览流是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回畸变矫正对于预览的使能状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetCalibration
    /// @brief     对采集是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureGetCalibration
    /// @brief     获取采集时是否进行畸变矫正处理
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回畸变矫正对于采集的使能状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadCalibrationMapFile
    /// @brief     用于从文件加载畸变校正参数信息
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszFilePath [in] 需要加载载畸变校正参数的文件名（完整路径）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetCalibrationMapMode
    /// @brief     获取畸变校正目标值计算方法
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pMapMode [out] 当前畸变校正目标值的计算方法
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置预曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fPreExpTimeMs [in] 设置的预曝光时间
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取预曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfPreExpTimeMs[out] 返回预曝光时间的指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置预曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nPreExpLines [in] 设置的预曝光行
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取预曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnPreExpLines[out] 返回预曝光时间的指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);

	/// Preview Mode
	enum KSJ_PREVIEWMODE// 枚举类型视频预览模式
	{
		PM_RAWDATA, ///预览原始数据，对于黑白设备，必须设置为PM_RAWDATA
		PM_RGBDATA  ///预览24位或32位彩色数据（由Bayer模式决定）
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取设备默认的预览模式
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pPreviewMode   [out] 获取相机默认的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetMode
	/// @brief     设置视频流为原始采集数据还是RGB 24位或32位彩色数据格式，一般用户无需设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     PreviewMode [in] 设置的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetMode
	/// @brief     获取相机的当前预览模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pPreviewMode   [out] 获取当前的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFrameRate
	/// @brief     获取帧速
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fFrameRate [out] 返回当前视频流的帧速
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取暂停时的那一帧图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewPause
	/// @brief     暂停或继续视频流
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bPause   [in] true 暂停视频流，false 继续视频流 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取暂停时的那一帧图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
	/// @param     pnWidth [out] 返回图像的宽度（像素）
	/// @param     pnHeight[out] 返回图像的高度（像素）
	/// @param     pnBitCount[out] 返回图像的每个像素位数（8，24或32）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置预览图像缓存的数量
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nCount [in] 设置预览缓存的数量 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取预览图像缓存的数量
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnCount [out] 返回预览缓存的数量 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);

	enum KSJ_USBSPEED//相机USB连接状态
	{
		USB_NOT_CONNECTED = 0x00,        ///USB通信失败
		USB_FULL_SPEED,                  ///全速USB
		USB_HIGH_SPEED,                  ///高速USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取USB连接状态
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pUSBSpeed [out] 返回当前USB连接状态 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);




	///-----------------------------------------------------------------------------
	///
	/// @brief     清空帧存后采集一帧原始或黑白图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize函数获得
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRawData);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRgbDataAfterEmptyFrameBuffer
	/// @brief     清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @param     pnWidth [out] 返回图像的宽度（像素）
	/// @param     pnHeight [out] 返回图像的高度（像素）
	/// @param     pnBitCount [out] 返回图像的每个像素位数（8，24或32），由KSJ_PreviewSetMode和KSJ_BayerSetMode的设置影响
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

#ifdef __cplusplus
}
#endif

#endif
