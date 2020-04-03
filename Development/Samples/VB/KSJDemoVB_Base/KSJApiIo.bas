Attribute VB_Name = "KSJApiIo"
Option Explicit

enum KSJ_SNAPBUTTONSTATUS 
	KSJ_UP
	KSJ_DOWN 
End Enum

'When KSJ_SUPPORT_GPIO_NORMAL is True, KSJ_SUPPORT_SNAP_BUTTON will Enable after Set External Trigger Pin as Normal Input Pin
Public Declare Function KSJ_SnapButtonStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pSnapButtonStatus As KSJ_SNAPBUTTONSTATUS) As Long

'����GPIO���ŵ��������״̬��btDirectionλѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3(=1��ʾ��GPIO�����=0��ʾ��GPIO����)
Public Declare Function KSJ_GpioSetDirection Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btDirection As Byte) As Long
'��ȡGPIO���ŵ��������״̬��pbtDirectionλѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3(=1��ʾ��GPIO�����=0��ʾ��GPIO����)
Public Declare Function KSJ_GpioGetDirection Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtDirection As Byte) As Long

'����GPIO���������ֻ��btDirection��Ӧλ����Ϊ1�����Ų���ͨ���˺����������������btGpioStatusλѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3(=1��ʾ��GPIO���TTL�ߵ�ƽ��=0��ʾ��GPIO���TTL�͵�ƽ)
Public Declare Function KSJ_GpioSetStatus Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btGpioStatus As Byte) As Long
'��ȡGPIO����״̬��*pbtGpioStatusλѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3(=1��ʾ��GPIO���TTL�ߵ�ƽ��=0��ʾ��GPIO���TTL�͵�ƽ)
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
'�ⴥ����������Ĭ��Ϊ�ⴥ�����룬Ҳ��������Ϊ��ͨIO���룬ͨ����ȡ�������ж�ȡ
Public Declare Function KSJ_GpioInModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal GpioInMode As KSJ_GPIOIN_MODE) As Long
Public Declare Function KSJ_GpioInModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pGpioInMode As KSJ_GPIOIN_MODE) As Long

'���ⴥ������������Ϊ��ͨIOʱ������ͨ���˺������ж�ȡ��BIT0Ϊ�����ŵ�ƽ״̬��1Ϊ�ߵ�ƽ��0Ϊ�͵�ƽ
'ע�⣺ֻ��������ΪKSJ_GPIOIN_NORMALģʽ�²ſ��Զ�ȡ
Public Declare Function KSJ_GpioInStatusGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pbtValue As Byte) As Long

enum KSJ_GPIOOUT_MODE
	KSJ_GPIOOUT_FLASH
	KSJ_GPIOOUT_NORMAL
End Enum

Public Declare Function KSJ_GpioOutModeSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal GpioOutMode As KSJ_GPIOOUT_MODE) As Long
Public Declare Function KSJ_GpioOutModeGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pGpioOutMode As KSJ_GPIOOUT_MODE) As Long
'ע�⣺ֻ����KSJ_NORMAL_OUTģʽ�£��ſ�������
Public Declare Function KSJ_GpioOutStatusSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal btValue As Byte) As Long
'�����˲�ʱ�䣬��λΪUs���������Ϊ0����Ӳ������200ns�����˲�
Public Declare Function KSJ_GpioFilterSet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByVal wFilterTimeUs As Long) As Long
Public Declare Function KSJ_GpioFilterGet Lib "KSJAPI.dll" (ByVal nChannel As Long, ByRef pwFilterTimeUs As Long) As Long
