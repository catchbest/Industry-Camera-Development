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

// ��ʼ����ز���, Ĭ��Ϊ12bits��LUT16TO8��KSJC_CUBICSPLINE��4���༭��
KSJTABLEMAKER_API KSJTableMaker_Init  ( HANDLE *hTableMaker, HWND  hWnd );
KSJTABLEMAKER_API KSJTableMaker_UnInit( HANDLE *hTableMaker);

// nX�����hWnd�ͻ��������Ͻ�ˮƽƫ�ƣ�nY�������hWnd�ͻ��������ϽǴ�ֱƫ�ƣ�nWΪLutTable����ʾ��ȣ�nHΪLutTable����ʾ�߶�
KSJTABLEMAKER_API KSJTableMaker_SetPos(HANDLE hTableMaker, HWND  hWnd, int nX, int nY, int nW, int nH );


// ���ò��ұ�Ϊ��λ���ұ�ֻ��������10��12λ�������ADCResolution�����á�
KSJTABLEMAKER_API KSJTableMaker_TableSetSize(HANDLE hTableMaker, int nBits);
// ���ز��ұ��λ��
KSJTABLEMAKER_API KSJTableMaker_TableGetSize(HANDLE hTableMaker, int *pnBits);


enum KSJTABLEMAKER_TABLE_TYPE { LUT16TO8 = 0, LUT16TO16 };
// ���ò��ұ�����LUT16TO8ΪLUT,LUT16TO16ΪGammaLUT
KSJTABLEMAKER_API KSJTableMaker_TableSetType(HANDLE hTableMaker, KSJTABLEMAKER_TABLE_TYPE TableType);
KSJTABLEMAKER_API KSJTableMaker_TableGetType(HANDLE hTableMaker, KSJTABLEMAKER_TABLE_TYPE *pTableType);

// ��λ���ұ�,��λΪKSJC_CUBICSPLINE��4���༭�㣬��Ӱ��bitλ���Ͳ��ұ����͡�
KSJTABLEMAKER_API KSJTableMaker_Reset ( HANDLE hTableMaker );

// ���ø��ݱ༭�������ұ�Ĳ�ͬ�㷨��
// KSJC_LINES���ֱ�����
// KSJC_CUBICSPLINE ����������ֵ
enum KSJ_CURVEFITTING { KSJC_LINES = 0, KSJC_BEZIER2, KSJC_BEZIER3, KSJC_CUBICSPLINE, KSJC_GAMMA };

// ����ʹ�����ַ��������
KSJTABLEMAKER_API KSJTableMaker_TableSetFitting(HANDLE hTableMaker, KSJ_CURVEFITTING CurveFitting);

KSJTABLEMAKER_API KSJTableMaker_TableGetFitting(HANDLE hTableMaker, KSJ_CURVEFITTING *pCurveFitting);

KSJTABLEMAKER_API KSJTableMaker_SetGamma(HANDLE hTableMaker, float fGamma);
KSJTABLEMAKER_API KSJTableMaker_GetGamma(HANDLE hTableMaker, float *pfGamma);

// ����
KSJTABLEMAKER_API KSJTableMaker_Draw           ( HANDLE hTableMaker );

// �������
KSJTABLEMAKER_API KSJTableMaker_IsPassEditPoint( HANDLE hTableMaker, int nX, int nY );
KSJTABLEMAKER_API KSJTableMaker_IsHitEditPoint ( HANDLE hTableMaker, int nX, int nY );
KSJTABLEMAKER_API KSJTableMaker_MoveEditPoint  ( HANDLE hTableMaker, int nOffsetX, int nOffsetY );

// ���ñ༭�����
KSJTABLEMAKER_API KSJTableMaker_SetEditPointNum( HANDLE hTableMaker, int nNum );
KSJTABLEMAKER_API KSJTableMaker_GetEditPointNum( HANDLE hTableMaker, int *pnNum );

// ���ز��ұ�
KSJTABLEMAKER_API KSJTableMaker_TableGet( HANDLE hTableMaker, unsigned char *pTable );
// ���ò��ұ�
KSJTABLEMAKER_API KSJTableMaker_TableSet( HANDLE hTableMaker, unsigned char *pTable );

// ������Ϊ���Ӽ�ר��ʶ��Ĳ��ұ��ļ�
KSJTABLEMAKER_API KSJTableMaker_TableWrite( HANDLE hTableMaker, TCHAR *pTableName );
// ��ȡ���Ӽ�ר��ʶ��Ĳ��ұ��ļ�
KSJTABLEMAKER_API KSJTableMaker_TableRead ( HANDLE hTableMaker, TCHAR *pTableName );

#endif




