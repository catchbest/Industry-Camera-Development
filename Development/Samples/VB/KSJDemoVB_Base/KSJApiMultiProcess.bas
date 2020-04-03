Attribute VB_Name = "KSJApiMultiProcess"
Option Explicit

'注意：当无特殊说明时，所有第一个参数为nChannle的函数，在设备对象没有创建的情况下，都会自动创建设备对象并打开设备
'关闭指定索引的设备，如果不关闭指定相机，那么在多进程下是不能操作这台相机的
'虽然KSJ_DeviceClose函数的第一个参数为nIndex，但内部不会隐式创建设备对象并开启设备
Public Declare Function KSJ_DeviceClose Lib "KSJAPI.dll" (ByVal nChannel As Long) As Long

enum KSJ_DEVICESTATUS
	KSJ_DS_CLOSE
	KSJ_DS_OPEN
End Enum

'KSJ_DeviceGetStatus这个函数不会自动创建设备对象，只是获取当前设备在当前进程的开启状态
Public Declare Function KSJ_DeviceGetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pDs As KSJ_DEVICESTATUS) As Long