#ifndef __KSJ_API_KSJAPI_ROISIZELIST_H__
#define __KSJ_API_KSJAPI_ROISIZELIST_H__

#include "KSJApi.h"

// #pragma message("Include KSJApiBase.h") 

#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifdef __cplusplus
extern "C"{
#endif
	
	/// ROI(感兴趣区域)数据结构定义
	typedef struct _tag_MVD_ROI_SIZE
	{
		unsigned int     uiColSize;         ///< 视场列像元数目
		unsigned int     uiRowSize;         ///< 视场行像元数目
		KSJ_ADDRESSMODE  ColAddressMode;    ///< 列像元提取模式（是在ColSize基础上进行提取)
		KSJ_ADDRESSMODE  RowAddressMode;    ///< 行像元提取模式（是在RowSize基础上进行提取)

	}MVD_ROI_SIZE, *PMVD_MVD_ROI_SIZE;

	#define MAX_ROI_SIZE_TIEMS_NUM   16

	struct MVD_ROI_SIZE_LIST
	{
		unsigned int     uiRoiSizeItemsNum;
		MVD_ROI_SIZE    *pRoiSizeItem[MAX_ROI_SIZE_TIEMS_NUM];
		TCHAR           *pRoiSizeItemString[MAX_ROI_SIZE_TIEMS_NUM];
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetRoiSizeItems
	/// @brief     获取指定型号相机的常用ROI列表
	/// @param     usDeviceType [in] 相机类型（参考KSJ_DEVICETYPE定义）
	/// @param     pRoiSizeList [out] ROI列表（参考MVD_ROI_SIZE_LIST定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 该函数可以随时调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API int __stdcall KSJ_GetRoiSizeItems(IN KSJ_DEVICETYPE usDeviceType, OUT MVD_ROI_SIZE_LIST *pRoiSizeList);

#ifdef __cplusplus
}
#endif

#endif
