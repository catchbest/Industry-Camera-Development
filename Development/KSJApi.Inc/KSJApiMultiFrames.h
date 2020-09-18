#ifndef __KSJ_API_MULTI_FRAMES_H__
#define __KSJ_API_MULTI_FRAMES_H__

// #pragma message("Include KSJApiMultiFrames.h") 

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
    /// @brief     设置多帧拼接时的预览视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nColStart [in] 预览时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     nRowStart [in] 预览时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	/// @param     nColSize [in] 预览时拼接的单个帧有效成像区域的水平像素数
    /// @param     nRowSize [in] 预览时拼接的单个帧有效成像区域的垂直行数
	/// @param     AmCol [in] 预览时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     AmRow [in] 预览时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     wMultiFrameNum [in] 返回图像感光芯片预览时成像感光的有效区域垂直行数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取预览的多帧拼接信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返返回拼接的单个帧图像感光芯片预览时成像感光的有效区域起始列位置
    /// @param     pnRowStart [out] 返回拼接的单个帧图像感光芯片预览时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回拼接的单个帧图像感光芯片预览时成像感光的有效区域水平像素数
    /// @param     pnRowSize [out] 返回拼接的单个帧图像感光芯片预览时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回拼接的单个帧图像感光芯片预览时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode [out] 返回拼接的单个帧图像感光芯片预览时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pwMultiFrameNum [out] 返回预览的拼接帧数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置多帧拼接时的采集视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nColStart [in] 采集时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     nRowStart [in] 采集时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	/// @param     nColSize [in] 采集时拼接的单个帧有效成像区域的水平像素数
    /// @param     nRowSize [in] 采集时拼接的单个帧有效成像区域的垂直行数
	/// @param     AmCol [in] 采集时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     AmRow [in] 采集时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     wMultiFrameNum [in] 返回图像感光芯片采集时成像感光的有效区域垂直行数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取采集的多帧拼接信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始列位置
    /// @param     pnRowStart [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域水平像素数
    /// @param     pnRowSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pwMultiFrameNum [out] 返回采集的拼接帧数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);


#ifdef __cplusplus
}
#endif

#endif