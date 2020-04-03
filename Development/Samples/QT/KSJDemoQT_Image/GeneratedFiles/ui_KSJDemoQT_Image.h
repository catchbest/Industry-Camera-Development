/********************************************************************************
** Form generated from reading UI file 'KSJDemoQT_Image.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSJDEMOQT_IMAGE_H
#define UI_KSJDEMOQT_IMAGE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KSJDemoQT_Image
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
    QGroupBox *groupBox_3;
    QLabel *label_13;
    QSpinBox *LowSpinBox;
    QLabel *label_14;
    QSpinBox *HighSpinBox;
    QLabel *label_15;
    QComboBox *ModeComboBox;
    QCheckBox *EnableCheckBox;
    QGroupBox *groupBox_4;
    QSpinBox *ContrastSpinBox;
    QLabel *label_16;
    QSpinBox *SaturationSpinBox;
    QLabel *label_17;
    QSpinBox *BrghtnessSpinBox;
    QLabel *label_23;
    QSpinBox *GammaSpinBox;
    QLabel *label_24;
    QPushButton *ProcessResetButton;
    QGroupBox *groupBox_5;
    QSpinBox *HueSpinBox;
    QLabel *label_33;
    QSpinBox *LightnessSpinBox;
    QLabel *label_34;
    QSpinBox *HueSaturationSpinBox;
    QLabel *label_35;
    QPushButton *HueResetButton;
    QCheckBox *HueEnableCheckBox;
    QPushButton *HueSetButton;
    QLabel *label_36;
    QComboBox *HueComboBox;

    void setupUi(QDialog *KSJDemoQT_Image)
    {
        if (KSJDemoQT_Image->objectName().isEmpty())
            KSJDemoQT_Image->setObjectName(QStringLiteral("KSJDemoQT_Image"));
        KSJDemoQT_Image->resize(1210, 564);
        PREVIEWWND_Widget = new QWidget(KSJDemoQT_Image);
        PREVIEWWND_Widget->setObjectName(QStringLiteral("PREVIEWWND_Widget"));
        PREVIEWWND_Widget->setGeometry(QRect(-10, 0, 501, 561));
        DEVICENUM_Label = new QLabel(KSJDemoQT_Image);
        DEVICENUM_Label->setObjectName(QStringLiteral("DEVICENUM_Label"));
        DEVICENUM_Label->setGeometry(QRect(510, 20, 71, 21));
        DEVICE_LIST_ComboBox = new QComboBox(KSJDemoQT_Image);
        DEVICE_LIST_ComboBox->setObjectName(QStringLiteral("DEVICE_LIST_ComboBox"));
        DEVICE_LIST_ComboBox->setGeometry(QRect(590, 20, 301, 22));
        ExposureLinesSpinBox = new QSpinBox(KSJDemoQT_Image);
        ExposureLinesSpinBox->setObjectName(QStringLiteral("ExposureLinesSpinBox"));
        ExposureLinesSpinBox->setGeometry(QRect(640, 100, 91, 22));
        GainSpinBox = new QSpinBox(KSJDemoQT_Image);
        GainSpinBox->setObjectName(QStringLiteral("GainSpinBox"));
        GainSpinBox->setGeometry(QRect(640, 170, 91, 22));
        label_6 = new QLabel(KSJDemoQT_Image);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 170, 41, 21));
        label_7 = new QLabel(KSJDemoQT_Image);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(520, 60, 111, 21));
        label_8 = new QLabel(KSJDemoQT_Image);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(530, 100, 91, 21));
        ExposureTimeSpinBox = new QSpinBox(KSJDemoQT_Image);
        ExposureTimeSpinBox->setObjectName(QStringLiteral("ExposureTimeSpinBox"));
        ExposureTimeSpinBox->setGeometry(QRect(640, 60, 91, 22));
        label_9 = new QLabel(KSJDemoQT_Image);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(760, 60, 61, 21));
        label_10 = new QLabel(KSJDemoQT_Image);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(760, 100, 41, 21));
        label_11 = new QLabel(KSJDemoQT_Image);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(760, 170, 41, 21));
        EXPOSURE_TIME_RANGE_Label = new QLabel(KSJDemoQT_Image);
        EXPOSURE_TIME_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_RANGE_Label"));
        EXPOSURE_TIME_RANGE_Label->setGeometry(QRect(830, 60, 71, 21));
        EXPOSURE_LINES_RANGE_Label = new QLabel(KSJDemoQT_Image);
        EXPOSURE_LINES_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_LINES_RANGE_Label"));
        EXPOSURE_LINES_RANGE_Label->setGeometry(QRect(830, 100, 71, 21));
        GAIN_RANGE_Label = new QLabel(KSJDemoQT_Image);
        GAIN_RANGE_Label->setObjectName(QStringLiteral("GAIN_RANGE_Label"));
        GAIN_RANGE_Label->setGeometry(QRect(830, 170, 71, 21));
        EXPOSURE_TIME_REAL_Label = new QLabel(KSJDemoQT_Image);
        EXPOSURE_TIME_REAL_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_REAL_Label"));
        EXPOSURE_TIME_REAL_Label->setGeometry(QRect(640, 140, 201, 21));
        FOV_RANGE_Label = new QLabel(KSJDemoQT_Image);
        FOV_RANGE_Label->setObjectName(QStringLiteral("FOV_RANGE_Label"));
        FOV_RANGE_Label->setGeometry(QRect(640, 200, 201, 21));
        label_12 = new QLabel(KSJDemoQT_Image);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(570, 200, 61, 21));
        groupBox = new QGroupBox(KSJDemoQT_Image);
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
        groupBox_2 = new QGroupBox(KSJDemoQT_Image);
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
        PreviewButton = new QPushButton(KSJDemoQT_Image);
        PreviewButton->setObjectName(QStringLiteral("PreviewButton"));
        PreviewButton->setGeometry(QRect(840, 340, 75, 23));
        CaptureButton = new QPushButton(KSJDemoQT_Image);
        CaptureButton->setObjectName(QStringLiteral("CaptureButton"));
        CaptureButton->setGeometry(QRect(840, 480, 75, 23));
        ERROR_INFO_Label = new QLabel(KSJDemoQT_Image);
        ERROR_INFO_Label->setObjectName(QStringLiteral("ERROR_INFO_Label"));
        ERROR_INFO_Label->setGeometry(QRect(510, 530, 201, 21));
        ELAPSE_TIME_Label = new QLabel(KSJDemoQT_Image);
        ELAPSE_TIME_Label->setObjectName(QStringLiteral("ELAPSE_TIME_Label"));
        ELAPSE_TIME_Label->setGeometry(QRect(740, 530, 121, 21));
        FunctionTableWidget = new QTableWidget(KSJDemoQT_Image);
        FunctionTableWidget->setObjectName(QStringLiteral("FunctionTableWidget"));
        FunctionTableWidget->setGeometry(QRect(920, 0, 291, 181));
        SaveCheckBox = new QCheckBox(KSJDemoQT_Image);
        SaveCheckBox->setObjectName(QStringLiteral("SaveCheckBox"));
        SaveCheckBox->setGeometry(QRect(840, 450, 71, 20));
        groupBox_3 = new QGroupBox(KSJDemoQT_Image);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(920, 190, 281, 121));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 30, 91, 21));
        LowSpinBox = new QSpinBox(groupBox_3);
        LowSpinBox->setObjectName(QStringLiteral("LowSpinBox"));
        LowSpinBox->setGeometry(QRect(110, 30, 91, 22));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 60, 91, 21));
        HighSpinBox = new QSpinBox(groupBox_3);
        HighSpinBox->setObjectName(QStringLiteral("HighSpinBox"));
        HighSpinBox->setGeometry(QRect(110, 60, 91, 22));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 90, 91, 21));
        ModeComboBox = new QComboBox(groupBox_3);
        ModeComboBox->setObjectName(QStringLiteral("ModeComboBox"));
        ModeComboBox->setGeometry(QRect(110, 90, 151, 22));
        EnableCheckBox = new QCheckBox(groupBox_3);
        EnableCheckBox->setObjectName(QStringLiteral("EnableCheckBox"));
        EnableCheckBox->setGeometry(QRect(210, 60, 61, 16));
        groupBox_4 = new QGroupBox(KSJDemoQT_Image);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(920, 310, 281, 111));
        ContrastSpinBox = new QSpinBox(groupBox_4);
        ContrastSpinBox->setObjectName(QStringLiteral("ContrastSpinBox"));
        ContrastSpinBox->setGeometry(QRect(70, 20, 71, 22));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 20, 51, 21));
        SaturationSpinBox = new QSpinBox(groupBox_4);
        SaturationSpinBox->setObjectName(QStringLiteral("SaturationSpinBox"));
        SaturationSpinBox->setGeometry(QRect(210, 20, 71, 22));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(140, 20, 71, 21));
        BrghtnessSpinBox = new QSpinBox(groupBox_4);
        BrghtnessSpinBox->setObjectName(QStringLiteral("BrghtnessSpinBox"));
        BrghtnessSpinBox->setGeometry(QRect(70, 50, 71, 22));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 50, 51, 21));
        GammaSpinBox = new QSpinBox(groupBox_4);
        GammaSpinBox->setObjectName(QStringLiteral("GammaSpinBox"));
        GammaSpinBox->setGeometry(QRect(210, 50, 71, 22));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(150, 50, 51, 21));
        ProcessResetButton = new QPushButton(groupBox_4);
        ProcessResetButton->setObjectName(QStringLiteral("ProcessResetButton"));
        ProcessResetButton->setGeometry(QRect(170, 80, 75, 23));
        groupBox_5 = new QGroupBox(KSJDemoQT_Image);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(920, 430, 281, 121));
        HueSpinBox = new QSpinBox(groupBox_5);
        HueSpinBox->setObjectName(QStringLiteral("HueSpinBox"));
        HueSpinBox->setGeometry(QRect(70, 20, 71, 22));
        label_33 = new QLabel(groupBox_5);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 20, 51, 21));
        LightnessSpinBox = new QSpinBox(groupBox_5);
        LightnessSpinBox->setObjectName(QStringLiteral("LightnessSpinBox"));
        LightnessSpinBox->setGeometry(QRect(210, 20, 71, 22));
        label_34 = new QLabel(groupBox_5);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(140, 20, 71, 21));
        HueSaturationSpinBox = new QSpinBox(groupBox_5);
        HueSaturationSpinBox->setObjectName(QStringLiteral("HueSaturationSpinBox"));
        HueSaturationSpinBox->setGeometry(QRect(80, 50, 71, 22));
        label_35 = new QLabel(groupBox_5);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(10, 50, 71, 21));
        HueResetButton = new QPushButton(groupBox_5);
        HueResetButton->setObjectName(QStringLiteral("HueResetButton"));
        HueResetButton->setGeometry(QRect(220, 50, 61, 23));
        HueEnableCheckBox = new QCheckBox(groupBox_5);
        HueEnableCheckBox->setObjectName(QStringLiteral("HueEnableCheckBox"));
        HueEnableCheckBox->setGeometry(QRect(160, 50, 61, 21));
        HueSetButton = new QPushButton(groupBox_5);
        HueSetButton->setObjectName(QStringLiteral("HueSetButton"));
        HueSetButton->setGeometry(QRect(220, 80, 61, 23));
        label_36 = new QLabel(groupBox_5);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(10, 80, 61, 21));
        HueComboBox = new QComboBox(groupBox_5);
        HueComboBox->setObjectName(QStringLiteral("HueComboBox"));
        HueComboBox->setGeometry(QRect(80, 80, 111, 22));
        PREVIEWWND_Widget->raise();
        DEVICENUM_Label->raise();
        DEVICE_LIST_ComboBox->raise();
        ExposureLinesSpinBox->raise();
        GainSpinBox->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        ExposureTimeSpinBox->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        EXPOSURE_TIME_RANGE_Label->raise();
        EXPOSURE_LINES_RANGE_Label->raise();
        GAIN_RANGE_Label->raise();
        EXPOSURE_TIME_REAL_Label->raise();
        FOV_RANGE_Label->raise();
        label_12->raise();
        groupBox->raise();
        groupBox_2->raise();
        PreviewButton->raise();
        CaptureButton->raise();
        ERROR_INFO_Label->raise();
        ELAPSE_TIME_Label->raise();
        FunctionTableWidget->raise();
        SaveCheckBox->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        SaturationSpinBox->raise();
        ContrastSpinBox->raise();
        groupBox_5->raise();

        retranslateUi(KSJDemoQT_Image);

        QMetaObject::connectSlotsByName(KSJDemoQT_Image);
    } // setupUi

    void retranslateUi(QDialog *KSJDemoQT_Image)
    {
        KSJDemoQT_Image->setWindowTitle(QApplication::translate("KSJDemoQT_Image", "KSJDemoQT", 0));
        DEVICENUM_Label->setText(QApplication::translate("KSJDemoQT_Image", "Device Num:", 0));
        label_6->setText(QApplication::translate("KSJDemoQT_Image", "Gain:", 0));
        label_7->setText(QApplication::translate("KSJDemoQT_Image", "Exposure Time(ms):", 0));
        label_8->setText(QApplication::translate("KSJDemoQT_Image", "Exposure Lines:", 0));
        label_9->setText(QApplication::translate("KSJDemoQT_Image", "Range(ms):", 0));
        label_10->setText(QApplication::translate("KSJDemoQT_Image", "Range:", 0));
        label_11->setText(QApplication::translate("KSJDemoQT_Image", "Range:", 0));
        EXPOSURE_TIME_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Image", "Range", 0));
        EXPOSURE_LINES_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Image", "Range", 0));
        GAIN_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Image", "Range", 0));
        EXPOSURE_TIME_REAL_Label->setText(QApplication::translate("KSJDemoQT_Image", "REAL EXP TIME", 0));
        FOV_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Image", "EXP LINES RANGE", 0));
        label_12->setText(QApplication::translate("KSJDemoQT_Image", "FOV Range:", 0));
        groupBox->setTitle(QApplication::translate("KSJDemoQT_Image", "Preview", 0));
        label->setText(QApplication::translate("KSJDemoQT_Image", "Col Start:", 0));
        label_2->setText(QApplication::translate("KSJDemoQT_Image", "Row Start:", 0));
        label_3->setText(QApplication::translate("KSJDemoQT_Image", "Col Size:", 0));
        label_4->setText(QApplication::translate("KSJDemoQT_Image", "Row Size:", 0));
        label_5->setText(QApplication::translate("KSJDemoQT_Image", "MultiFrame:", 0));
        SetPreviewFovButton->setText(QApplication::translate("KSJDemoQT_Image", "Set Preview Fov", 0));
        groupBox_2->setTitle(QApplication::translate("KSJDemoQT_Image", "Capture", 0));
        label_18->setText(QApplication::translate("KSJDemoQT_Image", "Col Start:", 0));
        label_19->setText(QApplication::translate("KSJDemoQT_Image", "Row Start:", 0));
        label_20->setText(QApplication::translate("KSJDemoQT_Image", "Col Size:", 0));
        label_21->setText(QApplication::translate("KSJDemoQT_Image", "Row Size:", 0));
        label_22->setText(QApplication::translate("KSJDemoQT_Image", "MultiFrame:", 0));
        SetCaptureFovButton->setText(QApplication::translate("KSJDemoQT_Image", "Set Capture Fov", 0));
        PreviewButton->setText(QApplication::translate("KSJDemoQT_Image", "Preview", 0));
        CaptureButton->setText(QApplication::translate("KSJDemoQT_Image", "Capture", 0));
        ERROR_INFO_Label->setText(QApplication::translate("KSJDemoQT_Image", "Error Info", 0));
        ELAPSE_TIME_Label->setText(QApplication::translate("KSJDemoQT_Image", "Elapse", 0));
        SaveCheckBox->setText(QApplication::translate("KSJDemoQT_Image", "Save", 0));
        groupBox_3->setTitle(QApplication::translate("KSJDemoQT_Image", "Bad Pixel Correction", 0));
        label_13->setText(QApplication::translate("KSJDemoQT_Image", "Threshold Low:", 0));
        label_14->setText(QApplication::translate("KSJDemoQT_Image", "Threshold High:", 0));
        label_15->setText(QApplication::translate("KSJDemoQT_Image", "Threshold Mode:", 0));
        EnableCheckBox->setText(QApplication::translate("KSJDemoQT_Image", "Enable", 0));
        groupBox_4->setTitle(QApplication::translate("KSJDemoQT_Image", "Process", 0));
        label_16->setText(QApplication::translate("KSJDemoQT_Image", "Contrast:", 0));
        label_17->setText(QApplication::translate("KSJDemoQT_Image", "Saturation:", 0));
        label_23->setText(QApplication::translate("KSJDemoQT_Image", "Brghtness:", 0));
        label_24->setText(QApplication::translate("KSJDemoQT_Image", "Gamma:", 0));
        ProcessResetButton->setText(QApplication::translate("KSJDemoQT_Image", "Reset", 0));
        groupBox_5->setTitle(QApplication::translate("KSJDemoQT_Image", "Hue Saturation", 0));
        label_33->setText(QApplication::translate("KSJDemoQT_Image", "Hue:", 0));
        label_34->setText(QApplication::translate("KSJDemoQT_Image", "Lightness:", 0));
        label_35->setText(QApplication::translate("KSJDemoQT_Image", "Saturation:", 0));
        HueResetButton->setText(QApplication::translate("KSJDemoQT_Image", "Reset", 0));
        HueEnableCheckBox->setText(QApplication::translate("KSJDemoQT_Image", "Enable", 0));
        HueSetButton->setText(QApplication::translate("KSJDemoQT_Image", "Set", 0));
        label_36->setText(QApplication::translate("KSJDemoQT_Image", "Hue Range:", 0));
    } // retranslateUi

};

namespace Ui {
    class KSJDemoQT_Image: public Ui_KSJDemoQT_Image {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSJDEMOQT_IMAGE_H
