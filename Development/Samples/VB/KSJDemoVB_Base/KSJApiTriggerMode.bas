Attribute VB_Name = "KSJApiTriggerMode"
Option Explicit

Enum KSJ_TRIGGERMODE
        KSJ_TRIGGER_INTERNAL
        KSJ_TRIGGER_EXTERNAL
        KSJ_TRIGGER_SOFTWARE
        KSJ_TRIGGER_FIXFRAMERATE
End Enum

'Set Trigger Mode
Public Declare Function KSJ_TriggerModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal TriggerMode As KSJ_TRIGGERMODE) As Long
Public Declare Function KSJ_TriggerModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pTriggerMode As KSJ_TRIGGERMODE) As Long

Enum KSJ_TRIGGERSTATUS
        KSJ_NO
        KSJ_HAVE
End Enum

'Get Frame Buffer Status. Has One or more Frame or None. Maybe return RET_NOTSUPPORT
'When Fpga Version is not 0.0, This Function should support
Public Declare Function KSJ_TriggerStatusGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pTriggerStatus As KSJ_TRIGGERSTATUS) As Long

'Empty Frame Buffer. Not Support When In KSJ_TRIGGER_SOFTWARE Mode
Public Declare Function KSJ_EmptyFrameBuffer Lib "KSJAPI.dll" (ByVal nChannel As Long) As Long

'Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRawData. Not Support When In KSJ_TRIGGER_SOFTWARE Mode
Public Declare Function KSJ_CaptureRawDataAfterEmptyFrameBuffer Lib "KSJAPI.dll" (ByVal nChannel As Long, pRawData As Any) As Long

'Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRgbData. Not Support When In KSJ_TRIGGER_SOFTWARE Mode
Public Declare Function KSJ_CaptureRgbDataAfterEmptyFrameBuffer Lib "KSJAPI.dll" (ByVal nChannel As Long, pRawData As Any) As Long

'Same to call KSJ_EmptyFrameBuffer before KSJ_CaptureRgbDataEx. Not Support When In KSJ_TRIGGER_SOFTWARE Mode
Public Declare Function KSJ_CaptureRgbDataExAfterEmptyFrameBuffer Lib "KSJAPI.dll" (ByVal nChannel As Long, pRawData As Any, ByRef pnWidth As Long, ByRef pnHeight As Long, ByRef pnBitCount As Long) As Long

'Fixed Frame Rate when in KSJ_TRIGGER_FIXFRAMERATE mode. Maybe Return RET_NOTSUPPORT
Public Declare Function KSJ_SetFixedFrameRateEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal fFrameRate As Single) As Long
Public Declare Function KSJ_GetFixedFrameRateEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pfFrameRate As Single) As Long

Enum KSJ_TRIGGERMETHOD
        KSJ_TRIGGER_FALLINGEDGE
        KSJ_TRIGGER_RISINGEDGE
        KSJ_TRIGGER_HIGHLEVEL
        KSJ_TRIGGER_LOWLEVEL
End Enum

'Set Trigger Method when in KSJ_TRIGGER_EXTERNAL mode
Public Declare Function KSJ_TriggerMethodSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal TriggerMethod As KSJ_TRIGGERMETHOD) As Long
Public Declare Function KSJ_TriggerMethodGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pTriggerMethod As KSJ_TRIGGERMETHOD) As Long

'Set Trigger Delay when in KSJ_TRIGGER_EXTERNAL. May be Return RET_NOTSUPPORT
Public Declare Function KSJ_TriggerDelayGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wMin As Long, ByRef wMax As Long) As Long
Public Declare Function KSJ_TriggerDelaySet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wDelay As Long) As Long
Public Declare Function KSJ_TriggerDelayGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwDelay As Long) As Long

'Set Read action timeout (ms). Influence capture and preview
Public Declare Function KSJ_CaptureSetTimeOut Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal dwTimeOut As Long) As Long
'Get Read action image timeout (ms)
Public Declare Function KSJ_CaptureGetTimeOut Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pdwTimeOut As Long) As Long

'Set If recover device when Read Fail. It will Influence capture and preview
Public Declare Function KSJ_CaptureSetRecover Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bRecover As Boolean) As Long
'Get If recover device when Read Fail
Public Declare Function KSJ_CaptureGetRecover Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbRecover As Boolean) As Long

'Set timeout and recover at the same time
Public Declare Function KSJ_CaptureSetTimeOutEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal dwTimeOut As Long, ByVal bRecover As Boolean) As Long
'Get timeout and recover at the same time
Public Declare Function KSJ_CaptureGetTimeOutEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pdwTimeOut As Long, ByRef pbRecover As Boolean) As Long

