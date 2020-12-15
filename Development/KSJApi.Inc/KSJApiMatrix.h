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

	/// 白平衡模式枚举类型
	enum KSJ_WB_MODE
	{
		KSJ_WB_DISABLE,            ///< 关闭白平衡
		KSJ_SWB_PRESETTINGS,       ///< 软件预设白平衡
		KSJ_SWB_AUTO_ONCE,         ///< 软件一次白平衡
		KSJ_SWB_AUTO_CONITNUOUS,   ///< 软件连续白平衡
		KSJ_SWB_MANUAL,            ///< 软件手动白平衡
		KSJ_HWB_PRESETTINGS,       ///< 硬件预设白平衡
		KSJ_HWB_AUTO_ONCE,         ///< 硬件一次白平衡
		KSJ_HWB_AUTO_CONITNUOUS,   ///< 硬件连续白平衡
		KSJ_HWB_MANUAL             ///< 硬件手动白平衡
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceSet
	/// @brief     设置白平衡模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     WbMode [in] 设置的白平衡模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceSet(int nIndex, KSJ_WB_MODE WbMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceGet
	/// @brief     获取当前的白平衡模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pWbMode [out] 返回相机白平衡模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceGet(int nIndex, KSJ_WB_MODE *pWbMode);


	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceMatrixSet
	/// @brief     手动设置白平衡校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [in] 用于设置白平衡校正矩阵，校正矩阵为1x3的数组，其中中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 白平衡计算公式：Rw = fMatrix[0] * R, Gw = fMatrix[1] * G, Bw = fMatrix[1] * B
	///          \li 三个分量的取值范围为： 0 - 5
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixSet(int nIndex, float fMatrix[3]);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceMatrixGet
	/// @brief     获取当前的白平衡校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [out] 返回获取的白平衡调整系数，数组中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixGet(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WB_CALLBACK
	/// @brief     白平衡回调函数类型定义
	/// @param     fMatrix [out] 回传给用户的白平衡校正矩阵
	/// @param     lpContext [out] 用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 非手动白平衡模式时，回调返回当前的白平衡校正矩阵
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK)(float fMatrix[3], void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceAutoSetCallBack
	/// @brief     白平衡回调函数类型定义
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfCallBack [in] 自动白平衡回调函数指针
	/// @param     lpContext [in] 上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBack(int nIndex, KSJ_WB_CALLBACK    pfCallBack, void *lpContext);      /// The nPhi decide auto calculate Matrix.

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WB_CALLBACK_EX
	/// @brief     白平衡回调函数类型定义
	/// @param     fMatrixR [out] 回传给用户的白平衡红色校正值
	/// @param     fMatrixG [out] 回传给用户的白平衡绿色校正值
	/// @param     fMatrixB [out] 回传给用户的白平衡蓝色校正值
	/// @param     lpContext [out] 用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 非手动白平衡模式时，回调返回当前的白平衡校正矩阵
	///
	///-----------------------------------------------------------------------------
	// Call Callback Function When KSJ_AWB_AUTO_ONCE or KSJ_AWB_AUTO_CONITNUOUS Done. Finall Matrix will Return.
	typedef void(__stdcall *KSJ_WB_CALLBACK_EX)(float fMatrixR, float fMatrixG, float fMatrixB, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceAutoSetCallBackEx
	/// @brief     设置白平衡回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfCallBackEx [in] 自动白平衡回调函数指针
	/// @param     lpContext [in] 上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 注意前面KSJ_WhiteBalanceAutoSetCallBack设置的回调函数优先级高于这个函数设置，如果KSJ_WhiteBalanceAutoSetCallBack非空，那么这个函数设置的回调函数将不会被执行。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBackEx(int nIndex, KSJ_WB_CALLBACK_EX pfCallBackEx, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceAutoSet
	/// @brief     设置软件自动白平衡的参考像素，是一个阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nPhi [in] 默认值为0，用户无需改动
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 该阈值只有在软件白平衡的时候生效
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSet(int nIndex, int nPhi);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalanceAutoGet
	/// @brief     获取自动白平衡的阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnPhi [out] 返回当前的阈值参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGet(int nIndex, int *pnPhi);

	/// 色温枚举
	enum KSJ_COLOR_TEMPRATURE
	{
		KSJ_CT_5000K,   ///< 5000K色温
		KSJ_CT_6500K,   ///< 6500K色温
		KSJ_CT_2800K    ///< 2800K色温
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalancePresettingSet
	/// @brief     选择白平衡预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     WbPresetting [in] 预设色温白平衡。
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 凯视佳工业相机预设三种色温下的白平衡，在选择软件预设白平衡或者硬件预设白平衡的时候，可以选择不同的色温白平衡
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE WbPresetting);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_WhiteBalancePresettingGet
	/// @brief     获取并返回相机当前使用的预设色温白平衡
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pWbPresetting [out] 获取并返回相机当前使用的预设色温白平衡
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pWbPresetting);

	/// 颜色校正矩阵枚举
	/// SCCM - Software Color Correction Matrix; HCCM - Hardware Color Correction Matrix
	enum KSJ_CCM_MODE
	{
		KSJ_CCM_DISABLE,         ///< 不进行颜色校正操作
		KSJ_SCCM_PRESETTINGS,    ///< 软件预设值校正
		KSJ_SCCM_MANUAL,         ///< 软件手工输入矩阵值校正
		KSJ_HCCM_PRESETTINGS,    ///< 硬件预设值校正
		KSJ_HCCM_MANUAL          ///< 软件手工输入矩阵值校正
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionSet
	/// @brief     设置颜色校正模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     CcmMode [in] 颜色校正模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionSet(int nIndex, KSJ_CCM_MODE CcmMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionGet
	/// @brief     获取颜色校正模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pCcmMode [out] 颜色校正模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionGet(int nIndex, KSJ_CCM_MODE *pCcmMode);


	// Set Color Correction Matrix when in KSJ_SCCM_MANUAL or KSJ_HCCM_MANUAL
	// Rc = fMatrix[0][0] * Rw + fMatrix[0][1] * Gw + fMatrix[0][2] * Bw
	// Range -5 - 5
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionMatrixSet
	/// @brief     手动设置颜色校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [in] 颜色校正系数矩阵，为3x3 float型的矩阵
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 在软件/硬件手工输入矩阵值校正模式时生效，计算公式：
	///          \li Bc = fMatrix[2][0] * Rw + fMatrix[2][1] * Gw + fMatrix[2][2] * Bw
	///          \li Gc = fMatrix[1][0] * Rw + fMatrix[1][1] * Gw + fMatrix[1][2] * Bw
	///          \li Rc = fMatrix[0][0] * Rw + fMatrix[0][1] * Gw + fMatrix[0][2] * Bw
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixSet(int nIndex, float fMatrix[3][3]);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionMatrixGet
	/// @brief     获取当前的颜色校正矩阵
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [in] 颜色校正系数矩阵，为3x3 float型的矩阵
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixGet(int nIndex, float fMatrix[3][3]);


	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionPresettingSet
	/// @brief     设置颜色校正的预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     CcmPresetting [in] 预设色温颜色校正，凯视佳工业相机预设三种色温下的颜色校正矩阵
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE CcmPresetting);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ColorCorrectionPresettingGet
	/// @brief     获取当前选择的颜色校正预设组值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pCcmPresetting [out] 获取并返回相机当前使用的预设色温颜色校正
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pCcmPresetting);



#ifdef __cplusplus
}
#endif

#endif