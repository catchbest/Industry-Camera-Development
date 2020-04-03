Attribute VB_Name = "KSJApiMatrix"
Option Explicit

Enum KSJ_WB_MODE
        KSJ_WB_DISABLE
        KSJ_SWB_PRESETTINGS
        KSJ_SWB_AUTO_ONCE
        KSJ_SWB_AUTO_CONITNUOUS
        KSJ_SWB_MANUAL
        KSJ_HWB_PRESETTINGS
        KSJ_HWB_AUTO_ONCE
        KSJ_HWB_AUTO_CONITNUOUS
        KSJ_HWB_MANUAL
End Enum

'Set White Balance Matrix Mode
Public Declare Function KSJ_WhiteBalanceSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal WbMode As KSJ_WB_MODE) As Long
'Get White Balance Matrix Mode
Public Declare Function KSJ_WhiteBalanceGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pWbMode As KSJ_WB_MODE) As Long

'Set nPhi when KSJ_SWB_AUTO_ONCE or KSJ_SWB_AUTO_CONITNUOUS
Public Declare Function KSJ_WhiteBalanceAutoSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nPhi As Long) As Long
Public Declare Function KSJ_WhiteBalanceAutoGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnPhi As Long) As Long

'Set when KSJ_SWB_MANUAL or KSJ_HWB_MANUAL
Public Declare Function KSJ_WhiteBalanceMatrixSet Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long
Public Declare Function KSJ_WhiteBalanceMatrixGet Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long

'Call Callback Function When KSJ_AWB_AUTO_ONCE or KSJ_AWB_AUTO_CONITNUOUS Done. Finall Matrix will Return.
Public Declare Function KSJ_WhiteBalanceAutoSetCallBack Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfCallBack As Long, ByVal lpContext As Long) As Long

'Call Callback Function When KSJ_AWB_AUTO_ONCE or KSJ_AWB_AUTO_CONITNUOUS Done. Finall Matrix will Retur
Public Declare Function KSJ_WhiteBalanceAutoSetCallBackEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pfCallBackEx As Long, ByVal lpContext As Long) As Long

enum KSJ_COLOR_TEMPRATURE 
	KSJ_CT_5000K
	KSJ_CT_6500K
	KSJ_CT_2800K
End Enum

'Set Preseting White Balance Matrix according to Color Temprature when in KSJ_SWB_PRESETTINGS or KSJ_HWB_PRESETTINGS
Public Declare Function KSJ_WhiteBalancePresettingSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal WbPresetting As KSJ_COLOR_TEMPRATURE) As Long
Public Declare Function KSJ_WhiteBalancePresettingGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pWbPresetting As KSJ_COLOR_TEMPRATURE) As Long

Enum KSJ_CCM_MODE
        KSJ_CCM_DISABLE
        KSJ_SCCM_PRESETTINGS
        KSJ_SCCM_MANUAL
        KSJ_HCCM_PRESETTINGS
        KSJ_HCCM_MANUAL
End Enum

Public Declare Function KSJ_ColorCorrectionSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal CcmMode As KSJ_CCM_MODE) As Long
Public Declare Function KSJ_ColorCorrectionGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pCcmMode As KSJ_CCM_MODE) As Long

'Set Color Correction Matrix when in KSJ_SCCM_MANUAL or KSJ_HCCM_MANUAL
Public Declare Function KSJ_ColorCorrectionMatrixSet Lib "KSJAPI.dll" (ByVal nChannel As Long, Matrix() As Single) As Long
Public Declare Function KSJ_ColorCorrectionMatrixGet Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long

Public Declare Function KSJ_ColorCorrectionPresettingSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal CcmPresetting As KSJ_COLOR_TEMPRATURE) As Long
Public Declare Function KSJ_ColorCorrectionPresettingGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pCcmPresetting As KSJ_COLOR_TEMPRATURE) As Long



Public Sub KSJ_WB_CALLBACK(fMatrix() As Single, ByVal lpContext As Long)

End Sub

Public Sub KSJ_WB_CALLBACK_EX(ByVal fMatrixR As Single, ByVal fMatrixG As Single, ByVal fMatrixB As Single, ByVal lpContext As Long)

End Sub
