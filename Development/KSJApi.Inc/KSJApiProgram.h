#ifndef __KSJ_API_PROGRAM_H__
#define __KSJ_API_PROGRAM_H__

// #pragma message("Include KSJApiProgram.h") 

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
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// 参考“凯视佳工业相机内部API函数说明书（初始化厂商读写区域篇）”
	/// 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetSerials
	/// @brief     设置相机序号
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btSerials [in] 将序号设置到当前相机
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 序号即KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx所获取的pnSerials
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetSerials(int nIndex, unsigned char btSerials);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetSerials
	/// @brief     获取相机序号
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbtSerials [out] 返回相机序号
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 序号即KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx所获取的pnSerials
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetSerials(int nIndex, unsigned char *pbtSerials);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SerialsDescReadout
	/// @brief     获取相机唯一序列号SN
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btDesc [out] 返回相机唯一序列号SN
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 唯一序列号SN即为相机的唯一号，与硬件标牌上SN一致，为8个宽字符数字
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SerialsDescReadout(int nIndex, unsigned char btDesc[16]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HardwareVersionReadout
	/// @brief     获取相机的硬件版本号
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btDesc [out] 返回相机的硬件版本号
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HardwareVersionReadout(int nIndex, unsigned char btVersion[16]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutInfoProgram
	/// @brief     设置LUT信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wValue [in] LUT信息，即LUT表大小（LUT bytes size），应该为2^10、2^12或者2^14
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutInfoProgram(int nIndex, unsigned short wValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutInfoReadout
	/// @brief     获取LUT信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pValue [out] 返回LUT信息，即LUT表大小（LUT bytes size），应该为2^10、2^12或者2^14
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutInfoReadout(int nIndex, unsigned short *pValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixProgram
	/// @brief     设置硬件白平衡参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [in] 硬件白平衡参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixProgram(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixReadout
	/// @brief     获取硬件白平衡参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [out] 当前硬件保存的默认白平衡参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixReadout(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixUpload
	/// @brief     获取当前硬件执行白平衡参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [out] 当前硬件处理图像使用的白平衡参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 与KSJ_HWBMatrixReadout区别，上面是获取默认的白平衡参数，该函数是当前的白平衡参数，在硬件连续白平衡时，这个白平衡参数是变化的
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixUpload(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixProgram
	/// @brief     设置硬件CCM参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [in] 硬件CCM参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HCCMMatrixProgram(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixReadout
	/// @brief     获取硬件CCM参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [out] 当前硬件保存的默认CCM参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HCCMMatrixReadout(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixUpload
	/// @brief     获取当前硬件执行CCM参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMatrix [out] 当前硬件处理图像使用的CCM参数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 与KSJ_HCCMMatrixReadout区别，上面是获取默认的CCM参数，该函数是当前的CCM参数，在硬件连续CCM时，这个CCM参数是变化的
	KSJ_API  int __stdcall KSJ_HCCMMatrixUpload(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutFileProgram
	/// @brief     将LUT数据从文件下载到硬件中
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszFile [in] LUT文件路径
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileProgram(int nIndex, TCHAR *pszFile);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutDataProgram
	/// @brief     将LUT数据下载到硬件中
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [in] LUT数据
	/// @param     nBytes [in] LUT数据大小，单位：字节
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutDataProgram(int nIndex, unsigned char *pData, int nBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutDataReadout
	/// @brief     读取相机LUT数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] LUT数据内存地址，需要提前分配
	/// @param     nBytes [out] 返回LUT数据大小，单位：字节
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutDataReadout(int nIndex, unsigned char *pData, int *pnBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_ParamProgram
	/// @brief     将当前的相机设置参数保存到相机中
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 保存参数以后，相机断电再连接，软件启动后，会自动加载这些参数。
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ParamProgram(int nIndex);          /// 将目前的主要参数保存至相机，再次重启KSJApi库时会自动加载并设置

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadParamFromCamera
	/// @brief     将当前的相机设置参数恢复到保存在相机中的状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 在调试相机过程中，如果需要返回到相机保存的状态，可以执行该函数
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadParamFromCamera(int nIndex);   /// 将目前保存至相机的主要参数加载并设置

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_ParamErase
	/// @brief	   擦除保存在相机内的参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 可以执行该函数后，相机重新上电将会恢复到出厂设置
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ParamErase(int nIndex);            /// 清除目前保存至相机的主要参数（预览视场、采集视场、曝光、增益）

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SaveParamToFile
	/// @brief     将当前的相机设置参数保存到一个文件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszFile [in] 保存参数的文件路径
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveParamToFile(int nIndex, TCHAR *pszFile);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadParamFromFile
	/// @brief     用一个参数文件设置到当前的相机
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszFile [in] 保存参数的文件路径
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadParamFromFile(int nIndex, TCHAR *pszFile);

#ifdef __cplusplus
}
#endif

#endif