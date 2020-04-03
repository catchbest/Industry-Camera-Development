#include "stdafx.h"
#include "KSJDemoVC.h"
#include "KSJDemoVCDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PREVIEWWND, m_SnapStatic);
}

BEGIN_MESSAGE_MAP(CKSJDemoVCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CHECK_PREVIEWSTART, &CKSJDemoVCDlg::OnBnClickedCheckPreviewstart)
	ON_EN_CHANGE(IDC_EDIT_EXPOSURE_TIME_MS, &CKSJDemoVCDlg::OnEnChangeEditExposureTimeMs)
	ON_WM_TIMER()
	ON_MESSAGE(WM_UPDATE_SNAP_STATIC, MsgUpdateSnapStatic)
	ON_MESSAGE(WM_CAPTURE_START, MsgCaptureStart)
	ON_BN_CLICKED(IDC_CHECK_CAPTURE, &CKSJDemoVCDlg::OnBnClickedCheckCapture)
	ON_CBN_SELCHANGE(IDC_COMBO_DEVICE_LIST, &CKSJDemoVCDlg::OnCbnSelchangeComboDeviceList)
	ON_EN_CHANGE(IDC_EDIT_EXPOSURE_LINES, &CKSJDemoVCDlg::OnEnChangeEditExposureLines)
	ON_EN_CHANGE(IDC_EDIT_GAIN, &CKSJDemoVCDlg::OnEnChangeEditGain)
	ON_BN_CLICKED(IDC_BUTTON_PREVIEW_FOV_SET, &CKSJDemoVCDlg::OnBnClickedButtonPreviewFovSet)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE_FOV_SET, &CKSJDemoVCDlg::OnBnClickedButtonCaptureFovSet)
	ON_EN_CHANGE(IDC_EDIT_BADPIXEL_CORRECTION_LOW, &CKSJDemoVCDlg::OnEnChangeEditBadpixelCorrectionLow)
	ON_EN_CHANGE(IDC_EDIT_BADPIXEL_CORRECTION_HIGH, &CKSJDemoVCDlg::OnEnChangeEditBadpixelCorrectionHigh)
	ON_BN_CLICKED(IDC_CHECK_BADPIXEL_CORRECTION_ENABLE, &CKSJDemoVCDlg::OnBnClickedCheckBadpixelCorrectionEnable)
	ON_CBN_SELCHANGE(IDC_COMBO_BADPIXEL_CORRECTION_MODE, &CKSJDemoVCDlg::OnCbnSelchangeComboBadpixelCorrectionMode)
	ON_EN_CHANGE(IDC_EDIT_PROCESS_CONTRAST, &CKSJDemoVCDlg::OnEnChangeEditProcessContrast)
	ON_EN_CHANGE(IDC_EDIT_PROCESS_SATURATION, &CKSJDemoVCDlg::OnEnChangeEditProcessSaturation)
	ON_EN_CHANGE(IDC_EDIT_PROCESS_BRGHTNESS, &CKSJDemoVCDlg::OnEnChangeEditProcessBrightness)
	ON_EN_CHANGE(IDC_EDIT_PROCESS_GAMMA, &CKSJDemoVCDlg::OnEnChangeEditProcessGamma)
	ON_BN_CLICKED(IDC_BUTTON_PROCESS_RESET, &CKSJDemoVCDlg::OnBnClickedButtonProcessReset)
	ON_BN_CLICKED(IDC_CHECK_HUE_SATURATION_ENABLE, &CKSJDemoVCDlg::OnBnClickedCheckHueSaturationEnable)
	ON_BN_CLICKED(IDC_BUTTON_HUE_SATURATION_RESET, &CKSJDemoVCDlg::OnBnClickedButtonHueSaturationReset)
	ON_BN_CLICKED(IDC_BUTTON_HUE_SATURATION_SET, &CKSJDemoVCDlg::OnBnClickedButtonHueSaturationSet)
	ON_CBN_SELCHANGE(IDC_COMBO_HUE_SATURATION_HUERANGE, &CKSJDemoVCDlg::OnCbnSelchangeComboHueSaturationHuerange)
END_MESSAGE_MAP()

void CKSJDemoVCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKSJDemoVCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CKSJDemoVCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
CKSJDemoVCDlg::CKSJDemoVCDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CKSJDemoVCDlg::IDD, pParent), m_nDeviceNum(0),
m_nDeviceCurSel(-1), m_hCaptureThread(NULL), m_hCaptureThreadExitEvent(NULL), m_bInitial(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// You only call KSJ_Init once.
	int nRet = KSJ_Init();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	int nRet = KSJ_UnInit();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	((CStatic*)GetDlgItem(IDC_STATIC_ERROR_INFO))->SetWindowText(szErrorInfo);
}

//////////////////////////////////////////////////////////////////////////////////////////////
BOOL CKSJDemoVCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//CEdit *pEditCtrlExposureTimeMs = ((CEdit*)GetDlgItem(IDC_EDIT_EXPOSURE_TIME_MS));
	CSpinButtonCtrl * pSpinCtrlExposureTimeMs = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_EXPOSURE_TIME_MS);
	pSpinCtrlExposureTimeMs->SetBuddy(GetDlgItem(IDC_EDIT_EXPOSURE_TIME_MS));
	pSpinCtrlExposureTimeMs->SetBase(10);

	//CEdit *pEditCtrlExposureLines = ((CEdit*)GetDlgItem(IDC_EDIT_EXPOSURE_LINES));
	CSpinButtonCtrl * pSpinCtrlExposureLines = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_EXPOSURE_LINES);
	pSpinCtrlExposureLines->SetBuddy(GetDlgItem(IDC_EDIT_EXPOSURE_LINES));
	pSpinCtrlExposureLines->SetBase(10);

	CSpinButtonCtrl * pSpinCtrlGain = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GAIN);
	pSpinCtrlGain->SetBuddy(GetDlgItem(IDC_EDIT_GAIN));
	pSpinCtrlGain->SetBase(10);

	CListCtrl *pListFunction = (CListCtrl*)GetDlgItem(IDC_LIST_FUNCTION);
	pListFunction->DeleteAllItems();
	pListFunction->InsertColumn(0, _T("Function"));
	pListFunction->InsertColumn(1, _T("Support"));
	pListFunction->SetColumnWidth(0, 300);
	pListFunction->SetColumnWidth(1, 100);

	DWORD dwStyleEx = pListFunction->GetExtendedStyle();
	pListFunction->SetExtendedStyle(dwStyleEx | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	UpdateDeviceList();
	OnInitImage();
	m_bInitial = TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKSJDemoVCDlg::UpdateInterface()
{
	if (m_nDeviceCurSel == -1)   return;

	// Initial Exposure Time
	int nMin = 0;
	int nMax = 0;
	int nCur = 0;

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_EXPOSURE, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE, &nCur);

	CSpinButtonCtrl * pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_EXPOSURE_TIME_MS);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nCur);

	TCHAR   szText[64] = { '\0' };
	_stprintf_s(szText, _T("%d-%d ms (%0.2fsec, %0.2fmin)"), nMin, nMax, (float)nMin / 1000.0f, (float)nMax / 60000.0f);
	((CStatic*)GetDlgItem(IDC_STATIC_EXPOSURE_TIME_RANGE))->SetWindowText(szText);

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nCur);
	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_EXPOSURE_LINES);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nCur);

	_stprintf_s(szText, _T("%d-%d Lines"), nMin, nMax );
	((CStatic*)GetDlgItem(IDC_STATIC_EXPOSURE_LINES_RANGE))->SetWindowText(szText);
	
	// GAIN, Because R,G,B Gain has same range. 
	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_RED, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_RED, &nCur);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GAIN);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nCur);

	_stprintf_s(szText, _T("%d-%d"), nMin, nMax );
	((CStatic*)GetDlgItem(IDC_STATIC_GAIN_RANGE))->SetWindowText(szText);

	// FOV
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;
	KSJ_ADDRESSMODE ColAddressMode;
	KSJ_ADDRESSMODE RowAddressMode;
	KSJ_PreviewGetDefaultFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	// Preview, Capture they are same, so you should get one is ok!
	_stprintf_s(szText, _T("%d-%d"), nColSize, nRowSize);
	((CStatic*)GetDlgItem(IDC_STATIC_FOV_RANGE))->SetWindowText(szText);

	SetDlgItemInt(IDC_EDIT_PREVIEW_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_SIZE, nRowSize);

	KSJ_CaptureGetDefaultFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_SIZE, nRowSize);
}

void CKSJDemoVCDlg::UpdateDeviceList(void)
{
	KSJ_UnInit();
	KSJ_Init();

	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_LIST);
	pComboBox->ResetContent();

	m_nDeviceNum = KSJ_DeviceGetCount();
	TCHAR  szDeviceNum[64] = { '\0' };
	_stprintf_s(szDeviceNum, _T("%d Device Found:"), m_nDeviceNum);
	GetDlgItem(IDC_STATIC_DEVICENUM)->SetWindowText(szDeviceNum);

	if (m_nDeviceNum == 0)
	{
		m_nDeviceCurSel = -1;
		return;
	}

	if (m_nDeviceCurSel >= m_nDeviceNum)
	{
		m_nDeviceCurSel = 0;
	}

	for (int i = 0; i<m_nDeviceNum; i++)
	{
		m_DeviceInfo[i].nIndex = i;
		// KSJ_DeviceGetInformation( i, &(m_DeviceInfo[i].DeviceType), &(m_DeviceInfo[i].nSerials), &(m_DeviceInfo[i].wFirmwareVersion) );
		KSJ_DeviceGetInformationEx(i, &(m_DeviceInfo[i].DeviceType), &(m_DeviceInfo[i].nSerials), &(m_DeviceInfo[i].wFirmwareVersion), &(m_DeviceInfo[i].wFpgaVersion));

		BYTE btMajVersion = (m_DeviceInfo[i].wFirmwareVersion & 0xFF00) >> 8;		// 得到主版本号
		BYTE btMinVersion = m_DeviceInfo[i].wFirmwareVersion & 0x00FF;				// 得到副版本号

		BYTE btFpgaMajVersion = (m_DeviceInfo[i].wFpgaVersion & 0xFF00) >> 8;		// 得到主版本号
		BYTE btFpgaMinVersion = m_DeviceInfo[i].wFpgaVersion & 0x00FF;				// 得到副版本号

		TCHAR  szMenuItem[256] = { '\0' };
		_stprintf_s(szMenuItem, _T("Index(%d)-Type(%s)-Serials(%d)-FwVer(%d.%d)-FpgaVer(%d.%d)"), i, g_szDeviceType[m_DeviceInfo[i].DeviceType], m_DeviceInfo[i].nSerials, btMajVersion, btMinVersion, btFpgaMajVersion, btFpgaMinVersion);
		pComboBox->AddString(szMenuItem);
	}

	pComboBox->SetCurSel(m_nDeviceCurSel);
}


void CKSJDemoVCDlg::OnCbnSelchangeComboDeviceList()
{
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_LIST);
	m_nDeviceCurSel = pComboBox->GetCurSel();

	UpdateInterface();
	UpdateInterfaceFunction();
	UpdateInterfaceImage();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	_stprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	((CStatic*)GetDlgItem(IDC_STATIC_EXPOSURE_TIME_REAL))->SetWindowText(szExposureTimeMs);

}
// Set Exposure Time ms
void CKSJDemoVCDlg::OnEnChangeEditExposureTimeMs()
{
	if (m_nDeviceCurSel == -1)   return;
	CEdit *pEditCtrl = ((CEdit*)GetDlgItem(IDC_EDIT_EXPOSURE_TIME_MS));

	TCHAR    szExposureTimeMs[32] = { '\0' };
	pEditCtrl->GetWindowText(szExposureTimeMs, 32);

	DWORD    m_dwExposureTimeMs = _ttoi(szExposureTimeMs);

	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE, m_dwExposureTimeMs);

	GetRealExposureTime();
}

void CKSJDemoVCDlg::OnEnChangeEditGain()
{
	if (m_nDeviceCurSel == -1)   return;
	CEdit *pEditCtrl = ((CEdit*)GetDlgItem(IDC_EDIT_GAIN));

	TCHAR    szGain[32] = { '\0' };
	pEditCtrl->GetWindowText(szGain, 32);

	int nGain = _ttoi(szGain);

	KSJ_SetParam(m_nDeviceCurSel, KSJ_RED, nGain);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_GREEN, nGain);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_BLUE, nGain);
}

void CKSJDemoVCDlg::OnEnChangeEditExposureLines()
{
	if (m_nDeviceCurSel == -1)   return;
	CEdit *pEditCtrl = ((CEdit*)GetDlgItem(IDC_EDIT_EXPOSURE_LINES));

	TCHAR    szExposureLines[32] = { '\0' };
	pEditCtrl->GetWindowText(szExposureLines, 32);

	DWORD    m_dwExposureLines = _ttoi(szExposureLines);

	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, m_dwExposureLines);

	GetRealExposureTime();

}

void CKSJDemoVCDlg::OnBnClickedButtonPreviewFovSet()
{
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;

	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;

	nColStart = GetDlgItemInt(IDC_EDIT_PREVIEW_COL_START);
	nRowStart = GetDlgItemInt(IDC_EDIT_PREIVEW_ROW_START);
	nColSize = GetDlgItemInt(IDC_EDIT_PREIVEW_COL_SIZE);
	nRowSize = GetDlgItemInt(IDC_EDIT_PREIVEW_ROW_SIZE);

	KSJ_PreviewSetFieldOfView(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode);
	
	// User may not set FOV correctly, ksjapi will correct it!
	KSJ_PreviewGetFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	SetDlgItemInt(IDC_EDIT_PREVIEW_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_SIZE, nRowSize);

}


void CKSJDemoVCDlg::OnBnClickedButtonCaptureFovSet()
{
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;

	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;

	nColStart = GetDlgItemInt(IDC_EDIT_CAPTURE_COL_START);
	nRowStart = GetDlgItemInt(IDC_EDIT_CAPTURE_ROW_START);
	nColSize = GetDlgItemInt(IDC_EDIT_CAPTURE_COL_SIZE);
	nRowSize = GetDlgItemInt(IDC_EDIT_CAPTURE_ROW_SIZE);
	KSJ_CaptureSetFieldOfView(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode);

	KSJ_CaptureGetFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_SIZE, nRowSize);
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == TIMERID_CAPTURE_PROGRESS)
	{
		CProgressCtrl *pProgressCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_EXPOSURE);
		pProgressCtrl->SetPos(pProgressCtrl->GetPos() + 1000);
	}
	else if (nIDEvent == TIMERID_GET_FRAME_RATE)
	{
		float fFrameRate = 0.0f;
		KSJ_PreviewGetFrameRate(m_nDeviceCurSel, &fFrameRate);
		TCHAR   szFrameRate[32] = { '\0' };
		_stprintf_s(szFrameRate, _T("KSJDemo Fps=%0.2f"), fFrameRate);
		SetWindowText(szFrameRate);
	}

	CDialogEx::OnTimer(nIDEvent);
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Start Preview
void CKSJDemoVCDlg::OnBnClickedCheckPreviewstart()
{
	if (m_nDeviceCurSel == -1)   return;

	HWND   hPreviewWnd = ((CStatic*)GetDlgItem(IDC_STATIC_PREVIEWWND))->m_hWnd;
	int    nPreviewWndWidth = 0;
	int    nPreviewWndHeight = 0;
	RECT   rtPreviewWndClient;
	((CStatic*)GetDlgItem(IDC_STATIC_PREVIEWWND))->GetClientRect(&rtPreviewWndClient);

	nPreviewWndWidth = rtPreviewWndClient.right - rtPreviewWndClient.left;
	nPreviewWndHeight = rtPreviewWndClient.bottom - rtPreviewWndClient.top;

	// You should assign window for preview once
	KSJ_PreviewSetPos(m_nDeviceCurSel, hPreviewWnd, 0, 0, nPreviewWndWidth, nPreviewWndHeight);

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_PREVIEWSTART))->GetCheck();

	int nRet = KSJ_PreviewStart(m_nDeviceCurSel, (bCheck ? true : false));

	if (bCheck)
	{
		SetTimer(TIMERID_GET_FRAME_RATE, 1000, NULL);
	}
	else
	{
		KillTimer(TIMERID_GET_FRAME_RATE);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Start Capture Message Function
afx_msg LRESULT CKSJDemoVCDlg::MsgCaptureStart(WPARAM wParam, LPARAM lParam)
{
	int nExposureTimeMs = 0;
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE, &nExposureTimeMs);

	CProgressCtrl *pProgressCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_EXPOSURE);
	pProgressCtrl->SetRange32(0, nExposureTimeMs);
	pProgressCtrl->SetPos(0);

	SetTimer(TIMERID_CAPTURE_PROGRESS, 1000, NULL);

	return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////
// Capture Finish Message Function
afx_msg LRESULT CKSJDemoVCDlg::MsgUpdateSnapStatic(WPARAM wParam, LPARAM lParam)
{
	BOOL bSuccess = (BOOL)lParam;

	if (bSuccess)
	{
		MSG_UPDATE_SNAP_STATIC_CONTEXT    *pContext = (MSG_UPDATE_SNAP_STATIC_CONTEXT*)wParam;

		TCHAR   szElapseTime[32] = { '\0' };
		_stprintf_s(szElapseTime, _T("Elapse: %0.2fms"), pContext->fElapse);

		((CStatic*)GetDlgItem(IDC_STATIC_ELAPSE_TIME))->SetWindowText(szElapseTime);

		m_SnapStatic.LoadImage(pContext->pImageData, pContext->nCaptureWidth, pContext->nCaptureHeight, pContext->nCaptureBitCount);
		delete[] pContext->pImageData;
		delete pContext;
	}
	else
	{
		TCHAR   szElapseTime[32] = { '\0' };
		_stprintf_s(szElapseTime, _T("Capture Fail."));

		((CStatic*)GetDlgItem(IDC_STATIC_ELAPSE_TIME))->SetWindowText(szElapseTime);
	}

	KillTimer(TIMERID_CAPTURE_PROGRESS);

	int nExposureTimeMs = 0;
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE, &nExposureTimeMs);
	CProgressCtrl *pProgressCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_EXPOSURE);
	pProgressCtrl->SetPos(nExposureTimeMs);

	((CButton*)GetDlgItem(IDC_CHECK_CAPTURE))->SetCheck( FALSE );
	((CButton*)GetDlgItem(IDC_CHECK_CAPTURE))->SetWindowText(_T("Start Capture Thread"));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::Capture()
{
	if (m_nDeviceCurSel == -1)    return;

	int    nCaptureWidth, nCaptureHeight, nCaptureBitCount;

	int nRet = KSJ_CaptureGetSizeEx(m_nDeviceCurSel, &nCaptureWidth, &nCaptureHeight, &nCaptureBitCount);
	ShowErrorInfo(nRet);

	BYTE    *pImageData = new BYTE[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3)];

	LARGE_INTEGER    counterStart;
	QueryPerformanceCounter(&counterStart);

	PostMessage(WM_CAPTURE_START, NULL, NULL);

	nRet = KSJ_CaptureRgbData(m_nDeviceCurSel, pImageData);
	ShowErrorInfo(nRet);
	if (nRet != RET_SUCCESS)
	{
		PostMessage(WM_UPDATE_SNAP_STATIC, NULL, FALSE);
		goto CAPTURE_RETURN;
	}


	LARGE_INTEGER    counterEnd;
	QueryPerformanceCounter(&counterEnd);

	LARGE_INTEGER nFreq;
	QueryPerformanceFrequency(&nFreq);

	float fInterval = (float)(counterEnd.QuadPart - counterStart.QuadPart);
	float fElapse = fInterval / (float)nFreq.QuadPart * 1000;    // MS

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_SAVE))->GetCheck();
	if (bCheck)
	{
		TCHAR   szFileName[MAX_PATH] = { '\0' };

		SYSTEMTIME LocalTime;
		GetLocalTime(&LocalTime);
#ifdef SAVE_JPG
		_stprintf_s(szFileName, _T("capture-%04d-%02d-%02d-%02d-%02d-%02d-%03d-%05d.jpg"), LocalTime.wYear, LocalTime.wMonth, LocalTime.wDay, LocalTime.wHour, LocalTime.wMinute, LocalTime.wSecond, LocalTime.wMilliseconds, (int)fElapse);
		KSJ_HelperSaveToJpg(pImageData, nCaptureWidth, nCaptureHeight, nCaptureBitCount, 90,  szFileName);
#else
		_stprintf_s(szFileName, _T("capture-%04d-%02d-%02d-%02d-%02d-%02d-%03d-%05d.bmp"), LocalTime.wYear, LocalTime.wMonth, LocalTime.wDay, LocalTime.wHour, LocalTime.wMinute, LocalTime.wSecond, LocalTime.wMilliseconds, (int)fElapse);
		KSJ_HelperSaveToBmp(pImageData, nCaptureWidth, nCaptureHeight, nCaptureBitCount, szFileName);
#endif
	}



	// Show This Capture Data
	MSG_UPDATE_SNAP_STATIC_CONTEXT    *pContext = new MSG_UPDATE_SNAP_STATIC_CONTEXT;
	memset(pContext, 0, sizeof(MSG_UPDATE_SNAP_STATIC_CONTEXT));
	pContext->pImageData = pImageData;
	pContext->nCaptureWidth = nCaptureWidth;
	pContext->nCaptureHeight = nCaptureHeight;
	pContext->nCaptureBitCount = nCaptureBitCount;
	pContext->fElapse = fElapse;

	PostMessage(WM_UPDATE_SNAP_STATIC, (WPARAM)pContext, TRUE);

	return;

CAPTURE_RETURN:
	delete[] pImageData;
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::CaptureXX()
{
#ifdef CIRCLE_CAPTURE_IN_THREAD
	while (TRUE)
	{
		if (WAIT_OBJECT_0 == WaitForSingleObject(m_hCaptureThreadExitEvent, 0))
		{ // Exit Capture Thread
			break;
		}

		Capture();
	}
#else
	Capture();
#endif

	m_hCaptureThread = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////
UINT WINAPI CKSJDemoVCDlg::CaptureX(LPVOID pParam)
{
	CKSJDemoVCDlg *pDlg = (CKSJDemoVCDlg*)pParam;
	pDlg->CaptureXX();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::StartCaptureThread(BOOL bStart)
{
	if (bStart)
	{
		m_hCaptureThreadExitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);		// Manual Reset, No signal

		DWORD    dwThreadID;
		m_hCaptureThread = (HANDLE)_beginthreadex(NULL, 0, (PBEGINTHREADEX_FUNC)CKSJDemoVCDlg::CaptureX, this, 0, (PBEGINTHREADEX_ID)&dwThreadID);

		if (m_hCaptureThread != NULL)
		{
			// MessageBox(_T("Capture Thread Starting..."), _T("KSJ"), 0 );
		}
	}
	else
	{
		if (m_hCaptureThreadExitEvent != NULL)
		{
			SetEvent(m_hCaptureThreadExitEvent);
		}

		if (WAIT_OBJECT_0 != WaitForSingleObject(m_hCaptureThread, 5000))
			return;

		CloseHandle(m_hCaptureThread);
		m_hCaptureThread = NULL;
		CloseHandle(m_hCaptureThreadExitEvent);
		m_hCaptureThreadExitEvent = NULL;

		// MessageBox(_T("Capture Thread Closed..."), _T("KSJ"), 0);
	}
}



// Capture Image, In Thread or In Proccess
void CKSJDemoVCDlg::OnBnClickedCheckCapture()
{
	if (m_nDeviceCurSel == -1)    return;
	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_CAPTURE))->GetCheck();

#ifdef CAPTURE_THREAD
	if (bCheck)
	{
		StartCaptureThread(TRUE);
		((CButton*)GetDlgItem(IDC_CHECK_CAPTURE))->SetWindowText(_T("Stop Capture Thread"));
	}
	else
	{
		StartCaptureThread(FALSE);
		((CButton*)GetDlgItem(IDC_CHECK_CAPTURE))->SetWindowText(_T("Start Capture Thread"));
	}
#else
	if( bCheck )
	{
		Capture();
	}
#endif
}

void CKSJDemoVCDlg::UpdateInterfaceFunction()
{
	if (m_nDeviceCurSel == -1)    return;

	CListCtrl *pListFunction = (CListCtrl*)GetDlgItem(IDC_LIST_FUNCTION);
	pListFunction->DeleteAllItems();

	int i = g_nFunction - 1;
	TCHAR szSupport[32] = { '\0' };
	
	do{
		int nIndex;
		nIndex = pListFunction->InsertItem(0, g_szFunction[i]);
		if (nIndex < 0) return;
		int nSupport = 0;
		KSJ_QueryFunction(m_nDeviceCurSel, (KSJ_FUNCTION)i, &nSupport);
		_stprintf_s(szSupport, _T("%d"), nSupport);
		pListFunction->SetItemText(nIndex, 1, szSupport);
	}while (i--);
}

///////////////////////////////////////////////////////////////////////Image
const TCHAR* g_szHueRange[] =
{
	_T("ALL"),
	_T("RED"),
	_T("YELLOW"),
	_T("GREEN"),
	_T("CYAN"),
	_T("BLUE"),
	_T("MAGENTA")
};
const int g_nHueRange = sizeof(g_szHueRange) / sizeof(TCHAR*);

void CKSJDemoVCDlg::OnInitImage()
{
	CSpinButtonCtrl * pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_CONTRAST);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_PROCESS_CONTRAST));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_SATURATION);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_PROCESS_SATURATION));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_BRGHTNESS);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_PROCESS_BRGHTNESS));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_GAMMA);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_PROCESS_GAMMA));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_HUE);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_HUE_SATURATION_HUE));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_LIGHTNESS);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_HUE_SATURATION_LIGHTNESS));
	pSpinCtrl->SetBase(10);

	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_SATURATION);
	pSpinCtrl->SetBuddy(GetDlgItem(IDC_EDIT_HUE_SATURATION_SATURATION));
	pSpinCtrl->SetBase(10);
}

void CKSJDemoVCDlg::UpdateInterfaceImage()
{
	if (m_nDeviceCurSel == -1)    return;

	int nSupport = 0;//Bad Pixel Correction
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_BAD_PIXEL_CORRECTION, &nSupport);

	if (!nSupport)
	{
		unsigned char btLow;
		unsigned char btHigh;
		
		KSJ_BadPixelCorrectionGetThreshold(m_nDeviceCurSel, &btLow, &btHigh);
		SetDlgItemInt(IDC_EDIT_BADPIXEL_CORRECTION_LOW, btLow);
		SetDlgItemInt(IDC_EDIT_BADPIXEL_CORRECTION_HIGH, btHigh);
		CComboBox    *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_BADPIXEL_CORRECTION_MODE);
		pComboBox->ResetContent();
		pComboBox->AddString(g_szBadPixelThreshold[1]);
		pComboBox->SetCurSel(0);
		GetDlgItem(IDC_COMBO_BADPIXEL_CORRECTION_MODE)->EnableWindow(false);
	}
	else
	{
		bool		  bEnable;
		KSJ_THRESHOLD Threshold;
		KSJ_BadPixelCorrectionGet(m_nDeviceCurSel, &bEnable, &Threshold);
		((CButton*)GetDlgItem(IDC_CHECK_BADPIXEL_CORRECTION_ENABLE))->SetCheck(bEnable);

		CComboBox    *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_BADPIXEL_CORRECTION_MODE);
		pComboBox->ResetContent();
		for (int i = 0; i < g_nBadPixelThreshold; i++)
		{
			pComboBox->AddString(g_szBadPixelThreshold[g_nBadPixelThreshold - 1 - i]);
		}

		pComboBox->SetCurSel(Threshold);
		GetDlgItem(IDC_EDIT_BADPIXEL_CORRECTION_LOW)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_BADPIXEL_CORRECTION_HIGH)->EnableWindow(false);

	}

	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_PROPERTY_MONO_DEVICE, &nSupport);//Process

	int nMin;
	int nMax;
	int nValue;
	KSJ_ProcessContrastGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_ProcessContrastGet(m_nDeviceCurSel, &nValue);
	SetDlgItemInt(IDC_EDIT_PROCESS_CONTRAST, nValue);
	CSpinButtonCtrl * pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_CONTRAST);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nValue);

	KSJ_ProcessBrightnessGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_ProcessBrightnessGet(m_nDeviceCurSel, &nValue);
	SetDlgItemInt(IDC_EDIT_PROCESS_BRGHTNESS, nValue);
	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_BRGHTNESS);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nValue);

	KSJ_GammaGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_GammaGetValue(m_nDeviceCurSel, &nValue);
	SetDlgItemInt(IDC_EDIT_PROCESS_GAMMA, nValue);
	pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_GAMMA);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nValue);
	
	if (!nSupport)
	{
		KSJ_ProcessSaturationGetRange(m_nDeviceCurSel, &nMin, &nMax);
		KSJ_ProcessSaturationGet(m_nDeviceCurSel, &nValue);
		SetDlgItemInt(IDC_EDIT_PROCESS_SATURATION, nValue);
		pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_PROCESS_SATURATION);
		pSpinCtrl->SetRange32(nMin, nMax);
		pSpinCtrl->SetPos32(nValue);
		GetDlgItem(IDC_EDIT_PROCESS_SATURATION)->EnableWindow(true);
		GetDlgItem(IDC_SPIN_PROCESS_SATURATION)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_PROCESS_SATURATION)->EnableWindow(false);
		GetDlgItem(IDC_SPIN_PROCESS_SATURATION)->EnableWindow(false);
	}

	if (!nSupport)//Hue Saturation
	{
		int nHue;
		int nSaturation;
		int nLightness;
		KSJ_HueSaturationGet(m_nDeviceCurSel, KSJ_ALL_HUES, &nHue, &nSaturation, &nLightness);
		CSpinButtonCtrl * pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_HUE);
		pSpinCtrl->SetRange32(-180, 180);
		pSpinCtrl->SetPos32(nHue);
		SetDlgItemInt(IDC_EDIT_HUE_SATURATION_HUE, nHue);
		pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_SATURATION);
		pSpinCtrl->SetRange32(-100, 100);
		pSpinCtrl->SetPos32(nSaturation);
		SetDlgItemInt(IDC_EDIT_HUE_SATURATION_SATURATION, nSaturation);
		pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE_SATURATION_LIGHTNESS);
		pSpinCtrl->SetRange32(-100, 100);
		pSpinCtrl->SetPos32(nLightness);
		SetDlgItemInt(IDC_EDIT_HUE_SATURATION_LIGHTNESS, nLightness);

		CComboBox    *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE);
		pComboBox->ResetContent();
		for (int i = 0; i < g_nHueRange; i++)
		{
			pComboBox->AddString(g_szHueRange[i]);
		}

		pComboBox->SetCurSel(0);
		GetDlgItem(IDC_EDIT_HUE_SATURATION_HUE)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_HUE_SATURATION_SATURATION)->EnableWindow(true);
		GetDlgItem(IDC_EDIT_HUE_SATURATION_LIGHTNESS)->EnableWindow(true);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_HUE)->EnableWindow(true);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_SATURATION)->EnableWindow(true);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_LIGHTNESS)->EnableWindow(true);
		GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE)->EnableWindow(true);
		GetDlgItem(IDC_CHECK_HUE_SATURATION_ENABLE)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_HUE_SATURATION_RESET)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_HUE_SATURATION_SET)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_EDIT_HUE_SATURATION_HUE)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_HUE_SATURATION_SATURATION)->EnableWindow(false);
		GetDlgItem(IDC_EDIT_HUE_SATURATION_LIGHTNESS)->EnableWindow(false);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_HUE)->EnableWindow(false);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_SATURATION)->EnableWindow(false);
		GetDlgItem(IDC_SPIN_HUE_SATURATION_LIGHTNESS)->EnableWindow(false);
		GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE)->EnableWindow(false);
		GetDlgItem(IDC_CHECK_HUE_SATURATION_ENABLE)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_HUE_SATURATION_RESET)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_HUE_SATURATION_SET)->EnableWindow(false);
	}
}

void CKSJDemoVCDlg::SetThreshold()
{
	if (m_nDeviceCurSel == -1)    return;

	unsigned char btLow;
	unsigned char btHigh;
	btLow  = GetDlgItemInt(IDC_EDIT_BADPIXEL_CORRECTION_LOW);
	btHigh = GetDlgItemInt(IDC_EDIT_BADPIXEL_CORRECTION_HIGH);
	KSJ_BadPixelCorrectionSetThreshold(m_nDeviceCurSel, btLow, btHigh);
}

void CKSJDemoVCDlg::OnEnChangeEditBadpixelCorrectionLow()
{
	SetThreshold();
}

void CKSJDemoVCDlg::OnEnChangeEditBadpixelCorrectionHigh()
{
	SetThreshold();
}

void CKSJDemoVCDlg::SetBadpixelCorrection()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL		  bEnable;
	KSJ_THRESHOLD Threshold;
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_BADPIXEL_CORRECTION_MODE);
	Threshold = (KSJ_THRESHOLD)(pComboBox->GetCurSel());
	bEnable = ((CButton*)GetDlgItem(IDC_CHECK_BADPIXEL_CORRECTION_ENABLE))->GetCheck();
	KSJ_BadPixelCorrectionSet(m_nDeviceCurSel, bEnable ? TRUE : FALSE, Threshold);
}

void CKSJDemoVCDlg::OnBnClickedCheckBadpixelCorrectionEnable()
{
	SetBadpixelCorrection();
}

void CKSJDemoVCDlg::OnCbnSelchangeComboBadpixelCorrectionMode()
{
	SetBadpixelCorrection();
}

void CKSJDemoVCDlg::OnEnChangeEditProcessContrast()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue;
	nValue = GetDlgItemInt(IDC_EDIT_PROCESS_CONTRAST);
	KSJ_ProcessContrastSet(m_nDeviceCurSel, nValue);
}


void CKSJDemoVCDlg::OnEnChangeEditProcessSaturation()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue;
	nValue = GetDlgItemInt(IDC_EDIT_PROCESS_SATURATION);
	KSJ_ProcessSaturationSet(m_nDeviceCurSel, nValue);
}


void CKSJDemoVCDlg::OnEnChangeEditProcessBrightness()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue;
	nValue = GetDlgItemInt(IDC_EDIT_PROCESS_BRGHTNESS);
	KSJ_ProcessBrightnessSet(m_nDeviceCurSel, nValue);
}


void CKSJDemoVCDlg::OnEnChangeEditProcessGamma()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue;
	nValue = GetDlgItemInt(IDC_EDIT_PROCESS_GAMMA);
	KSJ_GammaSetValue(m_nDeviceCurSel, nValue);
}


void CKSJDemoVCDlg::OnBnClickedButtonProcessReset()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL bEnable = GetDlgItem(IDC_EDIT_PROCESS_SATURATION)->IsWindowEnabled();
	if (bEnable)
	{
		SetDlgItemInt(IDC_EDIT_PROCESS_SATURATION, 0);
		KSJ_ProcessSaturationSet(m_nDeviceCurSel, 0);
	}

	SetDlgItemInt(IDC_EDIT_PROCESS_CONTRAST, 0);
	KSJ_ProcessContrastSet(m_nDeviceCurSel, 0);
	SetDlgItemInt(IDC_EDIT_PROCESS_BRGHTNESS, 0);
	KSJ_ProcessBrightnessSet(m_nDeviceCurSel, 0);
	SetDlgItemInt(IDC_EDIT_PROCESS_GAMMA, 0);
	KSJ_GammaSetValue(m_nDeviceCurSel, 0);
}

void CKSJDemoVCDlg::OnBnClickedCheckHueSaturationEnable()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_HUE_SATURATION_ENABLE))->GetCheck();
	KSJ_HueSaturationSetEnable(m_nDeviceCurSel, bCheck ? TRUE : FALSE);
}

void CKSJDemoVCDlg::OnBnClickedButtonHueSaturationReset()
{
	if (m_nDeviceCurSel == -1)    return;

	for (int i = 0; i < g_nHueRange;i++)
	{
		KSJ_HueSaturationSet(m_nDeviceCurSel, KSJHueRange(i), 0, 0, 0);
	}

	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_HUE, 0);
	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_SATURATION, 0);
	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_LIGHTNESS, 0);

	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE);
	pComboBox->SetCurSel(0);
}

void CKSJDemoVCDlg::OnBnClickedButtonHueSaturationSet()
{
	if (m_nDeviceCurSel == -1)    return;

	int nHue		= GetDlgItemInt(IDC_EDIT_HUE_SATURATION_HUE);
	int nSaturation = GetDlgItemInt(IDC_EDIT_HUE_SATURATION_SATURATION);
	int nLightness  = GetDlgItemInt(IDC_EDIT_HUE_SATURATION_LIGHTNESS);

	KSJHueRange HueRange;
	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE);
	HueRange = (KSJHueRange)(pComboBox->GetCurSel());

	KSJ_HueSaturationSet(m_nDeviceCurSel, HueRange, nHue, nSaturation, nLightness);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboHueSaturationHuerange()
{
	if (m_nDeviceCurSel == -1)    return;

	int nHue;
	int nSaturation;
	int nLightness;

	KSJHueRange HueRange;
	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_HUE_SATURATION_HUERANGE);
	HueRange = (KSJHueRange)(pComboBox->GetCurSel());

	KSJ_HueSaturationGet(m_nDeviceCurSel, HueRange, &nHue, &nSaturation, &nLightness);
	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_HUE, nHue);
	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_SATURATION, nSaturation);
	SetDlgItemInt(IDC_EDIT_HUE_SATURATION_LIGHTNESS, nLightness);
}
