#include "KSJDemoQT_3A.h"
#include "ui_KSJDemoQT_3A.h"

KSJDemoQT_3A::KSJDemoQT_3A(QWidget *parent) :
	QDialog(parent),
	m_bPreview(false),
	m_bAEStart(false),
	m_bAFStart(false),
    ui(new Ui::KSJDemoQT_3A)
{
    ui->setupUi(this);

	KSJ_Init();

	UpdateDeviceList();
	UpdateInterfaceFunction();
	QPalette pal = ui->PreviewButton->palette();
	QBrush brush = pal.background();
	m_col = brush.color();
	for (int i = 0; i < 256; i++)
	{
		m_vcolorTable.append(qRgb(i, i, i));
	}
}

KSJDemoQT_3A::~KSJDemoQT_3A()
{
	KSJ_UnInit();
    delete ui;
}


void KSJDemoQT_3A::on_DEVICE_LIST_ComboBox_currentIndexChanged(int index)
{
	m_nDeviceCurSel = index;
	UpdateInterface();
}

void KSJDemoQT_3A::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	_stprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	ui->EXPOSURE_TIME_REAL_Label->setText(szExposureTimeMs);
}

void KSJDemoQT_3A::on_ExposureTimeSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_3A::on_ExposureLinesSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_3A::on_GainSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_RED, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_GREEN, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_BLUE, arg1);
}

void KSJDemoQT_3A::on_SetPreviewFovButton_clicked()
{
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;
	unsigned short usMultiFrame;
	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;

	nColStart = ui->PreviewColStartSpinBox->value();
	nRowStart = ui->PreviewRowStartSpinBox->value();
	nColSize = ui->PreviewColSizeSpinBox->value();
	nRowSize = ui->PreviewRowSizeSpinBox->value();
	usMultiFrame = ui->PreviewMultiFrameSpinBox->value();

	KSJ_PreviewSetFieldOfViewEx(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode, usMultiFrame);
	KSJ_PreviewGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &usMultiFrame);
	ui->PreviewColStartSpinBox->setValue(nColStart);
	ui->PreviewRowStartSpinBox->setValue(nRowStart);
	ui->PreviewColSizeSpinBox->setValue(nColSize);
	ui->PreviewRowSizeSpinBox->setValue(nRowSize);
	ui->PreviewMultiFrameSpinBox->setValue(usMultiFrame);
}

void KSJDemoQT_3A::on_PreviewButton_clicked()
{
	if (m_nDeviceCurSel == -1)   return;

	HWND   hPreviewWnd = (HWND)ui->PREVIEWWND_Widget->winId();
	int    nPreviewWndWidth = ui->PREVIEWWND_Widget->width();
	int    nPreviewWndHeight = ui->PREVIEWWND_Widget->height();

	KSJ_PreviewSetPos(m_nDeviceCurSel, hPreviewWnd, 0, 0, nPreviewWndWidth, nPreviewWndHeight);
	QPalette pal = ui->PreviewButton->palette();
	if (m_bPreview)
	{
		m_bPreview = false;
		pal.setColor(QPalette::Button, m_col);
	}
	else
	{
		m_bPreview = true;
		pal.setColor(QPalette::Button, Qt::blue);
	}

	ui->PreviewButton->setPalette(pal);
	ui->PreviewButton->setAutoFillBackground(true);

	KSJ_PreviewStart(m_nDeviceCurSel, m_bPreview);
}

void KSJDemoQT_3A::on_SetCaptureFovButton_clicked()
{
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;
	unsigned short usMultiFrame;
	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;

	nColStart = ui->CaptureColStartSpinBox->value();
	nRowStart = ui->CaptureRowStartSpinBox->value();
	nColSize = ui->CaptureColSizeSpinBox->value();
	nRowSize = ui->CaptureRowSizeSpinBox->value();
	usMultiFrame = ui->CaptureMultiFrameSpinBox->value();

	KSJ_CaptureSetFieldOfViewEx(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode, usMultiFrame);
	KSJ_CaptureGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &usMultiFrame);
	ui->CaptureColStartSpinBox->setValue(nColStart);
	ui->CaptureRowStartSpinBox->setValue(nRowStart);
	ui->CaptureColSizeSpinBox->setValue(nColSize);
	ui->CaptureRowSizeSpinBox->setValue(nRowSize);
	ui->CaptureMultiFrameSpinBox->setValue(usMultiFrame);
}

void KSJDemoQT_3A::ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData)
{
	int nPixelBytes = nBitCount >> 3;
	int nWidthBytes = nWidth * nPixelBytes;
	unsigned char *pImageDataTmp;
	for (int i = 0; i < nHeight; i++)
	{
		pImageDataTmp = pData + (nHeight - 1 - i) * nWidthBytes;
		for (int j = 0; j < nWidthBytes; j++)
		{
			*(pConvertData + i * nWidthBytes + j) = *(pImageDataTmp + j);
		}
	}
}

void KSJDemoQT_3A::on_CaptureButton_clicked()
{
	if (m_nDeviceCurSel == -1)   return;
	int   nCaptureWidth = 0, nCaptureHeight = 0, nCaptureBitCount = 8;

	int   nRet = KSJ_CaptureGetSizeEx(m_nDeviceCurSel, &nCaptureWidth, &nCaptureHeight, &nCaptureBitCount);
	ShowErrorInfo(nRet);
	unsigned char *pImageData = new unsigned char[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3)];
	LARGE_INTEGER    counterStart;
	QueryPerformanceCounter(&counterStart);
	nRet = KSJ_CaptureRgbData(m_nDeviceCurSel, pImageData);
	ShowErrorInfo(nRet);

	LARGE_INTEGER    counterEnd;
	QueryPerformanceCounter(&counterEnd);
	LARGE_INTEGER nFreq;
	QueryPerformanceFrequency(&nFreq);
	float fInterval = (float)(counterEnd.QuadPart - counterStart.QuadPart);
	float fElapse = fInterval / (float)nFreq.QuadPart * 1000;    // MS
	TCHAR   szElapseTime[32] = { '\0' };
	_stprintf_s(szElapseTime, _T("Elapse: %0.2fms"), fElapse);
	ui->ELAPSE_TIME_Label->setText(szElapseTime);

	unsigned char* pConvertData = new unsigned char[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3)];
	ConvetData(pImageData, nCaptureWidth, nCaptureHeight, nCaptureBitCount, pConvertData);
	QImage::Format format;
	if (nCaptureBitCount == 24)
	{
		format = QImage::Format_RGB888;
	}
	else
	{
		format = QImage::Format_Indexed8;
	}

	QImage img = QImage(pConvertData, nCaptureWidth, nCaptureHeight, format);  //封装QImage   
	if (nCaptureBitCount == 8) img.setColorTable(m_vcolorTable); //设置颜色表    
	QPixmap pixmap = QPixmap::fromImage(img);
	pixmap = pixmap.scaled(ui->PREVIEWWND_Widget->size());
	ui->PREVIEWWND_Widget->setAutoFillBackground(true);
	QPalette palette;
	palette.setBrush(ui->PREVIEWWND_Widget->backgroundRole(), QBrush(pixmap));
	ui->PREVIEWWND_Widget->setPalette(palette);
	ui->PREVIEWWND_Widget->repaint();
	if (Qt::Checked == ui->SaveCheckBox->checkState())
	{
		KSJ_HelperSaveToBmp(pImageData, nCaptureWidth, nCaptureHeight, nCaptureBitCount, "Capture.bmp");
	}

	delete[] pImageData;
	pImageData = NULL;
}


void KSJDemoQT_3A::UpdateInterfaceFunction()
{
	ui->FunctionTableWidget;

	ui->FunctionTableWidget->setColumnCount(2);
	ui->FunctionTableWidget->setHorizontalHeaderLabels(QStringList() << "Function" << "Support");
	ui->FunctionTableWidget->verticalHeader()->setVisible(false); // 隐藏水平header

	ui->FunctionTableWidget->setColumnWidth(0, 210);
	ui->FunctionTableWidget->setColumnWidth(1, 80);
	ui->FunctionTableWidget->setRowCount(g_nFunction);
	int i = g_nFunction - 1;
	TCHAR szSupport[32] = { 0 };

	do{
		ui->FunctionTableWidget->setItem(i, 0, new QTableWidgetItem(QString(QLatin1String(g_szFunction[i]))));
		int nSupport = 0;
		KSJ_QueryFunction(m_nDeviceCurSel, (KSJ_FUNCTION)i, &nSupport);
		_stprintf_s(szSupport, _T("%d"), nSupport);
		ui->FunctionTableWidget->setItem(i, 1, new QTableWidgetItem(QString(QLatin1String(szSupport))));
	} while (i--);
}


void KSJDemoQT_3A::UpdateInterface()
{
	if (m_nDeviceCurSel == -1)   return;

	// Initial Exposure Time
	int nMin = 0;
	int nMax = 0;
	int nCur = 0;

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_EXPOSURE, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE, &nCur);
	ui->ExposureTimeSpinBox->setRange(nMin, nMax);
	ui->ExposureTimeSpinBox->setValue(nCur);
	TCHAR   szText[64] = { '\0' };
	_stprintf_s(szText, _T("%d-%d ms (%0.2fsec, %0.2fmin)"), nMin, nMax, (float)nMin / 1000.0f, (float)nMax / 60000.0f);
	ui->EXPOSURE_TIME_RANGE_Label->setText(szText);

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nCur);
	ui->ExposureLinesSpinBox->setRange(nMin, nMax);
	ui->ExposureLinesSpinBox->setValue(nCur);
	_stprintf_s(szText, _T("%d-%d Lines"), nMin, nMax);
	ui->EXPOSURE_LINES_RANGE_Label->setText(szText);

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_RED, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_RED, &nCur);
	ui->GainSpinBox->setRange(nMin, nMax);
	ui->GainSpinBox->setValue(nCur);
	_stprintf_s(szText, _T("%d-%d"), nMin, nMax);
	ui->GAIN_RANGE_Label->setText(szText);

	// FOV
	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;
	unsigned short usMultiFrame;
	KSJ_ADDRESSMODE ColAddressMode;
	KSJ_ADDRESSMODE RowAddressMode;
	KSJ_PreviewGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &usMultiFrame);
	// Preview, Capture they are same, so you should get one is ok!
	_stprintf_s(szText, _T("%d-%d"), nColSize, nRowSize);
	ui->FOV_RANGE_Label->setText(szText);

	ui->PreviewColStartSpinBox->setRange(0, nColSize);
	ui->PreviewColStartSpinBox->setValue(nColStart);
	ui->PreviewRowStartSpinBox->setRange(0, nRowSize);
	ui->PreviewRowStartSpinBox->setValue(nRowStart);
	ui->PreviewColSizeSpinBox->setRange(0, nColSize);
	ui->PreviewColSizeSpinBox->setValue(nColSize);
	ui->PreviewRowSizeSpinBox->setRange(0, nRowSize);
	ui->PreviewRowSizeSpinBox->setValue(nRowSize);
	ui->PreviewMultiFrameSpinBox->setRange(1, 20000);
	ui->PreviewMultiFrameSpinBox->setValue(usMultiFrame);

	KSJ_CaptureGetFieldOfViewEx(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode, &usMultiFrame);
	ui->CaptureColStartSpinBox->setRange(0, nColSize);
	ui->CaptureColStartSpinBox->setValue(nColStart);
	ui->CaptureRowStartSpinBox->setRange(0, nRowSize);
	ui->CaptureRowStartSpinBox->setValue(nRowStart);
	ui->CaptureColSizeSpinBox->setRange(0, nColSize);
	ui->CaptureColSizeSpinBox->setValue(nColSize);
	ui->CaptureRowSizeSpinBox->setRange(0, nRowSize);
	ui->CaptureRowSizeSpinBox->setValue(nRowSize);
	ui->CaptureMultiFrameSpinBox->setRange(1, 20000);
	ui->CaptureMultiFrameSpinBox->setValue(usMultiFrame);

	KSJ_CaptureGetDefaultFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	int nSetColStart = (int)(nColStart + nColSize / 4);
	int nSetRowStart = (int)(nRowStart + nRowSize / 4);
	int nSetColSize = nColSize / 2;
	int nSetRowSize = nRowSize / 2;

	KSJ_AESetRegion(m_nDeviceCurSel, nSetColStart, nSetRowStart, nSetColSize, nSetRowSize);
	bool bShow = true;
	KSJ_AEGetRegion(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &bShow);
	ui->AEColStartSpinBox->setRange(0, nColSize);
	ui->AEColStartSpinBox->setValue(nColStart);
	ui->AERowStartSpinBox->setRange(0, nRowSize);
	ui->AERowStartSpinBox->setValue(nRowStart);
	ui->AEColSizeSpinBox->setRange(0, nColSize);
	ui->AEColSizeSpinBox->setValue(nColSize);
	ui->AERowSizeSpinBox->setRange(0, nRowSize);
	ui->AERowSizeSpinBox->setValue(nRowSize);
	ui->MaxCountSpinBox->setValue(20);
	ui->TargetSpinBox->setValue(128);

	KSJ_AFSetRegion(m_nDeviceCurSel, nSetColStart, nSetRowStart, nSetColSize, nSetRowSize);
	ui->AFColStartSpinBox->setRange(0, nColSize);
	ui->AFColStartSpinBox->setValue(nSetColStart);
	ui->AFRowStartSpinBox->setRange(0, nRowSize);
	ui->AFRowStartSpinBox->setValue(nSetRowStart);
	ui->AFColSizeSpinBox->setRange(0, nColSize);
	ui->AFColSizeSpinBox->setValue(nSetColSize);
	ui->AFRowSizeSpinBox->setRange(0, nRowSize);
	ui->AFRowSizeSpinBox->setValue(nSetRowSize);
	ui->AFSpinBox->setValue(0);
}


void KSJDemoQT_3A::UpdateDeviceList()
{
	m_nDeviceNum = KSJ_DeviceGetCount();
	if (m_nDeviceNum == 0)
	{
		return;
	}

	ui->DEVICE_LIST_ComboBox->blockSignals(true);
	for (int i = 0; i < m_nDeviceNum; i++)
	{
		m_DeviceInfo[i].nIndex = i;
		KSJ_DeviceGetInformationEx(i, &(m_DeviceInfo[i].DeviceType), &(m_DeviceInfo[i].nSerials), &(m_DeviceInfo[i].wFirmwareVersion), &(m_DeviceInfo[i].wFpgaVersion));

		unsigned char btMajVersion = (m_DeviceInfo[i].wFirmwareVersion & 0xFF00) >> 8;		// 得到主版本号
		unsigned char btMinVersion = m_DeviceInfo[i].wFirmwareVersion & 0x00FF;				// 得到副版本号

		unsigned char btFpgaMajVersion = (m_DeviceInfo[i].wFpgaVersion & 0xFF00) >> 8;		// 得到主版本号
		unsigned char btFpgaMinVersion = m_DeviceInfo[i].wFpgaVersion & 0x00FF;				// 得到副版本号

		TCHAR  szMenuItem[256] = { '\0' };
		sprintf(szMenuItem, _T("Index(%d)-Type(%s)-Serials(%d)-FwVer(%d.%d)-FpgaVer(%d.%d)"), i, g_szDeviceType[m_DeviceInfo[i].DeviceType], m_DeviceInfo[i].nSerials, btMajVersion, btMinVersion, btFpgaMajVersion, btFpgaMinVersion);
		ui->DEVICE_LIST_ComboBox->addItem(szMenuItem);
	}

	ui->DEVICE_LIST_ComboBox->blockSignals(false);
	on_DEVICE_LIST_ComboBox_currentIndexChanged(0);
}

void KSJDemoQT_3A::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	ui->ERROR_INFO_Label->setText(szErrorInfo);
}

void KSJDemoQT_3A::on_ShowCheckBox_clicked(bool arg1)
{
	if (m_nDeviceCurSel == -1)    return;
	int nRet = KSJ_AEShowRegion(m_nDeviceCurSel, arg1);
	ShowErrorInfo(nRet);
}

void KSJDemoQT_3A::on_AESetRegionButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;

	nColStart = ui->AEColStartSpinBox->value();
	nRowStart = ui->AERowStartSpinBox->value();
	nColSize = ui->AEColSizeSpinBox->value();
	nRowSize = ui->AERowSizeSpinBox->value();

	int nRet;
	nRet = KSJ_AESetRegion(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize);
	ShowErrorInfo(nRet);

	bool bShow;
	nRet = KSJ_AEGetRegion(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &bShow);
	ShowErrorInfo(nRet);
	ui->AFColStartSpinBox->setValue(nColStart);
	ui->AERowStartSpinBox->setValue(nRowStart);
	ui->AEColSizeSpinBox->setValue(nColSize);
	ui->AERowSizeSpinBox->setValue(nRowSize);
	ui->ShowCheckBox->setChecked(bShow);
}

void KSJDemoQT_3A::AeCallback(KSJ_AE_STATUS Status, int nResult)
{
	ui->ExposureTimeSpinBox->setValue(nResult);

	int nExposureLines = 0;
	int nRet = KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nExposureLines);
	KSJ_AEStartEx(m_nDeviceCurSel, false);
	on_AEStartButton_clicked();
}

VOID WINAPI AECALLBACK(KSJ_AE_STATUS Status, int nResult, void *lpContext)
{
	KSJDemoQT_3A *pVCDemoDlg = (KSJDemoQT_3A *)lpContext;
	pVCDemoDlg->AeCallback(Status, nResult);
}

void KSJDemoQT_3A::on_AEStartButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;
	if (m_bAEStart)
	{
		int nMaxCount = ui->MaxCountSpinBox->value();
		int nTarget = ui->TargetSpinBox->value();
		KSJ_AESetMaxCount(m_nDeviceCurSel, nMaxCount);
		KSJ_AESetTarget(m_nDeviceCurSel, nTarget);
	}

	int nRet = KSJ_AESetCallbackEx(m_nDeviceCurSel, AECALLBACK, this);
	ShowErrorInfo(nRet);

	QPalette pal = ui->AEStartButton->palette();
	if (m_bAEStart)
	{
		m_bAEStart = false;
		pal.setColor(QPalette::Button, m_col);
	}
	else
	{
		m_bAEStart = true;
		pal.setColor(QPalette::Button, Qt::blue);
	}

	ui->AEStartButton->setPalette(pal);
	ui->AEStartButton->setAutoFillBackground(true);

	nRet = KSJ_AEStartEx(m_nDeviceCurSel, m_bAEStart);
	ShowErrorInfo(nRet);
}

void KSJDemoQT_3A::on_AFSetRegionButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	int nColStart;
	int nRowStart;
	int nColSize;
	int nRowSize;

	nColStart = ui->AFColStartSpinBox->value();
	nRowStart = ui->AFRowStartSpinBox->value();
	nColSize = ui->AFColSizeSpinBox->value();
	nRowSize = ui->AFRowSizeSpinBox->value();

	int nRet;
	nRet = KSJ_AFSetRegion(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize);
	ShowErrorInfo(nRet);
}

void KSJDemoQT_3A::AfCallback(int nResult)
{
	ui->AFSpinBox->setValue(nResult);
}

VOID WINAPI AFCALLBACK(int nResult, void *lpContext)
{
	KSJDemoQT_3A *pVCDemoDlg = (KSJDemoQT_3A *)lpContext;
	pVCDemoDlg->AfCallback(nResult);
}

void KSJDemoQT_3A::on_AFStartButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	QPalette pal = ui->AFStartButton->palette();
	if (m_bAFStart)
	{
		m_bAFStart = false;
		pal.setColor(QPalette::Button, m_col);
	}
	else
	{
		m_bAFStart = true;
		pal.setColor(QPalette::Button, Qt::blue);
	}

	ui->AFStartButton->setPalette(pal);
	ui->AFStartButton->setAutoFillBackground(true);

	int nRet = KSJ_AFStart(m_nDeviceCurSel, m_bAFStart);
	ShowErrorInfo(nRet);
	if (m_bAFStart)
	{
		nRet = KSJ_AFSetCallback(m_nDeviceCurSel, AFCALLBACK, this);
		ShowErrorInfo(nRet);
	}
	else
	{
		nRet = KSJ_AFSetCallback(m_nDeviceCurSel, NULL, this);
		ShowErrorInfo(nRet);
	}
}