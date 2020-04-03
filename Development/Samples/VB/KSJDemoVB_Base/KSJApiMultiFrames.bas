Attribute VB_Name = "KSJApiMultiFrames"
Option Explicit

'设置预览视场
Public Declare Function KSJ_PreviewSetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long

'获取预览视场
Public Declare Function KSJ_PreviewGetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long


'设置采集视场大小
Public Declare Function KSJ_CaptureSetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long

'获取采集视场的实际大小
Public Declare Function KSJ_CaptureGetFieldOfViewEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE, ByVal wMultiFrameNum As Long) As Long
