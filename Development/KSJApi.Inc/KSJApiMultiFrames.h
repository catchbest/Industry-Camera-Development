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
	/// @brief     KSJ_CaptureSetFieldOfViewEx
	/// @brief     设置多帧拼接时的预览视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nColStart [in] 采集时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     nRowStart [in] 采集时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	/// @param     nColSize [in] 采集时拼接的单个帧有效成像区域的水平像素数
	/// @param     nRowSize [in] 采集时拼接的单个帧有效成像区域的垂直行数
	/// @param     AmCol [in] 采集时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     AmRow [in] 采集时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     wMultiFrameNum [in] 设置单次采集的拼接帧数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 设置多帧wMultiFrameNum>1时，内触发或者软触发，采集一次图像就会返回wMultiFrameNum帧图像组成的拼帧数据；如果是外触发或者固定帧率，需要有wMultiFrameNum个触发信号之后，采集函数才返回一个拼帧。
	///          \li 多帧情况更多是用在线阵相机时，自动拼接wMultiFrameNum行图像成一个面阵图像。
	///          \li 如果设置参数无效，比如wMultiFrameNum太大造成相机帧缓存不够，API自动会使用最接近的参数对相机进行设置，所以设置成功以后，需要通过KSJ_CaptureGetFieldOfViewEx获取实际生效的参数。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfViewEx
	/// @brief     获取预览的多帧拼接信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始列位置
	/// @param     pnRowStart [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域水平像素数
	/// @param     pnRowSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pRowAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pwMultiFrameNum [out] 返回采集的拼接帧数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetFieldOfViewEx
	/// @brief     设置多帧拼接时的采集视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nColStart [in] 采集时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     nRowStart [in] 采集时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	/// @param     nColSize [in] 采集时拼接的单个帧有效成像区域的水平像素数
	/// @param     nRowSize [in] 采集时拼接的单个帧有效成像区域的垂直行数
	/// @param     AmCol [in] 采集时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     AmRow [in] 采集时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     wMultiFrameNum [in] 设置单次采集的拼接帧数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 设置多帧wMultiFrameNum>1时，内触发或者软触发，采集一次图像就会返回wMultiFrameNum帧图像组成的拼帧数据；如果是外触发或者固定帧率，需要有wMultiFrameNum个触发信号之后，采集函数才返回一个拼帧。
	///          \li 多帧情况更多是用在线阵相机时，自动拼接wMultiFrameNum行图像成一个面阵图像。
	///          \li 如果设置参数无效，比如wMultiFrameNum太大造成相机帧缓存不够，API自动会使用最接近的参数对相机进行设置，所以设置成功以后，需要通过KSJ_CaptureGetFieldOfViewEx获取实际生效的参数。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfViewEx
	/// @brief     获取采集的多帧拼接信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始列位置
	/// @param     pnRowStart [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域水平像素数
	/// @param     pnRowSize [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pRowAddressMode [out] 返回拼接的单个帧图像感光芯片采集时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pwMultiFrameNum [out] 返回采集的拼接帧数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);


#ifdef __cplusplus
}
#endif

#endif