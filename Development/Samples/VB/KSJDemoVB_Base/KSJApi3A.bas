Attribute VB_Name = "KSJApi3A"
Option Explicit


'�����Զ��ع������������������Ԥ��ͼ������Ͻ�����λ��
Public Declare Function KSJ_AESetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'�����Զ��ع������������������Ԥ��ͼ������Ͻ�����λ��,�Ƿ���ʾ����
Public Declare Function KSJ_AEShowRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bShow As Boolean) As Long
Public Declare Function KSJ_AEGetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnX As Long, ByRef pnY As Long, ByRef pnW As Long, ByRef pnH As Long) As Long

'�����Զ��ع����������Ļص����������Զ��ع����ʱ��KSJ���������Զ�����AECallback�û�ָ���Ļص�����
Public Declare Function KSJ_AESetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfAECallback As Long, ByVal lpContext As Long) As Long

'��ʼ����ֹ�Զ��ع����
Public Declare Function KSJ_AEStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal nMaxCount As Long, ByVal nTarget As Long) As Long

'�����Զ���ƽ������������������Ԥ��ͼ������Ͻ�����λ��
Public Declare Function KSJ_AWBSetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'�����Զ���ƽ�������������������Ԥ��ͼ������Ͻ�����λ��,�Ƿ���ʾ����
Public Declare Function KSJ_AWBShowRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bShow As Boolean) As Long
Public Declare Function KSJ_AWBGetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnX As Long, ByRef pnY As Long, ByRef pnW As Long, ByRef pnH As Long) As Long

'�����Զ���ƽ�����������Ļص����������Զ��ع����ʱ��KSJ���������Զ�����AECallback�û�ָ���Ļص�����
Public Declare Function KSJ_AWBSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfAWBCallback As Long, ByVal lpContext As Long) As Long

'��ʼ����ֹ�Զ���ƽ�����
Public Declare Function KSJ_AWBStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal nMaxCount As Long, ByVal nTarget As Long) As Long

'���þ۽���������
Public Declare Function KSJ_AFSetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'���þ۽������ص�
Public Declare Function KSJ_AFSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal fpAFCallback As Long, ByVal lpContext As Long) As Long

'��ʼ����ֹ�۽�����
Public Declare Function KSJ_AFStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long

'Ӳ���Զ��ع�
Public Declare Function KSJ_AECSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long
Public Declare Function KSJ_AECGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bStart As Boolean) As Long

Public Declare Function KSJ_AECSetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal usMin As Long, ByVal usMax As Long) As Long
Public Declare Function KSJ_AECGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usMin As Long, ByRef usMax As Long) As Long

'�õ��Զ��ع���ڵĵ�ǰ�ع�ֵ
Public Declare Function KSJ_AECGetCur Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usCurGain As Long) As Long

'Ӳ���Զ�����
Public Declare Function KSJ_AGCSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long
Public Declare Function KSJ_AGCGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bStart As Boolean) As Long

Public Declare Function KSJ_AGCSetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal usMin As Long, ByVal usMax As Long) As Long
Public Declare Function KSJ_AGCGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usMin As Long, ByRef usMax As Long) As Long

'�õ��Զ�������ڵĵ�ǰ����ֵ
Public Declare Function KSJ_AGCGetCur Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usCurGain As Long) As Long


'�Զ��ع�ص�����
Public Sub pfAECallback(ByVal bSuccess As Boolean, ByVal nResult As Long, ByVal lpContext As Long)

End Sub

'�Զ��ع�ص�����
Public Sub pfAWBCallback(ByVal bSuccess As Boolean, ByVal nValueR As Long, ByVal nValueG As Long, ByVal nValueB As Long, ByVal lpContext As Long)

End Sub

'�۽������ص�����
Public Sub pfAFCallback(ByVal nValue As Long, ByVal lpContext As Long)

End Sub
