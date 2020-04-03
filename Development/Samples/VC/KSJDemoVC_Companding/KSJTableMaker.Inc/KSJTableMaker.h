#ifndef KSJ_TABLE_MAKER_H__
#define KSJ_TABLE_MAKER_H__

#ifdef KSJTABLEMAKER_EXPORTS
#define KSJTABLEMAKER_API __declspec(dllexport) int
#elif defined(KSJTABLEMAKER_STATIC)
#define KSJTABLEMAKER_API int
#else
#define KSJTABLEMAKER_API __declspec(dllimport) int
#endif

#define KSJTABLEMAKER_RET_SUCCESS                   0
#define KSJTABLEMAKER_RET_FAIL                      1
#define KSJTABLEMAKER_RET_NOTSUPPORT                2
#define KSJTABLEMAKER_RET_VERSIONNOTMATCH           3

// 初始化相关参数, 默认为12bits，LUT16TO8，KSJC_CUBICSPLINE，4个编辑点
KSJTABLEMAKER_API KSJTableMaker_Init  ( HANDLE *hTableMaker, HWND  hWnd );
KSJTABLEMAKER_API KSJTableMaker_UnInit( HANDLE *hTableMaker);

// nX是相对hWnd客户区的左上角水平偏移，nY是相对于hWnd客户区的左上角垂直偏移，nW为LutTable的显示宽度，nH为LutTable的显示高度
KSJTABLEMAKER_API KSJTableMaker_SetPos(HANDLE hTableMaker, HWND  hWnd, int nX, int nY, int nW, int nH );


// 设置查找表为几位查找表，只可以设置10或12位，需根据ADCResolution来设置。
KSJTABLEMAKER_API KSJTableMaker_TableSetSize(HANDLE hTableMaker, int nBits);
// 返回查找表的位数
KSJTABLEMAKER_API KSJTableMaker_TableGetSize(HANDLE hTableMaker, int *pnBits);


enum KSJTABLEMAKER_TABLE_TYPE { LUT16TO8 = 0, LUT16TO16 };
// 设置查找表类型LUT16TO8为LUT,LUT16TO16为GammaLUT
KSJTABLEMAKER_API KSJTableMaker_TableSetType(HANDLE hTableMaker, KSJTABLEMAKER_TABLE_TYPE TableType);
KSJTABLEMAKER_API KSJTableMaker_TableGetType(HANDLE hTableMaker, KSJTABLEMAKER_TABLE_TYPE *pTableType);

// 复位查找表,复位为KSJC_CUBICSPLINE，4个编辑点，不影响bit位数和查找表类型。
KSJTABLEMAKER_API KSJTableMaker_Reset ( HANDLE hTableMaker );

// 设置根据编辑点计算查找表的不同算法。
// KSJC_LINES多段直线拟合
// KSJC_CUBICSPLINE 三次样条插值
enum KSJ_CURVEFITTING { KSJC_LINES = 0, KSJC_BEZIER2, KSJC_BEZIER3, KSJC_CUBICSPLINE, KSJC_GAMMA };

// 设置使用哪种方法来拟合
KSJTABLEMAKER_API KSJTableMaker_TableSetFitting(HANDLE hTableMaker, KSJ_CURVEFITTING CurveFitting);

KSJTABLEMAKER_API KSJTableMaker_TableGetFitting(HANDLE hTableMaker, KSJ_CURVEFITTING *pCurveFitting);

KSJTABLEMAKER_API KSJTableMaker_SetGamma(HANDLE hTableMaker, float fGamma);
KSJTABLEMAKER_API KSJTableMaker_GetGamma(HANDLE hTableMaker, float *pfGamma);

// 绘制
KSJTABLEMAKER_API KSJTableMaker_Draw           ( HANDLE hTableMaker );

// 跟踪鼠标
KSJTABLEMAKER_API KSJTableMaker_IsPassEditPoint( HANDLE hTableMaker, int nX, int nY );
KSJTABLEMAKER_API KSJTableMaker_IsHitEditPoint ( HANDLE hTableMaker, int nX, int nY );
KSJTABLEMAKER_API KSJTableMaker_MoveEditPoint  ( HANDLE hTableMaker, int nOffsetX, int nOffsetY );

// 设置编辑点个数
KSJTABLEMAKER_API KSJTableMaker_SetEditPointNum( HANDLE hTableMaker, int nNum );
KSJTABLEMAKER_API KSJTableMaker_GetEditPointNum( HANDLE hTableMaker, int *pnNum );

// 返回查找表
KSJTABLEMAKER_API KSJTableMaker_TableGet( HANDLE hTableMaker, unsigned char *pTable );
// 设置查找表
KSJTABLEMAKER_API KSJTableMaker_TableSet( HANDLE hTableMaker, unsigned char *pTable );

// 将表保存为凯视佳专门识别的查找表文件
KSJTABLEMAKER_API KSJTableMaker_TableWrite( HANDLE hTableMaker, TCHAR *pTableName );
// 读取凯视佳专用识别的查找表文件
KSJTABLEMAKER_API KSJTableMaker_TableRead ( HANDLE hTableMaker, TCHAR *pTableName );

#endif




