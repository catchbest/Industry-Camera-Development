Attribute VB_Name = "KSJApiCustom"
Option Explicit

'将pData(宽度为nWidth, 高度为nHeight, 比特位数为nBitCount)的图像数据缩放为宽度为nStretchWidh, 高度为nStretchHeight的数据并填充到用户分配的pStretchData缓冲区,比特位数不变
Public Declare Function KSJ_HelperStretchBmp Lib "KSJAPI.dll" (pData As Any, ByVal nWidth As Long, ByVal nHeight As Long,ByVal nBitCount As Long, pStretchData As Any, ByVal nStretchWidth As Long, ByVal nStretchHeight As Long) As Long

'根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
Public Declare Function KSJ_HelperGetBmpFileHeaderSize Lib "KSJAPI.dll" (ByVal nBitCount As Long,ByRef pnTotalBytes As Long) As Long

'得到BMP图像的文件头和信息头
Public Declare Function KSJ_HelperGetBmpFileHeader Lib "KSJAPI.dll" (ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, pHeader As Any) As Long

'采集一帧图像到系统剪贴板
Public Declare Function KSJ_CaptureRgbDataToClipboard Lib "KSJAPI.dll" (ByVal nChannel As Long) As Long