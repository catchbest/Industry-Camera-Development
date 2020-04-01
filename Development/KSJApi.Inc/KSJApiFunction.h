#ifndef __KSJ_API_FUNCTION_H__
#define __KSJ_API_FUNCTION_H__

// #pragma message("Include KSJApiFunction.h") 


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


enum KSJ_FUNCTION 
{
	KSJ_PROPERTY_MONO_DEVICE,                // �Ƿ�Ϊ�ڰ������     1 - �ǣ�     0 - ����
	KSJ_PROPERTY_ADC_RESOLUTION,             // ���ADC��ת������λ����8��10��12����KSJ_GetADCResolution������ͬ
	KSJ_SUPPORT_MIRROR,                      // �Ƿ�֧��Ӳ��ˮƽ��ת
	KSJ_SUPPORT_FLIP,                        // �Ƿ�֧��Ӳ����ֱ��ת
	KSJ_SUPPORT_SKIP2,                       // �Ƿ�֧��SKIP2
	KSJ_SUPPORT_SKIP3,
	KSJ_SUPPORT_SKIP4,
	KSJ_SUPPORT_SKIP8,
	KSJ_SUPPORT_BINNING,
	KSJ_SUPPORT_AGC,
	KSJ_SUPPORT_AEC,

	KSJ_SUPPORT_TRIGGER_MODE_EXTERNAL,       // �Ƿ�֧���ⴥ��
	KSJ_SUPPORT_TRIGGER_MODE_SOFTWARE,       // �Ƿ�֧���������
	KSJ_SUPPORT_TRIGGER_MODE_FIXED_FRAMERATE,// �Ƿ�֧�ֹ̼�֡�ʴ���
	KSJ_SUPPORT_FIXED_FRAMERATE_SW,	         // �Ƿ�֧��ͨ���������sensor�̶�֡�ʡ�0 - ��֧�֣�1 - ֧��
	KSJ_SUPPORT_FIXED_FRAMERATE_HW,          // �Ƿ�֧��ͨ��Ӳ������FPGA�̶�����Ƶ��
	KSJ_SUPPORT_LUT_ENABLE,                  // �Ƿ�֧��Ӳ�����ұ�ʹ�ܣ� 0 - ��֧�֣� 1 - ֧��
	KSJ_SUPPORT_TRIGGER_METHOD_NEGEDGE,      // �Ƿ�֧���½��ش���
	KSJ_SUPPORT_TRIGGER_METHOD_POSEDGE,
	KSJ_SUPPORT_TRIGGER_METHOD_HIGH_LEVEL,
	KSJ_SUPPORT_TRIGGER_METHOD_LOW_LEVEL,
	KSJ_SUPPORT_EMPTY_FRAMEBUFFER,      // �Ƿ�֧�����֡�档0 - ��֧�֣� 1 - ֧��
	KSJ_SUPPORT_SENSITIVITY_MODE,       // �Ƿ�֧�ֽ�ȡ8λ��ȡ��ͬ��������
	KSJ_SUPPORT_16BITS,			        // �Ƿ�֧��˫�ֽڴ��䣬һ��������2���ֽڣ����ݶ�ȡ�ӱ���0 - ��֧�֣�1 - ֧��
	KSJ_SUPPORT_BAD_PIXEL_CORRECTION,   // �Ƿ�֧�ֻ���У��
	KSJ_SUPPORT_LUT_DOWNLOAD,           // �Ƿ�֧��LUT���ұ����ص�FPGA
	KSJ_SUPPORT_HWB_PRESETTINGS,        // Ӳ����ƽ���Ƿ�֧��Ԥ��ֵ
	KSJ_SUPPORT_HWB_PRESETTINGS_NUM,    // Ӳ����ƽ��Ԥ��ֵ�м���
	KSJ_SUPPORT_HWB_AUTO_ONCE,          // Ӳ���Ƿ�֧�ֵ��ΰ�ƽ�����
	KSJ_SUPPORT_HWB_AUTO_CONTINUOUS,    // Ӳ���Ƿ�֧��������ƽ�����
	KSJ_SUPPORT_HCCM_PRESETTINGS,       // Ӳ��CCM�Ƿ�֧��Ԥ��ֵ
	KSJ_SUPPORT_HCCM_PRESETTINGS_NUM,   // Ӳ��CCM�м���Ԥ��ֵ
	KSJ_SUPPORT_GAMMA_LUT_ENABLE,       // Ӳ���Ƿ�֧��GAMMA LUT���ұ�ʹ��
	KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD,     // �Ƿ�֧��Gamma LUT���ص�FPGA�����֧�ִ˹��ܣ��Ϳ���ʹ�ܲ���
	KSJ_SUPPORT_TRIGGER_DELAY,		    // �Ƿ�֧�ֶ��ⴥ���źŵ���ʱ�����á�0 - ��֧�֣�1 - ֧��
	KSJ_SUPPORT_MULTI_FRAMES,	        // �Ƿ�֧��һ�ζ�ȡ��֡���ݽ��д�ֱƴͼ��0 - ��֧�֣�1 - ֧��
	KSJ_SUPPORT_HWB_MATRIX,             // Ӳ���Ƿ�֧�����ð�ƽ�����
	KSJ_SUPPORT_HCCM_MATRIX,            // Ӳ���Ƿ�֧������CCM����
	KSJ_SUPPORT_GPIO_NORMAL,            // �Ƿ�֧���ⴥ��������Ϊ��ͨ����IO���Խ��ж�ȡ��������������Ϊ��ͨ���IO���н�������
	KSJ_SUPPORT_IO_FILTER,              // ������Դ�����˲�
	KSJ_SUPPORT_WATERMAK,               // �Ƿ�֧��ˮӡ���ܣ�ʱ���ģʽ���ⴥ�����֣��ⴥ�����ܣ�

	KSJ_SUPPORT_GET_FRAME_BUFFER_STATE, // �̼��Ƿ�֧�ֻ�ȡ֡��״̬
	KSJ_SUPPORT_RESET_DEVICE,           // �Ƿ�֧�ָ�λ�豸��   0 - ��֧�֣� 1 - ֧��
	KSJ_SUPPORT_SEND_PKT_END,           // �Ƿ�֧����ֹһ֡����
	KSJ_SUPPORT_RECONNECT,              // �豸�Ƿ�֧����������
	KSJ_SUPPORT_FAST_UPDATE,            // �Ƿ�֧�ֿ�������
	KSJ_SUPPORT_WORKINGMODE_PROGRAM,    // �Ƿ�֧�ֹ̻�����ģʽ
	KSJ_SUPPORT_SERIALSDESC_PROGRAM,    // �Ƿ�֧�ֹ̻��豸���������
	KSJ_SUPPORT_LUT_PROGRAM,            // �Ƿ�֧�ֹ̻�LUT���ұ�����
	KSJ_SUPPORT_GAMMA_LUT_PROGRAM,      // �Ƿ�֧�ֹ̻�Gamma LUT�������
	KSJ_SUPPORT_WORKINGMODEEX_PROGRAM,  // �Ƿ�֧�ֹ̻���������ģʽ
	KSJ_SUPPORT_COLORMODE_PROGRAM,      // �Ƿ�֧�ֹ̻�ɫ��ģʽ
	KSJ_SUPPORT_COLORMATRIX_PROGRAM,    // �Ƿ�֧�ֽ�HWB,HCCMУ������̻�

	KSJ_SUPPORT_SNAP_BUTTON,            // �Ƿ�֧��KSJ_SnapButtonStatus, 0 - ��֧�֣�1 - ֧��(���ܸ����û�����)
	KSJ_SUPPORT_IO_NUM,                 // ֧�ּ���IO������
	KSJ_SUPPORT_TRIGGER_MODE_HIGHLOW_FIXEDFRAMERATE,// �Ƿ�֧�ֹ̼�֡�ʴ������ߵ͵�ƽ��Ч��
	KSJ_SUPPORT_STREAM_MODE,            // �Ƿ�֧����ģʽ
	KSJ_SUPPORT_STARTEND_CAPTURE,       // �Ƿ�֧�ֿ�ʼ������ͼ

};

KSJ_API  int __stdcall KSJ_QueryFunction( int nChannel, KSJ_FUNCTION Function, int *pInfo ); 

#ifdef __cplusplus
}
#endif

#endif