#ifndef __KSJ_FOV_H__
#define __KSJ_FOV_H__


struct FOV_ITEM
{
	int    nColSize;
	int    nRowSize;
};

extern FOV_ITEM  g_FovItems[];
extern const int g_nFovItems;
extern TCHAR*    g_szFovItems[];
extern int       g_szFovItemsNum[];

extern const TCHAR*  g_szFiledOfViewSkip[];
extern const int g_nFiledOfViewSkip;


#endif