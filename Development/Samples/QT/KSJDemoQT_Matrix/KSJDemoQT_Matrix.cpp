#include "KSJDemoQT_Matrix.h"
#include "ui_KSJDemoQT_Matrix.h"

KSJDemoQT_Matrix::KSJDemoQT_Matrix(QWidget *parent) :
    QDialog(parent),
	m_bPreview(false),
    ui(new Ui::KSJDemoQT_Matrix)
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

KSJDemoQT_Matrix::~KSJDemoQT_Matrix()
{
	KSJ_UnInit();
    delete ui;
}


void KSJDemoQT_Matrix::on_DEVICE_LIST_ComboBox_currentIndexChanged(int index)
{
	m_nDeviceCurSel = index;
	UpdateInterface();
	UpdateInterfaceColor();
}

void KSJDemoQT_Matrix::GetRealExposureTime()
{
	float fExposureTimeMs = 0.0f;
	KSJ_ExposureTimeGet(m_nDeviceCurSel, &fExposureTimeMs);

	TCHAR   szExposureTimeMs[32] = { '\0' };
	sprintf_s(szExposureTimeMs, _T("Exp Time: %0.5f ms"), fExposureTimeMs);
	ui->EXPOSURE_TIME_REAL_Label->setText(szExposureTimeMs);
}

void KSJDemoQT_Matrix::on_ExposureTimeSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Matrix::on_ExposureLinesSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, arg1);
	GetRealExposureTime();
}

void KSJDemoQT_Matrix::on_GainSpinBox_valueChanged(int arg1)
{
	KSJ_SetParam(m_nDeviceCurSel, KSJ_RED, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_GREEN, arg1);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_BLUE, arg1);
}

void KSJDemoQT_Matrix::on_SetPreviewFovButton_clicked()
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

void KSJDemoQT_Matrix::on_PreviewButton_clicked()
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

void KSJDemoQT_Matrix::on_SetCaptureFovButton_clicked()
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

void KSJDemoQT_Matrix::ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData)
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

void KSJDemoQT_Matrix::on_CaptureButton_clicked()
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


void KSJDemoQT_Matrix::UpdateInterfaceFunction()
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


void KSJDemoQT_Matrix::UpdateInterface()
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


void KSJDemoQT_Matrix::UpdateDeviceList()
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

void KSJDemoQT_Matrix::ShowErrorInfo(int nRet)
{
	TCHAR szErrorInfo[256] = { '\0' };
	KSJ_GetErrorInfo(nRet, szErrorInfo);
	ui->ERROR_INFO_Label->setText(szErrorInfo);
}


void KSJDemoQT_Matrix::UpdateWbmControls()
{
	float fMatrix[3];
	int nRet = KSJ_WhiteBalanceMatrixGet(m_nDeviceCurSel, fMatrix);

	TCHAR  szMatrix[16] = { '\0' };
	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fMatrix[0]);
	ui->REdit->setText(szMatrix);
	ui->RSlider->setRange(0, (int)(5 * WHITE_BALANCE_RATIO_PRESION));
	ui->RSlider->setValue((int)(fMatrix[0] * WHITE_BALANCE_RATIO_PRESION));


	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fMatrix[1]);
	ui->GEdit->setText(szMatrix);
	ui->GSlider->setRange(0, (int)(5 * WHITE_BALANCE_RATIO_PRESION));
	ui->GSlider->setValue((int)(fMatrix[1] * WHITE_BALANCE_RATIO_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fMatrix[2]);
	ui->BEdit->setText(szMatrix);
	ui->BSlider->setRange(0, (int)(5 * WHITE_BALANCE_RATIO_PRESION));
	ui->BSlider->setValue((int)(fMatrix[1] * WHITE_BALANCE_RATIO_PRESION));
}


void KSJDemoQT_Matrix::UpdateCcmControls()
{
	float fCcmMatrix[3][3];
	int nRet = KSJ_ColorCorrectionMatrixGet(m_nDeviceCurSel, fCcmMatrix);

	TCHAR  szMatrix[16] = { '\0' };
	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[0][0]);
	ui->GEdit00->setText(szMatrix);
	ui->GEdit00->setCursorPosition(1);
	ui->GSlider00->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider00->setValue((int)(fCcmMatrix[0][0] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[0][1]);
	ui->GEdit01->setText(szMatrix);
	ui->GEdit01->setCursorPosition(1);
	ui->GSlider01->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider01->setValue((int)(fCcmMatrix[0][1] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[0][2]);
	ui->GEdit02->setText(szMatrix);
	ui->GEdit02->setCursorPosition(1);
	ui->GSlider02->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider02->setValue((int)(fCcmMatrix[0][2] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[1][0]);
	ui->GEdit10->setText(szMatrix);
	ui->GEdit10->setCursorPosition(1);
	ui->GSlider10->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider10->setValue((int)(fCcmMatrix[1][0] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[1][1]);
	ui->GEdit11->setText(szMatrix);
	ui->GEdit11->setCursorPosition(1);
	ui->GSlider11->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider11->setValue((int)(fCcmMatrix[1][1] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[1][2]);
	ui->GEdit12->setText(szMatrix);
	ui->GEdit12->setCursorPosition(1);
	ui->GSlider12->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider12->setValue((int)(fCcmMatrix[1][2] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[2][0]);
	ui->GEdit20->setText(szMatrix);
	ui->GEdit20->setCursorPosition(1);
	ui->GSlider20->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider20->setValue((int)(fCcmMatrix[2][0] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[2][1]);
	ui->GEdit21->setText(szMatrix);
	ui->GEdit21->setCursorPosition(1);
	ui->GSlider21->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider21->setValue((int)(fCcmMatrix[2][1] * COLOR_CORRECTION_PRESION));

	sprintf_s(szMatrix, WHITE_BALANCE_RATIO_FORMAT, fCcmMatrix[2][2]);
	ui->GEdit22->setText(szMatrix);
	ui->GEdit22->setCursorPosition(1);
	ui->GSlider22->setRange((int)(-COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION), (int)(COLOR_CORRECTION_RANGE * COLOR_CORRECTION_PRESION));
	ui->GSlider22->setValue((int)(fCcmMatrix[2][2] * COLOR_CORRECTION_PRESION));
}


void KSJDemoQT_Matrix::UpdateInterfaceColor()
{
	if (m_nDeviceCurSel == -1)   return;
	int i = 0;
	ui->WBComboBox->clear();
	ui->WBComboBox->blockSignals(true);
	for (i = 0; i < g_nWBMode; i++)
	{
		ui->WBComboBox->addItem(g_szWBMode[i]);
	}
	ui->WBComboBox->blockSignals(false);
	KSJ_WB_MODE WbMode;
	KSJ_WhiteBalanceGet(m_nDeviceCurSel, &WbMode);
	ui->WBComboBox->setCurrentIndex((int)WbMode);

	ui->PresettingComboBox->clear();
	ui->PresettingComboBox->blockSignals(true);
	for (i = 0; i < g_nCCMPresettings; i++)
	{
		ui->PresettingComboBox->addItem(g_szCCMPresettings[i]);
	}

	ui->PresettingComboBox->blockSignals(false);
	KSJ_COLOR_TEMPRATURE ColorTemprature;
	KSJ_ColorCorrectionPresettingGet(m_nDeviceCurSel, &ColorTemprature);
	ui->PresettingComboBox->setCurrentIndex((int)ColorTemprature);

	ui->PhiSpinBox->setRange(-255, 255);
	int nPhi = 0;
	KSJ_WhiteBalanceAutoGet(m_nDeviceCurSel, &nPhi);
	ui->PhiSpinBox->setValue(nPhi);

	UpdateWbmControls();

	///////////////////////////////////////////////////////////////////////////
	ui->CCMComboBox->clear();
	ui->CCMComboBox->blockSignals(true);
	for (i = 0; i < g_nCCMMode; i++)
	{
		ui->CCMComboBox->addItem(g_szCCMMode[i]);
	}

	ui->CCMComboBox->blockSignals(false);
	KSJ_CCM_MODE CcmMode;
	KSJ_ColorCorrectionGet(m_nDeviceCurSel, &CcmMode);
	ui->CCMComboBox->setCurrentIndex((int)CcmMode);


	ui->CCMPresettingComboBox->clear();
	ui->CCMPresettingComboBox->blockSignals(true);
	for (i = 0; i < g_nCCMPresettings; i++)
	{
		ui->CCMPresettingComboBox->addItem(g_szCCMPresettings[i]);
	}
	
	ui->CCMPresettingComboBox->blockSignals(false);
	KSJ_ColorCorrectionPresettingGet(m_nDeviceCurSel, &ColorTemprature);
	ui->CCMPresettingComboBox->setCurrentIndex((int)ColorTemprature);

	UpdateCcmControls();
}

VOID WINAPI WBACALLBACK(float fMatrix[3], void *lpContext)
{
	KSJDemoQT_Matrix *pKSJDemoVCDlg = (KSJDemoQT_Matrix *)lpContext;
	pKSJDemoVCDlg->WBACallback(fMatrix);
}

void KSJDemoQT_Matrix::WBACallback(float fMatrix[3])
{
	// fMatrix is Final Matrix for White Balance
	TCHAR  szWBValue[16] = { '\0' };

	// Make User easy to read code
	float fRRatio = fMatrix[0];
	float fGRatio = fMatrix[1];
	float fBRatio = fMatrix[2];

	sprintf_s(szWBValue, WHITE_BALANCE_RATIO_FORMAT, fRRatio);
	ui->REdit->setText(szWBValue);

	sprintf_s(szWBValue, WHITE_BALANCE_RATIO_FORMAT, fGRatio);
	ui->GEdit->setText(szWBValue);

	sprintf_s(szWBValue, WHITE_BALANCE_RATIO_FORMAT, fBRatio);
	ui->BEdit->setText(szWBValue);

	ui->RSlider->setValue((int)(fRRatio * WHITE_BALANCE_RATIO_PRESION));
	ui->GSlider->setValue((int)(fGRatio * WHITE_BALANCE_RATIO_PRESION));
	ui->BSlider->setValue((int)(fBRatio * WHITE_BALANCE_RATIO_PRESION));
}

void KSJDemoQT_Matrix::on_WBComboBox_currentIndexChanged(int index)
{
	if (m_nDeviceCurSel == -1)   return;

	int nWidth, nHeight;
	KSJ_PreviewGetSize(m_nDeviceCurSel, &nWidth, &nHeight);
	KSJ_AWBSetRegion(m_nDeviceCurSel, 0, 0, nWidth, nHeight);


	int nRet = KSJ_WhiteBalanceSet(m_nDeviceCurSel, KSJ_WB_MODE(index));
	KSJ_WhiteBalanceAutoSetCallBack(m_nDeviceCurSel, WBACALLBACK, this);
}

void KSJDemoQT_Matrix::on_PresettingComboBox_currentIndexChanged(int index)
{
	if (m_nDeviceCurSel == -1)   return;

	int nRet = KSJ_WhiteBalancePresettingSet(m_nDeviceCurSel, KSJ_COLOR_TEMPRATURE(index));
}

void KSJDemoQT_Matrix::on_PhiSpinBox_valueChanged(int arg1)
{
	if (m_nDeviceCurSel == -1)    return;

	KSJ_WhiteBalanceAutoSet(m_nDeviceCurSel, arg1);
}

void KSJDemoQT_Matrix::on_RSlider_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, WHITE_BALANCE_RATIO_FORMAT, (float)(nValue / WHITE_BALANCE_RATIO_PRESION));
	ui->REdit->setText(szValue);
	SetWbm();
}

void KSJDemoQT_Matrix::on_GSlider_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, WHITE_BALANCE_RATIO_FORMAT, (float)(nValue / WHITE_BALANCE_RATIO_PRESION));
	ui->GEdit->setText(szValue);
	SetWbm();
}

void KSJDemoQT_Matrix::on_BSlider_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, WHITE_BALANCE_RATIO_FORMAT, (float)(nValue / WHITE_BALANCE_RATIO_PRESION));
	ui->BEdit->setText(szValue); 
	SetWbm();
}

void KSJDemoQT_Matrix::SetWbm()
{
	float fMatrix[3] = { 0.0f };

	fMatrix[0] = (float)ui->RSlider->value() / WHITE_BALANCE_RATIO_PRESION;
	fMatrix[1] = (float)ui->GSlider->value() / WHITE_BALANCE_RATIO_PRESION;
	fMatrix[2] = (float)ui->BSlider->value() / WHITE_BALANCE_RATIO_PRESION;

	KSJ_WhiteBalanceMatrixSet(m_nDeviceCurSel, fMatrix);
}

void KSJDemoQT_Matrix::on_CCMComboBox_currentIndexChanged(int index)
{
	if (m_nDeviceCurSel == -1)   return;

	int nRet = KSJ_ColorCorrectionSet(m_nDeviceCurSel, KSJ_CCM_MODE(index));
}

void KSJDemoQT_Matrix::on_CCMPresettingComboBox_currentIndexChanged(int index)
{
	if (m_nDeviceCurSel == -1)   return;

	int nRet = KSJ_ColorCorrectionPresettingSet(m_nDeviceCurSel, KSJ_COLOR_TEMPRATURE(index));
	UpdateCcmControls();
}

void KSJDemoQT_Matrix::on_GSlider00_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit00->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider01_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit01->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider02_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit02->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider10_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit10->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider11_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit11->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider12_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit12->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider20_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit20->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider21_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit21->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::on_GSlider22_valueChanged(int nValue)
{
	if (m_nDeviceCurSel == -1)   return;

	TCHAR               szValue[16] = { '\0' };
	sprintf_s(szValue, COLOR_CORRECTION_FORMAT, (float)(nValue / COLOR_CORRECTION_PRESION));
	ui->GEdit22->setText(szValue);
	SetCcm();
}

void KSJDemoQT_Matrix::SetCcm()
{
	float fMatrix[3][3] = { 0.0f };
	fMatrix[0][0] = (float)ui->GSlider00->value() / COLOR_CORRECTION_PRESION;
	fMatrix[0][1] = (float)ui->GSlider01->value() / COLOR_CORRECTION_PRESION;
	fMatrix[0][2] = (float)ui->GSlider02->value() / COLOR_CORRECTION_PRESION;
	fMatrix[1][0] = (float)ui->GSlider10->value() / COLOR_CORRECTION_PRESION;
	fMatrix[1][1] = (float)ui->GSlider11->value() / COLOR_CORRECTION_PRESION;
	fMatrix[1][2] = (float)ui->GSlider12->value() / COLOR_CORRECTION_PRESION;
	fMatrix[2][0] = (float)ui->GSlider20->value() / COLOR_CORRECTION_PRESION;
	fMatrix[2][1] = (float)ui->GSlider21->value() / COLOR_CORRECTION_PRESION;
	fMatrix[2][2] = (float)ui->GSlider22->value() / COLOR_CORRECTION_PRESION;

	KSJ_ColorCorrectionMatrixSet(m_nDeviceCurSel, fMatrix);
}
