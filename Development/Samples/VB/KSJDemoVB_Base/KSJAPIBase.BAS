Attribute VB_Name = "KSJAPIBase"
Option Explicit



'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

'凯视佳工业相机设备类型定义
Enum KSJ_DEVICETYPE
    KSJ_UC130C_MRNN = 0
    KSJ_UC130M_MRNN
    KSJ_UC200C_MRNN
    KSJ_UC320C_MRNN
    KSJ_UC130C_MRYN
    KSJ_UC130M_MRYN
    KSJ_UC200C_MRYN
    KSJ_UC320C_MRYN
    KSJ_UC500C_MRNN
    KSJ_UC500M_MRNN
    KSJ_UC500C_MRYN
    KSJ_UC500M_MRYN
    KSJ_UC320C_OCR
    KSJ_UC900C_MRNN
    KSJ_UC1000C_MRNN
    KSJ_UC900C_MRYN
    KSJ_UC1000C_MRYN
    KSJ_UC130C_MRYY
    KSJ_UC130M_MRYY
    KSJ_UD140C_SRNN
    KSJ_UD140M_SRNN
    KSJ_UC36C_MGNN
    KSJ_UC36M_MGNN
    KSJ_UC36C_MGYN
    KSJ_UC36M_MGYN
    KSJ_UC900C_MRYY
    KSJ_UC1000C_MRYY
    KSJ_UC1400C_MRYY
    KSJ_UC36C_MGYY
    KSJ_UC36M_MGYY
    KSJ_UC320C_MRYY
    KSJ_UC500C_MRYY
    KSJ_UC500M_MRYY
    KSJ_MUC130C_MRYN
    KSJ_MUC130M_MRYN
    KSJ_MUC320C_MRYN
    KSJ_MUC36C_MGYY
    KSJ_MUC36M_MGYY
    KSJ_MUC130C_MRYY
    KSJ_MUC130M_MRYY
    KSJ_MUC320C_MRYY
    KSJ_MUC500C_MRYY
    KSJ_MUC500M_MRYY
    KSJ_MUC900C_MRYY
    KSJ_MUC1000C_MRYY
    KSJ_MUC1400C_MRYY
    KSJ_UD205C_SGYY
    KSJ_UD205M_SGYY
    KSJ_UD274C_SGYY
    KSJ_UD274M_SGYY
    KSJ_UD285C_SGYY
    KSJ_UD285M_SGYY
    KSJ_MU3C500C_MRYY
    KSJ_MU3C500M_MRYY
    KSJ_MU3C1000C_MRYY
    KSJ_MU3C1400C_MRYY
    KSJ_MU3V130C_CGYY
    KSJ_MU3V130M_CGYY
End Enum

'Enable or Disable Log output
Public Declare Function KSJ_LogSet Lib "KSJAPI.dll" (ByVal bEnable As Boolean, ByVal szFolder As String) As Long

'Get Log Status
Public Declare Function KSJ_LogGet Lib "KSJAPI.dll" (ByRef bEnable As Boolean, ByRef szFolder As String) As Long

'Get KSJApi.dll Version, call any time
Public Declare Function KSJ_GetVersion Lib "KSJAPI.dll" (ByRef pnMaj1 As Integer, ByRef pnMaj2 As Integer, ByRef pnMin1 As Integer, ByRef pnMin2 As Integer) As Long

'获得错误的详细信息，可以在任何时候调用
Public Declare Function KSJ_GetErrorInfo Lib "KSJAPI.dll" (ByVal nErrorNo As Long, ByVal pszErrorInfo As String) As Long

'初始化KSJApi动态库
Public Declare Function KSJ_Init Lib "KSJAPI.dll" () As Long

'反初始化KSJApi动态库
Public Declare Function KSJ_UnInit Lib "KSJAPI.dll" () As Long

'得到设备数目
Public Declare Function KSJ_DeviceGetCount Lib "KSJAPI.dll" () As Long

Public Declare Function KSJ_WrEEPROM Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAddress As Integer, ByVal btValue As Byte) As Long
Public Declare Function KSJ_RdEEPROM Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAddress As Integer, ByRef btValue As Byte) As Long

'得到设备信息（型号，序号，固件版本号）
Public Declare Function KSJ_DeviceGetInformation Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pDeviceType As KSJ_DEVICETYPE, ByRef pnIndex As Long, ByRef pwFirmwareVersion As Integer) As Long

'得到设备信息（型号，序号，固件版本号）
Public Declare Function KSJ_DeviceGetInformationEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pDeviceType As KSJ_DEVICETYPE, ByRef pnIndex As Long, ByRef pwFirmwareVersion As Integer, ByRef pwFpgaVersion As Integer) As Long

'参数设置项
Enum KSJ_PARAM
    KSJ_EXPOSURE = 0
    KSJ_RED = 1
    KSJ_GREEN = 2
    KSJ_BLUE = 3
    KSJ_GAMMA = 4
    KSJ_PREVIEW_COLUMNSTART = 5
    KSJ_PREVIEW_ROWSTART = 6
    KSJ_CAPTURE_COLUMNSTART = 7
    KSJ_CAPTURE_ROWSTART = 8
    KSJ_HORIZONTALBLANK = 9
    KSJ_VERTICALBLANK = 10
    KSJ_FLIP = 11
    KSJ_BIN = 12
    KSJ_MIRROR = 13
    KSJ_CONTRAST = 14
    KSJ_BRIGHTNESS = 15
    KSJ_VGAGAIN = 16
    KSJ_CLAMPLEVEL = 17
    KSJ_CDSGAIN = 18
    KSJ_RED_SHIFT = 19
    KSJ_GREEN_SHIFT = 20
    KSJ_BLUE_SHIFT = 21
    KSJ_COMPANDING = 22
    KSJ_EXPOSURE_LINES = 23
    KSJ_SATURATION = 24
End Enum

'获得参数的设置范围
Public Declare Function KSJ_GetParamRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal Param As KSJ_PARAM, ByRef pnMinValue As Long, ByRef pnMaxValue As Long) As Long

'设置参数
Public Declare Function KSJ_SetParam Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal Param As KSJ_PARAM, ByVal nValue As Long) As Long

'获取参数
Public Declare Function KSJ_GetParam Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal Param As KSJ_PARAM, ByRef pnValue As Long) As Long

'Set Exposure Time (ms) for float format.( more precision )
Public Declare Function KSJ_ExposureTimeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal fExpTimeMs As Single) As Long

'Get Exposure Time (ms) for float format
Public Declare Function KSJ_ExposureTimeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef fExpTimeMs As Single) As Long

'抽点模式定义（分为列抽点和行抽点）
Enum KSJ_ADDRESSMODE
    KSJ_SKIPNONE = 0
    KSJ_SKIP2
    KSJ_SKIP3
    KSJ_SKIP4
    KSJ_SKIP8
End Enum

'Get The Max Capture FOV( Field Of View ） supported by device
Public Declare Function KSJ_CaptureGetDefaultFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE) As Long

'设置采集视场大小
Public Declare Function KSJ_CaptureSetFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE) As Long

'获取采集视场的实际大小
Public Declare Function KSJ_CaptureGetFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE) As Long

'得到采集图像的宽度和高度（单位：像素）
Public Declare Function KSJ_CaptureGetSize Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnWidth As Long, ByRef pnHeight As Long) As Long

'得到采集图像的宽度和高度（单位：像素）
Public Declare Function KSJ_CaptureGetSizeEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long) As Long

'采集一帧原始数据图像数据
Public Declare Function KSJ_CaptureRawData Lib "KSJAPI.dll" (ByVal nChannel As Long, pRawData As Any) As Long

'采集一帧24位彩色图像数据
Public Declare Function KSJ_CaptureRgbData Lib "KSJAPI.dll" (ByVal nChannel As Long, pRgbData As Any) As Long

'采集一帧24位彩色图像数据
Public Declare Function KSJ_CaptureRgbDataEx Lib "KSJAPI.dll" (ByVal nChannel As Long, pRgbData As Any, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long) As Long
 
 '保存为Bmp文件
Public Declare Function KSJ_HelperSaveToBmp Lib "KSJAPI.dll" (pData As Any, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal pszFileName As String) As Long

'保存为Jpg文件
Public Declare Function KSJ_HelperSaveToJpg Lib "KSJAPI.dll" (ByVal pData As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal nQulity As Long, ByVal pszFileName As String) As Long
 
'Get The Max Preview FOV( Field Of View ） supported by device
Public Declare Function KSJ_PreviewGetDefaultFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE) As Long
 
'设置预览视场
Public Declare Function KSJ_PreviewSetFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nColumnStart As Long, ByVal nRowStart As Long, ByVal nColumnSize As Long, ByVal nRowSize As Long, ByVal ColumnAddressMode As KSJ_ADDRESSMODE, ByVal RowAddressMode As KSJ_ADDRESSMODE) As Long

'获取预览视场
Public Declare Function KSJ_PreviewGetFieldOfView Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nColumnStart As Long, ByRef nRowStart As Long, ByRef nColumnSize As Long, ByRef nRowSize As Long, ByRef ColumnAddressMode As KSJ_ADDRESSMODE, ByRef RowAddressMode As KSJ_ADDRESSMODE) As Long

'获取在用户设置的视场模式下，预览图像的宽度和高度（像素）
Public Declare Function KSJ_PreviewGetSize Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnWidth As Long, ByRef pnHeight As Long) As Long

'获取在用户设置的视场模式下，预览图像的宽度（像素）和高度（像素）及比特位数
Public Declare Function KSJ_PreviewGetSizeEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long) As Long
 
'设置预览图像的显示位置
Public Declare Function KSJ_PreviewSetPos Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal hwnd As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long

'获取预览图像的显示位置
Public Declare Function KSJ_PreviewGetPos Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef px As Long, ByRef py As Long, ByRef pnWidth As Long, ByRef pnHeight As Long) As Long
 
Enum KSJ_PREVIEWMODE
    PM_RAWDATA = 0
    PM_RGBDATA
End Enum

'设置预览模式
Public Declare Function KSJ_PreviewSetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal PreviewMode As KSJ_PREVIEWMODE) As Long

'获取预览模式
Public Declare Function KSJ_PreviewGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pPreviewMode As KSJ_PREVIEWMODE) As Long
 
'获取默认预览模式
Public Declare Function KSJ_PreviewGetDefaultMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pPreviewMode As KSJ_PREVIEWMODE) As Long
 
'启动或停止预览
Public Declare Function KSJ_PreviewStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long

'启动或停止预览
Public Declare Function KSJ_PreviewStartEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal bParallel As Boolean) As Long

'暂停或继续预览
Public Declare Function KSJ_PreviewPause Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bPause As Boolean) As Long

Enum KSJ_PREVIEWSTATUS
    PS_STOP
    PS_START
    PS_PAUSE
End Enum

'Get Preview Status
Public Declare Function KSJ_PreviewGetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pPreviewStatus As KSJ_PREVIEWSTATUS) As Long

'Get Preview Frame Rate
Public Declare Function KSJ_PreviewGetFrameRate Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef fFrameRate As Single) As Long

'Get Paused Image Data when PS_PAUSE Status
Public Declare Function KSJ_PreviewGetPausedData Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any) As Long

'Get Paused Image Data when PS_PAUSE Status
Public Declare Function KSJ_PreviewGetPausedDataEx Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long) As Long

