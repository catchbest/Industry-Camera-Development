#ifndef __KSJ_API_AWAIBA_H__
#define __KSJ_API_AWAIBA_H__

// #pragma message("Include KSJApiAwaiba.h") 

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
    // 函数：KSJ_AWAIBA_IsUsed
    // 功能：设置自动曝光的参考区域，这个区域是相对预览图像的位置
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bUsed：输出，当前相机是否是AWAIBA传感器相机
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_IsUsed( int nChannel, bool *bUsed );
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetSegmentNum
    // 功能：取得相机的区段数目
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnSegNum：输出，返回当前相机的区段数目
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSegmentNum(int nChannel, int *pnSegNum );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetGainRange
    // 功能：获取相机指定区段的增益范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       pnMin：输出，返回最小增益
	//       pnMax：输出，返回最大增益
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGainRange(int nChannel, int nSegIndex, int *pnMin, int *pnMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_SetGain
    // 功能：获取相机某个区段的增益
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       nGain：输入，设置增益值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetGain(int nChannel, int nSegIndex, int nGain);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetGain
    // 功能：获取相机某个区段的增益
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       pnGain：输出，返回当前的增益值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGain(int nChannel, int nSegIndex, int *pnGain);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetBlackLevelRange
    // 功能：获取相机指定区段的黑电平范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       pnMin：输出，返回最小黑电平值
	//       pnMax：输出，返回最大黑电平值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevelRange(int nChannel, int nSegIndex, int *pnMin, int *pnMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_SetBlackLevel
    // 功能：设置相机某个区段的黑电平值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       nBlackLevel：输入，设置黑电平值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetBlackLevel(int nChannel, int nSegIndex, int nBlackLevel);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetBlackLevel
    // 功能：获取相机某个区段的黑电平值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	//       pnBlackLevel：输出，返回当前的黑电平值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevel (int nChannel, int nSegIndex, int *pnBlackLevel);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_AutoBlackLevel
    // 功能：设置相机某个区段的自动黑电平设置
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSegIndex：输入，区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_AutoBlackLevel(int nChannel, int nSegIndex);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_SetSplitSegment
    // 功能：设置奇数列和偶数分离
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bSplit：输入，设置奇数列和偶数分离
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	KSJ_API  int __stdcall KSJ_AWAIBA_SetSplitSegment(int nChannel, bool bSplit);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_AWAIBA_GetSplitSegment
    // 功能：获取奇数列和偶数分离
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbSplit：输出，返回当前奇数列和偶数是否分离
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSplitSegment(int nChannel, bool *pbSplit);

	// 如下函数未实现
	/*
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiBlooming(int nChannel, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiBlooming(int nChannel, bool *bEnable);

	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiCorona(int nChannel, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiCorona(int nChannel, bool *bEnable);

	enum KSJ_AWAIBA_ANALOGUE_GAIN {KSJ_AAG_X1, KSJ_AAG_X4};
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAnalogueGain(int nChannel, KSJ_AWAIBA_ANALOGUE_GAIN Gain);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAnalogueGain(int nChannel, KSJ_AWAIBA_ANALOGUE_GAIN *pGain);
	*/



#ifdef __cplusplus
}
#endif

#endif