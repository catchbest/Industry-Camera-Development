#pragma once
#include "afxwin.h"

#include "SnapStatic.h"

#define MAX_DEVICE    64

struct DEVICEINFO
{
	int                 nIndex;
	KSJ_DEVICETYPE		DeviceType;
	int					nSerials;
	WORD				wFirmwareVersion;
	WORD                wFpgaVersion;
};

#define TIMERID_GET_FRAME_RATE  101

#define WM_CAPTURE_END  WM_USER + 1

class CKSJDemoVCDlg : public CDialogEx
{
public:
	CKSJDemoVCDlg(CWnd* pParent = NULL);	// standard constructor

	enum { IDD = IDD_KSJDEMOVC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEditExposureTimeMs();
	afx_msg void OnEnChangeEditExposureLines();
	afx_msg void OnEnChangeEditGain();
	afx_msg void OnCbnSelchangeComboDeviceList();
	afx_msg void OnBnClickedButtonCaptureFovSet();
	afx_msg void OnBnClickedButtonCapture();

	afx_msg LRESULT MsgCaptureEnd(WPARAM wParam, LPARAM lParam);

protected:
	int m_nDeviceNum;
	int m_nDeviceCurSel;
	DEVICEINFO m_DeviceInfo[MAX_DEVICE];

public:
	bool StartAcquisition();
	bool StopAcquisition();

protected:
	static UINT WINAPI CaptureThread(LPVOID pParam);
	void               CaptureThreadX();

	HANDLE  m_hCaptureExitEvent;
	HANDLE  m_hCaptureThread;

	bool    m_bIsAcquiring;

	unsigned int m_nCaptureTickCount;

	bool    m_bZoomImage;
	int     m_nZoomImgWidth;
	int     m_nZoomImgHeight;

	unsigned int m_nLastTickCount;
	unsigned int m_dwTimeBegin;
	unsigned int m_dwTimeEnd;

protected:
	CSnapStatic m_SnapStatic;//ÏÔÊ¾Í¼Ïñ¿Ø¼þ

protected:
	void UpdateDeviceList(void);

	void ShowErrorInfo(int nRet);
	void GetRealExposureTime();
	void UpdateInterface();

public:
	afx_msg void OnBnClickedCheckZoomimage();
};
