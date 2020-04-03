Attribute VB_Name = "KSJApiWaterMark"
Option Explicit

Enum KSJ_WATERMARKMODE
        KSJ_WMM_TIMESTAMP
        KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER
        KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER
End Enum

Public Declare Function KSJ_WaterMarkSetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal WaterMarkMode As KSJ_WATERMARKMODE) As Long
Public Declare Function KSJ_WaterMarkGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pWaterMarkMode As KSJ_WATERMARKMODE) As Long

Public Declare Function KSJ_WaterMarkSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean) As Long
Public Declare Function KSJ_WaterMarkGetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbEnable As Boolean) As Long

Public Declare Function KSJ_WaterMarkGetInfo Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwId As Long, ByRef pdwTimestampLowPart As Long, ByRef pdwTimestampHighPart As Long) As Long
