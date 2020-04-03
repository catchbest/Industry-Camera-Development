Attribute VB_Name = "WINGDI"
Option Explicit

Private Const BI_RGB = 0&
Private Const DIB_RGB_COLORS = 0 'color table in RGBs
Private Const SRCCOPY = &HCC0020


Type BITMAPFILEHEADER
    bfType(0 To 1) As Byte
    bfSize As Long
    bfReserved1 As Integer
    bfReserved2 As Integer
    bfOffBits As Long
End Type


Type BITMAPINFOHEADER
    biSize As Long
    biWidth As Long
    biHeight As Long
    biPlanes As Integer
    biBitCount As Integer
    biCompression As Long
    biSizeImage As Long
    biXPelsPerMeter As Long
    biYPelsPerMeter As Long
    biClrUsed As Long
    biClrImportant As Long
End Type

Type RGBQUAD
    rgbBlue As Byte
    rgbGreen As Byte
    rgbRed As Byte
    rgbReserved As Byte
End Type

Type BITMAPINFO
        bmiHeader As BITMAPINFOHEADER
        bmiColors(0 To 255) As RGBQUAD
End Type

Declare Function GetLastError Lib "kernel32.dll" () As Long
Declare Function SetStretchBltMode Lib "gdi32" (ByVal hdc As Long, ByVal nStretchMode As Long) As Long
Declare Function StretchDIBits Lib "gdi32" (ByVal hdc As Long, ByVal XDest As Long, ByVal YDest As Long, ByVal nDestWidth As Long, ByVal nDestHeight As Long, ByVal XSrc As Long, ByVal YSrc As Long, ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, lpBits As Any, lpBitsInfo As BITMAPINFO, ByVal wUsage As Long, ByVal dwRop As Long) As Long

Type RECT
        Left    As Long
        Top     As Long
        Right   As Long
        Bottom  As Long
End Type

Type POINT
        x    As Long
        y    As Long
End Type

Declare Function GetWindowRect Lib "user32 " (ByVal hwnd As Long, lpRect As RECT) As Long
Declare Function GetClientRect Lib "user32 " (ByVal hwnd As Long, lpRect As RECT) As Long
Declare Function MoveWindow Lib "user32" (ByVal hwnd As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal bRepaint As Long) As Long
Declare Function ScreenToClient Lib "user32" (ByVal hwnd As Long, lpPoint As POINT) As Long

Public FunctionName(55) As String

