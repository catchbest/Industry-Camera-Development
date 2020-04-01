#ifndef __KSJ_API_AWAIBA_H__
#define __KSJ_API_AWAIBA_H__

// #pragma message("Include KSJApiAwaiba.h") 

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
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_IsUsed
    // ���ܣ������Զ��ع�Ĳο�����������������Ԥ��ͼ���λ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bUsed���������ǰ����Ƿ���AWAIBA���������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_IsUsed( int nChannel, bool *bUsed );
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetSegmentNum
    // ���ܣ�ȡ�������������Ŀ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnSegNum����������ص�ǰ�����������Ŀ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSegmentNum(int nChannel, int *pnSegNum );

	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetGainRange
    // ���ܣ���ȡ���ָ�����ε����淶Χ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       pnMin�������������С����
	//       pnMax������������������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGainRange(int nChannel, int nSegIndex, int *pnMin, int *pnMax);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_SetGain
    // ���ܣ���ȡ���ĳ�����ε�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       nGain�����룬��������ֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetGain(int nChannel, int nSegIndex, int nGain);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetGain
    // ���ܣ���ȡ���ĳ�����ε�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       pnGain����������ص�ǰ������ֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGain(int nChannel, int nSegIndex, int *pnGain);

	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetBlackLevelRange
    // ���ܣ���ȡ���ָ�����εĺڵ�ƽ��Χ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       pnMin�������������С�ڵ�ƽֵ
	//       pnMax��������������ڵ�ƽֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevelRange(int nChannel, int nSegIndex, int *pnMin, int *pnMax);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_SetBlackLevel
    // ���ܣ��������ĳ�����εĺڵ�ƽֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       nBlackLevel�����룬���úڵ�ƽֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetBlackLevel(int nChannel, int nSegIndex, int nBlackLevel);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetBlackLevel
    // ���ܣ���ȡ���ĳ�����εĺڵ�ƽֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	//       pnBlackLevel����������ص�ǰ�ĺڵ�ƽֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevel (int nChannel, int nSegIndex, int *pnBlackLevel);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_AutoBlackLevel
    // ���ܣ��������ĳ�����ε��Զ��ڵ�ƽ����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nSegIndex�����룬������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_AutoBlackLevel(int nChannel, int nSegIndex);

	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_SetSplitSegment
    // ���ܣ����������к�ż������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bSplit�����룬���������к�ż������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	KSJ_API  int __stdcall KSJ_AWAIBA_SetSplitSegment(int nChannel, bool bSplit);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_AWAIBA_GetSplitSegment
    // ���ܣ���ȡ�����к�ż������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pbSplit����������ص�ǰ�����к�ż���Ƿ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSplitSegment(int nChannel, bool *pbSplit);

	// ���º���δʵ��
	/*
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiBlooming(int nChannel, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiBlooming(int nChannel, bool *bEnable);

	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiCorona(int nChannel, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiCorona(int nChannel, bool *bEnable);

	enum KSJ_AWAIBA_ANALOGUE_GAIN {KSJ_AAG_X1, KSJ_AAG_X4};
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAnalogueGain(int nChannel, KSJ_AWAIBA_ANALOGUE_GAIN Gain);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAnalogueGain(int nChannel, KSJ_AWAIBA_ANALOGUE_GAIN *pGain);
	*/



#ifdef __cplusplus
}
#endif

#endif