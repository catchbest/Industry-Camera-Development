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
	ON_MESSAGE(WM_SHOW_ERROR_INFO, MsgShowErrorInfo)
	
	ON_BN_CLICKED(IDC_CHECK_CAPTURE, &CKSJDemoVCDlg::OnBnClickedCheckCapture)
	ON_CBN_SELCHANGE(IDC_COMBO_DEVICE_LIST, &CKSJDemoVCDlg::OnCbnSelchangeComboDeviceList)
	ON_EN_CHANGE(IDC_EDIT_EXPOSURE_LINES, &CKSJDemoVCDlg::OnEnChangeEditExposureLines)
	ON_EN_CHANGE(IDC_EDIT_GAIN, &CKSJDemoVCDlg::OnEnChangeEditGain)
	ON_BN_CLICKED(IDC_BUTTON_PREVIEW_FOV_SET, &CKSJDemoVCDlg::OnBnClickedButtonPreviewFovSet)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE_FOV_SET, &CKSJDemoVCDlg::OnBnClickedButtonCaptureFovSet)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_MODE, &CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMode)
	ON_CBN_SELCHANGE(IDC_COMBO_TRIGGER_METHOD, &CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMethod)
	ON_EN_CHANGE(IDC_EDIT_TRIGGER_DELAY, &CKSJDemoVCDlg::OnEnChangeEditTriggerDelay)
	ON_EN_CHANGE(IDC_EDIT_FIXED_FRAME_RATE_HW, &CKSJDemoVCDlg::OnEnChangeEditFixedFrameRateHw)
	ON_BN_CLICKED(IDC_CHECK_GET_FRAME_BUFFER_STATUS, &CKSJDemoVCDlg::OnBnClickedCheckGetFrameBufferStatus)
	ON_BN_CLICKED(IDC_BUTTON_EMPTY_FRAME_BUFFER, &CKSJDemoVCDlg::OnBnClickedButtonEmptyFrameBuffer)
	ON_CBN_SELCHANGE(IDC_COMBO_TIMEOUT, &CKSJDemoVCDlg::OnCbnSelchangeComboTimeout)
	ON_BN_CLICKED(IDC_CHECK_RECOVER, &CKSJDemoVCDlg::OnBnClickedCheckRecover)
	ON_BN_CLICKED(IDC_BUTTON_RESET_DEVICE, &CKSJDemoVCDlg::OnBnClickedButtonResetDevice)
	ON_BN_CLICKED(IDC_BUTTON_SEND_PKT_END, &CKSJDemoVCDlg::OnBnClickedButtonSendPktEnd)
	ON_BN_CLICKED(IDC_BUTTON_RECONNECT, &CKSJDemoVCDlg::OnBnClickedButtonReconnect)
	ON_BN_CLICKED(IDC_CHECK_INVERT, &CKSJDemoVCDlg::OnBnClickedCheckInvert)
	ON_BN_CLICKED(IDC_CHECK_FLASH_ENABLE, &CKSJDemoVCDlg::OnBnClickedCheckFlashEnable)
	ON_EN_CHANGE(IDC_EDIT_SEGINDEX, &CKSJDemoVCDlg::OnEnChangeEditSegindex)
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

//-----------------------------------------------------------------------------
// 函数：OnDestroy
// 功能：退出对话框调用程序
// 参数：无
// 返回：无
// 说明：可以在函数内进行释放资源
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	int nRet = KSJ_UnInit();
}

//-----------------------------------------------------------------------------
// 函数：ShowErrorInfo
// 功能：在界面上打印执行结果
// 参数：
//       nRet： 输入，ksjapi函数返回值
// 返回：无
// 说明：调用ksjapi函数后根据其返回值显示执行结果
//-----------------------------------------------------------------------------
LRESULT CKSJDemoVCDlg::MsgShowErrorInfo(WPARAM wParam, LPARAM lParam)
{
	ShowErrorInfo((int)wParam);
	return 0;
}

//-----------------------------------------------------------------------------
// 函数：ShowErrorInfo
// 功能：在界面上打印执行结果
// 参数：
//       nRet： 输入，ksjapi函数返回值
// 返回：无
// 说明：调用ksjapi函数后根据其返回值显示执行结果
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);

	((CStatic*)GetDlgItem(IDC_STATIC_ERROR_INFO))->SetWindowText(szErrorInfo);
}

//-----------------------------------------------------------------------------
// 函数：OnInitDialog
// 功能：进入对话框时进行初始化
// 参数：无
// 返回：执行是否成功
// 说明：在函数内初始化控件参数
//-----------------------------------------------------------------------------
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
	UpdateInterfaceFlash();
	UpdateInterfaceTriggerMode();
	UpdateInterfaceFunction();
	

	m_bInitial = TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//-----------------------------------------------------------------------------
// 函数：UpdateInterface
// 功能：获取选中相机的数据显示在界面上
// 参数：无
// 返回：无
// 说明：每次更换设备时调用，刷新界面参数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：UpdateDeviceList
// 功能：更新相机设备的列表
// 参数：无
// 返回：无
// 说明：获取相机数量并将每个相机的信息填入combox控件
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：OnCbnSelchangeComboDeviceList
// 功能：下拉框重新选择相机
// 参数：无
// 返回：无
// 说明：在下拉框选中相机，更新相机参数和功能支持列表到界面
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboDeviceList()
{
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_LIST);
	m_nDeviceCurSel = pComboBox->GetCurSel();

	UpdateInterface();
	UpdateInterfaceFlash();
	UpdateInterfaceTriggerMode();
	UpdateInterfaceFunction(); 
	UpdateInterfaceAWAIBA();
}

//-----------------------------------------------------------------------------
// 函数：GetRealExposureTime
// 功能：更新实际曝光时间到界面
// 参数：无
// 返回：无
// 说明：获取实际曝光时间
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	_stprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	((CStatic*)GetDlgItem(IDC_STATIC_EXPOSURE_TIME_REAL))->SetWindowText(szExposureTimeMs);

}

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditExposureTimeMs
// 功能：更新曝光时间
// 参数：无
// 返回：无
// 说明：界面修改曝光时间后调用此函数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditSegindex
// 功能：更新增益通道号
// 参数：无
// 返回：无
// 说明：界面修改增益通道号后调用此函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnEnChangeEditSegindex()
{
	if (m_nDeviceCurSel == -1)   return;
	int nMin = 0;
	int nMax = 0;
	int nCur = 0;

	m_nSegIndex = GetDlgItemInt(IDC_EDIT_SEGINDEX);
	KSJ_AWAIBA_GetGainRange(m_nDeviceCurSel, m_nSegIndex, &nMin, &nMax);
	KSJ_AWAIBA_GetGain(m_nDeviceCurSel, m_nSegIndex, &nCur);

	CSpinButtonCtrl *pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GAIN);
	pSpinCtrl->SetRange32(nMin, nMax);
	pSpinCtrl->SetPos32(nCur);
	TCHAR   szText[64] = { 0 };
	_stprintf_s(szText, _T("%d-%d"), nMin, nMax);
	(GetDlgItem(IDC_STATIC_GAIN_RANGE))->SetWindowText(szText);
}

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditGain
// 功能：更新增益
// 参数：无
// 返回：无
// 说明：界面修改增益后调用此函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnEnChangeEditGain()
{
	if (m_nDeviceCurSel == -1)   return;

	int nGain = GetDlgItemInt(IDC_EDIT_GAIN);
	KSJ_AWAIBA_SetGain(m_nDeviceCurSel, m_nSegIndex, nGain);
}

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditExposureLines
// 功能：更新曝光行
// 参数：无
// 返回：无
// 说明：界面修改曝光行后调用此函数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonPreviewFovSet
// 功能：修改预览视场
// 参数：无
// 返回：无
// 说明：点击预览修改按钮后调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonPreviewFovSet()
{
	unsigned short wMultiFrameNum = GetDlgItemInt(IDC_EDIT_MULTIFRAME);
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

	KSJ_PreviewSetFieldOfViewEx(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode, wMultiFrameNum);
	
	// User may not set FOV correctly, ksjapi will correct it!
	KSJ_PreviewGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &wMultiFrameNum);
	SetDlgItemInt(IDC_EDIT_PREVIEW_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_PREIVEW_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_PREIVEW_ROW_SIZE, nRowSize);
	SetDlgItemInt(IDC_EDIT_MULTIFRAME, wMultiFrameNum);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonCaptureFovSet
// 功能：修改采集视场
// 参数：无
// 返回：无
// 说明：点击采集修改按钮后调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonCaptureFovSet()
{
	unsigned short wMultiFrameNum = GetDlgItemInt(IDC_EDIT_MULTIFRAME2);
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
	KSJ_CaptureSetFieldOfViewEx(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode, wMultiFrameNum);

	KSJ_CaptureGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &wMultiFrameNum);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_START, nColStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_START, nRowStart);
	SetDlgItemInt(IDC_EDIT_CAPTURE_COL_SIZE, nColSize);
	SetDlgItemInt(IDC_EDIT_CAPTURE_ROW_SIZE, nRowSize);
	SetDlgItemInt(IDC_EDIT_MULTIFRAME2, wMultiFrameNum);
}

//-----------------------------------------------------------------------------
// 函数：OnTimer
// 功能：计时器函数
// 参数：无
// 返回：无
// 说明：函数内可以操作计时器显示当前预览帧率以及更新进度条
//-----------------------------------------------------------------------------
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
	else if (nIDEvent == TIMERID_GET_FRAME_BUFFER_STATUS)
	{
		KSJ_TRIGGERSTATUS TriggerStatus = KSJ_NO;
		KSJ_TriggerStatusGet(m_nDeviceCurSel, &TriggerStatus);
		TCHAR   szFrameBufferStatus[32] = { '\0' };
		_stprintf_s(szFrameBufferStatus, _T("Frame Buffer %s Image"), TriggerStatus == KSJ_NO ? _T("No") : _T("Has") );
		((CStatic*)GetDlgItem(IDC_STATIC_FRAME_BUFFER_STATUS))->SetWindowText(szFrameBufferStatus);

	}

	CDialogEx::OnTimer(nIDEvent);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckPreviewstart
// 功能：启动/停止预览
// 参数：无
// 返回：无
// 说明：启动或停止预览时调用此函数
//-----------------------------------------------------------------------------
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

	int nRet;
	if (bCheck)
	{
		nRet = KSJ_PreviewStart(m_nDeviceCurSel, true);
		if (nRet != RET_SUCCESS)
		{
			((CButton*)GetDlgItem(IDC_CHECK_PREVIEWSTART))->SetCheck( FALSE );
		}
	}
	else
	{
		nRet = KSJ_PreviewStart(m_nDeviceCurSel, (bCheck ? true : false));
		if (nRet != RET_SUCCESS)
		{
			((CButton*)GetDlgItem(IDC_CHECK_PREVIEWSTART))->SetCheck(TRUE);
		}
	}

	bCheck = ((CButton*)GetDlgItem(IDC_CHECK_PREVIEWSTART))->GetCheck();
	if (bCheck)
	{
		SetTimer(TIMERID_GET_FRAME_RATE, 1000, NULL);
	}
	else
	{
		KillTimer(TIMERID_GET_FRAME_RATE);
	}
}

//-----------------------------------------------------------------------------
// 函数：MsgCaptureStart
// 功能：启动采集进度条
// 参数：无
// 返回：无
// 说明：应对WM_CAPTURE_START消息的函数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：MsgUpdateSnapStatic
// 功能：采集完成函数，采集成功显示采集图片，失败则显示采集失败
// 参数：无
// 返回：无
// 说明：应对WM_UPDATE_SNAP_STATIC消息的函数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：Capture
// 功能：采集函数
// 参数：无
// 返回：无
// 说明：相机采集函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::Capture()
{
	if (m_nDeviceCurSel == -1)    return;

	int    nCaptureWidth, nCaptureHeight, nCaptureBitCount;
	int    nBitsPerSample;

	int nRet = KSJ_CaptureGetSizeExEx(m_nDeviceCurSel, &nCaptureWidth, &nCaptureHeight, &nCaptureBitCount, &nBitsPerSample);
	// ShowErrorInfo(nRet);
	BYTE    *pImageData = new BYTE[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3) * (nBitsPerSample >> 3)];

	LARGE_INTEGER    counterStart;
	QueryPerformanceCounter(&counterStart);

	PostMessage(WM_CAPTURE_START, NULL, NULL);

	nRet = KSJ_CaptureRgbData(m_nDeviceCurSel, pImageData);
	// ShowErrorInfo(nRet);
	PostMessage(WM_SHOW_ERROR_INFO, nRet, 0);
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

//-----------------------------------------------------------------------------
// 函数：CaptureXX
// 功能：被线程调用的函数，根据是否循环的宏调用采集函数Capture
// 参数：无
// 返回：无
// 说明：采集线程调用的函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::CaptureXX( )
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

//-----------------------------------------------------------------------------
// 函数：CaptureX
// 功能：线程函数，调用对话框的CaptureXX函数进行实现
// 参数：
//       pParam： 输入，对话框句柄
// 返回：无
// 说明：采集线程
//-----------------------------------------------------------------------------
UINT WINAPI CKSJDemoVCDlg::CaptureX(LPVOID pParam)
{
	CKSJDemoVCDlg *pDlg = (CKSJDemoVCDlg*)pParam;
	pDlg->CaptureXX();
	return 0;
}

//-----------------------------------------------------------------------------
// 函数：StartCaptureThread
// 功能：启动\停止线程函数
// 参数：
//       bStart： 输入，TRUE启动线程，FALSE停止线程
// 返回：无
// 说明：启动或停止线程，且通过操作事件退出线程
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckCapture
// 功能：相机采集函数，根据宏定义选择启动线程或者只进行一次采集
// 参数：无
// 返回：无
// 说明：点击界面的采集按钮调用此函数
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：UpdateInterfaceTriggerMode
// 功能：更新触发模式相关的参数显示到界面
// 参数：无
// 返回：无
// 说明：每次更换设备时调用，刷新触发模式参数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::UpdateInterfaceTriggerMode()
{
	if (m_nDeviceCurSel == -1)    return;

	CComboBox    *pComboBox = NULL;
	int i = 0;
	// Time Out
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TIMEOUT);
	pComboBox->ResetContent();
	for (i = 0; i<sizeof(g_szTimeOut) / sizeof(TCHAR*); i++)
	{
		pComboBox->AddString(g_szTimeOut[i]);
	}
	KSJ_CaptureSetTimeOut(m_nDeviceCurSel, g_nTimeOut[0]);
	pComboBox->SetCurSel(0);

	bool bRecover = false;
	KSJ_CaptureGetRecover(m_nDeviceCurSel, &bRecover);
	((CButton*)GetDlgItem(IDC_CHECK_RECOVER))->SetCheck(bRecover);


	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_MODE);
	pComboBox->ResetContent();

	for (i = 0; i<g_nTriggerMode; i++)
	{
		pComboBox->AddString(g_szTriggerMode[i]);
	}

	KSJ_TRIGGERMODE    TriggerMode = KSJ_TRIGGER_SOFTWARE;
	KSJ_TriggerModeSet(m_nDeviceCurSel, TriggerMode);
	//int nRet = KSJ_TriggerModeGet(m_nDeviceCurSel, &TriggerMode);

	pComboBox->SetCurSel((int)TriggerMode);

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_METHOD);
	pComboBox->ResetContent();

	for (i = 0; i<g_nTriggerMethod; i++)
	{
		pComboBox->AddString(g_szTriggerMethod[i]);
	}

	KSJ_TRIGGERMETHOD    TriggerMethod;
	int nRet = KSJ_TriggerMethodGet(m_nDeviceCurSel, &TriggerMethod);

	pComboBox->SetCurSel((int)TriggerMethod);

	CSpinButtonCtrl * pSpinCtrlTriggerDelay = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_TRIGGER_DELAY);
	pSpinCtrlTriggerDelay->SetBuddy(GetDlgItem(IDC_EDIT_TRIGGER_DELAY));
	pSpinCtrlTriggerDelay->SetBase(10);

	int nMin = 0;
	int nMax = 0;
	int nCur = 0;
	nRet = KSJ_TriggerDelayGetRange(m_nDeviceCurSel, (WORD*)&nMin, (WORD*)&nMax);
	pSpinCtrlTriggerDelay->SetRange32(nMin, nMax);

	TCHAR szText[128] = {'\0'};
	_stprintf_s(szText, _T("%d-%d Step, %d %d Ms"), nMin, nMax, (nMin * 100 / 1000), (nMax * 100 / 1000 ));
	((CStatic*)GetDlgItem(IDC_STATIC_TRIGGER_DELAY_RANGE))->SetWindowText(szText);
	

	nRet = KSJ_TriggerDelayGet(m_nDeviceCurSel, (WORD*)&nCur);
	pSpinCtrlTriggerDelay->SetPos32(nCur);

	CSpinButtonCtrl * pSpinCtrlFixedFrameRateHw = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_FIXED_FRAME_RATE_HW);
	pSpinCtrlFixedFrameRateHw->SetBuddy(GetDlgItem(IDC_EDIT_FIXED_FRAME_RATE_HW));
	pSpinCtrlFixedFrameRateHw->SetBase(10);
	pSpinCtrlFixedFrameRateHw->SetRange32(1, 150);    // Frame Rate is decided by Exposure, aoi, so it's difficult to get range, use can test it.

	float fFixedFrameRate = 0.0f;
	nRet = KSJ_GetFixedFrameRateEx(m_nDeviceCurSel, &fFixedFrameRate );
	pSpinCtrlFixedFrameRateHw->SetPos32((int)fFixedFrameRate);
}

//-----------------------------------------------------------------------------
// 函数：OnCbnSelchangeComboTriggerMode
// 功能：在下拉框重新选择触发模式
// 参数：无
// 返回：无
// 说明：在下拉框选中触发模式，更新相应触发参数到界面
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboTriggerMode()
{
	if (m_nDeviceCurSel == -1)    return;
	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TRIGGER_MODE);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	int nRet = KSJ_TriggerModeSet(m_nDeviceCurSel, (KSJ_TRIGGERMODE)nIndex);
	ShowErrorInfo(nRet);

	KSJ_TRIGGERMODE    TriggerMode;
	nRet = KSJ_TriggerModeGet(m_nDeviceCurSel, &TriggerMode);

	pComboBox->SetCurSel((int)TriggerMode);

	// If Set External Trigger Mode and Not Preview, We call Create Thread for Capture External Trigger Image
	KSJ_PREVIEWSTATUS PreviewStatus;
	nRet = KSJ_PreviewGetStatus(m_nDeviceCurSel, &PreviewStatus);

	if (PreviewStatus == PS_STOP)
	{
		StartCaptureThread(TriggerMode == KSJ_TRIGGER_EXTERNAL ? TRUE : FALSE);

		// If We Start Capture Thread, You should not Clike Start Preview Button!!!!!
		((CButton*)GetDlgItem(IDC_CHECK_PREVIEWSTART))->EnableWindow(TriggerMode == KSJ_TRIGGER_EXTERNAL ? FALSE : TRUE);
	}


}

//-----------------------------------------------------------------------------
// 函数：OnCbnSelchangeComboTriggerMethod
// 功能：在下拉框重新选择触发方法
// 参数：无
// 返回：无
// 说明：在下拉框选中触发方法，更新相应触发参数到界面
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditTriggerDelay
// 功能：获取界面修改的触发延时设置到相机
// 参数：无
// 返回：无
// 说明：修改界面上的触发延时时调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnEnChangeEditTriggerDelay()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue = GetDlgItemInt(IDC_EDIT_TRIGGER_DELAY);
	int nRet = KSJ_TriggerDelaySet(m_nDeviceCurSel, nValue);

	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：OnEnChangeEditFixedFrameRateHw
// 功能：获取界面修改的固定帧率设置到相机
// 参数：无
// 返回：无
// 说明：修改界面上的固定帧率时调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnEnChangeEditFixedFrameRateHw()
{
	if (m_nDeviceCurSel == -1)    return;

	int nValue = GetDlgItemInt(IDC_EDIT_FIXED_FRAME_RATE_HW);
	int nRet = KSJ_SetFixedFrameRateEx(m_nDeviceCurSel, nValue);

	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：UpdateInterfaceFunction
// 功能：显示相机的支持功能列表
// 参数：无
// 返回：无
// 说明：重新选择相机时调用此函数进行更新
//-----------------------------------------------------------------------------
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
	} while (i--);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckGetFrameBufferStatus
// 功能：启动或停止获取帧存状态计时器
// 参数：无
// 返回：无
// 说明：根据界面的按键选择状态判断是否启动计时器
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckGetFrameBufferStatus()
{
	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_GET_FRAME_BUFFER_STATUS))->GetCheck();
	if (bCheck)
	{
		SetTimer(TIMERID_GET_FRAME_BUFFER_STATUS, 1000, NULL);
	}
	else
	{
		KillTimer(TIMERID_GET_FRAME_BUFFER_STATUS);
	}
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonEmptyFrameBuffer
// 功能：清空buffer
// 参数：无
// 返回：无
// 说明：界面点击清空buffer按钮时调用函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonEmptyFrameBuffer()
{
	int nRet = KSJ_EmptyFrameBuffer(m_nDeviceCurSel);
	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：OnCbnSelchangeComboTimeout
// 功能：在下拉框重新选择采集超时时间，设置到相机
// 参数：无
// 返回：无
// 说明：在下拉框选中超时时间时调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboTimeout()
{
	if (m_nDeviceCurSel == -1)    return;

	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TIMEOUT);
	int nIndex = pComboBox->GetCurSel();
	if (nIndex == CB_ERR)    return;

	KSJ_CaptureSetTimeOut(m_nDeviceCurSel, g_nTimeOut[nIndex]);

}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckRecover
// 功能：设置超时后是否恢复设备
// 参数：无
// 返回：无
// 说明：在界面点击Recover时调用函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckRecover()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL bRecover = ((CButton*)GetDlgItem(IDC_CHECK_RECOVER))->GetCheck();

	KSJ_CaptureSetRecover(m_nDeviceCurSel, bRecover == BST_CHECKED ? TRUE : FALSE);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonResetDevice
// 功能：重启选定的相机
// 参数：无
// 返回：无
// 说明：在界面点击重启设备按钮时调用函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonResetDevice()
{
	if (m_nDeviceCurSel == -1)    return;
	int nRet = KSJ_ResetDevice(m_nDeviceCurSel);
	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonSendPktEnd
// 功能：向相机发送结束包命令
// 参数：无
// 返回：无
// 说明：在界面点击发送结束包按钮时调用函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonSendPktEnd()
{
	if (m_nDeviceCurSel == -1)    return;
	int nRet = KSJ_SendPktEnd(m_nDeviceCurSel);
	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedButtonReconnect
// 功能：重新连接相机
// 参数：无
// 返回：无
// 说明：在界面点击重连相机按钮时调用函数
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonReconnect()
{
	if (m_nDeviceCurSel == -1)    return;
	int nRet = KSJ_ReconnectDevice(m_nDeviceCurSel);
	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：UpdateInterfaceFlash
// 功能：更新闪光灯状态
// 参数：无
// 返回：无
// 说明：将当前选择相机的闪光灯状态显示到界面
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::UpdateInterfaceFlash()
{
	if (m_nDeviceCurSel == -1)    return;
	bool bEnable = true;
	bool bInvert = true;
	int nMode = 0;
	//KSJ_FlashControlGet(m_nDeviceCurSel, &bEnable, &bInvert, &nMode);
	KSJ_FlashControlSet(m_nDeviceCurSel, bEnable, bInvert, nMode);
	((CButton*)GetDlgItem(IDC_CHECK_FLASH_ENABLE))->SetCheck(bEnable);
	((CButton*)GetDlgItem(IDC_CHECK_INVERT))->SetCheck(bInvert);
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckInvert
// 功能：设置闪光灯信号翻转状态
// 参数：无
// 返回：无
// 说明：在界面上点击Invert时调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckInvert()
{
	SetFlash();
}

//-----------------------------------------------------------------------------
// 函数：OnBnClickedCheckFlashEnable
// 功能：设置光灯是否使能
// 参数：无
// 返回：无
// 说明：在界面上点击Enable时调用
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckFlashEnable()
{
	SetFlash();
}

//-----------------------------------------------------------------------------
// 函数：SetFlash
// 功能：设置闪光灯状态
// 参数：无
// 返回：无
// 说明：设置闪光灯信号，使能和翻转
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::SetFlash()
{
	BOOL bEnable = ((CButton*)GetDlgItem(IDC_CHECK_FLASH_ENABLE))->GetCheck();
	BOOL bInvert = ((CButton*)GetDlgItem(IDC_CHECK_INVERT))->GetCheck();

	int nRet = KSJ_FlashControlSet(m_nDeviceCurSel, bEnable == BST_CHECKED ? TRUE : FALSE, bInvert == BST_CHECKED ? TRUE : FALSE, 0);
	ShowErrorInfo(nRet);
}

//-----------------------------------------------------------------------------
// 函数：SetFlash
// 功能：设置闪光灯状态
// 参数：无
// 返回：无
// 说明：设置闪光灯信号，使能和翻转
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::UpdateInterfaceAWAIBA()
{
	if (m_nDeviceCurSel == -1)   return;

	bool bUsed;
	KSJ_AWAIBA_IsUsed(m_nDeviceCurSel, &bUsed);

	if (bUsed)
	{
		int nMin = 0;
		int nMax = 0;
		int nCur = 0;

		KSJ_AWAIBA_GetSegmentNum(m_nDeviceCurSel, &nMax);
		CSpinButtonCtrl * pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_SEGINDEX);
		pSpinCtrl->SetRange32(nMin, nMax - 1);
		pSpinCtrl->SetPos32(nCur);
		int nGain = 0;
		KSJ_AWAIBA_GetGainRange(m_nDeviceCurSel, nCur, &nMin, &nMax);
		KSJ_AWAIBA_GetGain(m_nDeviceCurSel, nCur, &nGain);
		pSpinCtrl = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GAIN);
		pSpinCtrl->SetRange32(nMin, nMax);
		pSpinCtrl->SetPos32(nGain);
		TCHAR   szText[64] = { 0 };
		_stprintf_s(szText, _T("%d-%d"), nMin, nMax);
		(GetDlgItem(IDC_STATIC_GAIN_RANGE))->SetWindowText(szText);
		m_nSegIndex = 0;
		SetDlgItemInt(IDC_EDIT_MULTIFRAME, 1);
		SetDlgItemInt(IDC_EDIT_MULTIFRAME2, 1);
	}
	else
	{
		(GetDlgItem(IDC_STATIC_ERROR_INFO))->SetWindowText(_T("Not Awaiba Camera"));
		GetDlgItem(IDC_EDIT_SEGINDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN_SEGINDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_GAIN)->EnableWindow(FALSE);
		GetDlgItem(IDC_SPIN_GAIN)->EnableWindow(FALSE);
	}
}

//-----------------------------------------------------------------------------
// 函数：PreTranslateMessage
// 功能：屏蔽空格和回车键防止退出程序
// 参数：无
// 返回：无
// 说明：接收键盘按钮消息
//-----------------------------------------------------------------------------
BOOL CKSJDemoVCDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg -> message == WM_KEYDOWN &&
		(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN)){
		return TRUE;
	}return CDialog::PreTranslateMessage(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}
