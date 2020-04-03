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
	ON_BN_CLICKED(IDC_CHECK_READLOOP, &CKSJDemoVCDlg::OnBnClickedCheckReadloop)
	ON_CBN_SELCHANGE(IDC_COMBO_IO0_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo0Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO1_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo1Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO2_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo2Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO3_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo3Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO4_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo4Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO5_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo5Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO6_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo6Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO7_DIRECTION, &CKSJDemoVCDlg::OnCbnSelchangeComboIo7Direction)
	ON_CBN_SELCHANGE(IDC_COMBO_IO0_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo0Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO1_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo1Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO2_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo2Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO3_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo3Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO4_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo4Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO5_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo5Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO6_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo6Status)
	ON_CBN_SELCHANGE(IDC_COMBO_IO7_STATUS, &CKSJDemoVCDlg::OnCbnSelchangeComboIo7Status)
	ON_BN_CLICKED(IDC_CHECK_SNAP_STARTDETECT, &CKSJDemoVCDlg::OnBnClickedCheckSnapStartdetect)
	ON_CBN_SELCHANGE(IDC_COMBO_SNAP_CONDITION, &CKSJDemoVCDlg::OnCbnSelchangeComboSnapCondition)
	ON_EN_CHANGE(IDC_EDIT_FILTER, &CKSJDemoVCDlg::OnEnChangeEditFilter)
	ON_CBN_SELCHANGE(IDC_COMBO_TIMEOUT, &CKSJDemoVCDlg::OnCbnSelchangeComboTimeout)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_MODE, &CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMode)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_METHOD, &CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMethod)
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
m_nDeviceCurSel(-1), m_hCaptureThread(NULL), m_hCaptureThreadExitEvent(NULL), m_bInitial(FALSE), 
m_nSnapDetectInterval(100),
m_bSnapDetectStart(FALSE),
m_nSnapConditionIndex(0),
m_wIoFilter(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// You only call KSJ_Init once.
	int nRet = KSJ_Init();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void CKSJDemoVCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	KillTimer(IDT_READLOOP);

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
	UpdateInterface();
	UpdateInterfaceFunction();

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
	UpdateInterfaceIO();
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
	else if (nIDEvent == IDT_READLOOP)
	{
		int nIoNum = 0;
		KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_IO_NUM, &nIoNum);

		int i = 0;
		for (i = 0; i < nIoNum; i++)
		{
			GetGpioStatus(i);
		}
	}

	else if (nIDEvent == ID_TIMER_SNAP_INTERVAL)
	{
		// 检测Snap按键是否满足条件，如果满足，则采集
		// _T("Falling Edge"),	_T("Rising Edge"),	_T("High Level"),	_T("Low Level")
		KSJ_SnapButtonStatus(m_nDeviceCurSel, &m_CurSnapButtonStatus);

		if (0 == m_nSnapConditionIndex)
		{ // 下降沿
			if (m_CurSnapButtonStatus == KSJ_DOWN && m_PrvSnapButtonStatus == KSJ_UP)
			{
				Capture();
			}
		}

		else if (1 == m_nSnapConditionIndex)
		{ // 上升沿
			if (m_CurSnapButtonStatus == KSJ_UP && m_PrvSnapButtonStatus == KSJ_DOWN)
			{
				Capture();
			}
		}
		else if (2 == m_nSnapConditionIndex)
		{ // 高电平
			if (m_CurSnapButtonStatus == KSJ_UP)
			{
				Capture();
			}
		}
		else
		{ // 低电平
			if (m_CurSnapButtonStatus == KSJ_DOWN)
			{
				Capture();
			}
		}

		m_PrvSnapButtonStatus = m_CurSnapButtonStatus;

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
	int    nBitsPerSample;

	int nRet = KSJ_CaptureGetSizeExEx(m_nDeviceCurSel, &nCaptureWidth, &nCaptureHeight, &nCaptureBitCount, &nBitsPerSample);
	ShowErrorInfo(nRet);
	BYTE    *pImageData = new BYTE[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3) * (nBitsPerSample >> 3)];

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

void CKSJDemoVCDlg::UpdateInterfaceIO()
{
	int nIoNum = 0;
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_IO_NUM, &nIoNum);

	// ((CButton*)GetDlgItem(IDC_CHECK_READLOOP))->EnableWindow(nIoNum == 0 ? FALSE : TRUE);


	CComboBox    *pComboBox = NULL;
	int i = 0;
	int j = 0;

	for (i = 0; i <= 7; i++)
	{
		if (i >= nIoNum)
		{
			pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_DIRECTION + i);
			pComboBox->EnableWindow(FALSE);
			pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_STATUS + i);
			pComboBox->EnableWindow(FALSE);
			continue;
		}
		pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_DIRECTION + i);
		pComboBox->ResetContent();

		for (j = 0; j < g_nGpioDirection; j++)
		{
			pComboBox->AddString(g_szGpioDirection[j]);
		}

		BOOL    bOutput = FALSE;
		GetGpioDirection( i, &bOutput);
		pComboBox->SetCurSel(bOutput);

		// 对于输入管脚，相应的Status选择框不可选
		pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_STATUS + i);
		pComboBox->ResetContent();

		for (j = 0; j < g_nGpioStatus; j++)
		{
			pComboBox->AddString(g_szGpioStatus[j]);
		}

		if (bOutput)
		{
			pComboBox->SetCurSel(0);
			SetGpioStatus(i);
		}
		else
		{
			BOOL    bLevel = FALSE;
			GetGpioStatus(i, &bLevel);
			pComboBox->SetCurSel(bLevel);
		}

		pComboBox->EnableWindow(bOutput);
	}

	// io filter
	int nSupport;

	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_IO_FILTER, &nSupport);
	((CEdit*)GetDlgItem(IDC_EDIT_FILTER))->EnableWindow(nSupport == 1 ? TRUE : FALSE);

	KSJ_GpioFilterGet(m_nDeviceCurSel, &m_wIoFilter);
	CSpinButtonCtrl * pSpinCtrlFilter = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_FILTER);
	pSpinCtrlFilter->SetBuddy(GetDlgItem(IDC_EDIT_FILTER));
	pSpinCtrlFilter->SetBase(10);
	pSpinCtrlFilter->SetRange32(0, 65535);

	SetDlgItemInt(IDC_EDIT_FILTER, m_wIoFilter);

	// Snap Button Function

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_SNAP_CONDITION);
	pComboBox->ResetContent();


	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TIMEOUT);
	pComboBox->ResetContent();
	for (i = 0; i < sizeof(g_szTimeOut) / sizeof(TCHAR*); i++)
	{
		pComboBox->AddString(g_szTimeOut[i]);
	}
	KSJ_CaptureSetTimeOut(m_nDeviceCurSel, g_nTimeOut[0]);
	pComboBox->SetCurSel(0);

	for (i = 0; i<g_nTriggerMethod; i++)
	{
		pComboBox->AddString(g_szTriggerMethod[i]);
	}
	pComboBox->SetCurSel(m_nSnapConditionIndex);

	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_SNAP_BUTTON, &nSupport);
	((CButton*)GetDlgItem(IDC_CHECK_SNAP_STARTDETECT))->EnableWindow(nSupport == 1 ? TRUE : FALSE);

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_MODE);
	pComboBox->ResetContent();

	for (i = 0; i < g_nTriggerMode; i++)
	{
		pComboBox->AddString(g_szTriggerMode[i]);
	}

	KSJ_TRIGGERMODE    TriggerMode;
	int nRet = KSJ_TriggerModeGet(m_nDeviceCurSel, &TriggerMode);
	KSJ_FlashControlSet(m_nDeviceCurSel, true, false, 0);
	pComboBox->SetCurSel((int)TriggerMode);
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_METHOD);
	pComboBox->ResetContent();
	int nMin = 0;
	int nMax = 0;
	int nCur = 0;

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_TRIGGER_MODE, &nMin, &nMax);
	for (i = 0; i < g_nTriggerMethod; i++)
	{
		pComboBox->AddString(g_szTriggerMethod[i]);
	}
	if (nMax == KSJ_TRIGGER_HIGHLOWFIXFRAMERATE) pComboBox->AddString(_T("High Low Fixed Frame Rate"));
	KSJ_TRIGGERMETHOD    TriggerMethod;
	nRet = KSJ_TriggerMethodGet(m_nDeviceCurSel, &TriggerMethod);

	pComboBox->SetCurSel((int)TriggerMethod);

}

void CKSJDemoVCDlg::SetGpioDirection(int nPinIndex)
{
	if (m_nDeviceCurSel == -1)       return;

	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_DIRECTION + nPinIndex);
	int nSel = pComboBox->GetCurSel();			// 0 - input, 1 - output

	BOOL bOutput = (nSel == 0 ? FALSE : TRUE);
	int nRet = SetGpioDirection(nPinIndex, bOutput);
	if (nRet != RET_SUCCESS)     return;

	// 如果是设置为输出，则读取Status的值并进行设置
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_STATUS + nPinIndex);
	if (bOutput)
	{
		nSel = pComboBox->GetCurSel();			// 0 - low, 1 - high

		BOOL    bLevel = (nSel == 0 ? FALSE : TRUE);
		nRet = SetGpioStatus(nPinIndex, bLevel);
		if (nRet != RET_SUCCESS)     return;
	}

	// 如果是输入，则读取GPIO状态，更新Status的列表值
	else
	{
		BOOL    bLevel = FALSE;
		nRet = GetGpioStatus(nPinIndex, &bLevel);
		if (nRet != RET_SUCCESS)     return;

		pComboBox->SetCurSel(bLevel == FALSE ? 0 : 1);
	}

	pComboBox->EnableWindow(bOutput);
}

int   CKSJDemoVCDlg::SetGpioDirection(int nPinIndex, BOOL  bOutput)			// 1 - 输出，0 - 输入
{
	if (m_nDeviceCurSel == -1)               return RET_FAIL;

	BYTE    btDirection;
	int nRet = KSJ_GpioGetDirection(m_nDeviceCurSel, &btDirection);
	if (nRet != RET_SUCCESS)                return RET_FAIL;

	BYTE   btMask = (0x01 << nPinIndex);

	if (bOutput)
		btDirection |= btMask;
	else
		btDirection &= ~btMask;

	nRet = KSJ_GpioSetDirection(m_nDeviceCurSel, btDirection);

	return nRet;
}


int   CKSJDemoVCDlg::GetGpioDirection(int nPinIndex, BOOL *pbOutput)				// 1 - 输出，0 - 输入
{
	if (m_nDeviceCurSel == -1)    return RET_FAIL;

	BYTE    btDirection = 0x00;
	int nRet = KSJ_GpioGetDirection(m_nDeviceCurSel, &btDirection);
	if (nRet != RET_SUCCESS)                return RET_FAIL;

	BYTE   btMask = (0x01 << nPinIndex);

	*pbOutput = ((((btDirection & btMask) >> nPinIndex) == 0x00) ? FALSE : TRUE);

	return nRet;
}


// 只对输入引脚有效
int   CKSJDemoVCDlg::GetGpioStatus(int nPinIndex, BOOL *pbLevel)			// 1 - 高电平，0 - 低电平
{
	if (m_nDeviceCurSel == -1)    return RET_FAIL;

	BOOL    bOutput = FALSE;
	int nRet = GetGpioDirection(nPinIndex, &bOutput);
	if (nRet != RET_SUCCESS || bOutput != 0)     return RET_FAIL;

	BYTE             btStatus;
	nRet = KSJ_GpioGetStatus(m_nDeviceCurSel, &btStatus);
	if (nRet != RET_SUCCESS)                return RET_FAIL;

	BYTE   btMask = (0x01 << nPinIndex);

	*pbLevel = ((((btStatus & btMask) >> nPinIndex) == 0x00) ? FALSE : TRUE);

	return RET_SUCCESS;
}

void CKSJDemoVCDlg::GetGpioStatus(int nPinIndex)
{
	if (m_nDeviceCurSel == -1)       return;

	// 如果已经设置为输出，则不能进行读取
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_DIRECTION + nPinIndex);
	int nSel = pComboBox->GetCurSel();			// 0 - input, 1 - output
	BOOL bOutput = (nSel == 0 ? FALSE : TRUE);

	if (bOutput == TRUE)           return;

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_STATUS + nPinIndex);

	BOOL    bLevel = FALSE;
	int nRet = GetGpioStatus(nPinIndex, &bLevel);

	pComboBox->SetCurSel(bLevel ? 1 : 0);

}

void CKSJDemoVCDlg::SetGpioStatus(int nPinIndex)
{
	if (m_nDeviceCurSel == -1)    return;

	// 如果已经设置为输入，则不能进行设置
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_DIRECTION + nPinIndex);
	int nSel = pComboBox->GetCurSel();			// 0 - input, 1 - output

	BOOL bOutput = (nSel == 0 ? FALSE : TRUE);

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_IO0_STATUS + nPinIndex);
	if (bOutput == FALSE)
	{
		pComboBox->EnableWindow(FALSE);
		return;
	}

	nSel = pComboBox->GetCurSel();			// 0 - low, 1 - high

	BOOL    bLevel = (nSel == 0 ? FALSE : TRUE);
	int nRet = SetGpioStatus(nPinIndex, bLevel);
	if (nRet != RET_SUCCESS)     return;
}

// 只对输出引脚有效
int   CKSJDemoVCDlg::SetGpioStatus(int nPinIndex, BOOL  bLevel)			// 1 - 高电平，0 - 低电平
{
	if (m_nDeviceCurSel == -1)    return RET_FAIL;

	BOOL    bOutput = FALSE;
	int nRet = GetGpioDirection(nPinIndex, &bOutput);
	if (nRet != RET_SUCCESS || bOutput != 1)     return RET_FAIL;

	BYTE             btStatus;
	nRet = KSJ_GpioGetStatus(m_nDeviceCurSel, &btStatus);
	if (nRet != RET_SUCCESS)                return RET_FAIL;

	BYTE   btMask = (0x01 << nPinIndex);

	if (bLevel)
		btStatus |= btMask;
	else
		btStatus &= ~btMask;

	nRet = KSJ_GpioSetStatus(m_nDeviceCurSel, btStatus);

	return nRet;
}


void CKSJDemoVCDlg::OnBnClickedCheckReadloop()
{
	if (m_nDeviceCurSel == -1)       return;

	BOOL bChecked = ((CButton*)GetDlgItem(IDC_CHECK_READLOOP))->GetCheck();

	if (bChecked)
		SetTimer(IDT_READLOOP, 10, NULL);
	else
		KillTimer(IDT_READLOOP);
}

// 用户设置IO0为输入还是输出
void CKSJDemoVCDlg::OnCbnSelchangeComboIo0Direction()
{
	SetGpioDirection(0);
	int nSupport;
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_SNAP_BUTTON, &nSupport);
	((CButton*)GetDlgItem(IDC_CHECK_SNAP_STARTDETECT))->EnableWindow(nSupport == 1 ? TRUE : FALSE);

}


void CKSJDemoVCDlg::OnCbnSelchangeComboIo1Direction()
{
	SetGpioDirection(1);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo2Direction()
{
	SetGpioDirection(2);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo3Direction()
{
	SetGpioDirection(3);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo4Direction()
{
	SetGpioDirection(4);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo5Direction()
{
	SetGpioDirection(5);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo6Direction()
{
	SetGpioDirection(6);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo7Direction()
{
	SetGpioDirection(7);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo0Status()
{
	SetGpioStatus(0);

}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo1Status()
{
	SetGpioStatus(1);

}
void CKSJDemoVCDlg::OnCbnSelchangeComboIo2Status()
{
	SetGpioStatus(2);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo3Status()
{
	SetGpioStatus(3);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo4Status()
{
	SetGpioStatus(4);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo5Status()
{
	SetGpioStatus(5);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo6Status()
{
	SetGpioStatus(6);
}

void CKSJDemoVCDlg::OnCbnSelchangeComboIo7Status()
{
	SetGpioStatus(7);
}

void CKSJDemoVCDlg::OnBnClickedCheckSnapStartdetect()
{
	if (m_nDeviceCurSel == -1)       return;

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_SNAP_STARTDETECT))->GetCheck();

	if (bCheck)
		((CButton*)GetDlgItem(IDC_CHECK_SNAP_STARTDETECT))->SetWindowText(_T("Detecting..."));
	else
		((CButton*)GetDlgItem(IDC_CHECK_SNAP_STARTDETECT))->SetWindowText(_T("Start Detecting"));

	StartSnapDetect(bCheck);
}

int    CKSJDemoVCDlg::StartSnapDetect(BOOL bStart)				// 启动Snap按键检测
{
	if (bStart)
	{
		if (m_nSnapDetectInterval <= 0)    return -1;

		KSJ_SnapButtonStatus(m_nDeviceCurSel, &m_CurSnapButtonStatus);
		m_PrvSnapButtonStatus = m_CurSnapButtonStatus;

		SetTimer(ID_TIMER_SNAP_INTERVAL, m_nSnapDetectInterval, NULL);

		m_bSnapDetectStart = TRUE;
	}
	else
	{
		KillTimer(ID_TIMER_SNAP_INTERVAL);

		m_bSnapDetectStart = FALSE;
	}
	return RET_SUCCESS;
}


void CKSJDemoVCDlg::OnCbnSelchangeComboSnapCondition()
{
	if (m_nDeviceCurSel == -1)       return;

	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_SNAP_CONDITION);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	m_nSnapConditionIndex = nIndex;
}


void CKSJDemoVCDlg::OnEnChangeEditFilter()
{
	if (m_nDeviceCurSel == -1)       return;

	m_wIoFilter = GetDlgItemInt(IDC_EDIT_FILTER);
	KSJ_GpioFilterSet(m_nDeviceCurSel, m_wIoFilter);
}


void CKSJDemoVCDlg::OnCbnSelchangeComboTimeout()
{
	if (m_nDeviceCurSel == -1)    return;

	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TIMEOUT);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	KSJ_CaptureSetTimeOut(m_nDeviceCurSel, g_nTimeOut[nIndex]);
}


void CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMode()
{
	if (m_nDeviceCurSel == -1)    return;
	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_MODE);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	int nRet = KSJ_TriggerModeSet(m_nDeviceCurSel, (KSJ_TRIGGERMODE)nIndex);
	ShowErrorInfo(nRet);
}


void CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMethod()
{
	if (m_nDeviceCurSel == -1)    return;

	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_METHOD);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	int nRet = KSJ_TriggerMethodSet(m_nDeviceCurSel, (KSJ_TRIGGERMETHOD)nIndex);
	ShowErrorInfo(nRet);

	KSJ_TRIGGERMETHOD    TriggerMethod;
	nRet = KSJ_TriggerMethodGet(m_nDeviceCurSel, &TriggerMethod);

	pComboBox->SetCurSel((int)TriggerMethod);
}
