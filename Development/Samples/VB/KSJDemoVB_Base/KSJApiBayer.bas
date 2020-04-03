Attribute VB_Name = "KSJApiBayer"
Option Explicit


Enum KSJ_BAYERMODE
    KSJ_BGGR_BGR24
    KSJ_GRBG_BGR24
    KSJ_RGGB_BGR24
    KSJ_GBRG_BGR24
    KSJ_BGGR_BGR24_FLIP
    KSJ_GRBG_BGR24_FLIP
    KSJ_RGGB_BGR24_FLIP
    KSJ_GBRG_BGR24_FLIP
    KSJ_BGGR_BGR32
    KSJ_GRBG_BGR32
    KSJ_RGGB_BGR32
    KSJ_GBRG_BGR32
    KSJ_BGGR_BGR32_FLIP
    KSJ_GRBG_BGR32_FLIP
    KSJ_RGGB_BGR32_FLIP
    KSJ_GBRG_BGR32_FLIP
    KSJ_BGGR_GRAY8
    KSJ_GRBG_GRAY8
    KSJ_RGGB_GRAY8
    KSJ_GBRG_GRAY8
    KSJ_BGGR_GRAY8_FLIP
    KSJ_GRBG_GRAY8_FLIP
    KSJ_RGGB_GRAY8_FLIP
    KSJ_GBRG_GRAY8_FLIP
End Enum

'�õ���ǰ�����Ĭ��Bayerģʽ
Public Declare Function KSJ_BayerGetDefaultMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pBayerMode As KSJ_BAYERMODE) As Long

'����Bayerģʽ��ͬʱӰ��ɼ���Ԥ�������������������Ҫ���ã������û�������ô˹���
Public Declare Function KSJ_BayerSetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pBayerMode As KSJ_BAYERMODE) As Long

'��õ�ǰBayerģʽ
Public Declare Function KSJ_BayerGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pBayerMode As KSJ_BAYERMODE) As Long

Enum KSJ_FILTERMODE
        KSJ_NEARESTNEIGHBOR
        KSJ_BILINEAR
        KSJ_SMOOTHHUE
        KSJ_EDGESENSING
        KSJ_LAPLACIAN
        KSJ_FASTBILINEAR
End Enum

'����Bayer Filterģʽ��ͬʱӰ��ɼ���Ԥ�������������������Ҫ���ã������û�������ô˹���
Public Declare Function KSJ_FilterSetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal FilterMode As KSJ_FILTERMODE) As Long

'��õ�ǰBayerģʽ
Public Declare Function KSJ_FilterGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef FilterMode As KSJ_FILTERMODE) As Long
