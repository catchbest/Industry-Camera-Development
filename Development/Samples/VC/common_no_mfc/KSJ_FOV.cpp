#include <tchar.h>
#include "KSJ_FOV.h"

FOV_ITEM  g_FovItems[] =
{
	640, 480,	  // 1 
	752, 480,	  // 2 
	728, 544,	  // 3 
	800, 600,	  // 4 
	1024, 768,	  // 5 
	1280, 960,    // 6 
	1280, 1024,	  // 7 
	1360, 1024,   // 8 
	1600, 1200,   // 9 
	// 1920, 1080,   // 10
	1944, 1096,
	1936, 1216,   // 11
	1628, 1236,   // 12
	2048, 1536,   // 13
	2048, 1,      // 14
	2048, 2,      // 15
	2560, 1440,   // 16
	2592, 1944,   // 17
	2464, 2056,   // 18
	2616, 1976,   // 19
	3096, 2080,   // 20
	3488, 2616,   // 21
	3664, 2748,   // 22
	3840, 2160,   // 23
	3856, 2764,   // 24
	4072, 3046,   // 25 ++MU3S1200C/M 
	4152, 2160,   // 26
	4096, 1,      // 27
	4096, 2,      // 28
	4384, 3288,   // 29
	4608, 2592,   // 30
	4608, 3288,   // 31
	5472, 3648,   // 32
	2040, 2048,   // 33
	2048, 2048,   // 34
	2064, 1544,   // 35
};

const int g_nFovItems = sizeof(g_FovItems) / sizeof(FOV_ITEM);

TCHAR* g_szFovItems[] =
{
	_T("640 x 480"),                              // 1
	_T("752 x 480(UC36C/M)"),                     // 2
	_T("728 x 544"),                              // 3
	_T("800 x 600"),                              // 4
	_T("1024 x 768"),                             // 5
	_T("1280 x 960(MU3C120C/M)"),                 // 6
	_T("1280 x 1024(UC130C/M)"),                  // 7
	_T("1360 x 1024(UD205(285)C/M)"),             // 8
	_T("1600 x 1200(MU3E200C/M"),                 // 9
	//_T("1920 x 1080(1080p)"),                  // 10
	_T("1944 x 1096(MU3S210C/M)"),
	_T("1936 x 1216(U3S230C/M)"),                 // 11
	_T("1628 x 1236(UD274C/M)"),                  // 12
	_T("2048 x 1536(UC320C)"),                    // 13
	_T("2048 x 1(MU3L2K7M)"),                     // 14
	_T("2048 x 2(MU3L2K7C)"),                     // 15
	_T("2560 x 1440(720p)"),                      // 16
	_T("2592 x 1944(UC500C/M)"),                  // 17
	_T("2464 x 2056(MU3S500C/M)"),                // 18
	_T("2616 x 1976"),                            // 19
	_T("3096 x 2080(MU3S640C/M)"),                // 20
	_T("3488 x 2616(UC900C)"),                    // 21
	_T("3664 x 2748(UC1000C 4:3)"),               // 22
	_T("3840 x 2160(UC1000C 1080p)"),             // 23
	_T("3856 x 2764(UC1000C Entire)"),            // 24
	_T("4072 x 3046(U3S1200C/M)"),                // 25
	_T("4152 x 2160(U3S1200C/M BINNING)"),        // 26
	_T("4096 x 1(MU3L4K3M)"),                     // 27
	_T("4096 x 2(MU3L4K3C)"),                     // 28
	_T("4384 x 3288(UC1400C 4:3 Still Mode)"),    // 29
	_T("4608 x 2592(UC1400C 16:9 Video Mode)"),   // 30
	_T("4608 x 3288(UC1400C Entire)"),            // 31
	_T("5472 x 3648(MU3HS2000C/M Entire)"),       // 32
	_T("2040 x 2048(MU3HI400C/M)"),                // 33
	_T("2048 x 2048(MU3HI401C/M)"),                // 34
	_T("2064 x 1544(MU3S321C/M)")                  // 35
};

// 这个索引是设备型号
int   g_szFovItemsNum[] =
{
	7,   // KSJ_UC130C_MRNN (1280X1024), 
	7,	 // KSJ_UC130M_MRNN , 
	0,   // KSJ_UC200C_MRNN, 
	13,	 // KSJ_UC320C_MRNN, 
	7,	 // KSJ_UC130C_MRYN, 
	7,	 // KSJ_UC130M_MRYN, 
	7,	 // KSJ_UC200C_MRYN, 
	13,	 // KSJ_UC320C_MRYN, 
	17,	 // KSJ_UC500C_MRNN, 
	17,	 // KSJ_UC500M_MRNN, 
	17,	 // KSJ_UC500C_MRYN, 
	17,	 // KSJ_UC500M_MRYN, 
	0,	 // KSJ_UC320C_OCR,
	21,	 // KSJ_UC900C_MRNN,
	24,	 // KSJ_UC1000C_MRNN, 
	0,	 // KSJ_UC900C_MRYN, 
	0,	 // KSJ_UC1000C_MRYN, 
	7,	 // KSJ_UC130C_MRYY,
	7,	 // KSJ_UC130M_MRYY,
	8,	 // KSJ_UD140C_SGNN, 
	8,	 // KSJ_UD140M_SGNN, 
	2,	 // KSJ_UC36C_MGNN, 
	2,	 // KSJ_UC36M_MGNN,
	0,	 // KSJ_UC36C_MGYN,
	0,	 // KSJ_UC36M_MGYN,
	21,	 // KSJ_UC900C_MRYY,
	24,	 // KSJ_UC1000C_MRYY,
	30,	 // KSJ_UC1400C_MRYY,
	2,	 // KSJ_UC36C_MGYY,
	2,	 // KSJ_UC36M_MGYY,
	13,	 // KSJ_UC320C_MRYY,
	17,	 // KSJ_UC500C_MRYY,
	17,	 // KSJ_UC500M_MRYY,
	7,	 // KSJ_MUC130C_MRYN, 
	7,	 // KSJ_MUC130M_MRYN, 
	13,	 // KSJ_MUC320C_MRYN,
	2,	 // KSJ_MUC36C_MGYYO, 
	2,	 // KSJ_MUC36M_MGYYO, 
	7,	 // KSJ_MUC130C_MRYY, 
	7,	 // KSJ_MUC130M_MRYY, 
	13,	 // KSJ_MUC320C_MRYY, 
	17,	 // KSJ_MUC500C_MRYY, 
	17,	 // KSJ_MUC500M_MRYY,
	21,	 // KSJ_MUC900C_MRYY, 
	24,	 // KSJ_MUC1000C_MRYY,
	31,	 // KSJ_MUC1400C_MRYY,
	8,	 // KSJ_UD205C_SGYY,
	8,	 // KSJ_UD205M_SGYY,
	12,	 // KSJ_UD274C_SGYY,
	12,	 // KSJ_UD274M_SGYY,
	8,	 // KSJ_UD285C_SGYY,
	8,	 // KSJ_UD285M_SGYY,
	17,	 // KSJ_MU3C500C_MRYYO,
	17,	 // KSJ_MU3C500M_MRYYO,
	24,	 // KSJ_MU3C1000C_MRYYO,
	31,	 // KSJ_MU3C1400C_MRYYO,
	7,   // KSJ_MU3V130C_CGYYO,
	7,	 // KSJ_MU3V130M_CGYYO,
	7,	 // KSJ_MU3E130C_EGYYO,
	7,	 // KSJ_MU3E130M_EGYYO,
	2,	 // KSJ_MUC36C_MGYFO,
	2,	 // KSJ_MUC36M_MGYFO
	6,	 // KSJ_MU3C120C_MGYYO,
	6,	 // KSJ_MU3C120M_MGYYO,
	9,   // KSJ_MU3E200C_EGYY,
	9,   // KSJ_MU3E200M_EGYY,
	7,   // KSJ_MUC130C_MRYNO,
	7,   // KSJ_MUC130M_MRYNO,
	13,  // KSJ_MUC320C_MRYNO,
	8,   // KSJ_U3C130C_MRYNO,
	8,   // KSJ_U3C130M_MRYNO,
	13,  // KSJ_U3C320C_MRYNO,
	17,  // KSJ_U3C500C_MRYNO,
	17,  // KSJ_U3C500M_MRYNO,
	31,  // KSJ_MU3C1401C_MRYYO
	24,  // KSJ_MU3C1001C_MRYYO
	7,	 // KSJ_MUC131M_MRYN, 
	17,	 // KSJ_MU3C501C_MRYYO,
	17,	 // KSJ_MU3C501M_MRYYO,
	6,   // KSJ_MU3C121C_MGYYO
	6,   // KSJ_MU3C121M_MGYYO
	7,   // KSJ_MU3E131C_EGYYO
	7,   // KSJ_MU3E131M_EGYYO
	9,   // KSJ_MU3E201C_EGYYO
	9,   // KSJ_MU3C201M_EGYYO
	0,   // KSJ_MISSING_DEVICE
	11,  // KSJ_MU3S230C_SGYYO,   // Jelly3
	11,  // KSJ_MU3S230M_SGYYO,   // Jelly3
	20,  // KSJ_MU3S640C_SRYYO,   // Jelly3
	20,  // KSJ_MU3S640C_SRYYO,   // Jelly3
	8,	 // KSJ_CUD285C_SGYY,
	8,	 // KSJ_CUD285M_SGYY,
	11,  // KSJ_MU3S231C_SGYYO,   // Jelly3
	11,  // KSJ_MU3S231M_SGYYO,   // Jelly3
	18,  // MU3S500C
	18,  // MU3S500M
	26,  // MU3S1200C
	26,  // MU3S1200M
	15,  // KSJ_MU3L2K7C_AGYYO
	14,  // KSJ_MU3L2K7M_AGYYO
	28,  // KSJ_MU3L4K3C_AGYYO
	27,  // KSJ_MU3L4K3M_AGYYO
	32,  // KSJ_MU3HS2000C_SRYYO
	32,  // KSJ_MU3HS2000M_SRYYO
	18,  // MU3HS500C
	18,  // MU3HS500M
	11,  // KSJ_MU3HS230C_SGYYO,   // Jelly3
	11,  // KSJ_MU3HS230M_SGYYO,   // Jelly3
	33,
	33,
	33,
	34,
	34,
	3,    // MU3S40C
	3,    // MU3S40M
	10,   // MU3S210C(SGYYO)
	10,   // MU3S210M(SGYYO)
	7,    // KSJ_MU3I130C_IGYYO
	7,    // KSJ_MU3I130M_IGYYO
	35,
	35,
	20,  // DT_CB_MU3S641M_SGYYO     KSJ_MU3S641M_SGYYO,   // Jelly3
	26,  // KSJ_MU3S1201M_SRYYO    MU3S1201M
	32,  // KSJ_MU3HS2001M_SRYYO   KSJ_MU3HS2000M_SRYYO
	10,  // DT_CB_MU3S211M_SGYYO     MU3S210M(SGYYO)
	2,	 // DT_CB_MU3C36C_MGYY       KSJ_MUC36C_MGYYO, 
	2,	 // DT_CB_MU3C36M_MGYY       KSJ_MUC36M_MGYYO, 
	26,	 // DT_CB_MU3HS1200C_SGYYO   MU3S1200C
	26,	 // DT_CB_MU3HS1200M_SGYYO   MU3S1201M
};

const TCHAR*  g_szFiledOfViewSkip[] =
{
	_T("0 x 0"),
	_T("2 x 2"),
	_T("3 x 3"),
	_T("4 x 4"),
	_T("8 x 8")
};

const int g_nFiledOfViewSkip = sizeof(g_szFiledOfViewSkip) / sizeof(g_szFiledOfViewSkip[0]);
