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

	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewSetFieldOfViewEx
    // 功能：设置多帧拼接时的预览视场
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nColStart： 输入，预览时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
    //       nRowStart：输入，预览时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	//       nColSize： 输入，预览时拼接的单个帧有效成像区域的水平像素数
    //       nRowSize：输入，预览时拼接的单个帧有效成像区域的垂直行数
	//       AmCol： 输入，预览时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    //       AmRow：输入，预览时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       wMultiFrameNum：输入，返回图像感光芯片预览时成像感光的有效区域垂直行数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_PreviewGetFieldOfViewEx
    // 功能：获取预览的多帧拼接信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnColStart： 输出，返返回拼接的单个帧图像感光芯片预览时成像感光的有效区域起始列位置
    //       pnRowStart：输出，返回拼接的单个帧图像感光芯片预览时成像感光的有效区域起始行位置
	//       pnColSize： 输出，返回拼接的单个帧图像感光芯片预览时成像感光的有效区域水平像素数
    //       pnRowSize：输出，返回拼接的单个帧图像感光芯片预览时成像感光的有效区域垂直行数
	//       pColAddressMode： 输出，返回拼接的单个帧图像感光芯片预览时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    //       pRowAddressMode：输出，返回拼接的单个帧图像感光芯片预览时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       pwMultiFrameNum：输出，返回预览的拼接帧数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfViewEx(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetFieldOfViewEx
    // 功能：设置多帧拼接时的采集视场
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nColStart： 输入，采集时拼接的单个帧有效成像区域相对于默认最大成像区域的水平像素起始位置
    //       nRowStart：输入，采集时拼接的单个帧有效成像区域相对于最大默认成像区域的垂直行起始位置
	//       nColSize： 输入，采集时拼接的单个帧有效成像区域的水平像素数
    //       nRowSize：输入，采集时拼接的单个帧有效成像区域的垂直行数
	//       AmCol： 输入，采集时拼接的单个帧针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    //       AmRow：输入，采集时针拼接的单个帧对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       wMultiFrameNum：输入，返回图像感光芯片采集时成像感光的有效区域垂直行数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureGetFieldOfViewEx
    // 功能：获取采集的多帧拼接信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnColStart： 输出，返返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始列位置
    //       pnRowStart：输出，返回拼接的单个帧图像感光芯片采集时成像感光的有效区域起始行位置
	//       pnColSize： 输出，返回拼接的单个帧图像感光芯片采集时成像感光的有效区域水平像素数
    //       pnRowSize：输出，返回拼接的单个帧图像感光芯片采集时成像感光的有效区域垂直行数
	//       pColAddressMode： 输出，返回拼接的单个帧图像感光芯片采集时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    //       pRowAddressMode：输出，返回拼接的单个帧图像感光芯片采集时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	//       pwMultiFrameNum：输出，返回采集的拼接帧数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfViewEx(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);


#ifdef __cplusplus
}
#endif

#endif