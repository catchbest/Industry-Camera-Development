#ifndef __KSJ_API_COMPANDING_H__
#define __KSJ_API_COMPANDING_H__

// #pragma message("Include KSJApiCompanding.h") 

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

    // 参考“凯视佳工业相机API函数说明书（数据压扩篇）”
	// Related API KSJ_GetADCResolution to Get Valid bits of 16bits
	// Please KSJ_QueryFunction ( KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_LutFileDownload
    // 功能：以ktb文件形式，下载LUT查找表至相机
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pszKtbFile：输入，.ktb文件路径
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nChannel, const TCHAR *pszKtbFile);
	
    //-----------------------------------------------------------------------------
    // 函数：KSJ_LutDataDownload
    // 功能：此函数可用于加载用户自定义的LUT查找表数据
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pData：输出，指向查找表数据的指针
	//       nBytes：输入，查找表数据个数，即pData指针指向的内存块的大小
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload( int nChannel, unsigned char *pData, int nBytes   );
    
	//-----------------------------------------------------------------------------
    // 函数：KSJ_LutSetEnable
    // 功能：使能LUT查找表功能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，设置是否使LUT功能生效
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable( int nChannel, bool bEnable   );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_LutGetEnable
    // 功能：获取LUT查找表是否使能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回是否LUT功能已生效
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable( int nChannel, bool *pbEnable );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaLutFileDownload
    // 功能：以ktb文件形式，下载Gamma LUT查找表至相机
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pszKtbFile：输入，.ktb文件路径
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutFileDownload( int nChannel, const TCHAR *pszKtbFile );
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaLutDataDownload
    // 功能：加载用户自定义的Gamma LUT查找表数据
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pData：输出，指向查找表数据的指针，每个元素为双字节
	//       nWords：输入，查找表数据个数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutDataDownload( int nChannel, unsigned short *pData, int nWords );
    
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaLutSetEnable
    // 功能：使能Gamma LUT查找表功能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，设置是否使Gamma LUT功能生效
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutSetEnable( int nChannel, bool bEnable   );
    
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaLutGetEnable
    // 功能：获取Gamma LUT查找表是否使能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回是否Gamma LUT功能已生效
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutGetEnable( int nChannel, bool *pbEnable );

    enum KSJ_SENSITIVITYMODE // 灵敏度模式设置（使用截取8位方式）
    {
	    KSJ_LOW = 0, 
	    KSJ_MID, 
	    KSJ_HIGH, 
	    KSJ_HIGHER, 
	    KSJ_HIGHEST 
    };
    
	//-----------------------------------------------------------------------------
    // 函数：KSJ_SensitivitySetMode
    // 功能：选择截位模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       SensitivityMode：输入，设置截位模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nChannel, KSJ_SENSITIVITYMODE SensitivityMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_SensitivityGetMode
    // 功能：选择截位模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pSensitivityMode：输出，获取当前截位模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nChannel, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif