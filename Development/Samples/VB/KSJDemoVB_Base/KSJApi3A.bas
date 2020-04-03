Attribute VB_Name = "KSJApi3A"
Option Explicit


'设置自动曝光的区域，这个区域是相对预览图像的左上角像素位置
Public Declare Function KSJ_AESetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'设置自动曝光的区域，这个区域是相对预览图像的左上角像素位置,是否显示区域
Public Declare Function KSJ_AEShowRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bShow As Boolean) As Long
Public Declare Function KSJ_AEGetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnX As Long, ByRef pnY As Long, ByRef pnW As Long, ByRef pnH As Long) As Long

'定义自动曝光操作结束后的回调函数，当自动曝光结束时，KSJ开发包会自动调用AECallback用户指定的回调函数
Public Declare Function KSJ_AESetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfAECallback As Long, ByVal lpContext As Long) As Long

'开始或终止自动曝光调节
Public Declare Function KSJ_AEStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal nMaxCount As Long, ByVal nTarget As Long) As Long

'设置自动白平衡区域，这个区域是相对预览图像的左上角像素位置
Public Declare Function KSJ_AWBSetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'设置自动白平衡的区域，这个区域是相对预览图像的左上角像素位置,是否显示区域
Public Declare Function KSJ_AWBShowRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bShow As Boolean) As Long
Public Declare Function KSJ_AWBGetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnX As Long, ByRef pnY As Long, ByRef pnW As Long, ByRef pnH As Long) As Long

'定义自动白平衡操作结束后的回调函数，当自动曝光结束时，KSJ开发包会自动调用AECallback用户指定的回调函数
Public Declare Function KSJ_AWBSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfAWBCallback As Long, ByVal lpContext As Long) As Long

'开始或终止自动白平衡调节
Public Declare Function KSJ_AWBStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal nMaxCount As Long, ByVal nTarget As Long) As Long

'设置聚焦评估区域
Public Declare Function KSJ_AFSetRegion Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nX As Long, ByVal nY As Long, ByVal nW As Long, ByVal nH As Long) As Long

'设置聚焦评估回调
Public Declare Function KSJ_AFSetCallback Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal fpAFCallback As Long, ByVal lpContext As Long) As Long

'开始或终止聚焦评估
Public Declare Function KSJ_AFStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long

'硬件自动曝光
Public Declare Function KSJ_AECSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long
Public Declare Function KSJ_AECGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bStart As Boolean) As Long

Public Declare Function KSJ_AECSetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal usMin As Long, ByVal usMax As Long) As Long
Public Declare Function KSJ_AECGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usMin As Long, ByRef usMax As Long) As Long

'得到自动曝光调节的当前曝光值
Public Declare Function KSJ_AECGetCur Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usCurGain As Long) As Long

'硬件自动增益
Public Declare Function KSJ_AGCSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean) As Long
Public Declare Function KSJ_AGCGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bStart As Boolean) As Long

Public Declare Function KSJ_AGCSetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal usMin As Long, ByVal usMax As Long) As Long
Public Declare Function KSJ_AGCGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usMin As Long, ByRef usMax As Long) As Long

'得到自动增益调节的当前增益值
Public Declare Function KSJ_AGCGetCur Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef usCurGain As Long) As Long


'自动曝光回调函数
Public Sub pfAECallback(ByVal bSuccess As Boolean, ByVal nResult As Long, ByVal lpContext As Long)

End Sub

'自动曝光回调函数
Public Sub pfAWBCallback(ByVal bSuccess As Boolean, ByVal nValueR As Long, ByVal nValueG As Long, ByVal nValueB As Long, ByVal lpContext As Long)

End Sub

'聚焦评估回调函数
Public Sub pfAFCallback(ByVal nValue As Long, ByVal lpContext As Long)

End Sub
