#ifndef __KSJ_API_MATRIX_H__
#define __KSJ_API_MATRIX_H__

// #pragma message("Include KSJApiMatrix.h") 

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

	enum KSJ_WB_MODE//白平衡模式
	{
		KSJ_WB_DISABLE,
		KSJ_SWB_PRESETTINGS,
		KSJ_SWB_AUTO_ONCE,
		KSJ_SWB_AUTO_CONITNUOUS,
		KSJ_SWB_MANUAL,
		KSJ_HWB_PRESETTINGS,
		KSJ_HWB_AUTO_ONCE,
		KSJ_HWB_AUTO_CONITNUOUS,
		KSJ_HWB_MANUAL
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置白平衡模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     WbMode [in] 设置的白平衡模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceSet(int nIndex, KSJ_WB_MODE WbMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取当前的白平衡模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pWbMode [out] 返回相机白平衡模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceGet(int nIndex, KSJ_WB_MODE *pWbMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置软件自动白平衡的参考像素，是一个阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nPhi [in] 默认值为0，用户无需改动
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSet(int nIndex, int nPhi);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取自动白平衡的阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnPhi [out] 返回当前的阈值参数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGet(int nIndex, int *pnPhi);


	///-----------------------------------------------------------------------------
    ///
    /// @brief     手动设置白平衡校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMatrix [in] 用于设置白平衡校正矩阵，校正矩阵为1x3的数组，其中中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixSet(int nIndex, float fMatrix[3]);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取当前的白平衡校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMatrix [out] 返回获取的白平衡调整系数，数组中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixGet(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     白平衡回调函数类型定义
    /// @param     fMatrix [out] 回传给用户的白平衡校正矩阵
	/// @param     lpContext [out] 用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK)(float fMatrix[3], void *lpContext);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     白平衡回调函数类型定义
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfCallBack [in] 自动白平衡回调函数指针
	/// @param     lpContext [in] 上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBack(int nIndex, KSJ_WB_CALLBACK    pfCallBack, void *lpContext);      /// The nPhi decide auto calculate Matrix.

	///-----------------------------------------------------------------------------
    ///
    /// @brief     白平衡回调函数类型定义
    /// @param     fMatrixR [out] 回传给用户的白平衡红色校正值
	/// @param     fMatrixG [out] 回传给用户的白平衡绿色校正值
	/// @param     fMatrixB [out] 回传给用户的白平衡蓝色校正值
	/// @param     lpContext [out] 用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK_EX)(float fMatrixR, float fMatrixG, float fMatrixB, void *lpContext);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置白平衡回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfCallBackEx [in] 自动白平衡回调函数指针
	/// @param     lpContext [in] 上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBackEx(int nIndex, KSJ_WB_CALLBACK_EX pfCallBackEx, void *lpContext);

	enum KSJ_COLOR_TEMPRATURE ///预设白平衡
	{ 
		KSJ_CT_5000K, 
		KSJ_CT_6500K, 
		KSJ_CT_2800K 
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     选择预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     WbPresetting [in] 预设色温白平衡，凯视佳工业相机预设三种色温下的白平衡
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE WbPresetting);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取并返回相机当前使用的预设色温白平衡
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pWbPresetting [out] 获取并返回相机当前使用的预设色温白平衡
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pWbPresetting);

	enum KSJ_CCM_MODE//颜色校正模式枚举类型
	{
		KSJ_CCM_DISABLE,
		KSJ_SCCM_PRESETTINGS,
		KSJ_SCCM_MANUAL,
		KSJ_HCCM_PRESETTINGS,
		KSJ_HCCM_MANUAL
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置颜色校正模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     CcmMode [in] 颜色校正模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionSet(int nIndex, KSJ_CCM_MODE CcmMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取颜色校正模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pCcmMode [out] 颜色校正模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionGet(int nIndex, KSJ_CCM_MODE *pCcmMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     手动设置颜色校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMatrix [in] 颜色校正系数矩阵，为3x3 float型的矩阵
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixSet(int nIndex, float fMatrix[3][3]);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取当前的颜色校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMatrix [in] 颜色校正系数矩阵，为3x3 float型的矩阵
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixGet(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置颜色校正的预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     CcmPresetting [in] 预设色温颜色校正，凯视佳工业相机预设三种色温下的颜色校正矩阵
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE CcmPresetting);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取当前选择的颜色校正预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pCcmPresetting [out] 获取并返回相机当前使用的预设色温颜色校正
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pCcmPresetting);



#ifdef __cplusplus
}
#endif

#endif