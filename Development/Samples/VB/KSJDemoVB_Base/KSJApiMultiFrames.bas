Attribute VB_Name = "KSJApiMultiFrames"
Option Explicit

'����Ԥ���ӳ�
Public Declare Function KSJ_PreviewSetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long

'��ȡԤ���ӳ�
Public Declare Function KSJ_PreviewGetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long


'���òɼ��ӳ���С
Public Declare Function KSJ_CaptureSetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long

'��ȡ�ɼ��ӳ���ʵ�ʴ�С
Public Declare Function KSJ_CaptureGetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long
