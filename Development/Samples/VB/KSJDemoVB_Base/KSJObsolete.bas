Attribute VB_Name = "KSJObsolete"
Option Explicit

'�򿪻�ر�GammaУ������Ӱ��Ԥ����Ӱ��ɼ�
Public Declare Function KSJ_GammaOn Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bOn As Boolean) As Long

'���ù̶�֡��(ͨ������sensor�Ĵ���,ʹsensor����̶�֡��)��ֻ��MUC36C/M(MGYY)��MU3E130C/M(CGYY)֧��
'V4.0.86.12�汾��ʼ��bEnable������Ч��ͨ���û�����KSJ_TRIGGER_FIXFRAMERATEģʽ�������Ƿ�ʹ��
Public Declare Function KSJ_SetFixedFrameRate Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean, ByVal fFrameRate As Single) As Long
Public Declare Function KSJ_GetFixedFrameRate Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbEnable As Boolean, ByRef pfFrameRate As Single) As Long

'������ź������ʵ������������ʱ���ã��ݲ�֧�֣�
Public Declare Function KSJ_StrobeDelaySet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wDelay As Long) As Long
Public Declare Function KSJ_StrobeDelayGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwDelay As Long) As Long
Public Declare Function KSJ_StrobeDelayGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wMin As Long, ByVal wMax As Long) As Long

'����ͼ�񴫸����Ĺ�����ʽ���ݲ�֧�֣�
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