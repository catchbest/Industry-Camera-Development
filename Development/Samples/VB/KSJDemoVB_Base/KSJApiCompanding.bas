Attribute VB_Name = "KSJApiCompanding"
Option Explicit

'KtbFile Must Created by KSJShow. Download 16 to 8 Look Up Data to Camera, it will lost when power off
Public Declare Function KSJ_LutFileDownload Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pszKtbFile As String) As Long

'Download 16 to 8 Look Up Data to Camera, it will lost when power off
Public Declare Function KSJ_LutDataDownload Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByVal nBytes As Long) As Long

'Enable LUT
Public Declare Function KSJ_LutSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean) As Long

'Get If LUT Enable
Public Declare Function KSJ_LutGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bEnable As Boolean) As Long


'KtbFile Must Created by KSJShow. Download 16 to 16 Gamma Look Up Data to Camera, it will lost when power off
Public Declare Function KSJ_GammaLutFileDownload Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pszKtbFile As String) As Long

'Download Gamma Look Up Data to Camera, it will lost when power off
Public Declare Function KSJ_GammaLutDataDownload Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByVal nBytes As Long) As Long

'Enable Gamma LUT
Public Declare Function KSJ_GammaLutSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean) As Long

'Get If Gamma LUT Enable
Public Declare Function KSJ_GammaLutGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bEnable As Boolean) As Long

enum KSJ_SENSITIVITYMODE
	KSJ_LOW 
	KSJ_MID 
	KSJ_HIGH 
	KSJ_HIGHER 
	KSJ_HIGHEST
End Enum

'Related API KSJ_GetADCResolution
Public Declare Function KSJ_SensitivitySetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal SensitivityMode As KSJ_SENSITIVITYMODE) As Long
Public Declare Function KSJ_SensitivityGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef SensitivityMode As KSJ_SENSITIVITYMODE) As Long