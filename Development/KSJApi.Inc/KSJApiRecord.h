#ifndef __KSJ_API_RECORD_H__
#define __KSJ_API_RECORD_H__

// #pragma message("Include KSJApiRecord.h") 

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
	/// @brief     预览开启状态下，设置是否启动或停止视频录影并弹出视频编码器对话窗口供用户选择视频编码器
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] 是否启动录影，如果为false，后两个参数无意义
	/// @param     fRecordRate [in] 设置录影帧速，这个帧速代表录影文件的回放帧速
	/// @param     pFileName [in] 录影文件名
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStart(int nIndex, bool bStart, float fRecordRate, const TCHAR *pFileName);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     预览开启状态下，设置是否启动或停止视频录影，并可以选择是否弹出视频编码器对话窗口供用户选择视频编码器
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] 是否启动录影，如果为false，后面参数无意义
	/// @param     fRecordRate [in] 设置录影帧速，这个帧速代表录影文件的回放帧速
	/// @param     pFileName [in] 录影文件名
	/// @param     bShowCompossorSelection [in] 是否弹出视频编码器对话框供用户选择
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartEx(int nIndex, bool bStart, float fRecordRate, const TCHAR *pFileName, bool bShowCompossorSelection);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置是否启动或停止视频录影，后期可以通过KSJ_RecordAddOneFrame函数加入视频帧序列，并可以选择是否弹出视频编码器对话窗口供用户选择视频编码器
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] 是否启动录影，如果为false，后面参数无意义
	/// @param     fRecordRate [in] 设置录影帧速，这个帧速代表录影文件的回放帧速
	/// @param     nWidth [in] 视频宽度（像素），这个值需要与KSJ_RecordAddOneFrame函数的nWidth参数一致
	/// @param     nHeight [in] 视频高度（像素），这个值需要与KSJ_RecordAddOneFrame函数的nHeight参数一致
	/// @param     nBitCount [in] 视频比特深度（8/24/32），这个值需要与KSJ_RecordAddOneFrame函数的nBitCount参数一致
	/// @param     pFileName [in] 录影文件名
	/// @param     bShowCompossorSelection [in] 是否弹出视频编码器对话框供用户选择
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartExEx(int nIndex, bool bStart, float fRecordRate, int nWidth, int nHeight, int nBitCount,  const TCHAR *pFileName, bool bShowCompossorSelection);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     将视频的帧序列添加到录影文件中
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pFrameData [in] 图像数据指针
	/// @param     nFrameNum [in] 图像在视频流中的帧序号
	/// @param     nWidth [in] 图像宽度（像素），这个值需要与KSJ_ RecordStartExEx函数的nWidth参数一致
	/// @param     nHeight [in] 视频高度（像素），这个值需要与KSJ_ RecordStartExEx函数的nHeight参数一致
	/// @param     nBitCount [in] 视频比特深度（8/24/32），这个值需要与KSJ_ RecordStartExEx函数的nBitCount参数一致
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordAddOneFrame(int nIndex, unsigned char *pFrameData, int nFrameNum, int nWidth, int nHeight, int nBitcount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到当前录影状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] 返回是否正在录影
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStatusGet(int nIndex, bool *bStart);

#ifdef __cplusplus
}
#endif

#endif