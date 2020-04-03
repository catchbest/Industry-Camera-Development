/********************************************************************************
** Form generated from reading UI file 'KSJDemoQT_Matrix.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSJDEMOQT_MATRIX_H
#define UI_KSJDEMOQT_MATRIX_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KSJDemoQT_Matrix
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
    QLabel *DEVICENUM_Label_2;
    QComboBox *WBComboBox;
    QComboBox *PresettingComboBox;
    QLabel *DEVICENUM_Label_3;
    QLabel *label_13;
    QSpinBox *PhiSpinBox;
    QSlider *RSlider;
    QLabel *label_14;
    QLineEdit *REdit;
    QSlider *GSlider;
    QLabel *label_15;
    QLineEdit *GEdit;
    QSlider *BSlider;
    QLabel *label_16;
    QLineEdit *BEdit;
    QComboBox *CCMComboBox;
    QLabel *DEVICENUM_Label_4;
    QComboBox *CCMPresettingComboBox;
    QLabel *DEVICENUM_Label_5;
    QSlider *GSlider00;
    QLineEdit *GEdit00;
    QLineEdit *GEdit01;
    QSlider *GSlider01;
    QLineEdit *GEdit02;
    QSlider *GSlider02;
    QSlider *GSlider12;
    QLineEdit *GEdit10;
    QSlider *GSlider10;
    QSlider *GSlider11;
    QLineEdit *GEdit11;
    QLineEdit *GEdit12;
    QLineEdit *GEdit20;
    QSlider *GSlider20;
    QLineEdit *GEdit21;
    QSlider *GSlider22;
    QLineEdit *GEdit22;
    QSlider *GSlider21;

    void setupUi(QDialog *KSJDemoQT_Matrix)
    {
        if (KSJDemoQT_Matrix->objectName().isEmpty())
            KSJDemoQT_Matrix->setObjectName(QStringLiteral("KSJDemoQT_Matrix"));
        KSJDemoQT_Matrix->resize(1199, 561);
        PREVIEWWND_Widget = new QWidget(KSJDemoQT_Matrix);
        PREVIEWWND_Widget->setObjectName(QStringLiteral("PREVIEWWND_Widget"));
        PREVIEWWND_Widget->setGeometry(QRect(-10, 0, 501, 561));
        DEVICENUM_Label = new QLabel(KSJDemoQT_Matrix);
        DEVICENUM_Label->setObjectName(QStringLiteral("DEVICENUM_Label"));
        DEVICENUM_Label->setGeometry(QRect(510, 20, 71, 21));
        DEVICE_LIST_ComboBox = new QComboBox(KSJDemoQT_Matrix);
        DEVICE_LIST_ComboBox->setObjectName(QStringLiteral("DEVICE_LIST_ComboBox"));
        DEVICE_LIST_ComboBox->setGeometry(QRect(590, 20, 301, 22));
        ExposureLinesSpinBox = new QSpinBox(KSJDemoQT_Matrix);
        ExposureLinesSpinBox->setObjectName(QStringLiteral("ExposureLinesSpinBox"));
        ExposureLinesSpinBox->setGeometry(QRect(640, 100, 91, 22));
        GainSpinBox = new QSpinBox(KSJDemoQT_Matrix);
        GainSpinBox->setObjectName(QStringLiteral("GainSpinBox"));
        GainSpinBox->setGeometry(QRect(640, 170, 91, 22));
        label_6 = new QLabel(KSJDemoQT_Matrix);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 170, 41, 21));
        label_7 = new QLabel(KSJDemoQT_Matrix);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(520, 60, 111, 21));
        label_8 = new QLabel(KSJDemoQT_Matrix);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(530, 100, 91, 21));
        ExposureTimeSpinBox = new QSpinBox(KSJDemoQT_Matrix);
        ExposureTimeSpinBox->setObjectName(QStringLiteral("ExposureTimeSpinBox"));
        ExposureTimeSpinBox->setGeometry(QRect(640, 60, 91, 22));
        label_9 = new QLabel(KSJDemoQT_Matrix);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(760, 60, 61, 21));
        label_10 = new QLabel(KSJDemoQT_Matrix);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(760, 100, 41, 21));
        label_11 = new QLabel(KSJDemoQT_Matrix);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(760, 170, 41, 21));
        EXPOSURE_TIME_RANGE_Label = new QLabel(KSJDemoQT_Matrix);
        EXPOSURE_TIME_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_RANGE_Label"));
        EXPOSURE_TIME_RANGE_Label->setGeometry(QRect(830, 60, 71, 21));
        EXPOSURE_LINES_RANGE_Label = new QLabel(KSJDemoQT_Matrix);
        EXPOSURE_LINES_RANGE_Label->setObjectName(QStringLiteral("EXPOSURE_LINES_RANGE_Label"));
        EXPOSURE_LINES_RANGE_Label->setGeometry(QRect(830, 100, 71, 21));
        GAIN_RANGE_Label = new QLabel(KSJDemoQT_Matrix);
        GAIN_RANGE_Label->setObjectName(QStringLiteral("GAIN_RANGE_Label"));
        GAIN_RANGE_Label->setGeometry(QRect(830, 170, 71, 21));
        EXPOSURE_TIME_REAL_Label = new QLabel(KSJDemoQT_Matrix);
        EXPOSURE_TIME_REAL_Label->setObjectName(QStringLiteral("EXPOSURE_TIME_REAL_Label"));
        EXPOSURE_TIME_REAL_Label->setGeometry(QRect(640, 140, 201, 21));
        FOV_RANGE_Label = new QLabel(KSJDemoQT_Matrix);
        FOV_RANGE_Label->setObjectName(QStringLiteral("FOV_RANGE_Label"));
        FOV_RANGE_Label->setGeometry(QRect(640, 200, 201, 21));
        label_12 = new QLabel(KSJDemoQT_Matrix);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(570, 200, 61, 21));
        groupBox = new QGroupBox(KSJDemoQT_Matrix);
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
        groupBox_2 = new QGroupBox(KSJDemoQT_Matrix);
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
        PreviewButton = new QPushButton(KSJDemoQT_Matrix);
        PreviewButton->setObjectName(QStringLiteral("PreviewButton"));
        PreviewButton->setGeometry(QRect(840, 340, 75, 23));
        CaptureButton = new QPushButton(KSJDemoQT_Matrix);
        CaptureButton->setObjectName(QStringLiteral("CaptureButton"));
        CaptureButton->setGeometry(QRect(840, 480, 75, 23));
        ERROR_INFO_Label = new QLabel(KSJDemoQT_Matrix);
        ERROR_INFO_Label->setObjectName(QStringLiteral("ERROR_INFO_Label"));
        ERROR_INFO_Label->setGeometry(QRect(510, 530, 201, 21));
        ELAPSE_TIME_Label = new QLabel(KSJDemoQT_Matrix);
        ELAPSE_TIME_Label->setObjectName(QStringLiteral("ELAPSE_TIME_Label"));
        ELAPSE_TIME_Label->setGeometry(QRect(740, 530, 121, 21));
        FunctionTableWidget = new QTableWidget(KSJDemoQT_Matrix);
        FunctionTableWidget->setObjectName(QStringLiteral("FunctionTableWidget"));
        FunctionTableWidget->setGeometry(QRect(920, 0, 311, 171));
        SaveCheckBox = new QCheckBox(KSJDemoQT_Matrix);
        SaveCheckBox->setObjectName(QStringLiteral("SaveCheckBox"));
        SaveCheckBox->setGeometry(QRect(840, 450, 71, 20));
        DEVICENUM_Label_2 = new QLabel(KSJDemoQT_Matrix);
        DEVICENUM_Label_2->setObjectName(QStringLiteral("DEVICENUM_Label_2"));
        DEVICENUM_Label_2->setGeometry(QRect(930, 190, 51, 21));
        WBComboBox = new QComboBox(KSJDemoQT_Matrix);
        WBComboBox->setObjectName(QStringLiteral("WBComboBox"));
        WBComboBox->setGeometry(QRect(980, 190, 191, 22));
        PresettingComboBox = new QComboBox(KSJDemoQT_Matrix);
        PresettingComboBox->setObjectName(QStringLiteral("PresettingComboBox"));
        PresettingComboBox->setGeometry(QRect(980, 220, 191, 22));
        DEVICENUM_Label_3 = new QLabel(KSJDemoQT_Matrix);
        DEVICENUM_Label_3->setObjectName(QStringLiteral("DEVICENUM_Label_3"));
        DEVICENUM_Label_3->setGeometry(QRect(910, 220, 71, 21));
        label_13 = new QLabel(KSJDemoQT_Matrix);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(950, 250, 31, 21));
        PhiSpinBox = new QSpinBox(KSJDemoQT_Matrix);
        PhiSpinBox->setObjectName(QStringLiteral("PhiSpinBox"));
        PhiSpinBox->setGeometry(QRect(980, 250, 71, 22));
        RSlider = new QSlider(KSJDemoQT_Matrix);
        RSlider->setObjectName(QStringLiteral("RSlider"));
        RSlider->setGeometry(QRect(960, 280, 141, 20));
        RSlider->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(KSJDemoQT_Matrix);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(940, 280, 16, 16));
        REdit = new QLineEdit(KSJDemoQT_Matrix);
        REdit->setObjectName(QStringLiteral("REdit"));
        REdit->setGeometry(QRect(1110, 280, 51, 20));
        REdit->setReadOnly(true);
        GSlider = new QSlider(KSJDemoQT_Matrix);
        GSlider->setObjectName(QStringLiteral("GSlider"));
        GSlider->setGeometry(QRect(960, 310, 141, 20));
        GSlider->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(KSJDemoQT_Matrix);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(940, 310, 16, 16));
        GEdit = new QLineEdit(KSJDemoQT_Matrix);
        GEdit->setObjectName(QStringLiteral("GEdit"));
        GEdit->setGeometry(QRect(1110, 310, 51, 20));
        GEdit->setReadOnly(true);
        BSlider = new QSlider(KSJDemoQT_Matrix);
        BSlider->setObjectName(QStringLiteral("BSlider"));
        BSlider->setGeometry(QRect(960, 340, 141, 20));
        BSlider->setOrientation(Qt::Horizontal);
        label_16 = new QLabel(KSJDemoQT_Matrix);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(940, 340, 16, 16));
        BEdit = new QLineEdit(KSJDemoQT_Matrix);
        BEdit->setObjectName(QStringLiteral("BEdit"));
        BEdit->setGeometry(QRect(1110, 340, 51, 20));
        BEdit->setReadOnly(true);
        CCMComboBox = new QComboBox(KSJDemoQT_Matrix);
        CCMComboBox->setObjectName(QStringLiteral("CCMComboBox"));
        CCMComboBox->setGeometry(QRect(980, 370, 191, 22));
        DEVICENUM_Label_4 = new QLabel(KSJDemoQT_Matrix);
        DEVICENUM_Label_4->setObjectName(QStringLiteral("DEVICENUM_Label_4"));
        DEVICENUM_Label_4->setGeometry(QRect(920, 370, 51, 21));
        CCMPresettingComboBox = new QComboBox(KSJDemoQT_Matrix);
        CCMPresettingComboBox->setObjectName(QStringLiteral("CCMPresettingComboBox"));
        CCMPresettingComboBox->setGeometry(QRect(980, 400, 191, 22));
        DEVICENUM_Label_5 = new QLabel(KSJDemoQT_Matrix);
        DEVICENUM_Label_5->setObjectName(QStringLiteral("DEVICENUM_Label_5"));
        DEVICENUM_Label_5->setGeometry(QRect(910, 400, 71, 21));
        GSlider00 = new QSlider(KSJDemoQT_Matrix);
        GSlider00->setObjectName(QStringLiteral("GSlider00"));
        GSlider00->setGeometry(QRect(930, 450, 41, 20));
        GSlider00->setOrientation(Qt::Horizontal);
        GEdit00 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit00->setObjectName(QStringLiteral("GEdit00"));
        GEdit00->setGeometry(QRect(979, 450, 31, 20));
        GEdit00->setReadOnly(true);
        GEdit01 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit01->setObjectName(QStringLiteral("GEdit01"));
        GEdit01->setGeometry(QRect(1070, 450, 31, 20));
        GEdit01->setReadOnly(true);
        GSlider01 = new QSlider(KSJDemoQT_Matrix);
        GSlider01->setObjectName(QStringLiteral("GSlider01"));
        GSlider01->setGeometry(QRect(1020, 450, 41, 20));
        GSlider01->setOrientation(Qt::Horizontal);
        GEdit02 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit02->setObjectName(QStringLiteral("GEdit02"));
        GEdit02->setGeometry(QRect(1160, 450, 31, 20));
        GEdit02->setReadOnly(true);
        GSlider02 = new QSlider(KSJDemoQT_Matrix);
        GSlider02->setObjectName(QStringLiteral("GSlider02"));
        GSlider02->setGeometry(QRect(1110, 450, 41, 20));
        GSlider02->setOrientation(Qt::Horizontal);
        GSlider12 = new QSlider(KSJDemoQT_Matrix);
        GSlider12->setObjectName(QStringLiteral("GSlider12"));
        GSlider12->setGeometry(QRect(1110, 480, 41, 20));
        GSlider12->setOrientation(Qt::Horizontal);
        GEdit10 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit10->setObjectName(QStringLiteral("GEdit10"));
        GEdit10->setGeometry(QRect(979, 480, 31, 20));
        GEdit10->setReadOnly(true);
        GSlider10 = new QSlider(KSJDemoQT_Matrix);
        GSlider10->setObjectName(QStringLiteral("GSlider10"));
        GSlider10->setGeometry(QRect(930, 480, 41, 20));
        GSlider10->setOrientation(Qt::Horizontal);
        GSlider11 = new QSlider(KSJDemoQT_Matrix);
        GSlider11->setObjectName(QStringLiteral("GSlider11"));
        GSlider11->setGeometry(QRect(1020, 480, 41, 20));
        GSlider11->setOrientation(Qt::Horizontal);
        GEdit11 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit11->setObjectName(QStringLiteral("GEdit11"));
        GEdit11->setGeometry(QRect(1070, 480, 31, 20));
        GEdit11->setReadOnly(true);
        GEdit12 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit12->setObjectName(QStringLiteral("GEdit12"));
        GEdit12->setGeometry(QRect(1160, 480, 31, 20));
        GEdit12->setReadOnly(true);
        GEdit20 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit20->setObjectName(QStringLiteral("GEdit20"));
        GEdit20->setGeometry(QRect(979, 510, 31, 20));
        GEdit20->setReadOnly(true);
        GSlider20 = new QSlider(KSJDemoQT_Matrix);
        GSlider20->setObjectName(QStringLiteral("GSlider20"));
        GSlider20->setGeometry(QRect(930, 510, 41, 20));
        GSlider20->setOrientation(Qt::Horizontal);
        GEdit21 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit21->setObjectName(QStringLiteral("GEdit21"));
        GEdit21->setGeometry(QRect(1070, 510, 31, 20));
        GEdit21->setReadOnly(true);
        GSlider22 = new QSlider(KSJDemoQT_Matrix);
        GSlider22->setObjectName(QStringLiteral("GSlider22"));
        GSlider22->setGeometry(QRect(1110, 510, 41, 20));
        GSlider22->setOrientation(Qt::Horizontal);
        GEdit22 = new QLineEdit(KSJDemoQT_Matrix);
        GEdit22->setObjectName(QStringLiteral("GEdit22"));
        GEdit22->setGeometry(QRect(1159, 510, 31, 20));
        GEdit22->setReadOnly(true);
        GSlider21 = new QSlider(KSJDemoQT_Matrix);
        GSlider21->setObjectName(QStringLiteral("GSlider21"));
        GSlider21->setGeometry(QRect(1020, 510, 41, 20));
        GSlider21->setOrientation(Qt::Horizontal);

        retranslateUi(KSJDemoQT_Matrix);

        QMetaObject::connectSlotsByName(KSJDemoQT_Matrix);
    } // setupUi

    void retranslateUi(QDialog *KSJDemoQT_Matrix)
    {
        KSJDemoQT_Matrix->setWindowTitle(QApplication::translate("KSJDemoQT_Matrix", "KSJDemoQT", 0));
        DEVICENUM_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Device Num:", 0));
        label_6->setText(QApplication::translate("KSJDemoQT_Matrix", "Gain:", 0));
        label_7->setText(QApplication::translate("KSJDemoQT_Matrix", "Exposure Time(ms):", 0));
        label_8->setText(QApplication::translate("KSJDemoQT_Matrix", "Exposure Lines:", 0));
        label_9->setText(QApplication::translate("KSJDemoQT_Matrix", "Range(ms):", 0));
        label_10->setText(QApplication::translate("KSJDemoQT_Matrix", "Range:", 0));
        label_11->setText(QApplication::translate("KSJDemoQT_Matrix", "Range:", 0));
        EXPOSURE_TIME_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Range", 0));
        EXPOSURE_LINES_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Range", 0));
        GAIN_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Range", 0));
        EXPOSURE_TIME_REAL_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "REAL EXP TIME", 0));
        FOV_RANGE_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "EXP LINES RANGE", 0));
        label_12->setText(QApplication::translate("KSJDemoQT_Matrix", "FOV Range:", 0));
        groupBox->setTitle(QApplication::translate("KSJDemoQT_Matrix", "Preview", 0));
        label->setText(QApplication::translate("KSJDemoQT_Matrix", "Col Start:", 0));
        label_2->setText(QApplication::translate("KSJDemoQT_Matrix", "Row Start:", 0));
        label_3->setText(QApplication::translate("KSJDemoQT_Matrix", "Col Size:", 0));
        label_4->setText(QApplication::translate("KSJDemoQT_Matrix", "Row Size:", 0));
        label_5->setText(QApplication::translate("KSJDemoQT_Matrix", "MultiFrame:", 0));
        SetPreviewFovButton->setText(QApplication::translate("KSJDemoQT_Matrix", "Set Preview Fov", 0));
        groupBox_2->setTitle(QApplication::translate("KSJDemoQT_Matrix", "Capture", 0));
        label_18->setText(QApplication::translate("KSJDemoQT_Matrix", "Col Start:", 0));
        label_19->setText(QApplication::translate("KSJDemoQT_Matrix", "Row Start:", 0));
        label_20->setText(QApplication::translate("KSJDemoQT_Matrix", "Col Size:", 0));
        label_21->setText(QApplication::translate("KSJDemoQT_Matrix", "Row Size:", 0));
        label_22->setText(QApplication::translate("KSJDemoQT_Matrix", "MultiFrame:", 0));
        SetCaptureFovButton->setText(QApplication::translate("KSJDemoQT_Matrix", "Set Capture Fov", 0));
        PreviewButton->setText(QApplication::translate("KSJDemoQT_Matrix", "Preview", 0));
        CaptureButton->setText(QApplication::translate("KSJDemoQT_Matrix", "Capture", 0));
        ERROR_INFO_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Error Info", 0));
        ELAPSE_TIME_Label->setText(QApplication::translate("KSJDemoQT_Matrix", "Elapse", 0));
        SaveCheckBox->setText(QApplication::translate("KSJDemoQT_Matrix", "Save", 0));
        DEVICENUM_Label_2->setText(QApplication::translate("KSJDemoQT_Matrix", "WB Mode:", 0));
        DEVICENUM_Label_3->setText(QApplication::translate("KSJDemoQT_Matrix", "Presetting:", 0));
        label_13->setText(QApplication::translate("KSJDemoQT_Matrix", "Phi:", 0));
        label_14->setText(QApplication::translate("KSJDemoQT_Matrix", "R:", 0));
        label_15->setText(QApplication::translate("KSJDemoQT_Matrix", "G:", 0));
        label_16->setText(QApplication::translate("KSJDemoQT_Matrix", "B:", 0));
        DEVICENUM_Label_4->setText(QApplication::translate("KSJDemoQT_Matrix", "CCM Mode:", 0));
        DEVICENUM_Label_5->setText(QApplication::translate("KSJDemoQT_Matrix", "Presetting:", 0));
    } // retranslateUi

};

namespace Ui {
    class KSJDemoQT_Matrix: public Ui_KSJDemoQT_Matrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSJDEMOQT_MATRIX_H
