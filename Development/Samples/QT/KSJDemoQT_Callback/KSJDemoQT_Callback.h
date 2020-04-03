#ifndef KSJDEMOQT_BASE_H
#define KSJDEMOQT_BASE_H


#include <QtWidgets/QDialog>
#include <QDateTime>
#include "ui_KSJDemoQT_Callback.h"

#include "../Common/KSJ_GS.H"

// �������Ҫ������ͷ�ļ����ã�·��������ڹ��̵����·��
#include "../../../KSJApi.Inc/KSJApi.h"

// ������Ҫ���ӵĿ��ļ����ã�·��������ڹ��̵����·��
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

class KSJDemoQT_Callback : public QDialog
{
    Q_OBJECT

public:
    explicit KSJDemoQT_Callback(QWidget *parent = 0);
    ~KSJDemoQT_Callback();


private slots:
    void on_DEVICE_LIST_ComboBox_currentIndexChanged(int index);

    void on_ExposureTimeSpinBox_valueChanged(int arg1);

    void on_ExposureLinesSpinBox_valueChanged(int arg1);

    void on_GainSpinBox_valueChanged(int arg1);

    void on_SetPreviewFovButton_clicked();


    void on_PreviewButton_clicked();

    void on_SetCaptureFovButton_clicked();

    void on_CaptureButton_clicked();

	void on_SetCallbackButton_clicked();

	void on_SetCallbackExButton_clicked();

private:
    Ui::KSJDemoQT_Callback *ui;
	int m_nDeviceNum;
	int m_nDeviceCurSel;
	DEVICEINFO    m_DeviceInfo[MAX_DEVICE];
	QVector<QRgb> m_vcolorTable; //���ɻҶ���ɫ��
	bool  m_bPreview;
	bool  m_bCallback;
	bool  m_bCallbackEx;
	QColor m_col;
public:
	void UpdateInterfaceFunction();
	void UpdateInterface();
	void UpdateDeviceList();
	void GetRealExposureTime();
	void ConvetData(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char* pConvertData);
	void ShowErrorInfo(int nRet);
	void PreviewCallback(unsigned char *pImageData, int nWidth, int nHeight, int nBitCount);
	void PreviewCallbackEx(HDC hDC, int nWidth, int nHeight, int nBitCount);
	void DrawCrossLine(unsigned int nX, unsigned int nY, unsigned int nLineWidth, unsigned char *pImageData, int nWidth, int nHeight, int nBitCount);
	void DrawSystemTime(HDC  hDC, int nWidth, int nHeight);
};

#endif // KSJDEMOQT_BASE_H
