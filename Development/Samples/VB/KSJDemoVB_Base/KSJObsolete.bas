Attribute VB_Name = "KSJObsolete"
Option Explicit

'打开或关闭Gamma校正，即影响预览又影响采集
Public Declare Function KSJ_GammaOn Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bOn As Boolean) As Long

'设置固定帧速(通过设置sensor寄存器,使sensor输出固定帧率)，只有MUC36C/M(MGYY)和MU3E130C/M(CGYY)支持
'V4.0.86.12版本开始，bEnable参数无效，通过用户设置KSJ_TRIGGER_FIXFRAMERATE模式来决定是否使能
Public Declare Function KSJ_SetFixedFrameRate Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean, ByVal fFrameRate As Single) As Long
Public Declare Function KSJ_GetFixedFrameRate Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbEnable As Boolean, ByRef pfFrameRate As Single) As Long

'闪光灯信号输出到实际相机输出的延时设置（暂不支持）
Public Declare Function KSJ_StrobeDelaySet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wDelay As Long) As Long
Public Declare Function KSJ_StrobeDelayGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwDelay As Long) As Long
Public Declare Function KSJ_StrobeDelayGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wMin As Long, ByVal wMax As Long) As Long

'设置图像传感器的工作方式（暂不支持）
enum KSJ_SENSORMODE
	KSJ_SM_TRIGGER_MODE
	KSJ_SM_FREERUN_MODE
	KSJ_SM_GRR_MODE
End Enum

Public Declare Function KSJ_SensorModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal SensorMode As KSJ_SENSORMODE) As Long
Public Declare Function KSJ_SensorModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef SensorMode As KSJ_SENSORMODE) As Long

Public Declare Function KSJ_ColorCorrectSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal fpCCCallback As Long, ByVal lpContext As Long) As Long

enum KSJ_COLORCORRECT
	KSJ_CC_NONE
	KSJ_CC_SHIFTRGB
	KSJ_CC_EQRGB
	KSJ_CC_EQALL
	KSJ_CC_WB
End Enum

Public Declare Function KSJ_ColorCorrectSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal ColorCorrect As KSJ_COLORCORRECT, ByVal nRTarget As Long, ByVal nGTarget As Long, ByVal nBTarget As Long) As Long
Public Declare Function KSJ_ColorCorrectGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pColorCorrect As KSJ_COLORCORRECT) As Long
Public Declare Function KSJ_ColorCorrectGetEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pColorCorrect As KSJ_COLORCORRECT, ByRef nRTarget As Long, ByRef nGTarget As Long, ByRef nBTarget As Long) As Long


Public Declare Function KSJ_ColorCorrectTableSave Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pszFileName As String) As Long
Public Declare Function KSJ_ColorCorrectTableLoad Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pszFileName As String) As Long
Public Declare Function KSJ_IsColorCorrectTableLoad Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bLoad As Boolean) As Long

Public Sub KSJ_CCCALLBACK(ByVal bSuccess As Boolean, ByVal nRShift As Long, ByVal nGShift As Long, ByVal nBShift As Long, ByVal lpContext As Long)

End Sub