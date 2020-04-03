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
	DDX_Control(pDX, IDC_STATIC_LUT, m_LutStatic);
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
	ON_BN_CLICKED(IDC_BUTTON_LUT_RESET, &CKSJDemoVCDlg::OnBnClickedLutReset)
	ON_CBN_SELCHANGE(IDC_COMBO_LUT_TYPE, &CKSJDemoVCDlg::OnCbnSelchangeComboLutType)
	ON_BN_CLICKED(IDC_BUTTON_SAVEFILE, &CKSJDemoVCDlg::OnBnClickedSavefile)
	ON_BN_CLICKED(IDC_BUTTON_FILE_DOWNLOAD, &CKSJDemoVCDlg::OnBnClickedButtonFileDownload)
	ON_BN_CLICKED(IDC_BUTTON_DATA_DOWNLOAD, &CKSJDemoVCDlg::OnBnClickedButtonDataDownload)
	ON_BN_CLICKED(IDC_CHECK_LUT, &CKSJDemoVCDlg::OnBnClickedCheckLut)
	ON_BN_CLICKED(IDC_CHECK_GAMMA_LUT, &CKSJDemoVCDlg::OnBnClickedCheckGammaLut)
	ON_CBN_SELCHANGE(IDC_COMBO_DEVICE_SENSITIVITY_MODE, &CKSJDemoVCDlg::OnCbnSelchangeComboDeviceSensitivityMode)
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
	m_hKSJTableMaker = NULL;
}

//-----------------------------------------------------------------------------
// ������OnDestroy
// ���ܣ��˳��Ի�����ó���
// ��������
// ���أ���
// ˵���������ں����ڽ����ͷ���Դ
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	int nRet = KSJ_UnInit();
	if (m_LutStatic.m_hKSJTableMaker != NULL)
	{
		KSJTableMaker_UnInit(&m_LutStatic.m_hKSJTableMaker);
		m_LutStatic.m_hKSJTableMaker = NULL;
		m_hKSJTableMaker = NULL;
	}
}

//-----------------------------------------------------------------------------
// ������ShowErrorInfo
// ���ܣ��ڽ����ϴ�ӡִ�н��
// ������
//       nRet�� ���룬ksjapi��������ֵ
// ���أ���
// ˵��������ksjapi����������䷵��ֵ��ʾִ�н��
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	((CStatic*)GetDlgItem(IDC_STATIC_ERROR_INFO))->SetWindowText(szErrorInfo);
}

//-----------------------------------------------------------------------------
// ������OnInitDialog
// ���ܣ�����Ի���ʱ���г�ʼ��
// ��������
// ���أ�ִ���Ƿ�ɹ�
// ˵�����ں����ڳ�ʼ���ؼ�����
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
	KSJTableMaker_Init(&m_hKSJTableMaker, m_LutStatic.m_hWnd);
	m_bInitial = TRUE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//-----------------------------------------------------------------------------
// ������UpdateInterface
// ���ܣ���ȡѡ�������������ʾ�ڽ�����
// ��������
// ���أ���
// ˵����ÿ�θ����豸ʱ���ã�ˢ�½������
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

//-----------------------------------------------------------------------------
// ������UpdateDeviceList
// ���ܣ���������豸���б�
// ��������
// ���أ���
// ˵������ȡ�����������ÿ���������Ϣ����combox�ؼ�
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

		BYTE btMajVersion = (m_DeviceInfo[i].wFirmwareVersion & 0xFF00) >> 8;		// �õ����汾��
		BYTE btMinVersion = m_DeviceInfo[i].wFirmwareVersion & 0x00FF;				// �õ����汾��

		BYTE btFpgaMajVersion = (m_DeviceInfo[i].wFpgaVersion & 0xFF00) >> 8;		// �õ����汾��
		BYTE btFpgaMinVersion = m_DeviceInfo[i].wFpgaVersion & 0x00FF;				// �õ����汾��

		TCHAR  szMenuItem[256] = { '\0' };
		_stprintf_s(szMenuItem, _T("Index(%d)-Type(%s)-Serials(%d)-FwVer(%d.%d)-FpgaVer(%d.%d)"), i, g_szDeviceType[m_DeviceInfo[i].DeviceType], m_DeviceInfo[i].nSerials, btMajVersion, btMinVersion, btFpgaMajVersion, btFpgaMinVersion);
		pComboBox->AddString(szMenuItem);
	}

	pComboBox->SetCurSel(m_nDeviceCurSel);
}

//-----------------------------------------------------------------------------
// ������OnCbnSelchangeComboDeviceList
// ���ܣ�����������ѡ�����
// ��������
// ���أ���
// ˵������������ѡ�������������������͹���֧���б�����
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboDeviceList()
{
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_LIST);
	m_nDeviceCurSel = pComboBox->GetCurSel();

	UpdateInterface();
	UpdateInterfaceFunction();
	UpdateInterfaceCompanding();
}

//-----------------------------------------------------------------------------
// ������GetRealExposureTime
// ���ܣ�����ʵ���ع�ʱ�䵽����
// ��������
// ���أ���
// ˵������ȡʵ���ع�ʱ��
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
// ������OnEnChangeEditExposureTimeMs
// ���ܣ������ع�ʱ��
// ��������
// ���أ���
// ˵���������޸��ع�ʱ�����ô˺���
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
// ������OnEnChangeEditGain
// ���ܣ���������
// ��������
// ���أ���
// ˵���������޸��������ô˺���
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// ������OnEnChangeEditExposureLines
// ���ܣ������ع���
// ��������
// ���أ���
// ˵���������޸��ع��к���ô˺���
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
// ������OnBnClickedButtonPreviewFovSet
// ���ܣ��޸�Ԥ���ӳ�
// ��������
// ���أ���
// ˵�������Ԥ���޸İ�ť�����
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// ������OnBnClickedButtonCaptureFovSet
// ���ܣ��޸Ĳɼ��ӳ�
// ��������
// ���أ���
// ˵��������ɼ��޸İ�ť�����
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// ������OnTimer
// ���ܣ���ʱ������
// ��������
// ���أ���
// ˵���������ڿ��Բ�����ʱ����ʾ��ǰԤ��֡���Լ����½�����
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

	CDialogEx::OnTimer(nIDEvent);
}

//-----------------------------------------------------------------------------
// ������OnBnClickedCheckPreviewstart
// ���ܣ�����/ֹͣԤ��
// ��������
// ���أ���
// ˵����������ֹͣԤ��ʱ���ô˺���
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

//-----------------------------------------------------------------------------
// ������MsgCaptureStart
// ���ܣ������ɼ�������
// ��������
// ���أ���
// ˵����Ӧ��WM_CAPTURE_START��Ϣ�ĺ���
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
// ������MsgUpdateSnapStatic
// ���ܣ��ɼ���ɺ������ɼ��ɹ���ʾ�ɼ�ͼƬ��ʧ������ʾ�ɼ�ʧ��
// ��������
// ���أ���
// ˵����Ӧ��WM_UPDATE_SNAP_STATIC��Ϣ�ĺ���
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
// ������Capture
// ���ܣ��ɼ�����
// ��������
// ���أ���
// ˵��������ɼ�����
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// ������CaptureXX
// ���ܣ����̵߳��õĺ����������Ƿ�ѭ���ĺ���òɼ�����Capture
// ��������
// ���أ���
// ˵�����ɼ��̵߳��õĺ���
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// ������CaptureX
// ���ܣ��̺߳��������öԻ����CaptureXX��������ʵ��
// ������
//       pParam�� ���룬�Ի�����
// ���أ���
// ˵�����ɼ��߳�
//-----------------------------------------------------------------------------
UINT WINAPI CKSJDemoVCDlg::CaptureX(LPVOID pParam)
{
	CKSJDemoVCDlg *pDlg = (CKSJDemoVCDlg*)pParam;
	pDlg->CaptureXX();
	return 0;
}

//-----------------------------------------------------------------------------
// ������StartCaptureThread
// ���ܣ�����\ֹͣ�̺߳���
// ������
//       bStart�� ���룬TRUE�����̣߳�FALSEֹͣ�߳�
// ���أ���
// ˵����������ֹͣ�̣߳���ͨ�������¼��˳��߳�
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
// ������OnBnClickedCheckCapture
// ���ܣ�����ɼ����������ݺ궨��ѡ�������̻߳���ֻ����һ�βɼ�
// ��������
// ���أ���
// ˵�����������Ĳɼ���ť���ô˺���
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
// ������UpdateInterfaceFunction
// ���ܣ���ʾ�����֧�ֹ����б�
// ��������
// ���أ���
// ˵��������ѡ�����ʱ���ô˺������и���
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
	}while (i--);
}

//-----------------------------------------------------------------------------
// ������UpdateInterfaceCompanding
// ���ܣ���ʾ�����ѹ����ز���
// ��������
// ���أ���
// ˵��������ѡ�����ʱ���ô˺������и���
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::UpdateInterfaceCompanding()
{
	if (m_nDeviceCurSel == -1)    return;

	CComboBox    *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_LUT_TYPE);
	pComboBox->ResetContent();

	BOOL nLutSupport = 0;
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_LUT_ENABLE, &nLutSupport);
	GetDlgItem(IDC_CHECK_LUT)->EnableWindow(nLutSupport ? TRUE : FALSE);
	if (nLutSupport)
	{
		bool bEnable;
		KSJ_LutGetEnable(m_nDeviceCurSel, &bEnable);
		((CButton*)GetDlgItem(IDC_CHECK_LUT))->SetCheck(bEnable);
		pComboBox->AddString(_T("LUT"));
	}

	BOOL nGammaSupport = 0;
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_GAMMA_LUT_ENABLE, &nGammaSupport);
	GetDlgItem(IDC_CHECK_GAMMA_LUT)->EnableWindow(nGammaSupport ? TRUE : FALSE);
	if (nGammaSupport)
	{
		bool bEnable;
		KSJ_GammaLutGetEnable(m_nDeviceCurSel, &bEnable);
		((CButton*)GetDlgItem(IDC_CHECK_GAMMA_LUT))->SetCheck(bEnable);
		pComboBox->AddString(_T("Gamma LUT"));
	}

	pComboBox->SetCurSel(0);
	
	if (nLutSupport || nGammaSupport)
	{
		m_LutStatic.m_hKSJTableMaker = m_hKSJTableMaker;
		if (nLutSupport)
		{
			KSJTableMaker_TableSetType(m_LutStatic.m_hKSJTableMaker, LUT16TO8);

			BOOL nSupport = 0;
			KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_LUT_DOWNLOAD, &nSupport);
			GetDlgItem(IDC_BUTTON_FILE_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
			GetDlgItem(IDC_BUTTON_DATA_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
		}
		else
		{
			KSJTableMaker_TableSetType(m_LutStatic.m_hKSJTableMaker, LUT16TO16);

			BOOL nSupport = 0;
			KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD, &nSupport);
			GetDlgItem(IDC_BUTTON_FILE_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
			GetDlgItem(IDC_BUTTON_DATA_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
		}

		int nAdc;
		KSJ_GetADCResolution(m_nDeviceCurSel, &nAdc);
		KSJTableMaker_TableSetSize(m_LutStatic.m_hKSJTableMaker, nAdc);

		m_LutStatic.Invalidate();
		m_LutStatic.UpdateWindow();
	}
	else
	{
		GetDlgItem(IDC_BUTTON_FILE_DOWNLOAD)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_DATA_DOWNLOAD)->EnableWindow(false); 
		GetDlgItem(IDC_BUTTON_LUT_RESET)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON_SAVEFILE)->EnableWindow(false);
		GetDlgItem(IDC_STATIC_LUT)->EnableWindow(false);
		pComboBox->EnableWindow(false);
	}

	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_SENSITIVITY_MODE);
	pComboBox->ResetContent();

	BOOL nSupport = 0;
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_SENSITIVITY_MODE, &nSupport);
	pComboBox->EnableWindow(nSupport ? TRUE : FALSE);
	if (nSupport)
	{
		for (int i = 0; i < g_nSensitivity; i++)
		{
			pComboBox->AddString(g_szSensitivity[i]);
		}

		KSJ_SENSITIVITYMODE Mode;
		KSJ_SensitivityGetMode(m_nDeviceCurSel, &Mode);
		pComboBox->SetCurSel(Mode);
	}
}

//-----------------------------------------------------------------------------
// ������OnBnClickedLutReset
// ���ܣ���λ����
// ��������
// ���أ���
// ˵������������Lut��λ��ť����
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedLutReset()
{
	if (m_LutStatic.m_hKSJTableMaker == NULL)    return;

	KSJTableMaker_Reset(m_LutStatic.m_hKSJTableMaker);
}

//-----------------------------------------------------------------------------
// ������OnCbnSelchangeComboLutType
// ���ܣ��޸Ĳ��ұ�����
// ��������
// ���أ���
// ˵�����޸Ľ���Ĳ��ұ��������������
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboLutType()
{
	if (m_nDeviceCurSel == -1)    return;
	if (m_LutStatic.m_hKSJTableMaker == NULL)    return;

	CString  szText;
	BOOL	 nSupport = 0;
	CComboBox *pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_LUT_TYPE);
	pComboBox->GetWindowText(szText);
	
	if (szText==_T("LUT"))
	{
		KSJTableMaker_TableSetType(m_LutStatic.m_hKSJTableMaker, LUT16TO8);

		KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_LUT_DOWNLOAD, &nSupport);
		GetDlgItem(IDC_BUTTON_FILE_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
		GetDlgItem(IDC_BUTTON_DATA_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
	}
	else
	{
		KSJTableMaker_TableSetType(m_LutStatic.m_hKSJTableMaker, LUT16TO16);

		KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD, &nSupport);
		GetDlgItem(IDC_BUTTON_FILE_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
		GetDlgItem(IDC_BUTTON_DATA_DOWNLOAD)->EnableWindow(nSupport ? TRUE : FALSE);
	}
}

//-----------------------------------------------------------------------------
// ������OnBnClickedSavefile
// ���ܣ�������ұ��ļ�
// ��������
// ���أ���
// ˵�����������ı�����ұ�ť����
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedSavefile()
{
	if (m_LutStatic.m_hKSJTableMaker == NULL)    return;

	CFileDialog    *pcBrowse;    
	pcBrowse = (CFileDialog*)new CFileDialog(FALSE, _T("ktb"), NULL, NULL, _T("CatchBEST Table Files |*.ktb||"), NULL);
	pcBrowse->DoModal();
	SetWindowText(pcBrowse->GetPathName());
	KSJTableMaker_TableWrite(m_LutStatic.m_hKSJTableMaker, (LPTSTR)(LPCTSTR)(pcBrowse->GetPathName()));

	delete pcBrowse;
}

//-----------------------------------------------------------------------------
// ������OnBnClickedButtonFileDownload
// ���ܣ�ѡ���ļ���ʽ������LUT���ұ������
// ��������
// ���أ���
// ˵�������������ļ����ز��ұ��ť����
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonFileDownload()
{
	if (m_nDeviceCurSel == -1)    return;

	CFileDialog    *pcBrowse;
	pcBrowse = (CFileDialog*)new CFileDialog(TRUE, _T("ktb"), NULL, NULL, _T("CatchBEST Table Files |*.ktb||"), NULL);
	pcBrowse->DoModal();
	SetWindowText(pcBrowse->GetPathName());


	KSJTABLEMAKER_TABLE_TYPE TableType;
	KSJTableMaker_TableGetType(m_LutStatic.m_hKSJTableMaker, &TableType);
	if (TableType == LUT16TO8)
	{
		KSJ_LutFileDownload(m_nDeviceCurSel, (LPTSTR)(LPCTSTR)(pcBrowse->GetPathName()));
	}
	else
	{
		KSJ_GammaLutFileDownload(m_nDeviceCurSel, (LPTSTR)(LPCTSTR)(pcBrowse->GetPathName()));
	}
}

//-----------------------------------------------------------------------------
// ������OnBnClickedButtonDataDownload
// ���ܣ������û��Զ����LUT���ұ�����
// ��������
// ���أ���
// ˵�������������������ز��ұ��ť����
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedButtonDataDownload()
{
	if (m_nDeviceCurSel == -1)    return;
	if (m_LutStatic.m_hKSJTableMaker == NULL)    return;

	int nBits;
	KSJTableMaker_TableGetSize(m_LutStatic.m_hKSJTableMaker, &nBits);
	int nTableSize = (int)pow((float)2, nBits);

	KSJTABLEMAKER_TABLE_TYPE TableType;
	KSJTableMaker_TableGetType(m_LutStatic.m_hKSJTableMaker, &TableType);
	if (TableType == LUT16TO8)
	{
		BYTE *pTableData = new BYTE[nTableSize];
		KSJTableMaker_TableGet(m_LutStatic.m_hKSJTableMaker, pTableData);
		KSJ_LutDataDownload(m_nDeviceCurSel, pTableData, nTableSize);
		delete[] pTableData;
	}
	else
	{
		BYTE *pTableData = new BYTE[nTableSize * 2];
		KSJTableMaker_TableGet(m_LutStatic.m_hKSJTableMaker, pTableData);
		KSJ_GammaLutDataDownload(m_nDeviceCurSel, (unsigned short*)pTableData, nTableSize);
		delete[] pTableData;
	}
}

//-----------------------------------------------------------------------------
// ������OnBnClickedCheckLut
// ���ܣ�ʹ��LUT���ұ���
// ��������
// ���أ���
// ˵������������ʹ�ܲ��ұ�ѡ������
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckLut()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_LUT))->GetCheck();
	KSJ_LutSetEnable(m_nDeviceCurSel, bCheck ? TRUE : FALSE);
}

//-----------------------------------------------------------------------------
// ������OnBnClickedCheckGammaLut
// ���ܣ�ʹ��Gamma LUT���ұ���
// ��������
// ���أ���
// ˵������������ʹ��Gamma���ұ�ѡ������
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnBnClickedCheckGammaLut()
{
	if (m_nDeviceCurSel == -1)    return;

	BOOL bCheck = ((CButton*)GetDlgItem(IDC_CHECK_GAMMA_LUT))->GetCheck();
	KSJ_GammaLutSetEnable(m_nDeviceCurSel, bCheck ? TRUE : FALSE);
}

//-----------------------------------------------------------------------------
// ������OnCbnSelchangeComboDeviceSensitivityMode
// ���ܣ��������ж�����
// ��������
// ���أ���
// ˵���������������ж��������������
//-----------------------------------------------------------------------------
void CKSJDemoVCDlg::OnCbnSelchangeComboDeviceSensitivityMode()
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_SENSITIVITYMODE Mode;
	CComboBox    *pComboBox = NULL;
	pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_SENSITIVITY_MODE);
	Mode = (KSJ_SENSITIVITYMODE)pComboBox->GetCurSel();
	KSJ_SensitivitySetMode(m_nDeviceCurSel, Mode);
}
