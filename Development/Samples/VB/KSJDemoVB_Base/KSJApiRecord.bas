Attribute VB_Name = "KSJApiRecord"
Option Explicit

'Start or Stop Record. Must Start Preview, Record FOV is equal to Preivew FOV
Public Declare Function KSJ_RecordStart Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal fRecordRate As Single, ByVal pFileName As String) As Long

'Start or Stop Record if Show Compossor Selection Dialog. Must Start Preview, Record FOV is equal to Preivew FOV
Public Declare Function KSJ_RecordStartEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal fRecordRate As Single, ByVal pFileName As String, ByVal bShowCompossorSelection As Boolean) As Long

'Start or Stop Record Use KSJ_RecordAddOneFrame to Add Frame Data
Public Declare Function KSJ_RecordStartExEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bStart As Boolean, ByVal fRecordRate As Single, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long, ByVal pFileName As String, ByVal bShowCompossorSelection As Boolean) As Long

'Add one Frame after call KSJ_RecordStartExEx
Public Declare Function KSJ_RecordAddOneFrame Lib "KSJAPI.dll" (ByVal nChannel As Long, pFrameData As Any, ByVal fRecordRate As Single, ByVal nFrameNum As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal nBitCount As Long) As Long

'Get Record Status
Public Declare Function KSJ_RecordStatusGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bStart As Boolean) As Long
