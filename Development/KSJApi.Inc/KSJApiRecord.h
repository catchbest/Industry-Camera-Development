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

	//-----------------------------------------------------------------------------
	// 函数：KSJ_RecordStart
	// 功能：预览开启状态下，设置是否启动或停止视频录影并弹出视频编码器对话窗口供用户选择视频编码器
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bStart：输入，是否启动录影，如果为false，后两个参数无意义
	//       fRecordRate：输入，设置录影帧速，这个帧速代表录影文件的回放帧速
	//       pFileName：输入，录影文件名
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStart(int nChannel, bool bStart, float fRecordRate, const TCHAR *pFileName);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_RecordStartEx
	// 功能：预览开启状态下，设置是否启动或停止视频录影，并可以选择是否弹出视频编码器对话窗口供用户选择视频编码器
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bStart：输入，是否启动录影，如果为false，后面参数无意义
	//       fRecordRate：输入，设置录影帧速，这个帧速代表录影文件的回放帧速
	//       pFileName：输入，录影文件名
	//       bShowCompossorSelection：输入，是否弹出视频编码器对话框供用户选择
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartEx(int nChannel, bool bStart, float fRecordRate, const TCHAR *pFileName, bool bShowCompossorSelection);

	//-----------------------------------------------------------------------------
	// 函数：KSJ_RecordStartExEx
	// 功能：设置是否启动或停止视频录影，后期可以通过KSJ_RecordAddOneFrame函数加入视频帧序列，并可以选择是否弹出视频编码器对话窗口供用户选择视频编码器
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bStart：输入，是否启动录影，如果为false，后面参数无意义
	//       fRecordRate：输入，设置录影帧速，这个帧速代表录影文件的回放帧速
	//       nWidth： 输入，视频宽度（像素），这个值需要与KSJ_RecordAddOneFrame函数的nWidth参数一致
	//       nHeight：输入，视频高度（像素），这个值需要与KSJ_RecordAddOneFrame函数的nHeight参数一致
	//       nBitCount：输入，视频比特深度（8/24/32），这个值需要与KSJ_RecordAddOneFrame函数的nBitCount参数一致
	//       pFileName：输入，录影文件名
	//       bShowCompossorSelection：输入，是否弹出视频编码器对话框供用户选择
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartExEx(int nChannel, bool bStart, float fRecordRate, int nWidth, int nHeight, int nBitCount,  const TCHAR *pFileName, bool bShowCompossorSelection);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_RecordAddOneFrame
	// 功能：将视频的帧序列添加到录影文件中
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pFrameData：输入，图像数据指针
	//       nFrameNum：输入，图像在视频流中的帧序号
	//       nWidth： 输入，图像宽度（像素），这个值需要与KSJ_ RecordStartExEx函数的nWidth参数一致
	//       nHeight：输入，视频高度（像素），这个值需要与KSJ_ RecordStartExEx函数的nHeight参数一致
	//       nBitCount：输入，视频比特深度（8/24/32），这个值需要与KSJ_ RecordStartExEx函数的nBitCount参数一致
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordAddOneFrame(int nChannel, unsigned char *pFrameData, int nFrameNum, int nWidth, int nHeight, int nBitcount);

	//-----------------------------------------------------------------------------
	// 函数：KSJ_RecordStatusGet
	// 功能：得到当前录影状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bStart：输入，返回是否正在录影
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStatusGet(int nChannel, bool *bStart);

#ifdef __cplusplus
}
#endif

#endif