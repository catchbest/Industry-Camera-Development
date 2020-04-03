#include "KSJDemoQT_Image.h"
#include "ui_KSJDemoQT_Image.h"

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

KSJDemoQT_Image::KSJDemoQT_Image(QWidget *parent) :
    QDialog(parent),
	m_bPreview(false),
    ui(new Ui::KSJDemoQT_Image)
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

KSJDemoQT_Image::~KSJDemoQT_Image()
{
	KSJ_UnInit();
    delete ui;
}


void KSJDemoQT_Image::on_DEVICE_LIST_ComboBox_currentIndexChanged(int index)
{
	m_nDeviceCurSel = index;
	UpdateInterface();
	UpdateInterfaceImage();
}

void KSJDemoQT_Image::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	sprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	ui->EXPOSURE_TIME_REAL_Label->setText(szExposureTimeMs);
}

void KSJDemoQT_Image::on_ExposureTimeSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Image::on_ExposureLinesSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Image::on_GainSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_RED, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_GREEN, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_BLUE, arg1);
}

void KSJDemoQT_Image::on_SetPreviewFovButton_clicked()
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

void KSJDemoQT_Image::on_PreviewButton_clicked()
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

void KSJDemoQT_Image::on_SetCaptureFovButton_clicked()
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

void KSJDemoQT_Image::ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData)
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

void KSJDemoQT_Image::on_CaptureButton_clicked()
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


void KSJDemoQT_Image::UpdateInterfaceFunction()
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
		sprintf_s(szSupport, _T("%d"), nSupport);
		ui->FunctionTableWidget->setItem(i, 1, new QTableWidgetItem(QString(QLatin1String(szSupport))));
	} while (i--);
}


void KSJDemoQT_Image::UpdateInterface()
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

void KSJDemoQT_Image::UpdateInterfaceImage()
{
	if (m_nDeviceCurSel == -1)    return;

	int nSupport = 0;//Bad Pixel Correction
	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_SUPPORT_BAD_PIXEL_CORRECTION, &nSupport);

	if (!nSupport)
	{
		unsigned char btLow;
		unsigned char btHigh;

		KSJ_BadPixelCorrectionGetThreshold(m_nDeviceCurSel, &btLow, &btHigh);
		ui->LowSpinBox->setValue(btLow);
		ui->HighSpinBox->setValue(btHigh);
		ui->ModeComboBox->clear();
		ui->ModeComboBox->addItem(g_szBadPixelThreshold[1]);
		ui->ModeComboBox->setCurrentIndex(0);
		ui->ModeComboBox->setEnabled(false);
		ui->LowSpinBox->setEnabled(true);
		ui->HighSpinBox->setEnabled(true);
	}
	else
	{
		bool		  bEnable;
		KSJ_THRESHOLD Threshold;
		KSJ_BadPixelCorrectionGet(m_nDeviceCurSel, &bEnable, &Threshold);
		ui->EnableCheckBox->setChecked(bEnable);
		ui->ModeComboBox->clear();
		ui->ModeComboBox->blockSignals(true);
		for (int i = 0; i < g_nBadPixelThreshold; i++)
		{
			ui->ModeComboBox->addItem(g_szBadPixelThreshold[g_nBadPixelThreshold - 1 - i]);
		}

		ui->ModeComboBox->blockSignals(false);
		ui->ModeComboBox->setCurrentIndex(Threshold);
		ui->ModeComboBox->setEnabled(true);
		ui->LowSpinBox->setEnabled(false);
		ui->HighSpinBox->setEnabled(false);
	}

	KSJ_QueryFunction(m_nDeviceCurSel, KSJ_PROPERTY_MONO_DEVICE, &nSupport);//Process

	int nMin;
	int nMax;
	int nValue;
	KSJ_ProcessContrastGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_ProcessContrastGet(m_nDeviceCurSel, &nValue);
	ui->ContrastSpinBox->setRange(nMin, nMax);
	ui->ContrastSpinBox->setValue(nValue);

	KSJ_ProcessBrightnessGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_ProcessBrightnessGet(m_nDeviceCurSel, &nValue);
	ui->BrghtnessSpinBox->setRange(nMin, nMax);
	ui->BrghtnessSpinBox->setValue(nValue);

	KSJ_GammaGetRange(m_nDeviceCurSel, &nMin, &nMax);
	KSJ_GammaGetValue(m_nDeviceCurSel, &nValue);
	ui->GammaSpinBox->setRange(nMin, nMax);
	ui->GammaSpinBox->setValue(nValue);

	if (!nSupport)
	{
		KSJ_ProcessSaturationGetRange(m_nDeviceCurSel, &nMin, &nMax);
		KSJ_ProcessSaturationGet(m_nDeviceCurSel, &nValue);
		ui->SaturationSpinBox->setRange(nMin, nMax);
		ui->SaturationSpinBox->setValue(nValue);
	}
	else
	{
		ui->SaturationSpinBox->setEnabled(false);
	}

	if (!nSupport)//Hue Saturation
	{
		int nHue;
		int nSaturation;
		int nLightness;
		KSJ_HueSaturationGet(m_nDeviceCurSel, KSJ_ALL_HUES, &nHue, &nSaturation, &nLightness);
		ui->HueSpinBox->setRange(-180, 180);
		ui->HueSpinBox->setValue(nHue);
		ui->HueSaturationSpinBox->setRange(-100, 100);
		ui->HueSaturationSpinBox->setValue(nSaturation);
		ui->LightnessSpinBox->setRange(-100, 100);
		ui->LightnessSpinBox->setValue(nLightness);

		ui->HueComboBox->clear();
		ui->HueComboBox->blockSignals(true);
		for (int i = 0; i < g_nHueRange; i++)
		{
			ui->HueComboBox->addItem(g_szHueRange[i]);
		}

		ui->HueComboBox->blockSignals(false);
		ui->HueComboBox->setCurrentIndex(0);
		ui->HueSpinBox->setEnabled(true);
		ui->LightnessSpinBox->setEnabled(true);
		ui->HueSaturationSpinBox->setEnabled(true);
		ui->HueEnableCheckBox->setEnabled(true);
		ui->HueResetButton->setEnabled(true);
		ui->HueComboBox->setEnabled(true);
		ui->HueSetButton->setEnabled(true);
	}
	else
	{
		ui->HueSpinBox->setEnabled(false);
		ui->LightnessSpinBox->setEnabled(false);
		ui->HueSaturationSpinBox->setEnabled(false);
		ui->HueEnableCheckBox->setEnabled(false);
		ui->HueResetButton->setEnabled(false);
		ui->HueComboBox->setEnabled(false);
		ui->HueSetButton->setEnabled(false);
	}
}


void KSJDemoQT_Image::UpdateDeviceList()
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

void KSJDemoQT_Image::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	ui->ERROR_INFO_Label->setText(szErrorInfo);
}

void KSJDemoQT_Image::SetThreshold()
{
	if (m_nDeviceCurSel == -1)    return;

	unsigned char btLow;
	unsigned char btHigh;
	btLow = ui->LowSpinBox->value();
	btHigh = ui->HighSpinBox->value();
	KSJ_BadPixelCorrectionSetThreshold(m_nDeviceCurSel, btLow, btHigh);
}

void KSJDemoQT_Image::on_LowSpinBox_valueChanged(int arg1)
{
	SetThreshold();
}

void KSJDemoQT_Image::on_HighSpinBox_valueChanged(int arg1)
{
	SetThreshold();
}

void KSJDemoQT_Image::SetBadpixelCorrection()
{
	if (m_nDeviceCurSel == -1)    return;

	bool		  bEnable;
	KSJ_THRESHOLD Threshold;
	
	Threshold = (KSJ_THRESHOLD)ui->ModeComboBox->currentIndex();
	bEnable = ui->EnableCheckBox->isChecked();
	KSJ_BadPixelCorrectionSet(m_nDeviceCurSel, bEnable, Threshold);
}

void KSJDemoQT_Image::on_EnableCheckBox_clicked()
{
	SetBadpixelCorrection();
}

void KSJDemoQT_Image::on_ModeComboBox_currentIndexChanged()
{
	SetBadpixelCorrection();
}

void KSJDemoQT_Image::on_ContrastSpinBox_valueChanged(int arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_ProcessContrastSet(m_nDeviceCurSel, arg1);
}

void KSJDemoQT_Image::on_SaturationSpinBox_valueChanged(int arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_ProcessSaturationSet(m_nDeviceCurSel, arg1);
}

void KSJDemoQT_Image::on_BrghtnessSpinBox_valueChanged(int arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_ProcessBrightnessSet(m_nDeviceCurSel, arg1);
}

void KSJDemoQT_Image::on_GammaSpinBox_valueChanged(int arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_GammaSetValue(m_nDeviceCurSel, arg1);
}

void KSJDemoQT_Image::on_ProcessResetButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	bool bEnable = ui->EnableCheckBox->isChecked();
	if (bEnable)
	{
		ui->SaturationSpinBox->setValue(0);
		KSJ_ProcessSaturationSet(m_nDeviceCurSel, 0);
	}

	ui->ContrastSpinBox->setValue(0);
	KSJ_ProcessContrastSet(m_nDeviceCurSel, 0);
	ui->BrghtnessSpinBox->setValue(0);
	KSJ_ProcessBrightnessSet(m_nDeviceCurSel, 0);
	ui->GammaSpinBox->setValue(0);
	KSJ_GammaSetValue(m_nDeviceCurSel, 0);
}

void KSJDemoQT_Image::on_HueEnableCheckBox_clicked(bool arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	bool bCheck = ui->HueEnableCheckBox->isChecked();
	KSJ_HueSaturationSetEnable(m_nDeviceCurSel, bCheck);
}

void KSJDemoQT_Image::on_HueResetButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	for (int i = 0; i < g_nHueRange; i++)
	{
		KSJ_HueSaturationSet(m_nDeviceCurSel, KSJHueRange(i), 0, 0, 0);
	}

	ui->HueSpinBox->setValue(0);
	ui->LightnessSpinBox->setValue(0);
	ui->HueSaturationSpinBox->setValue(0);

	ui->HueComboBox->setCurrentIndex(0);
}

void KSJDemoQT_Image::on_HueSetButton_clicked()
{
	if (m_nDeviceCurSel == -1)    return;

	int nHue = ui->HueSpinBox->value();
	int nSaturation = ui->HueSaturationSpinBox->value();
	int nLightness = ui->LightnessSpinBox->value();

	KSJHueRange HueRange = (KSJHueRange)ui->HueComboBox->currentIndex();
	KSJ_HueSaturationSet(m_nDeviceCurSel, HueRange, nHue, nSaturation, nLightness);
}

void KSJDemoQT_Image::on_HueComboBox_currentIndexChanged(int index)
{
	if (m_nDeviceCurSel == -1)    return;

	int nHue;
	int nSaturation;
	int nLightness;
	KSJHueRange HueRange = (KSJHueRange)index;
	KSJ_HueSaturationGet(m_nDeviceCurSel, HueRange, &nHue, &nSaturation, &nLightness);
	ui->HueSpinBox->setValue(nHue);
	ui->LightnessSpinBox->setValue(nLightness);
	ui->HueSaturationSpinBox->setValue(nSaturation);
}


