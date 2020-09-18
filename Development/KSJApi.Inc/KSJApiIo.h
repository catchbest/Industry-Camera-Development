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
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ����IOΪ��������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btDirection [in] ��λѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3�����֧�ֵ�BIT7
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetDirection( int nIndex, unsigned char btDirection );
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ����IOΪ��������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbtDirection [out] ����IO�����뻹��[out] ��λѰַ��BIT0��ӦGPIO0, BIT1��ӦGPIO1, BIT2��ӦGPIO2, BIT3��ӦGPIO3�����֧�ֵ�BIT7
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetDirection( int nIndex, unsigned char *pbtDirection );

	///-----------------------------------------------------------------------------
	///
	/// @brief     ������������������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btGpioStatus [in] ����IO�������״̬����λѰַ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetStatus( int nIndex, unsigned char btGpioStatus );
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ����IO����״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbtGpioStatus [out] ��ȡIO��������״̬��ֻ��ͨ��KSJ_GpioSetDirection ��������btDirection��Ӧλ����Ϊ0�����Ų���ͨ���˺�����ȡ��������״̬
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetStatus( int nIndex, unsigned char *pbtGpioStatus );

	///-----------------------------------------------------------------------------
	///
	/// @brief     ���������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] �Ƿ�ʹ������ƣ�true������false�ر�
	/// @param     bInvert [in] �Ƿ�ת������ź�
	/// @param     nMode [in] �����ģʽ���ݲ�֧��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlSet(int nIndex, bool bEnable, bool bInvert, int nMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�����״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] �����Ƿ�ʹ������ƣ�true������false�ر�
	/// @param     pbInvert [out] �����Ƿ�������źŷ�ת
	/// @param     pnMode [out] ���������ģʽ���ݲ�֧��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlGet(int nIndex, bool *pbEnable, bool *pbInvert, int *pnMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ���������ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] �Ƿ�ʹ������ƣ�true������false�ر�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableSet(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�����ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] �����Ƿ�ʹ������ƣ�true������false�ر�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableGet(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����������źŷ�ת
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bInvert [in] �Ƿ�ת������ź�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertSet(int nIndex, bool bInvert);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ������źŷ�ת
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbInvert [out] �����Ƿ�������źŷ�ת
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertGet(int nIndex, bool *pbInvert);

	/// ���º���ֻ������YYO�ͺ����(֡�������)
	/// ͨ����ѯ���ܵ������º���
	/// ע�⣺���ⴥ��ģʽ�£�����������ΪKSJ_GPIOIN_NORMAL�������л������ⴥ��ģʽʱ���á�
	/// ���û���������Ϊ�ⴥ��ģʽʱ���Զ�����ΪKSJ_GPIOIN_EXTERNALTRIGGER��
	/// KSJ_QueryFunction (KSJ_SUPPORT_GPIO_NORMAL)
	/// When call KSJ_GpioSetDirection(, bit0 = 0 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_NORMAL)
	/// When call KSJ_GpioSetDirection(, bit0 = 1 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_EXTERNALTRIGGER)
	enum KSJ_GPIOIN_MODE ///�ⴥ���������Ź���ģʽ
	{ 
		KSJ_GPIOIN_EXTERNALTRIGGER, ///��Ϊ�ⴥ�����ţ�Ĭ�ϣ�
		KSJ_GPIOIN_NORMAL			///��Ϊ��ͨ�������ţ�ͬʱҲ������ΪSnap��������ʹ�ã�
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     �����ⴥ���������ŵĹ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     GpioInMode [in] �����ⴥ�����ŵĹ���ģʽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeSet(int nIndex, KSJ_GPIOIN_MODE GpioInMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�ⴥ���������ŵĹ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pGpioInMode [out] �ⴥ�����ŵĵ�ǰ����ģʽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeGet(int nIndex, KSJ_GPIOIN_MODE *pGpioInMode);
	
	///-----------------------------------------------------------------------------
	/// @brief     ���ⴥ������������ΪKSJ_GPIOIN_NORMALʱ������ͨ���˺������ж�ȡ����״̬
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbtValue [out] �ⴥ�����ŵĵ�ǰ����ģʽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInStatusGet(int nIndex, unsigned char *pbtValue);

	/// ͨ����ѯKSJ_SUPPORT_GPIO_NORMAL���ܵ������º���
	/// When call KSJ_GpioSetDirection(, bit1 = 1 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_FLASH)
	/// When call KSJ_GpioSetDirection(, bit1 = 0 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_NORMAL)
	/// 
	enum KSJ_GPIOOUT_MODE	///�����������Ź���ģʽ
	{ 
		KSJ_GPIOOUT_FLASH, 	///��Ϊ�����������ţ�Ĭ�ϣ�
		KSJ_GPIOOUT_NORMAL 	///��Ϊ��ͨ������ţ�����ͨ��KSJ_GpioOutStatusSet��KSJ_GpioSetStatus��������
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ���������������ŵĹ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     GpioOutMode [in] ����������������ŵĹ���ģʽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeSet(int nIndex, KSJ_GPIOOUT_MODE GpioOutMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ǰIO�����ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pGpioOutMode [out] ��ȡ������������ŵĹ���ģʽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeGet(int nIndex, KSJ_GPIOOUT_MODE *pGpioOutMode);

	/// ע�⣺ֻ����KSJ_NORMAL_OUTģʽ�£��ſ������á�
	///-----------------------------------------------------------------------------
	///
	/// @brief     �������������������Ϊ��ͨIO���ʱ��״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btValue [in] �������������������Ϊ��ͨIO���ʱ��״̬����λѰַ��bit0��ʾ���õ����״̬��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutStatusSet(int nIndex, unsigned char btValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����ⴥ��������˲�ʱ����΢�룩
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wFilterTimeUs [in] �����˲�ʱ������Ϊ0ʱ��Ĭ��200ns�˲�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterSet(int nIndex, unsigned short wFilterTimeUs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�ⴥ��������˲�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwFilterTimeUs [out] �����˲�ʱ������Ϊ0ʱ��Ĭ��200ns�˲�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterGet(int nIndex, unsigned short *pwFilterTimeUs);



#ifdef __cplusplus
}
#endif


#endif