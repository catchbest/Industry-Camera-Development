Attribute VB_Name = "KSJApi16Bits"
Option Explicit

'Get AD Resolution. Valid bits in 16 bits
Public Declare Function KSJ_GetADCResolution Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnADCResolution As Long) As Long

'Set 16bits Transfer, Image Data Bytes Number doubled
Public Declare Function KSJ_SetData16Bits Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean) As Long

'Get If 16bits Transfer
Public Declare Function KSJ_GetData16Bits Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bEnable As Boolean) As Long

'Get Capture Image Information. nBitsPerSample = 8 when not 16bits. = 16 when 16 bits.
'Allocate Capture buffer according to these information.
Public Declare Function KSJ_CaptureGetSizeExEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long, ByRef nBitsPerSample As Long) As Long

 '保存为Tiff文件
Public Declare Function KSJ_HelperSaveToTiff Lib "KSJAPI.dll" (pData As Any, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal nSamplesPerPixel As Long, ByVal pszFileName As String) As Long