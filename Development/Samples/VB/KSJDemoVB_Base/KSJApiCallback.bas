Attribute VB_Name = "KSJApiCallback"
Option Explicit

'…Ë÷√‘§¿¿ªÿµ˜
Public Declare Function KSJ_PreviewSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfPreviewCallback As Long, ByVal lpContext As Long) As Long

Public Declare Function KSJ_PreviewSetCallbackEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfPreviewCallbackEx As Long, ByVal lpContext As Long) As Long


Public Sub PreviewCallback(ByRef pImageData As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal lpContext As Long)

End Sub

Public Sub PreviewCallbackEx(ByRef hDC As Long, ByRef pImageData As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal lpContext As Long)

End Sub
