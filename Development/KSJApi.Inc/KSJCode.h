#ifndef	__KSJ_CODE_H__
#define __KSJ_CODE_H__

// #pragma message("Include KSJCode.h") 


/*-------------------------------------------------
	Return Code
  ================================================*/
#define		RET_SUCCESS			    1      // Function Return Successfully.
#define		RET_PARAMERROR			-1     // User's Parameter Passed to API Error.
#define		RET_MALLOCFAIL			-2     // Memory Allocated Fail.
#define		RET_NOTSUPPORT			-3     // Function not supported by such type camera.
#define		RET_DEVICENOTEXIST		-4     // Device doesn't be detected.
#define		RET_DEVICENOTINIT		-5     // Device haven't be initialized
#define		RET_VIOLATION			-6     // This operation is conflict to other operation.
#define		RET_NOPRIVILEGE			-7     // User no privilege
#define		RET_FAIL			    -8     // Function Return Failed.( Normal Error, no Detail )
#define		RET_WRONG			    -9     // Same to RET_FAIL.
#define     RET_RECOVERY_SUCCESS    -10    // Device is recovered successfully.
#define     RET_RECOVERY_FAIL       -11    // Device recovered, but fail.
#define     RET_BADFRAME            -12    // Bad Frame comes from sensor, should be skipped. 
#define     RET_INVALIDFRAME        -13    // Invalid Frame, Transmission Error, this frame should re-get.
#define     RET_ZEROFRAME           -14    // ֡������᷵�ش�ֵ����ʾ�ɼ�ͼ������0�ֽڣ������֡
#define     RET_VERSION_ERROR       -15    // �汾����
#define     RET_TIMEOUT             -16    // �����ö�ȡ��ʱ֮�󲻽��лָ�ʱ���ɼ������᷵�ش���ֵ�������᷵�ػָ���״̬
#define     RET_DEVICECLOSED        -17	   // �豸�Ѿ��ر�
#define     RET_BUSNOTINIT          -18    // ����û�г�ʼ��
#define     RET_CAM_NOT_CREATED     -19	   // ����޷�������ͨ����Ϊȱ�ٶ�Ӧ���͵�������ļ����
#define     RET_INVALID_HANDLE      -20	   // �Ƿ��ľ��
#define     RET_STREAMNOSTART       -21	   // ��ģʽû�д�
#define     RET_3DNOTINIT           -22	   // ���3D����û�г�ʼ��
#define     RET_3DNOTSUPPORT        -23	   // �����֧��3D����
#define     RET_STOPSTREAMFIRST     -24	   // ��Ҫ��ֹͣ��ģʽ
#define     RET_DATAIO_ERROR        -25	   // ����IO����ͨ������Ϊ���ݴ���������
#define     RET_3DINIT_ERROR        -26	   // ���3D���ܳ�ʼ�����󣬿�����Ϊ�����֧��3D���ܻ������3D��������


#endif