Attribute VB_Name = "KSJApiIo"
Option Explicit

enum KSJ_SNAPBUTTONSTATUS 
	KSJ_UP
	KSJ_DOWN 
End Enum

'When KSJ_SUPPORT_GPIO_NORMAL is True, KSJ_SUPPORT_SNAP_BUTTON will Enable after Set External Trigger Pin as Normal Input Pin
Public Declare Function KSJ_SnapButtonStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pSnapButtonStatus As KSJ_SNAPBUTTONSTATUS) As Long

'设置GPIO引脚的输入输出状态，btDirection位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出，=0表示此GPIO输入)
Public Declare Function KSJ_GpioSetDirection Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btDirection As Byte) As Long
'获取GPIO引脚的输入输出状态，pbtDirection位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出，=0表示此GPIO输入)
Public Declare Function KSJ_GpioGetDirection Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtDirection As Byte) As Long

'控制GPIO引脚输出，只有btDirection相应位设置为1的引脚才能通过此函数控制引脚输出。btGpioStatus位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出TTL高电平，=0表示此GPIO输出TTL低电平)
Public Declare Function KSJ_GpioSetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btGpioStatus As Byte) As Long
'读取GPIO引脚状态，*pbtGpioStatus位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3(=1表示此GPIO输出TTL高电平，=0表示此GPIO输出TTL低电平)
Public Declare Function KSJ_GpioGetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtGpioStatus As Byte) As Long

'About Flash. nMode not valid
Public Declare Function KSJ_FlashControlSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal bEnable As boolean, ByVal bInvert As boolean, ByVal nMode As Long) As Long
Public Declare Function KSJ_FlashControlGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef bEnable As boolean, ByRef bInvert As boolean, ByRef nMode As Long) As Long

enum KSJ_FLASHMODE
	KSJ_FM_TROW
	KSJ_FM_SIMULTANEOUSEXPOSURE
	KSJ_FM_SHUTTERWIDTH
End Enum

Public Declare Function KSJ_FlashSetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal FlashMode As KSJ_FLASHMODE) As Long
Public Declare Function KSJ_FlashGetMode Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pFlashMode As KSJ_FLASHMODE) As Long

enum KSJ_GPIOIN_MODE
	KSJ_GPIOIN_EXTERNALTRIGGER
	KSJ_GPIOIN_NORMAL
End Enum
'外触发输入引脚默认为外触发输入，也可以设置为普通IO输入，通过读取函数进行读取
Public Declare Function KSJ_GpioInModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal GpioInMode As KSJ_GPIOIN_MODE) As Long
Public Declare Function KSJ_GpioInModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pGpioInMode As KSJ_GPIOIN_MODE) As Long

'当外触发输入引脚作为普通IO时，可以通过此函数进行读取，BIT0为该引脚电平状态。1为高电平，0为低电平
'注意：只有在设置为KSJ_GPIOIN_NORMAL模式下才可以读取
Public Declare Function KSJ_GpioInStatusGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtValue As Byte) As Long

enum KSJ_GPIOOUT_MODE
	KSJ_GPIOOUT_FLASH
	KSJ_GPIOOUT_NORMAL
End Enum

Public Declare Function KSJ_GpioOutModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal GpioOutMode As KSJ_GPIOOUT_MODE) As Long
Public Declare Function KSJ_GpioOutModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pGpioOutMode As KSJ_GPIOOUT_MODE) As Long
'注意：只有在KSJ_NORMAL_OUT模式下，才可以设置
Public Declare Function KSJ_GpioOutStatusSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btValue As Byte) As Long
'设置滤波时间，单位为Us，如果设置为0，则硬件将以200ns进行滤波
Public Declare Function KSJ_GpioFilterSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wFilterTimeUs As Long) As Long
Public Declare Function KSJ_GpioFilterGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwFilterTimeUs As Long) As Long
