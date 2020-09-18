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
	///-----------------------------------------------------------------------------
    ///
    /// @brief     当前相机是否是AWAIBA传感器相机
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bUsed [out] 当前相机是否是AWAIBA传感器相机
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_IsUsed( int nIndex, bool *bUsed );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     取得相机的区段数目
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnSegNum [out] 返回当前相机的区段数目
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSegmentNum(int nIndex, int *pnSegNum );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机指定区段的增益范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     pnMin [out] 返回最小增益
	/// @param     pnMax [out] 返回最大增益
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGainRange(int nIndex, int nSegIndex, int *pnMin, int *pnMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机某个区段的增益
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     nGain [in] 设置增益值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetGain(int nIndex, int nSegIndex, int nGain);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机某个区段的增益
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     pnGain [out] 返回当前的增益值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGain(int nIndex, int nSegIndex, int *pnGain);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机指定区段的黑电平范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     pnMin [out] 返回最小黑电平值
	/// @param     pnMax [out] 返回最大黑电平值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevelRange(int nIndex, int nSegIndex, int *pnMin, int *pnMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机某个区段的黑电平值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     nBlackLevel [in] 设置黑电平值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetBlackLevel(int nIndex, int nSegIndex, int nBlackLevel);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机某个区段的黑电平值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
	/// @param     pnBlackLevel [out] 返回当前的黑电平值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevel (int nIndex, int nSegIndex, int *pnBlackLevel);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机某个区段的自动黑电平设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSegIndex [in] 区段索引（范围由KSJ_AWAIBA_GetSegmentNum得到）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_AutoBlackLevel(int nIndex, int nSegIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置奇数列和偶数分离
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bSplit [in] 设置奇数列和偶数分离
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetSplitSegment(int nIndex, bool bSplit);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取奇数列和偶数分离
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbSplit [out] 返回当前奇数列和偶数是否分离
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSplitSegment(int nIndex, bool *pbSplit);

	/// 如下函数未实现
	/*
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiBlooming(int nIndex, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiBlooming(int nIndex, bool *bEnable);

	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiCorona(int nIndex, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiCorona(int nIndex, bool *bEnable);

	enum KSJ_AWAIBA_ANALOGUE_GAIN {KSJ_AAG_X1, KSJ_AAG_X4};
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAnalogueGain(int nIndex, KSJ_AWAIBA_ANALOGUE_GAIN Gain);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAnalogueGain(int nIndex, KSJ_AWAIBA_ANALOGUE_GAIN *pGain);
	*/



#ifdef __cplusplus
}
#endif

#endif