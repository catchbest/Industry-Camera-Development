#ifndef __KSJ_API_IO_H__
#define __KSJ_API_IO_H__

// #pragma message("Include KSJApiIo.h") 

#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"{
#endif

	enum KSJ_SNAPBUTTONSTATUS //Snap��������״̬
	{ 
		KSJ_UP, 	//�������ڱպ�״̬
		KSJ_DOWN 	//�������ڿ���״̬
	};

	//-----------------------------------------------------------------------------
	// ������KSJ_SnapButtonStatus
	// ���ܣ���ȡSnap��������״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pSnapButtonStatus�����������Snap��������״̬, KSJ_SNAPBUTTONSTATUS����
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus( int nChannel, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus );

	//-----------------------------------------------------------------------------
	// ������KSJ_GpioSetDirection
	// ���ܣ�����IOΪ��������
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       btDirection�����룬��λѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3�����֧�ֵ�BIT7
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetDirection( int nChannel, unsigned char btDirection );
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioGetDirection
	// ���ܣ�����IOΪ��������
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbtDirection�����������IO�����뻹���������λѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3�����֧�ֵ�BIT7
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetDirection( int nChannel, unsigned char *pbtDirection );

	//-----------------------------------------------------------------------------
	// ������KSJ_GpioSetStatus
	// ���ܣ�������������������״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       btGpioStatus�����룬����IO�������״̬����λѰַ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetStatus   ( int nChannel, unsigned char btGpioStatus );
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioGetStatus
	// ���ܣ���ȡ����IO����״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbtGpioStatus���������ȡIO��������״̬��ֻ��ͨ��KSJ_GpioSetDirection ��������btDirection��Ӧλ����Ϊ0�����Ų���ͨ���˺�����ȡ��������״̬
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetStatus   ( int nChannel, unsigned char *pbtGpioStatus );

	//-----------------------------------------------------------------------------
	// ������KSJ_FlashControlSet
	// ���ܣ����������
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       bEnable�����룬�Ƿ�ʹ������ƣ�true������false�ر�
	//       bInvert�����룬�Ƿ�ת������ź�
	//       nMode�����룬�����ģʽ���ݲ�֧��
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlSet(int nChannel, bool bEnable, bool bInvert, int nMode);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_FlashControlGet
	// ���ܣ���ȡ�����״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbEnable������������Ƿ�ʹ������ƣ�true������false�ر�
	//       pbInvert������������Ƿ�������źŷ�ת
	//       pnMode����������������ģʽ���ݲ�֧��
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlGet(int nChannel, bool *pbEnable, bool *pbInvert, int *pnMode);

	//-----------------------------------------------------------------------------
	// ������KSJ_FlashEnableSet
	// ���ܣ����������ʹ��
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       bEnable�����룬�Ƿ�ʹ������ƣ�true������false�ر�
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableSet(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_FlashEnableGet
	// ���ܣ���ȡ�����ʹ��
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbEnable������������Ƿ�ʹ������ƣ�true������false�ر�
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableGet(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
	// ������KSJ_FlashInvertSet
	// ���ܣ�����������źŷ�ת
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       bInvert�����룬�Ƿ�ת������ź�
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertSet(int nChannel, bool bInvert);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_FlashInvertGet
	// ���ܣ���ȡ������źŷ�ת
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbInvert������������Ƿ�������źŷ�ת
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertGet(int nChannel, bool *pbInvert);

	enum KSJ_FLASHMODE//�����ģʽ���ݲ�֧�֣�
	{
		KSJ_FM_TROW,
		KSJ_FM_SIMULTANEOUSEXPOSURE,
		KSJ_FM_SHUTTERWIDTH
	};
	KSJ_API  int __stdcall KSJ_FlashSetMode(int nChannel, KSJ_FLASHMODE FlashMode);//���������ģʽ���ݲ�֧�֣�
	KSJ_API  int __stdcall KSJ_FlashGetMode(int nChannel, KSJ_FLASHMODE *pFlashMode);//��ȡ�����ģʽ���ݲ�֧�֣�

	// ���º���ֻ������YYO�ͺ����(֡�������)
	// ͨ����ѯ���ܵ������º���
	// ע�⣺���ⴥ��ģʽ�£�����������ΪKSJ_GPIOIN_NORMAL�������л������ⴥ��ģʽʱ���á�
	// ���û���������Ϊ�ⴥ��ģʽʱ���Զ�����ΪKSJ_GPIOIN_EXTERNALTRIGGER��
	// KSJ_QueryFunction (KSJ_SUPPORT_GPIO_NORMAL)
	// When call KSJ_GpioSetDirection(, bit0 = 0 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_NORMAL)
	// When call KSJ_GpioSetDirection(, bit0 = 1 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_EXTERNALTRIGGER)
	enum KSJ_GPIOIN_MODE //�ⴥ���������Ź���ģʽ
	{ 
		KSJ_GPIOIN_EXTERNALTRIGGER, //��Ϊ�ⴥ�����ţ�Ĭ�ϣ�
		KSJ_GPIOIN_NORMAL			//��Ϊ��ͨ�������ţ�ͬʱҲ������ΪSnap��������ʹ�ã�
	};
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioInModeSet
	// ���ܣ������ⴥ���������ŵĹ���ģʽ
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       GpioInMode�����룬�����ⴥ�����ŵĹ���ģʽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeSet(int nChannel, KSJ_GPIOIN_MODE GpioInMode);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioInModeGet
	// ���ܣ���ȡ�ⴥ���������ŵĹ���ģʽ
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pGpioInMode��������ⴥ�����ŵĵ�ǰ����ģʽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeGet(int nChannel, KSJ_GPIOIN_MODE *pGpioInMode);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioInStatusGet
	// ���ܣ����ⴥ������������ΪKSJ_GPIOIN_NORMALʱ������ͨ���˺������ж�ȡ����״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbtValue��������ⴥ�����ŵĵ�ǰ����ģʽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInStatusGet(int nChannel, unsigned char *pbtValue);

	// ͨ����ѯKSJ_SUPPORT_GPIO_NORMAL���ܵ������º���
	// When call KSJ_GpioSetDirection(, bit1 = 1 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_FLASH)
	// When call KSJ_GpioSetDirection(, bit1 = 0 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_NORMAL)
	// 
	enum KSJ_GPIOOUT_MODE	//�����������Ź���ģʽ
	{ 
		KSJ_GPIOOUT_FLASH, 	//��Ϊ�����������ţ�Ĭ�ϣ�
		KSJ_GPIOOUT_NORMAL 	//��Ϊ��ͨ������ţ�����ͨ��KSJ_GpioOutStatusSet��KSJ_GpioSetStatus��������
	};
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioOutModeSet
	// ���ܣ����������������ŵĹ���ģʽ
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       GpioOutMode�����룬����������������ŵĹ���ģʽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeSet(int nChannel, KSJ_GPIOOUT_MODE GpioOutMode);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioOutModeGet
	// ���ܣ���ȡ��ǰIO�����ģʽ
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pGpioOutMode���������ȡ������������ŵĹ���ģʽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeGet(int nChannel, KSJ_GPIOOUT_MODE *pGpioOutMode);

	// ע�⣺ֻ����KSJ_NORMAL_OUTģʽ�£��ſ������á�
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioOutStatusSet
	// ���ܣ��������������������Ϊ��ͨIO���ʱ��״̬
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       btValue�����룬�������������������Ϊ��ͨIO���ʱ��״̬����λѰַ��bit0��ʾ���õ����״̬��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutStatusSet(int nChannel, unsigned char btValue);

	//-----------------------------------------------------------------------------
	// ������KSJ_GpioFilterSet
	// ���ܣ������ⴥ��������˲�ʱ����΢�룩
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       wFilterTimeUs�����룬�����˲�ʱ������Ϊ0ʱ��Ĭ��200ns�˲�
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterSet(int nChannel, unsigned short wFilterTimeUs);
	
	//-----------------------------------------------------------------------------
	// ������KSJ_GpioFilterGet
	// ���ܣ���ȡ�ⴥ��������˲�ʱ��
	// ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pwFilterTimeUs������������˲�ʱ������Ϊ0ʱ��Ĭ��200ns�˲�
	// ���أ��ο�����״̬�루KSJCode.H��
	// ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterGet(int nChannel, unsigned short *pwFilterTimeUs);



#ifdef __cplusplus
}
#endif


#endif