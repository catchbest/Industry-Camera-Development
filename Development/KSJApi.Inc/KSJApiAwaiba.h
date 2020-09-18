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
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ǰ����Ƿ���AWAIBA���������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bUsed [out] ��ǰ����Ƿ���AWAIBA���������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_IsUsed( int nIndex, bool *bUsed );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ȡ�������������Ŀ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnSegNum [out] ���ص�ǰ�����������Ŀ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSegmentNum(int nIndex, int *pnSegNum );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ���ָ�����ε����淶Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     pnMin [out] ������С����
	/// @param     pnMax [out] �����������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGainRange(int nIndex, int nSegIndex, int *pnMin, int *pnMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ���ĳ�����ε�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     nGain [in] ��������ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetGain(int nIndex, int nSegIndex, int nGain);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ���ĳ�����ε�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     pnGain [out] ���ص�ǰ������ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetGain(int nIndex, int nSegIndex, int *pnGain);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ���ָ�����εĺڵ�ƽ��Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     pnMin [out] ������С�ڵ�ƽֵ
	/// @param     pnMax [out] �������ڵ�ƽֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevelRange(int nIndex, int nSegIndex, int *pnMin, int *pnMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �������ĳ�����εĺڵ�ƽֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     nBlackLevel [in] ���úڵ�ƽֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetBlackLevel(int nIndex, int nSegIndex, int nBlackLevel);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ���ĳ�����εĺڵ�ƽֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
	/// @param     pnBlackLevel [out] ���ص�ǰ�ĺڵ�ƽֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetBlackLevel (int nIndex, int nSegIndex, int *pnBlackLevel);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �������ĳ�����ε��Զ��ڵ�ƽ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSegIndex [in] ������������Χ��KSJ_AWAIBA_GetSegmentNum�õ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_AutoBlackLevel(int nIndex, int nSegIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������к�ż������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bSplit [in] ���������к�ż������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_SetSplitSegment(int nIndex, bool bSplit);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����к�ż������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbSplit [out] ���ص�ǰ�����к�ż���Ƿ����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWAIBA_GetSplitSegment(int nIndex, bool *pbSplit);

	/// ���º���δʵ��
	/*
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiBlooming(int nIndex, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiBlooming(int nIndex, bool *bEnable);

	KSJ_API  int __stdcall KSJ_AWAIBA_SetAntiCorona(int nIndex, bool bEnable);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAntiCorona(int nIndex, bool *bEnable);

	enum KSJ_AWAIBA_ANALOGUE_GAIN {KSJ_AAG_X1, KSJ_AAG_X4};
	KSJ_API  int __stdcall KSJ_AWAIBA_SetAnalogueGain(int nIndex, KSJ_AWAIBA_ANALOGUE_GAIN Gain);
	KSJ_API  int __stdcall KSJ_AWAIBA_GetAnalogueGain(int nIndex, KSJ_AWAIBA_ANALOGUE_GAIN *pGain);
	*/



#ifdef __cplusplus
}
#endif

#endif