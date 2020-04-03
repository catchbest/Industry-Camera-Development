Attribute VB_Name = "KSJApiImage"
Option Explicit

'坏点校正低阈值和高阈值设置（硬件不支持此设置，由软件处理时有效）
Public Declare Function KSJ_BadPixelCorrectionSetThreshold Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btLow As Byte, ByVal btHigh As Byte) As Long
Public Declare Function KSJ_BadPixelCorrectionGetThreshold Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef btLow As Byte, ByRef btHigh As Byte) As Long

Enum KSJ_THRESHOLD
        KSJ_THRESHOLD_LOW
        KSJ_THRESHOLD_HIGH
End Enum

'坏点校正设置及阈值设置，低阈值会过滤更多的坏点
Public Declare Function KSJ_BadPixelCorrectionSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As KSJ_THRESHOLD) As Long
Public Declare Function KSJ_BadPixelCorrectionGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbEnable As KSJ_THRESHOLD) As Long

'Same to Parameter KSJ_CONTRAST（-128~128）， Software Preccess, may influence capture efficiency or preivew frame rate
Public Declare Function KSJ_ProcessContrastGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnMinContrast As Long, ByRef pnMaxContrast As Long) As Long
Public Declare Function KSJ_ProcessContrastSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nContrast As Long) As Long
Public Declare Function KSJ_ProcessContrastGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnContrast As Long) As Long

'Same to Parameter KSJ_BRIGHTNESS（-128~128）, Software Preccess, may influence capture efficiency or preivew frame rate
Public Declare Function KSJ_ProcessBrightnessGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnMinBrightness As Long, ByRef pnMaxBrightness As Long) As Long
Public Declare Function KSJ_ProcessBrightnessSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nBrightness As Long) As Long
Public Declare Function KSJ_ProcessBrightnessGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnBrightness As Long) As Long

'Same to Parameter KSJ_SATURATION（-128~128）, Software Preccess, may influence capture efficiency or preivew frame rate
Public Declare Function KSJ_ProcessSaturationGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnMinSaturation As Long, ByRef pnMaxSaturation As Long) As Long
Public Declare Function KSJ_ProcessSaturationSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal nSaturation As Long) As Long
Public Declare Function KSJ_ProcessSaturationGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnStaturation As Long) As Long

'设置Gamma值，范围 -9 - +9
Public Declare Function KSJ_GammaGetRange Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pnMinGamma As Long, ByRef pnMaxGamm As Long) As Long
Public Declare Function KSJ_GammaGetValue Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal pnValue As Long) As Long
Public Declare Function KSJ_GammaSetValue Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef nValue As Long) As Long

Enum KSJHueRange
        KSJ_ALL_HUES
        KSJ_RED_HUES
        KSJ_YELLOW_HUES
        KSJ_GREEN_HUES
        KSJ_CYAN_HUES
        KSJ_BLUE_HUES
        KSJ_MAGENTA_HUES
End Enum

'nHue: -180 ~ 180, nSaturation: -100 ~ 100, nLightness: -100 ~ 100
Public Declare Function KSJ_HueSaturationSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal HueRange As KSJHueRange, ByVal nHue As Long, ByVal nSaturation As Long, ByVal nLightness As Long) As Long
Public Declare Function KSJ_HueSaturationGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal HueRange As KSJHueRange, ByRef nHue As Long, ByRef nSaturation As Long, ByRef nLightness As Long) As Long
Public Declare Function KSJ_HueSaturationSetEnable Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As Boolean) As Long
