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

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceSet
    // 功能：设置白平衡模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       WbMode：输入，设置的白平衡模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceSet(int nChannel, KSJ_WB_MODE WbMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceGet
    // 功能：获取当前的白平衡模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pWbMode：输出，返回相机白平衡模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceGet(int nChannel, KSJ_WB_MODE *pWbMode);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceAutoSet
    // 功能：设置软件自动白平衡的参考像素，是一个阈值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nPhi：输入，默认值为0，用户无需改动
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSet(int nChannel, int nPhi);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceAutoGet
    // 功能：获取自动白平衡的阈值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnPhi：输出，返回当前的阈值参数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGet(int nChannel, int *pnPhi);


	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceMatrixSet
    // 功能：手动设置白平衡校正矩阵
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fMatrix：输入，用于设置白平衡校正矩阵，校正矩阵为1x3的数组，其中中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixSet(int nChannel, float fMatrix[3]);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceMatrixGet
    // 功能：获取当前的白平衡校正矩阵
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fMatrix：输出，返回获取的白平衡调整系数，数组中R、G、B三个分量的系数分别为fMatrix [0] 、fMatrix [1] 、fMatrix [2] 
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixGet(int nChannel, float fMatrix[3]);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WB_CALLBACK
    // 功能：白平衡回调函数类型定义
    // 参数：
    //       fMatrix：输出，回传给用户的白平衡校正矩阵
	//       lpContext： 输出，用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK)(float fMatrix[3], void *lpContext);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceAutoSetCallBack
    // 功能：白平衡回调函数类型定义
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfCallBack：输入，自动白平衡回调函数指针
	//       lpContext： 输入，上下文指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBack(int nChannel, KSJ_WB_CALLBACK    pfCallBack, void *lpContext);      // The nPhi decide auto calculate Matrix.

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WB_CALLBACK_EX
    // 功能：白平衡回调函数类型定义
    // 参数：
    //       fMatrixR：输出，回传给用户的白平衡红色校正值
	//       fMatrixG：输出，回传给用户的白平衡绿色校正值
	//       fMatrixB：输出，回传给用户的白平衡蓝色校正值
	//       lpContext： 输出，用户调用KSJ_WhiteBalanceAutoSetCallBack时传入的上下文指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK_EX)(float fMatrixR, float fMatrixG, float fMatrixB, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalanceAutoSetCallBackEx
    // 功能：设置白平衡回调函数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfCallBackEx：输入，自动白平衡回调函数指针
	//       lpContext： 输入，上下文指针
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBackEx(int nChannel, KSJ_WB_CALLBACK_EX pfCallBackEx, void *lpContext);

	enum KSJ_COLOR_TEMPRATURE //预设白平衡
	{ 
		KSJ_CT_5000K, 
		KSJ_CT_6500K, 
		KSJ_CT_2800K 
	};
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalancePresettingSet
    // 功能：选择预设组值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       WbPresetting：输入，预设色温白平衡，凯视佳工业相机预设三种色温下的白平衡
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE WbPresetting);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WhiteBalancePresettingGet
    // 功能：获取并返回相机当前使用的预设色温白平衡
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pWbPresetting：输出，获取并返回相机当前使用的预设色温白平衡
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingGet(int nChannel, KSJ_COLOR_TEMPRATURE *pWbPresetting);

	enum KSJ_CCM_MODE//颜色校正模式枚举类型
	{
		KSJ_CCM_DISABLE,
		KSJ_SCCM_PRESETTINGS,
		KSJ_SCCM_MANUAL,
		KSJ_HCCM_PRESETTINGS,
		KSJ_HCCM_MANUAL
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionSet
    // 功能：设置颜色校正模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       CcmMode：输入，颜色校正模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionSet(int nChannel, KSJ_CCM_MODE CcmMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionGet
    // 功能：获取颜色校正模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pCcmMode：输出，颜色校正模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionGet(int nChannel, KSJ_CCM_MODE *pCcmMode);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionMatrixSet
    // 功能：手动设置颜色校正矩阵
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fMatrix：输入，颜色校正系数矩阵，为3x3 float型的矩阵
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixSet(int nChannel, float fMatrix[3][3]);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionMatrixGet
    // 功能：获取当前的颜色校正矩阵
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fMatrix：输入，颜色校正系数矩阵，为3x3 float型的矩阵
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixGet(int nChannel, float fMatrix[3][3]);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionPresettingSet
    // 功能：设置颜色校正的预设组值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       CcmPresetting：输入，预设色温颜色校正，凯视佳工业相机预设三种色温下的颜色校正矩阵
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE CcmPresetting);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ColorCorrectionPresettingGet
    // 功能：获取当前选择的颜色校正预设组值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pCcmPresetting：输出，获取并返回相机当前使用的预设色温颜色校正
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingGet(int nChannel, KSJ_COLOR_TEMPRATURE *pCcmPresetting);



#ifdef __cplusplus
}
#endif

#endif