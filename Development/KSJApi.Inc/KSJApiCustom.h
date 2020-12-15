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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  输出图像格式：根据需要直接设置图像的输出格式，API自动将采集到的图像转换成需要的输出图像格式
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetImageFormat
	/// @brief     设置图像输出的数据格式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     ImageFormat [in] 图像格式（请参考KSJ_IMAGE_FORMAT的定义）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetImageFormat(IN int nIndex, IN KSJ_IMAGE_FORMAT ImageFormat);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetImageFormat
	/// @brief     获得图像输出的数据格式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pImageFormat [out] 返回当前输出的图像格式（请参考KSJ_IMAGE_FORMAT的定义）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetImageFormat(IN int nIndex, OUT KSJ_IMAGE_FORMAT *pImageFormat);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  图像负片功能：设置是否输出图像负片
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetNegativeImageMode
	/// @brief     设置图像输出的负片
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bNegative [in] 负片
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetNegativeImageMode(IN int nIndex, IN bool bNegative);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetNegativeImageMode
	/// @brief     获得图像是否负片输出
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbNegative [out] 返回当前输出的图像是否负片
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetNegativeImageMode(IN int nIndex, OUT bool* pbNegative);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  全局复位滚动快门：设置全局快门是否使能
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  FFC校正：目的是消除像素与像素间不同的灵敏度特性以及光路的畸变所造成的亮度不均匀的现象，FFC校正流程：
    ///     1、首先通过KSJ_SetFlatFieldCorrectionFieldOfView设置FFC的参考视场，这个视场可以是您的采集或预览视场，当以后使能FFC时，所设置的视场必须与FFC的参考视场一致，才可以进行校正。
    ///     2、调节相机参数，使采集的图像保持正常。
    ///     3、盖住镜头，不要让光进入，调用KSJ_MakeDarkFrame采集一幅黑图，您可以指定采集多少张，此函数会做平均最终得到一幅黑图。(该步骤非必须，如果不采集黑图，那么黑图默认为全黑)。
    ///     4、不要盖住镜头，让光正常进入，放一张白纸，调用KSJ_MakeFlatFieldFrame采集一幅图像，您可以指定采集多少张，此函数会做平均最终得到一幅白纸图像。
    ///     5、调用KSJ_PreviewSetFlatFieldCorrection或KSJ_CaptureSetFlatFieldCorrection函数，用于设置是否在预览流中还是在采集图像时，进行FFC校正处理。
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// 预曝光设置：在Sensor采图曝光之前，闪光灯会提前曝光一段时间，可以通过以下函数进行测试，该功能仅几个定制相机支持
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureRangeGet
	/// @brief     得到预曝光时间范围
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinValue[out] 设置预曝光时间最小值指针，单位为曝光行
	/// @param     pnMaxValue[out] 设置预曝光时间最大值指针，单位为曝光行
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureTimeSet
	/// @brief     设置预曝光时间
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fPreExpTimeMs [in] 设置的预曝光时间
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureTimeGet
	/// @brief     获取预曝光时间
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfPreExpTimeMs[out] 返回预曝光时间的指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureLinesSet
	/// @brief     设置预曝光行
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nPreExpLines [in] 设置的预曝光行
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureLinesGet
	/// @brief     获取预曝光行
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnPreExpLines[out] 返回预曝光时间的指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  设置预览图像缓存数，默认预览缓存数为4，仅使用预览功能的时候起作用，占用系统内存
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetBufferCount
	/// @brief     设置预览图像缓存的数量
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nCount [in] 设置预览缓存的数量 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetBufferCount
	/// @brief     获取预览图像缓存的数量
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnCount [out] 返回预览缓存的数量 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  清空帧存后采集图像：对于需要采集实时图像，先把相机内帧缓存的数据清空，然后在采集图像
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRawDataAfterEmptyFrameBuffer
	/// @brief     清空帧存后采集一帧原始或黑白图像数据
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize函数获得
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
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
	/// @brief     KSJ_CaptureRgbDataExAfterEmptyFrameBuffer
	/// @brief     清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @param     pnWidth [out] 返回图像的宽度（像素）
	/// @param     pnHeight [out] 返回图像的高度（像素）
	/// @param     pnBitCount [out] 返回图像的每个像素位数（8，24或32），由KSJ_PreviewSetMode和KSJ_BayerSetMode的设置影响
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  检测输入的视场参数与相机是否匹配：检查当前的FOV是否能够应用到相机上
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CheckFieldOfView
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
	/// @attention 该函数用户检测即将设置的FOV是否能够设置到当前相机上。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  相机USB连接状态：相机出现异常，比如无法采图，采集图像变慢，可以查看当前USB连接状态
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	enum KSJ_USBSPEED//相机USB连接状态
	{
		USB_NOT_CONNECTED = 0x00,        ///USB通信失败
		USB_FULL_SPEED,                  ///全速USB
		USB_HIGH_SPEED,                  ///高速USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
	/// @brief     获取USBKSJ_GetUsbState
	/// @brief     获取USB连接状态
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pUSBSpeed [out] 返回当前USB连接状态（请参考KSJ_USBSPEED的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);

	KSJ_API  int __stdcall KSJ_CalibrationProgram(int nIndex, float fCoefficient[14]);
	KSJ_API  int __stdcall KSJ_CalibrationReadout(int nIndex, float fCoefficient[14]);

#ifdef __cplusplus
}
#endif

#endif
