#ifndef KSJDEMOQT_BASE_H
#define KSJDEMOQT_BASE_H

#include <QtWidgets/QDialog>
#include "ui_KSJDemoQT_Matrix.h"

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

#define WHITE_BALANCE_RATIO_PRESION    1000.0f
#define WHITE_BALANCE_RATIO_FORMAT     _T("%.3f")
#define WHITE_BALANCE_RANGE            5


#define COLOR_CORRECTION_PRESION       1000.0f
#define COLOR_CORRECTION_FORMAT        _T("%.3f")
#define COLOR_CORRECTION_RANGE          5

class KSJDemoQT_Matrix : public QDialog
{
    Q_OBJECT

public:
    explicit KSJDemoQT_Matrix(QWidget *parent = 0);
    ~KSJDemoQT_Matrix();


private slots:
    void on_DEVICE_LIST_ComboBox_currentIndexChanged(int index);

    void on_ExposureTimeSpinBox_valueChanged(int arg1);

    void on_ExposureLinesSpinBox_valueChanged(int arg1);

    void on_GainSpinBox_valueChanged(int arg1);

    void on_SetPreviewFovButton_clicked();


    void on_PreviewButton_clicked();

    void on_SetCaptureFovButton_clicked();

    void on_CaptureButton_clicked();

	void on_WBComboBox_currentIndexChanged(int index);

	void on_PresettingComboBox_currentIndexChanged(int index);

	void on_PhiSpinBox_valueChanged(int arg1);

	void on_RSlider_valueChanged(int nValue);

	void on_GSlider_valueChanged(int nValue);

	void on_BSlider_valueChanged(int nValue);

	void on_CCMComboBox_currentIndexChanged(int index);

	void on_CCMPresettingComboBox_currentIndexChanged(int index);

	void on_GSlider00_valueChanged(int nValue);

	void on_GSlider01_valueChanged(int nValue);

	void on_GSlider02_valueChanged(int nValue);

	void on_GSlider10_valueChanged(int nValue);

	void on_GSlider11_valueChanged(int nValue);

	void on_GSlider12_valueChanged(int nValue);

	void on_GSlider20_valueChanged(int nValue);

	void on_GSlider21_valueChanged(int nValue);

	void on_GSlider22_valueChanged(int nValue);
private:
    Ui::KSJDemoQT_Matrix *ui;
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
	void UpdateWbmControls();
	void UpdateCcmControls();
	void UpdateInterfaceColor();
	void WBACallback(float fMatrix[3]);
	void SetWbm();
	void SetCcm();
};

#endif // KSJDEMOQT_BASE_H
