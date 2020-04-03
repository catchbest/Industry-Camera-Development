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

#define WM_UPDATE_SNAP_STATIC    WM_USER + 2
#define WM_CAPTURE_START         WM_USER + 1

#define TIMERID_CAPTURE_PROGRESS 1
#define TIMERID_GET_FRAME_RATE   2

struct MSG_UPDATE_SNAP_STATIC_CONTEXT
{
	BYTE *pImageData;
	int  nCaptureWidth;
	int  nCaptureHeight;
	int  nCaptureBitCount;
	float fElapse;
};

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
	afx_msg void OnBnClickedCheckPreviewstart();

	afx_msg LRESULT MsgUpdateSnapStatic(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT MsgCaptureStart(WPARAM wParam, LPARAM lParam);

private:
	void UpdateDeviceList(void);
private:
	int m_nDeviceNum;
	int m_nDeviceCurSel;
	DEVICEINFO    m_DeviceInfo[MAX_DEVICE];


public:
	static UINT WINAPI CaptureX(LPVOID pParam);
	void CaptureXX();
	void StartCaptureThread(BOOL bStart);
	void Capture();
private:
	HANDLE        m_hCaptureThread;
	HANDLE        m_hCaptureThreadExitEvent;

public:
	afx_msg void OnEnChangeEditExposureTimeMs();
	afx_msg void OnEnChangeEditExposureLines();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CSnapStatic m_SnapStatic;

	BOOL        m_bInitial;
public:
	afx_msg void OnBnClickedCheckCapture();

private:
	void ShowErrorInfo(int nRet);
public:
	afx_msg void OnCbnSelchangeComboDeviceList();
private:
	void UpdateInterface();
public:
	void GetRealExposureTime();
	afx_msg void OnEnChangeEditGain();
	afx_msg void OnBnClickedButtonPreviewFovSet();
	afx_msg void OnBnClickedButtonCaptureFovSet();
	void UpdateInterfaceFunction();
private:
	void UpdateInterfaceColor();
public:
	afx_msg void OnCbnSelchangeComboWbMode();
	afx_msg void OnCbnSelchangeComboWbPresetting();
	afx_msg void OnEnChangeEditPhi();
	afx_msg void OnCbnSelchangeComboCcmMode();
	afx_msg void OnCbnSelchangeComboCcmPresetting();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

public:
	void WBACallback(float fMatrix[3]);

private:
	void UpdateCcmControls();
	void UpdateWbmControls();
};
