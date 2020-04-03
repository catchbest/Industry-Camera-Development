#include "KSJDemoQT_Base.h"
#include "ui_KSJDemoQT_Base.h"

KSJDemoQT_Base::KSJDemoQT_Base(QWidget *parent) :
    QDialog(parent),
	m_bPreview(false),
    ui(new Ui::KSJDemoQT_Base)
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

KSJDemoQT_Base::~KSJDemoQT_Base()
{
	KSJ_UnInit();
    delete ui;
}


void KSJDemoQT_Base::on_DEVICE_LIST_ComboBox_currentIndexChanged(int index)
{
	m_nDeviceCurSel = index;
	UpdateInterface();
}

void KSJDemoQT_Base::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	sprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	ui->EXPOSURE_TIME_REAL_Label->setText(szExposureTimeMs);
}

void KSJDemoQT_Base::on_ExposureTimeSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Base::on_ExposureLinesSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Base::on_GainSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_RED, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_GREEN, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_BLUE, arg1);
}

void KSJDemoQT_Base::on_SetPreviewFovButton_clicked()
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

void KSJDemoQT_Base::on_PreviewButton_clicked()
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

void KSJDemoQT_Base::on_SetCaptureFovButton_clicked()
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

void KSJDemoQT_Base::ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData)
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

void KSJDemoQT_Base::on_CaptureButton_clicked()
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
	sprintf_s(szElapseTime, _T("Elapse: %0.2fms"), fElapse);
	ui->ELAPSE_TIME_Label->setText(szElapseTime);

	unsigned char* pConvertData = new unsigned char[nCaptureWidth * nCaptureHeight * (nCaptureBitCount >> 3)];
	ConvetData(pImageData, nCaptureWidth, nCaptureHeight, nCaptureBitCount, pConvertData);
	QImage::Format format;
	if (nCaptureBitCount == 24)
	{
		format = QImage::Format_BGR30;
	}
	else
	{
		format = QImage::Format_Indexed8;
	}

	QImage img = QImage(pConvertData, nCaptureWidth, nCaptureHeight, format);  //��װQImage   
	if (nCaptureBitCount == 8) img.setColorTable(m_vcolorTable); //������ɫ��    
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


void KSJDemoQT_Base::UpdateInterfaceFunction()
{
	ui->FunctionTableWidget;

	ui->FunctionTableWidget->setColumnCount(2);
	ui->FunctionTableWidget->setHorizontalHeaderLabels(QStringList() << "Function" << "Support");
	ui->FunctionTableWidget->verticalHeader()->setVisible(false); // ����ˮƽheader

	ui->FunctionTableWidget->setColumnWidth(0, 210);
	ui->FunctionTableWidget->setColumnWidth(1, 80);
	ui->FunctionTableWidget->setRowCount(g_nFunction);
	int i = g_nFunction - 1;
	TCHAR szSupport[32] = { 0 };

	do{
		ui->FunctionTableWidget->setItem(i, 0, new QTableWidgetItem(QString(QLatin1String(g_szFunction[i]))));
		int nSupport = 0;
		KSJ_QueryFunction(m_nDeviceCurSel, (KSJ_FUNCTION)i, &nSupport);
		sprintf_s(szSupport, _T("%d"), nSupport);
		ui->FunctionTableWidget->setItem(i, 1, new QTableWidgetItem(QString(QLatin1String(szSupport))));
	} while (i--);
}


void KSJDemoQT_Base::UpdateInterface()
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
	sprintf_s(szText, _T("%d-%d ms (%0.2fsec, %0.2fmin)"), nMin, nMax, (float)nMin / 1000.0f, (float)nMax / 60000.0f);
	ui->EXPOSURE_TIME_RANGE_Label->setText(szText);

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &nCur);
	ui->ExposureLinesSpinBox->setRange(nMin, nMax);
	ui->ExposureLinesSpinBox->setValue(nCur);
	sprintf_s(szText, _T("%d-%d Lines"), nMin, nMax);
	ui->EXPOSURE_LINES_RANGE_Label->setText(szText);

	KSJ_GetParamRange(m_nDeviceCurSel, KSJ_RED, &nMin, &nMax);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_RED, &nCur);
	ui->GainSpinBox->setRange(nMin, nMax);
	ui->GainSpinBox->setValue(nCur);
	sprintf_s(szText, _T("%d-%d"), nMin, nMax);
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
	sprintf_s(szText, _T("%d-%d"), nColSize, nRowSize);
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
}


void KSJDemoQT_Base::UpdateDeviceList()
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

		unsigned char btMajVersion = (m_DeviceInfo[i].wFirmwareVersion & 0xFF00) >> 8;		// �õ����汾��
		unsigned char btMinVersion = m_DeviceInfo[i].wFirmwareVersion & 0x00FF;				// �õ����汾��

		unsigned char btFpgaMajVersion = (m_DeviceInfo[i].wFpgaVersion & 0xFF00) >> 8;		// �õ����汾��
		unsigned char btFpgaMinVersion = m_DeviceInfo[i].wFpgaVersion & 0x00FF;				// �õ����汾��

		TCHAR  szMenuItem[256] = { '\0' };
		sprintf(szMenuItem, _T("Index(%d)-Type(%s)-Serials(%d)-FwVer(%d.%d)-FpgaVer(%d.%d)"), i, g_szDeviceType[m_DeviceInfo[i].DeviceType], m_DeviceInfo[i].nSerials, btMajVersion, btMinVersion, btFpgaMajVersion, btFpgaMinVersion);
		ui->DEVICE_LIST_ComboBox->addItem(szMenuItem);
	}

	ui->DEVICE_LIST_ComboBox->blockSignals(false);
	on_DEVICE_LIST_ComboBox_currentIndexChanged(0);
}

void KSJDemoQT_Base::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	ui->ERROR_INFO_Label->setText(szErrorInfo);
}
