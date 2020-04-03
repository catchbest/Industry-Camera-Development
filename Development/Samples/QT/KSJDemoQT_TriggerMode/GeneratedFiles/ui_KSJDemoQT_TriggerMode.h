/********************************************************************************
** Form generated from reading UI file 'KSJDemoQT_TriggerMode.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSJDEMOQT_TRIGGERMODE_H
#define UI_KSJDEMOQT_TRIGGERMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KSJDemoQT_TriggerMode
{
public:
    QWidget *PREVIEWWND_Widget;
    QLabel *DEVICENUM_Label;
    QComboBox *DEVICE_LIST_ComboBox;
    QSpinBox *ExposureLinesSpinBox;
    QSpinBox *GainSpinBox;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *ExposureTimeSpinBox;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *EXPOSURE_TIME_RANGE_Label;
    QLabel *EXPOSURE_LINES_RANGE_Label;
    QLabel *GAIN_RANGE_Label;
    QLabel *EXPOSURE_TIME_REAL_Label;
    QLabel *FOV_RANGE_Label;
    QLabel *label_12;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *SetPreviewFovButton;
    QSpinBox *PreviewColStartSpinBox;
    QSpinBox *PreviewColSizeSpinBox;
    QSpinBox *PreviewRowStartSpinBox;
    QSpinBox *PreviewRowSizeSpinBox;
    QSpinBox *PreviewMultiFrameSpinBox;
    QGroupBox *groupBox_2;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *SetCaptureFovButton;
    QSpinBox *CaptureColStartSpinBox;
    QSpinBox *CaptureColSizeSpinBox;
    QSpinBox *CaptureRowStartSpinBox;
    QSpinBox *CaptureRowSizeSpinBox;
    QSpinBox *CaptureMultiFrameSpinBox;
    QPushButton *PreviewButton;
    QPushButton *CaptureButton;
    QLabel *ERROR_INFO_Label;
    QLabel *ELAPSE_TIME_Label;
    QTableWidget *FunctionTableWidget;
    QCheckBox *SaveCheckBox;
    QLabel *label_13;
    QCheckBox *InvertCheckBox;
    QCheckBox *EnableCheckBox;
    QLabel *label_14;
    QComboBox *TimeoutComboBox;
    QCheckBox *RecoverCheckBox;
    QLabel *label_15;
    QComboBox *TriggerModeComboBox;
    QLabel *label_16;
    QComboBox *TriggerMethodComboBox;
    QLabel *label_17;
    QSpinBox *DelaySpinBox;
    QLabel *label_23;
    QLineEdit *DelayRangeEdit;
    QSpinBox *RateSpinBox;
    QLabel *label_24;
    QCheckBox *StatusCheckBox;
    QLineEdit *lineEdit;
    QPushButton *EmptyButton;

    void setupUi(QDialog *KSJDemoQT_TriggerMode)
    {
        if (KSJDemoQT_TriggerMode->objectName().isEmpty())
            KSJDemoQT_TriggerMode->setObjectName(QStringLiteral("KSJDemoQT_TriggerMode"));
        KSJDemoQT_TriggerMode->resize(1204, 561);
        PREVIEWWND_Widget = new QWidget(KSJDemoQT_TriggerMode);
        PREVIEWWND_Widget->setObjectName(QStringLiteral("PREVIEWWND_Widget"));
        PREVIEWWND_Widget->setGeometry(QRect(-10, 0, 501, 561));
        DEVICENUM_Label = new QLabel(KSJDemoQT_TriggerMode);
        DEVICENUM_Label->setObjectName(QStringLiteral("DEVICENUM_Label"));
        DEVICENUM_Label->setGeometry(QRect(510, 20, 71, 21));
        DEVICE_LIST_ComboBox = new QComboBox(KSJDemoQT_TriggerMode);
        DEVICE_LIST_ComboBox->setObjectName(QStringLiteral("DEVICE_LIST_ComboBox"));
        DEVICE_LIST_ComboBox->setGeometry(QRect(590, 20, 301, 22));
        ExposureLinesSpinBox = new QSpinBox(KSJDemoQT_TriggerMode);
        ExposureLinesSpinBox->setObjectName(QStringLiteral("ExposureLinesSpinBox"));
        ExposureLinesSpinBox->setGeometry(QRect(640, 100, 91, 22));
        GainSpinBox = new QSpinBox(KSJDemoQT_TriggerMode);
        GainSpinBox->setObjectName(QStringLiteral("GainSpinBox"));
        GainSpinBox->setGeometry(QRect(640, 170, 91, 22));
        label_6 = new QLabel(KSJDemoQT_TriggerMode);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 170, 41, 21));
        label_7 = new QLabel(KSJDemoQT_TriggerMode);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(520, 60, 111, 21));
        label_8 = new QLabel(KSJDemoQT_TriggerMode);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(530, 100, 91, 21));
        ExposureTimeSpinBox = new QSpinBox(KSJDemoQT_TriggerMode);
        ExposureTimeSpinBox->setObjectName(QStringLiteral("ExposureTimeSpinBox"));
        ExposureTimeSpinBox->setGeometry(QRect(640, 60, 91, 22));
        label_9 = new QLabel(KSJDemoQT_TriggerMode);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(760, 60, 61, 21));
        label_10 = new QLabel(KSJDemoQT_TriggerMode);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(760, 100, 41, 21));
        label_11 = new QLabel(KSJDemoQT_TriggerMode);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(760, 170, 41, 21));
        EXPOSURE_TIME_RANGE_Label = new QLabel(KSJDemoQT_TriggerMode);
        EXPOSURE_TIME_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_RANGE_Label"));
        EXPOSURE_TIME_RANGE_Label->setGeometry(QRect(830, 60, 71, 21));
        EXPOSURE_LINES_RANGE_Label = new QLabel(KSJDemoQT_TriggerMode);
        EXPOSURE_LINES_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_LINES_RANGE_Label"));
        EXPOSURE_LINES_RANGE_Label->setGeometry(QRect(830, 100, 71, 21));
        GAIN_RANGE_Label = new QLabel(KSJDemoQT_TriggerMode);
        GAIN_RANGE_Label->setObjectName(QStringLiteral("GAIN_RANGE_Label"));
        GAIN_RANGE_Label->setGeometry(QRect(830, 170, 71, 21));
        EXPOSURE_TIME_REAL_Label = new QLabel(KSJDemoQT_TriggerMode);
        EXPOSURE_TIME_REAL_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_REAL_Label"));
        EXPOSURE_TIME_REAL_Label->setGeometry(QRect(640, 140, 201, 21));
        FOV_RANGE_Label = new QLabel(KSJDemoQT_TriggerMode);
        FOV_RANGE_Label->setObjectName(QStringLiteral("FOV_RANGE_Label"));
        FOV_RANGE_Label->setGeometry(QRect(640, 200, 201, 21));
        label_12 = new QLabel(KSJDemoQT_TriggerMode);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(570, 200, 61, 21));
        groupBox = new QGroupBox(KSJDemoQT_TriggerMode);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(500, 230, 331, 141));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 61, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 20, 61, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 60, 61, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 60, 61, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 100, 71, 21));
        SetPreviewFovButton = new QPushButton(groupBox);
        SetPreviewFovButton->setObjectName(QStringLiteral("SetPreviewFovButton"));
        SetPreviewFovButton->setGeometry(QRect(180, 100, 111, 23));
        PreviewColStartSpinBox = new QSpinBox(groupBox);
        PreviewColStartSpinBox->setObjectName(QStringLiteral("PreviewColStartSpinBox"));
        PreviewColStartSpinBox->setGeometry(QRect(90, 20, 71, 22));
        PreviewColSizeSpinBox = new QSpinBox(groupBox);
        PreviewColSizeSpinBox->setObjectName(QStringLiteral("PreviewColSizeSpinBox"));
        PreviewColSizeSpinBox->setGeometry(QRect(90, 60, 71, 22));
        PreviewRowStartSpinBox = new QSpinBox(groupBox);
        PreviewRowStartSpinBox->setObjectName(QStringLiteral("PreviewRowStartSpinBox"));
        PreviewRowStartSpinBox->setGeometry(QRect(240, 20, 71, 22));
        PreviewRowSizeSpinBox = new QSpinBox(groupBox);
        PreviewRowSizeSpinBox->setObjectName(QStringLiteral("PreviewRowSizeSpinBox"));
        PreviewRowSizeSpinBox->setGeometry(QRect(240, 60, 71, 22));
        PreviewMultiFrameSpinBox = new QSpinBox(groupBox);
        PreviewMultiFrameSpinBox->setObjectName(QStringLiteral("PreviewMultiFrameSpinBox"));
        PreviewMultiFrameSpinBox->setGeometry(QRect(90, 100, 71, 22));
        groupBox_2 = new QGroupBox(KSJDemoQT_TriggerMode);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(500, 370, 331, 141));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 20, 61, 21));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(180, 20, 61, 21));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 60, 61, 21));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(180, 60, 61, 21));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 100, 71, 21));
        SetCaptureFovButton = new QPushButton(groupBox_2);
        SetCaptureFovButton->setObjectName(QStringLiteral("SetCaptureFovButton"));
        SetCaptureFovButton->setGeometry(QRect(180, 100, 111, 23));
        CaptureColStartSpinBox = new QSpinBox(groupBox_2);
        CaptureColStartSpinBox->setObjectName(QStringLiteral("CaptureColStartSpinBox"));
        CaptureColStartSpinBox->setGeometry(QRect(90, 20, 71, 22));
        CaptureColSizeSpinBox = new QSpinBox(groupBox_2);
        CaptureColSizeSpinBox->setObjectName(QStringLiteral("CaptureColSizeSpinBox"));
        CaptureColSizeSpinBox->setGeometry(QRect(90, 60, 71, 22));
        CaptureRowStartSpinBox = new QSpinBox(groupBox_2);
        CaptureRowStartSpinBox->setObjectName(QStringLiteral("CaptureRowStartSpinBox"));
        CaptureRowStartSpinBox->setGeometry(QRect(240, 20, 71, 22));
        CaptureRowSizeSpinBox = new QSpinBox(groupBox_2);
        CaptureRowSizeSpinBox->setObjectName(QStringLiteral("CaptureRowSizeSpinBox"));
        CaptureRowSizeSpinBox->setGeometry(QRect(240, 60, 71, 22));
        CaptureMultiFrameSpinBox = new QSpinBox(groupBox_2);
        CaptureMultiFrameSpinBox->setObjectName(QStringLiteral("CaptureMultiFrameSpinBox"));
        CaptureMultiFrameSpinBox->setGeometry(QRect(90, 100, 71, 22));
        PreviewButton = new QPushButton(KSJDemoQT_TriggerMode);
        PreviewButton->setObjectName(QStringLiteral("PreviewButton"));
        PreviewButton->setGeometry(QRect(840, 340, 75, 23));
        CaptureButton = new QPushButton(KSJDemoQT_TriggerMode);
        CaptureButton->setObjectName(QStringLiteral("CaptureButton"));
        CaptureButton->setGeometry(QRect(840, 480, 75, 23));
        ERROR_INFO_Label = new QLabel(KSJDemoQT_TriggerMode);
        ERROR_INFO_Label->setObjectName(QStringLiteral("ERROR_INFO_Label"));
        ERROR_INFO_Label->setGeometry(QRect(510, 530, 201, 21));
        ELAPSE_TIME_Label = new QLabel(KSJDemoQT_TriggerMode);
        ELAPSE_TIME_Label->setObjectName(QStringLiteral("ELAPSE_TIME_Label"));
        ELAPSE_TIME_Label->setGeometry(QRect(740, 530, 121, 21));
        FunctionTableWidget = new QTableWidget(KSJDemoQT_TriggerMode);
        FunctionTableWidget->setObjectName(QStringLiteral("FunctionTableWidget"));
        FunctionTableWidget->setGeometry(QRect(920, 0, 281, 211));
        SaveCheckBox = new QCheckBox(KSJDemoQT_TriggerMode);
        SaveCheckBox->setObjectName(QStringLiteral("SaveCheckBox"));
        SaveCheckBox->setGeometry(QRect(840, 450, 71, 20));
        label_13 = new QLabel(KSJDemoQT_TriggerMode);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(930, 230, 91, 21));
        InvertCheckBox = new QCheckBox(KSJDemoQT_TriggerMode);
        InvertCheckBox->setObjectName(QStringLiteral("InvertCheckBox"));
        InvertCheckBox->setGeometry(QRect(1020, 230, 61, 21));
        EnableCheckBox = new QCheckBox(KSJDemoQT_TriggerMode);
        EnableCheckBox->setObjectName(QStringLiteral("EnableCheckBox"));
        EnableCheckBox->setGeometry(QRect(1090, 230, 61, 21));
        label_14 = new QLabel(KSJDemoQT_TriggerMode);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(930, 260, 81, 21));
        TimeoutComboBox = new QComboBox(KSJDemoQT_TriggerMode);
        TimeoutComboBox->setObjectName(QStringLiteral("TimeoutComboBox"));
        TimeoutComboBox->setGeometry(QRect(1010, 260, 91, 22));
        RecoverCheckBox = new QCheckBox(KSJDemoQT_TriggerMode);
        RecoverCheckBox->setObjectName(QStringLiteral("RecoverCheckBox"));
        RecoverCheckBox->setGeometry(QRect(1130, 260, 71, 21));
        label_15 = new QLabel(KSJDemoQT_TriggerMode);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(930, 290, 81, 21));
        TriggerModeComboBox = new QComboBox(KSJDemoQT_TriggerMode);
        TriggerModeComboBox->setObjectName(QStringLiteral("TriggerModeComboBox"));
        TriggerModeComboBox->setGeometry(QRect(1010, 290, 191, 22));
        label_16 = new QLabel(KSJDemoQT_TriggerMode);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(920, 320, 91, 21));
        TriggerMethodComboBox = new QComboBox(KSJDemoQT_TriggerMode);
        TriggerMethodComboBox->setObjectName(QStringLiteral("TriggerMethodComboBox"));
        TriggerMethodComboBox->setGeometry(QRect(1010, 320, 191, 22));
        label_17 = new QLabel(KSJDemoQT_TriggerMode);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(930, 360, 91, 21));
        DelaySpinBox = new QSpinBox(KSJDemoQT_TriggerMode);
        DelaySpinBox->setObjectName(QStringLiteral("DelaySpinBox"));
        DelaySpinBox->setGeometry(QRect(1020, 360, 81, 22));
        label_23 = new QLabel(KSJDemoQT_TriggerMode);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(930, 390, 121, 21));
        DelayRangeEdit = new QLineEdit(KSJDemoQT_TriggerMode);
        DelayRangeEdit->setObjectName(QStringLiteral("DelayRangeEdit"));
        DelayRangeEdit->setGeometry(QRect(1050, 390, 141, 20));
        DelayRangeEdit->setReadOnly(true);
        RateSpinBox = new QSpinBox(KSJDemoQT_TriggerMode);
        RateSpinBox->setObjectName(QStringLiteral("RateSpinBox"));
        RateSpinBox->setGeometry(QRect(1060, 420, 81, 22));
        label_24 = new QLabel(KSJDemoQT_TriggerMode);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(930, 420, 131, 21));
        StatusCheckBox = new QCheckBox(KSJDemoQT_TriggerMode);
        StatusCheckBox->setObjectName(QStringLiteral("StatusCheckBox"));
        StatusCheckBox->setGeometry(QRect(930, 450, 171, 21));
        lineEdit = new QLineEdit(KSJDemoQT_TriggerMode);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(930, 480, 231, 20));
        lineEdit->setReadOnly(true);
        EmptyButton = new QPushButton(KSJDemoQT_TriggerMode);
        EmptyButton->setObjectName(QStringLiteral("EmptyButton"));
        EmptyButton->setGeometry(QRect(940, 510, 161, 31));

        retranslateUi(KSJDemoQT_TriggerMode);

        QMetaObject::connectSlotsByName(KSJDemoQT_TriggerMode);
    } // setupUi

    void retranslateUi(QDialog *KSJDemoQT_TriggerMode)
    {
        KSJDemoQT_TriggerMode->setWindowTitle(QApplication::translate("KSJDemoQT_TriggerMode", "KSJDemoQT", 0));
        DEVICENUM_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Device Num:", 0));
        label_6->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Gain:", 0));
        label_7->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Exposure Time(ms):", 0));
        label_8->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Exposure Lines:", 0));
        label_9->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range(ms):", 0));
        label_10->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range:", 0));
        label_11->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range:", 0));
        EXPOSURE_TIME_RANGE_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range", 0));
        EXPOSURE_LINES_RANGE_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range", 0));
        GAIN_RANGE_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Range", 0));
        EXPOSURE_TIME_REAL_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "REAL EXP TIME", 0));
        FOV_RANGE_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "EXP LINES RANGE", 0));
        label_12->setText(QApplication::translate("KSJDemoQT_TriggerMode", "FOV Range:", 0));
        groupBox->setTitle(QApplication::translate("KSJDemoQT_TriggerMode", "Preview", 0));
        label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Col Start:", 0));
        label_2->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Row Start:", 0));
        label_3->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Col Size:", 0));
        label_4->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Row Size:", 0));
        label_5->setText(QApplication::translate("KSJDemoQT_TriggerMode", "MultiFrame:", 0));
        SetPreviewFovButton->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Set Preview Fov", 0));
        groupBox_2->setTitle(QApplication::translate("KSJDemoQT_TriggerMode", "Capture", 0));
        label_18->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Col Start:", 0));
        label_19->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Row Start:", 0));
        label_20->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Col Size:", 0));
        label_21->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Row Size:", 0));
        label_22->setText(QApplication::translate("KSJDemoQT_TriggerMode", "MultiFrame:", 0));
        SetCaptureFovButton->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Set Capture Fov", 0));
        PreviewButton->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Preview", 0));
        CaptureButton->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Capture", 0));
        ERROR_INFO_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Error Info", 0));
        ELAPSE_TIME_Label->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Elapse", 0));
        SaveCheckBox->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Save", 0));
        label_13->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Flash Control:", 0));
        InvertCheckBox->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Invert", 0));
        EnableCheckBox->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Enable", 0));
        label_14->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Read Timeout:", 0));
        RecoverCheckBox->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Recover", 0));
        label_15->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Trigger Mode:", 0));
        label_16->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Trigger Method:", 0));
        label_17->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Trigger Delay:", 0));
        label_23->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Trigger Delay Range:", 0));
        label_24->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Fixed Frame Rate(HW):", 0));
        StatusCheckBox->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Get Frame Buffer Status", 0));
        lineEdit->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Frame Buffer Status", 0));
        EmptyButton->setText(QApplication::translate("KSJDemoQT_TriggerMode", "Empty Frame Buffer", 0));
    } // retranslateUi

};

namespace Ui {
    class KSJDemoQT_TriggerMode: public Ui_KSJDemoQT_TriggerMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSJDEMOQT_TRIGGERMODE_H
