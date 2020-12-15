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
	
	/// ROI(����Ȥ����)���ݽṹ����
	typedef struct _tag_MVD_ROI_SIZE
	{
		unsigned int     uiColSize;         ///< �ӳ�����Ԫ��Ŀ
		unsigned int     uiRowSize;         ///< �ӳ�����Ԫ��Ŀ
		KSJ_ADDRESSMODE  ColAddressMode;    ///< ����Ԫ��ȡģʽ������ColSize�����Ͻ�����ȡ)
		KSJ_ADDRESSMODE  RowAddressMode;    ///< ����Ԫ��ȡģʽ������RowSize�����Ͻ�����ȡ)

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
	/// @brief     ��ȡָ���ͺ�����ĳ���ROI�б�
	/// @param     usDeviceType [in] ������ͣ��ο�KSJ_DEVICETYPE���壩
	/// @param     pRoiSizeList [out] ROI�б��ο�MVD_ROI_SIZE_LIST���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention �ú���������ʱ����
	///
	///-----------------------------------------------------------------------------
	KSJ_API int __stdcall KSJ_GetRoiSizeItems(IN KSJ_DEVICETYPE usDeviceType, OUT MVD_ROI_SIZE_LIST *pRoiSizeList);

#ifdef __cplusplus
}
#endif

#endif
