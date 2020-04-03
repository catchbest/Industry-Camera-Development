#ifndef KSJDEMOQT_BASE_H
#define KSJDEMOQT_BASE_H

#include <QtWidgets/QDialog>
#include "ui_KSJDemoQT_Image.h"

#include "../Common/KSJ_GS.H"

// 这个是需要包含的头文件设置，路径是相对于工程的相对路径
#include "../../../KSJApi.Inc/KSJApi.h"

// 这是需要链接的库文件设置，路径是相对于工程的相对路径
#ifdef _UNICODE

#ifdef _WIN64
#pragma comment( lib, "../../../KSJApi.Lib/x64/KSJApi64u.lib" )
#else
#pragma comment( lib, "../../../KSJApi.Lib/x86/KSJApiu.lib" )
#endif

#else

#ifdef _WIN64
#pragma comment( lib, "../../../KSJApi.Lib/x64/KSJApi64.lib" )
#else
#pragma comment( lib, "../../../KSJApi.Lib/x86/KSJApi.lib" )
#endif

#endif

#define MAX_DEVICE    64



struct DEVICEINFO
{
	int                 nIndex;
	KSJ_DEVICETYPE		DeviceType;
	int					nSerials;
	WORD				wFirmwareVersion;
	WORD                wFpgaVersion;
};

class KSJDemoQT_Image : public QDialog
{
    Q_OBJECT

public:
    explicit KSJDemoQT_Image(QWidget *parent = 0);
    ~KSJDemoQT_Image();


private slots:
    void on_DEVICE_LIST_ComboBox_currentIndexChanged(int index);

    void on_ExposureTimeSpinBox_valueChanged(int arg1);

    void on_ExposureLinesSpinBox_valueChanged(int arg1);

    void on_GainSpinBox_valueChanged(int arg1);

    void on_SetPreviewFovButton_clicked();


    void on_PreviewButton_clicked();

    void on_SetCaptureFovButton_clicked();

    void on_CaptureButton_clicked();

	void on_LowSpinBox_valueChanged(int arg1);

	void on_HighSpinBox_valueChanged(int arg1);

	void on_EnableCheckBox_clicked();

	void on_ModeComboBox_currentIndexChanged();

	void on_ContrastSpinBox_valueChanged(int arg1);

	void on_SaturationSpinBox_valueChanged(int arg1);

	void on_BrghtnessSpinBox_valueChanged(int arg1);

	void on_GammaSpinBox_valueChanged(int arg1);

	void on_ProcessResetButton_clicked();

	void on_HueEnableCheckBox_clicked(bool arg1);

	void on_HueResetButton_clicked();

	void on_HueSetButton_clicked();

	void on_HueComboBox_currentIndexChanged(int index);

private:
    Ui::KSJDemoQT_Image *ui;
	int m_nDeviceNum;
	int m_nDeviceCurSel;
	DEVICEINFO    m_DeviceInfo[MAX_DEVICE];
	QVector<QRgb> m_vcolorTable; //生成灰度颜色表
	bool  m_bPreview;
	QColor m_col;
public:
	void UpdateInterfaceFunction();
	void UpdateInterface();
	void UpdateDeviceList();
	void GetRealExposureTime();
	void ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData);
	void ShowErrorInfo(int nRet);
	void SetThreshold();
	void SetBadpixelCorrection();
	void UpdateInterfaceImage();
};

#endif // KSJDEMOQT_BASE_H
