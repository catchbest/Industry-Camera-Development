Attribute VB_Name = "KSJApiMultiProcess"
Option Explicit

'ע�⣺��������˵��ʱ�����е�һ������ΪnChannle�ĺ��������豸����û�д���������£������Զ������豸���󲢴��豸
'�ر�ָ���������豸��������ر�ָ���������ô�ڶ�������ǲ��ܲ�����̨�����
'��ȻKSJ_DeviceClose�����ĵ�һ������ΪnIndex�����ڲ�������ʽ�����豸���󲢿����豸
Public Declare Function KSJ_DeviceClose Lib "KSJAPI.dll" (ByVal nChannel As Long) As Long

enum KSJ_DEVICESTATUS
	KSJ_DS_CLOSE
	KSJ_DS_OPEN
End Enum

'KSJ_DeviceGetStatus������������Զ������豸����ֻ�ǻ�ȡ��ǰ�豸�ڵ�ǰ���̵Ŀ���״̬
Public Declare Function KSJ_DeviceGetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pDs As KSJ_DEVICESTATUS) As Long