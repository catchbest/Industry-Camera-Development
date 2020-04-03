Attribute VB_Name = "KSJApiProgram"
Option Explicit

'Program and Modify Serials
Public Declare Function KSJ_SetSerials Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btSerials As Byte) As Long
Public Declare Function KSJ_GetSerials Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtSerials As Byte) As Long

Public Declare Function KSJ_WorkingModeProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wValue As Long) As Long
Public Declare Function KSJ_WorkingModeReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pValue As Long) As Long

Public Declare Function KSJ_WorkingModeExProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wValue As Long) As Long
Public Declare Function KSJ_WorkingModeExReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pValue As Long) As Long

Public Declare Function KSJ_ColorModeProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wValue As Long) As Long
Public Declare Function KSJ_ColorModeReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pValue As Long) As Long

Public Declare Function KSJ_SerialsDescProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, btDesc() As byte) As Long
Public Declare Function KSJ_SerialsDescReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, btDesc() As byte) As Long

Public Declare Function KSJ_LutInfoProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wValue As Long) As Long
Public Declare Function KSJ_LutInfoReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pValue As Long) As Long

Public Declare Function KSJ_GammaLutInfoProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wValue As Long) As Long
Public Declare Function KSJ_GammaLutInfoReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pValue As Long) As Long

Public Declare Function KSJ_HWBMatrixProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long
Public Declare Function KSJ_HWBMatrixReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long
Public Declare Function KSJ_HWBMatrixUpload Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long

Public Declare Function KSJ_HCCMMatrixProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long
Public Declare Function KSJ_HCCMMatrixReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long
Public Declare Function KSJ_HCCMMatrixUpload Lib "KSJAPI.dll" (ByVal nChannel As Long, fMatrix() As Single) As Long

Public Declare Function KSJ_LutFileProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pszFile As String) As Long
Public Declare Function KSJ_LutDataProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByVal nBytes As Long) As Long
Public Declare Function KSJ_LutDataReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByRef pnBytes As Long) As Long

Public Declare Function KSJ_GammaLutFileProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pszFile As String) As Long
Public Declare Function KSJ_GammaLutDataProgram Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByVal nWords As Long) As Long
Public Declare Function KSJ_GammaLutDataReadout Lib "KSJAPI.dll" (ByVal nChannel As Long, pData As Any, ByRef pnWords As Long) As Long