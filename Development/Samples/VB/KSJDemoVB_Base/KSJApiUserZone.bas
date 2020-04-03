Attribute VB_Name = "KSJApiUserZone"
Option Explicit

Enum KSJ_EEPROM_TYPE
        KSJ_24LC64
        KSJ_24LC1024
        KSJ_24LC128
End Enum

Public Declare Function KSJ_EEPROMTypeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pType As KSJ_EEPROM_TYPE) As Long

Public Declare Function KSJ_WrEEPROM Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAdress As Integer, ByVal btValue As Byte) As Long
Public Declare Function KSJ_RdEEPROM Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAdress As Integer, ByRef pbtValue As Byte) As Long

Public Declare Function KSJ_WrEEPROMEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAdress As Long, ByVal btValue As Byte) As Long
Public Declare Function KSJ_RdEEPROMEx Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal uRomAdress As Long, ByRef pbtValue As Byte) As Long

