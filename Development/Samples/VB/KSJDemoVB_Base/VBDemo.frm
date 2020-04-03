VERSION 5.00
Begin VB.Form VBDemoForm 
   ClientHeight    =   8265
   ClientLeft      =   5880
   ClientTop       =   4230
   ClientWidth     =   18105
   LinkTopic       =   "CatchBest VB Demo"
   ScaleHeight     =   8265
   ScaleWidth      =   18105
   Begin VB.TextBox FIXED_FRAME_RATE 
      Height          =   270
      Left            =   15480
      TabIndex        =   56
      Top             =   6000
      Width           =   2175
   End
   Begin VB.TextBox TriggerDelay 
      Height          =   270
      Left            =   15240
      TabIndex        =   54
      Top             =   5280
      Width           =   1575
   End
   Begin VB.ComboBox Combo_TriggerMothod 
      Height          =   300
      Left            =   15240
      Style           =   2  'Dropdown List
      TabIndex        =   52
      Top             =   4560
      Width           =   2535
   End
   Begin VB.ComboBox Combo_TriggerMode 
      Height          =   300
      Left            =   15240
      Style           =   2  'Dropdown List
      TabIndex        =   50
      Top             =   4080
      Width           =   2535
   End
   Begin VB.CheckBox Check_Recover 
      Caption         =   "Recover"
      Height          =   255
      Left            =   16800
      TabIndex        =   48
      Top             =   3480
      Width           =   975
   End
   Begin VB.ComboBox Combo_Timeout 
      Height          =   300
      Left            =   15240
      Style           =   2  'Dropdown List
      TabIndex        =   47
      Top             =   3480
      Width           =   1335
   End
   Begin VB.CheckBox Check_Enable 
      Caption         =   "Enable"
      Height          =   255
      Left            =   16440
      TabIndex        =   45
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CheckBox Check_Invert 
      Caption         =   "Invert"
      Height          =   255
      Left            =   15240
      TabIndex        =   44
      Top             =   2880
      Width           =   975
   End
   Begin VB.CheckBox Check_Preview 
      Caption         =   "Preview"
      Height          =   495
      Left            =   5280
      Style           =   1  'Graphical
      TabIndex        =   41
      Top             =   5280
      Width           =   1935
   End
   Begin VB.Frame Frame2 
      Caption         =   "Capture"
      Height          =   1335
      Left            =   5280
      TabIndex        =   31
      Top             =   5880
      Width           =   8055
      Begin VB.TextBox CaptureRowSize 
         Height          =   270
         Left            =   3480
         TabIndex        =   36
         Top             =   840
         Width           =   975
      End
      Begin VB.TextBox CaptureRowStart 
         Height          =   270
         Left            =   3480
         TabIndex        =   35
         Top             =   360
         Width           =   975
      End
      Begin VB.TextBox CaptureColSize 
         Height          =   270
         Left            =   1200
         TabIndex        =   34
         Top             =   840
         Width           =   975
      End
      Begin VB.TextBox CaptureColStart 
         Height          =   270
         Left            =   1200
         TabIndex        =   33
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton SetCapture 
         Caption         =   "Set Capture Field Of View"
         Height          =   375
         Left            =   4920
         TabIndex        =   32
         Top             =   720
         Width           =   2655
      End
      Begin VB.Label Label15 
         Caption         =   "Col Start:"
         Height          =   255
         Left            =   120
         TabIndex        =   40
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label14 
         Caption         =   "Row Size:"
         Height          =   255
         Left            =   2400
         TabIndex        =   39
         Top             =   840
         Width           =   975
      End
      Begin VB.Label Label12 
         Caption         =   "Row Start:"
         Height          =   255
         Left            =   2400
         TabIndex        =   38
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label5 
         Caption         =   "Col Size:"
         Height          =   255
         Left            =   120
         TabIndex        =   37
         Top             =   840
         Width           =   975
      End
   End
   Begin VB.ListBox Funtion 
      Height          =   1860
      Left            =   13800
      TabIndex        =   29
      Top             =   600
      Width           =   3975
   End
   Begin VB.Frame Frame1 
      Caption         =   "Preview"
      Height          =   1335
      Left            =   5280
      TabIndex        =   20
      Top             =   3720
      Width           =   8055
      Begin VB.CommandButton SetPreview 
         Caption         =   "Set Preview Field Of View"
         Height          =   375
         Left            =   4920
         TabIndex        =   30
         Top             =   720
         Width           =   2655
      End
      Begin VB.TextBox PreviewColStart 
         Height          =   270
         Left            =   1200
         TabIndex        =   25
         Top             =   360
         Width           =   975
      End
      Begin VB.TextBox PreviewColSize 
         Height          =   270
         Left            =   1200
         TabIndex        =   24
         Top             =   840
         Width           =   975
      End
      Begin VB.TextBox PreviewRowStart 
         Height          =   270
         Left            =   3480
         TabIndex        =   23
         Top             =   360
         Width           =   975
      End
      Begin VB.TextBox PreviewRowSize 
         Height          =   270
         Left            =   3480
         TabIndex        =   22
         Top             =   840
         Width           =   975
      End
      Begin VB.Label Label11 
         Caption         =   "Col Size:"
         Height          =   255
         Left            =   120
         TabIndex        =   28
         Top             =   840
         Width           =   975
      End
      Begin VB.Label Label10 
         Caption         =   "Row Start:"
         Height          =   255
         Left            =   2400
         TabIndex        =   27
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label9 
         Caption         =   "Row Size:"
         Height          =   255
         Left            =   2400
         TabIndex        =   26
         Top             =   840
         Width           =   975
      End
      Begin VB.Label Label13 
         Caption         =   "Col Start:"
         Height          =   255
         Left            =   120
         TabIndex        =   21
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.TextBox Gain 
      Height          =   270
      Left            =   7080
      TabIndex        =   16
      Top             =   2760
      Width           =   1335
   End
   Begin VB.TextBox FovRange 
      Enabled         =   0   'False
      Height          =   270
      Left            =   7080
      TabIndex        =   15
      Top             =   3240
      Width           =   1335
   End
   Begin VB.TextBox GainRange 
      Enabled         =   0   'False
      Height          =   270
      Left            =   10680
      TabIndex        =   14
      Top             =   2760
      Width           =   1335
   End
   Begin VB.TextBox ExposureReal 
      Enabled         =   0   'False
      Height          =   270
      Left            =   7080
      TabIndex        =   13
      Top             =   2040
      Width           =   2175
   End
   Begin VB.TextBox LinesRange 
      Enabled         =   0   'False
      Height          =   270
      Left            =   10680
      TabIndex        =   11
      Top             =   1560
      Width           =   1335
   End
   Begin VB.TextBox TimeRange 
      Enabled         =   0   'False
      Height          =   270
      Left            =   10680
      TabIndex        =   9
      Top             =   1080
      Width           =   1335
   End
   Begin VB.TextBox ExposureLines 
      Height          =   270
      Left            =   7080
      TabIndex        =   7
      Top             =   1560
      Width           =   1335
   End
   Begin VB.TextBox ExposureTime 
      Height          =   270
      Left            =   7080
      TabIndex        =   6
      Top             =   1080
      Width           =   1335
   End
   Begin VB.PictureBox CaptureWnd 
      AutoRedraw      =   -1  'True
      Height          =   3720
      Left            =   120
      ScaleHeight     =   3660
      ScaleWidth      =   4545
      TabIndex        =   3
      Top             =   4320
      Width           =   4605
   End
   Begin VB.Timer Timer1 
      Interval        =   2000
      Left            =   8040
      Top             =   7440
   End
   Begin VB.CommandButton Catpure 
      Caption         =   "Capture"
      Height          =   495
      Left            =   5280
      TabIndex        =   2
      Top             =   7440
      Width           =   1935
   End
   Begin VB.ComboBox Combo_Device_List 
      Height          =   300
      ItemData        =   "VBDemo.frx":0000
      Left            =   6720
      List            =   "VBDemo.frx":0002
      Style           =   2  'Dropdown List
      TabIndex        =   0
      Top             =   120
      Width           =   3495
   End
   Begin VB.PictureBox PreviewWnd 
      Height          =   3720
      Left            =   120
      ScaleHeight     =   263.784
      ScaleMode       =   0  'User
      ScaleWidth      =   342.011
      TabIndex        =   1
      Top             =   240
      Width           =   4605
   End
   Begin VB.Label Label22 
      Caption         =   "Fixed Frame Rate(HW):"
      Height          =   255
      Left            =   13560
      TabIndex        =   55
      Top             =   6000
      Width           =   1935
   End
   Begin VB.Label Label21 
      Caption         =   "Trigger Delay:"
      Height          =   255
      Left            =   13800
      TabIndex        =   53
      Top             =   5280
      Width           =   1335
   End
   Begin VB.Label Label20 
      Caption         =   "Trigger Method:"
      Height          =   255
      Left            =   13680
      TabIndex        =   51
      Top             =   4560
      Width           =   1455
   End
   Begin VB.Label Label19 
      Caption         =   "Trigger Mode:"
      Height          =   255
      Left            =   13800
      TabIndex        =   49
      Top             =   4080
      Width           =   1215
   End
   Begin VB.Label Label18 
      Caption         =   "Read Timeout:"
      Height          =   255
      Left            =   13800
      TabIndex        =   46
      Top             =   3480
      Width           =   1335
   End
   Begin VB.Label Label17 
      Caption         =   "Flash Control:"
      Height          =   255
      Left            =   13800
      TabIndex        =   43
      Top             =   2880
      Width           =   1335
   End
   Begin VB.Label Label16 
      Caption         =   "Funtion"
      Height          =   255
      Left            =   13920
      TabIndex        =   42
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label8 
      Caption         =   "Gain:"
      Height          =   255
      Left            =   5280
      TabIndex        =   19
      Top             =   2760
      Width           =   1695
   End
   Begin VB.Label Label7 
      Caption         =   "FOV Range:"
      Height          =   255
      Left            =   5280
      TabIndex        =   18
      Top             =   3240
      Width           =   1695
   End
   Begin VB.Label Label6 
      Caption         =   "Range:"
      Height          =   255
      Left            =   9600
      TabIndex        =   17
      Top             =   2760
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "Range:"
      Height          =   255
      Left            =   9480
      TabIndex        =   12
      Top             =   1560
      Width           =   1095
   End
   Begin VB.Label Label3 
      Caption         =   "Range(ms):"
      Height          =   255
      Left            =   9480
      TabIndex        =   10
      Top             =   1080
      Width           =   1095
   End
   Begin VB.Label Label2 
      Caption         =   "Exposure Lines:"
      Height          =   255
      Left            =   5160
      TabIndex        =   8
      Top             =   1560
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "Exposure Time(ms):"
      Height          =   255
      Left            =   5160
      TabIndex        =   5
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label LABEL_DEVICENUM 
      Caption         =   "Device Number"
      Height          =   255
      Left            =   5160
      TabIndex        =   4
      Top             =   120
      Width           =   1455
   End
End
Attribute VB_Name = "VBDemoForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public g_nDeviceNum  As Long
Public g_nPreviewWidth As Long
Public g_nPreviewHeight As Long
Public g_nBitCount As Long
Public g_nCaptureWidth As Long
Public g_nCaptureHeight As Long
Public g_nCurIndex As Long


Private Sub Check_Enable_Click()
    If g_nCurIndex = -1 Then Exit Sub
    SetFlash
End Sub

Private Sub Check_Invert_Click()
    If g_nCurIndex = -1 Then Exit Sub
    SetFlash
End Sub

Private Function SetFlash()
    Dim nRet As Long
    nRet = KSJ_FlashControlSet(g_nCurIndex, Check_Enable.Value, Check_Invert.Value, nMode)

End Function

Private Sub Check_Recover_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    
    nRet = KSJ_CaptureSetRecover(g_nCurIndex, Check_Recover.Value)
End Sub

Private Sub Combo_Timeout_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    Dim szTimeOut(5) As Long
    szTimeOut(0) = 8000
    szTimeOut(1) = &HFFFFFFFF
    szTimeOut(2) = 500
    szTimeOut(3) = 1000
    szTimeOut(4) = 2000
    szTimeOut(5) = 5000

    nRet = KSJ_CaptureSetTimeOut(g_nCurIndex, szTimeOut(Combo_Timeout.ListIndex))
End Sub

Private Sub Combo_TriggerMode_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_TriggerModeSet(m_nDeviceCurSel, Combo_TriggerMode.ListIndex)
End Sub

Private Sub Combo_TriggerMothod_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_TriggerMethodSet(m_nDeviceCurSel, Combo_TriggerMothod.ListIndex)
End Sub

Private Sub FIXED_FRAME_RATE_Change()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_SetFixedFrameRateEx(m_nDeviceCurSel, Val(FIXED_FRAME_RATE.Text))
End Sub

Private Sub TriggerDelay_Change()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_TriggerDelaySet(g_nCurIndex, Val(TriggerDelay.Text))
    
End Sub

Private Sub Form_Load()

    Dim nRet As Long
    Dim i As Integer
    Dim nIndex As Long
    Dim DeviceType As KSJ_DEVICETYPE
    Dim nSerials As Long
    Dim wFirmwareVersion As Integer
    Dim Pt As POINT
    Dim Rec     As RECT
    nRet = GetWindowRect(PreviewWnd.hwnd, Rec)
    Pt.x = Rec.Left
    Pt.y = Rec.Top
    nRet = ScreenToClient(VBDemoForm.hwnd, Pt)
    nRet = MoveWindow(PreviewWnd.hwnd, Pt.x, Pt.y, 320, 240, 1)
    nRet = MoveWindow(CaptureWnd.hwnd, Pt.x, Pt.y + 260, 320, 240, 1)
    
    nRet = KSJ_Init
    g_nDeviceNum = KSJ_DeviceGetCount
    
    If g_nDeviceNum <> 0 Then
    
    For i = 0 To g_nDeviceNum - 1 Step 1
        nRet = KSJ_DeviceGetInformation(i, DeviceType, nSerials, wFirmwareVersion)
        Combo_Device_List.AddItem (Str(i) + ", DeviceType:" + Str(DeviceType) + ", Serials" + Str(nSerials))
    Next i

    LABEL_DEVICENUM.Caption = Str(g_nDeviceNum) + "Device Found:"
    
    g_nCurIndex = -1
  
    Else
    End If
    
    FunctionName(0) = "KSJ_PROPERTY_MONO_DEVICE"
    FunctionName(1) = "KSJ_PROPERTY_ADC_RESOLUTION"
    FunctionName(2) = "KSJ_SUPPORT_MIRROR"
    FunctionName(3) = "KSJ_SUPPORT_FLIP"
    FunctionName(4) = "KSJ_SUPPORT_SKIP2"
    FunctionName(5) = "KSJ_SUPPORT_SKIP3"
    FunctionName(6) = "KSJ_SUPPORT_SKIP4"
    FunctionName(7) = "KSJ_SUPPORT_SKIP8"
    FunctionName(8) = "KSJ_SUPPORT_BINNING"
    FunctionName(9) = "KSJ_SUPPORT_AGC"
    FunctionName(10) = "KSJ_SUPPORT_AEC"
    FunctionName(11) = "KSJ_SUPPORT_TRIGGER_MODE_EXTERNAL"
    FunctionName(12) = "KSJ_SUPPORT_TRIGGER_MODE_SOFTWARE"
    FunctionName(13) = "KSJ_SUPPORT_TRIGGER_MODE_FIXED_FRAMERATE"
    FunctionName(14) = "KSJ_SUPPORT_FIXED_FRAMERATE_SW"
    FunctionName(15) = "KSJ_SUPPORT_FIXED_FRAMERATE_HW"
    FunctionName(16) = "KSJ_SUPPORT_LUT_ENABLE"
    FunctionName(17) = "KSJ_SUPPORT_TRIGGER_METHOD_NEGEDGE"
    FunctionName(18) = "KSJ_SUPPORT_TRIGGER_METHOD_POSEDGE"
    FunctionName(19) = "KSJ_SUPPORT_TRIGGER_METHOD_HIGH_LEVEL"
    FunctionName(20) = "KSJ_SUPPORT_TRIGGER_METHOD_LOW_LEVEL"
    FunctionName(21) = "KSJ_SUPPORT_EMPTY_FRAMEBUFFER"
    FunctionName(22) = "KSJ_SUPPORT_SENSITIVITY_MODE"
    FunctionName(23) = "KSJ_SUPPORT_16BITS"
    FunctionName(24) = "KSJ_SUPPORT_BAD_PIXEL_CORRECTION"
    FunctionName(25) = "KSJ_SUPPORT_LUT_DOWNLOAD"
    FunctionName(26) = "KSJ_SUPPORT_HWB_PRESETTINGS"
    FunctionName(27) = "KSJ_SUPPORT_HWB_PRESETTINGS_NUM"
    FunctionName(28) = "KSJ_SUPPORT_HWB_AUTO_ONCE"
    FunctionName(29) = "KSJ_SUPPORT_HWB_AUTO_CONTINUOUS"
    FunctionName(30) = "KSJ_SUPPORT_HCCM_PRESETTINGS"
    FunctionName(31) = "KSJ_SUPPORT_HCCM_PRESETTINGS_NUM"
    FunctionName(32) = "KSJ_SUPPORT_GAMMA_LUT_ENABLE"
    FunctionName(33) = "KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD"
    FunctionName(34) = "KSJ_SUPPORT_TRIGGER_DELAY"
    FunctionName(35) = "KSJ_SUPPORT_MULTI_FRAMES"
    FunctionName(36) = "KSJ_SUPPORT_HWB_MATRIX"
    FunctionName(37) = "KSJ_SUPPORT_HCCM_MATRIX"
    FunctionName(38) = "KSJ_SUPPORT_GPIO_NORMAL"
    FunctionName(39) = "KSJ_SUPPORT_IO_FILTER"
    FunctionName(40) = "KSJ_SUPPORT_WATERMAK"
    FunctionName(41) = "KSJ_SUPPORT_GET_FRAME_BUFFER_STATE"
    FunctionName(42) = "KSJ_SUPPORT_RESET_DEVICE"
    FunctionName(43) = "KSJ_SUPPORT_SEND_PKT_END"
    FunctionName(44) = "KSJ_SUPPORT_RECONNECT"
    FunctionName(45) = "KSJ_SUPPORT_FAST_UPDATE"
    FunctionName(46) = "KSJ_SUPPORT_WORKINGMODE_PROGRAM"
    FunctionName(47) = "KSJ_SUPPORT_SERIALSDESC_PROGRAM"
    FunctionName(48) = "KSJ_SUPPORT_LUT_PROGRAM"
    FunctionName(49) = "KSJ_SUPPORT_GAMMA_LUT_PROGRAM"
    FunctionName(50) = "KSJ_SUPPORT_WORKINGMODEEX_PROGRAM"
    FunctionName(51) = "KSJ_SUPPORT_COLORMODE_PROGRAM"
    FunctionName(52) = "KSJ_SUPPORT_COLORMATRIX_PROGRAM"
    FunctionName(53) = "KSJ_SUPPORT_SNAP_BUTTON"
    FunctionName(54) = "KSJ_SUPPORT_IO_NUM"
    
End Sub

Private Function UpdateInterface()
    Dim nMin As Long
    Dim nMax As Long
    Dim nCur As Long
    Dim bRet As Boolean
     
    nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_EXPOSURE, nMin, nMax)
    nRet = KSJ_GetParam(g_nCurIndex, KSJ_EXPOSURE, nCur)
    ExposureTime.Text = Str(nCur)
    TimeRange.Text = Str(nMin) + "-" + Str(nMax)
     
    nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_EXPOSURE_LINES, nMin, nMax)
    nRet = KSJ_GetParam(g_nCurIndex, KSJ_EXPOSURE_LINES, nCur)
    ExposureLines.Text = Str(nCur)
    LinesRange.Text = Str(nMin) + "-" + Str(nMax) + "ms"
    
    nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_RED, nMin, nMax)
    nRet = KSJ_GetParam(g_nCurIndex, KSJ_RED, nCur)
    Gain.Text = Str(nCur)
    GainRange.Text = Str(nMin) + "-" + Str(nMax)

    Dim nTop As Long
    Dim nLeft As Long
    Dim nWidth As Long
    Dim nHeight As Long
    Dim RowSkip As KSJ_ADDRESSMODE
    Dim ColSkip As KSJ_ADDRESSMODE
    nRet = KSJ_PreviewGetFieldOfView(g_nCurIndex, nLeft, nTop, nWidth, nHeight, RowSkip, ColSkip)
    FovRange.Text = Str(nWidth) + "-" + Str(nHeight)
    PreviewColStart.Text = Str(nLeft)
    PreviewColSize.Text = Str(nWidth)
    PreviewRowStart.Text = Str(nTop)
    PreviewRowSize.Text = Str(nHeight)
    nRet = KSJ_CaptureGetFieldOfView(g_nCurIndex, nLeft, nTop, nWidth, nHeight, RowSkip, ColSkip)
    CaptureColStart.Text = Str(nLeft)
    CaptureColSize.Text = Str(nWidth)
    CaptureRowStart.Text = Str(nTop)
    CaptureRowSize.Text = Str(nHeight)
    
    Dim bEnable As Boolean
    Dim bInvert As Boolean
    Dim nMode As Long
    nRet = KSJ_FlashControlGet(g_nCurIndex, bEnable, bInvert, nMode)
    Check_Enable.Value = bEnable
    Check_Invert.Value = bInvert
    
    Dim i As Integer
    Dim szTimeOut(5) As String
    szTimeOut(0) = "Default 8S"
    szTimeOut(1) = "Infinite"
    szTimeOut(2) = "500mS"
    szTimeOut(3) = "1S"
    szTimeOut(4) = "2S"
    szTimeOut(5) = "5S"
    Combo_Timeout.Clear
    For i = 0 To 5 Step 1
        Combo_Timeout.AddItem (szTimeOut(i))
    Next i
    Combo_Timeout.ListIndex = 0
    nRet = KSJ_CaptureSetTimeOut(g_nCurIndex, 8000)
    
    Dim bRecover As Boolean
    nRet = KSJ_CaptureGetRecover(g_nCurIndex, bRecover)
    Check_Recover.Value = bRecover
    
    Dim szTriggerMode(3) As String
    Dim TriggerMode As KSJ_TRIGGERMODE
    szTriggerMode(0) = "Internal"
    szTriggerMode(1) = "External"
    szTriggerMode(2) = "Software"
    szTriggerMode(3) = "Fixed Frame Rate"
    For i = 0 To 3 Step 1
        Combo_TriggerMode.AddItem (szTriggerMode(i))
    Next i
    nRet = KSJ_TriggerModeGet(g_nCurIndex, TriggerMode)
    Combo_TriggerMode.ListIndex = TriggerMode
    
    Dim szTriggerMetho(3) As String
    Dim TriggerMethod As KSJ_TRIGGERMETHOD
    szTriggerMetho(0) = "Falling Edge"
    szTriggerMetho(1) = "Rising Edge"
    szTriggerMetho(2) = "High Level"
    szTriggerMetho(3) = "Low Level"
    For i = 0 To 3 Step 1
        Combo_TriggerMothod.AddItem (szTriggerMetho(i))
    Next i
    nRet = KSJ_TriggerMethodGet(g_nCurIndex, TriggerMethod)
    Combo_TriggerMothod.ListIndex = TriggerMethod
    
    Dim Delay As Long
    nRet = KSJ_TriggerDelayGet(g_nCurIndex, Delay)
    TriggerDelay.Text = Str(Delay)
    
    Dim FrameRate As Single
    nRet = KSJ_GetFixedFrameRate(g_nCurIndex, bEnable, FrameRate)
    FIXED_FRAME_RATE.Text = Str(FrameRate)
End Function

Private Function UpdateInterfaceFunction()
    Funtion.Clear
    Dim nSupport As Long
    Dim i As Integer
    For i = 0 To 54 Step 1
        nRet = KSJ_QueryFunction(g_nCurIndex, i, nSupport)
        Funtion.AddItem FunctionName(i) + Str(nSupport)
    Next i
    
End Function

Private Sub Catpure_Click()
    If g_nCurIndex = -1 Then Exit Sub

    Dim nRet As Long
    Dim pRgbData() As Byte
    Dim nRgbDataSize As Long
    Dim biBitInfo As BITMAPINFO
    Dim bRet As Boolean
Const pixR = 3
Const pixG = 2
Const pixB = 1

    nRet = KSJ_CaptureGetSize(g_nCurIndex, g_nCaptureWidth, g_nCaptureHeight)
    nRet = KSJ_CaptureGetSizeEx(g_nCurIndex, g_nCaptureWidth, g_nCaptureHeight, g_nBitCount)
    
    nRgbDataSize = g_nCaptureWidth * g_nCaptureHeight * (g_nBitCount / 8)
    ReDim pRgbData(1 To g_nBitCount / 8, 1 To g_nCaptureWidth, 1 To g_nCaptureHeight)
    
    nRet = KSJ_CaptureRgbData(g_nCurIndex, pRgbData(1, 1, 1))
    nRet = KSJ_HelperSaveToBmp(pRgbData(1, 1, 1), g_nCaptureWidth, g_nCaptureHeight, g_nBitCount, "Capture1.bmp")

    With biBitInfo.bmiHeader
        .biBitCount = g_nBitCount
        .biCompression = BI_RGB
        .biPlanes = 1
        .biSize = Len(biBitInfo.bmiHeader)
        .biWidth = g_nCaptureWidth
        .biHeight = g_nCaptureHeight
        .biSizeImage = nRgbDataSize
         
    End With
    
    Dim i As Integer

    For i = 0 To 255
        biBitInfo.bmiColors(i).rgbRed = i
        biBitInfo.bmiColors(i).rgbGreen = i
        biBitInfo.bmiColors(i).rgbBlue = i
        biBitInfo.bmiColors(i).rgbReserved = i
    Next i
    
    nRet = SetStretchBltMode(CaptureWnd.hDC, 3)
    nRet = StretchDIBits(CaptureWnd.hDC, 0, 0, ScaleX(CaptureWnd.Width, vbTwips, vbPixels), ScaleY(CaptureWnd.Height, vbTwips, vbPixels), 0, 0, g_nCaptureWidth, g_nCaptureHeight, pRgbData(1, 1, 1), biBitInfo, DIB_RGB_COLORS, vbSrcCopy)
    CaptureWnd.Refresh

    
End Sub

Private Sub Check_Preview_Click()
    If g_nCurIndex = -1 Then Exit Sub
    If Check_Preview.Value = 1 Then
        nRet = KSJ_PreviewSetPos(g_nCurIndex, PreviewWnd.hwnd, 0, 0, ScaleX(CaptureWnd.Width, vbTwips, vbPixels), ScaleY(CaptureWnd.Height, vbTwips, vbPixels))
        nRet = KSJ_PreviewStartEx(g_nCurIndex, True, True)
    Else
        nRet = KSJ_PreviewStartEx(g_nCurIndex, False, True)
    End If
End Sub

Private Sub Combo_Device_List_Click()
    Dim nRet As Long
    Dim nCurIndex As Long

    nRet = KSJ_PreviewStart(g_nCurIndex, False)
    g_nCurIndex = Combo_Device_List.ListIndex
    UpdateInterface
    UpdateInterfaceFunction
End Sub

Private Function GetRealExposureTime()
    Dim nRet As Long
    Dim fExposureTimeMs As Single
    nRet = KSJ_ExposureTimeGet(g_nCurIndex, fExposureTimeMs)
    ExposureReal.Text = "Exp Time:" + Str(fExposureTimeMs) + "ms"
End Function

Private Sub ExposureLines_Change()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_SetParam(g_nCurIndex, KSJ_EXPOSURE_LINES, Val(ExposureLines.Text))
    GetRealExposureTime
End Sub

Private Sub ExposureTime_Change()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_SetParam(g_nCurIndex, KSJ_EXPOSURE, Val(ExposureTime.Text))
    GetRealExposureTime
End Sub

Private Sub Gain_Change()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    nRet = KSJ_SetParam(g_nCurIndex, KSJ_RED, Val(Gain.Text))
    nRet = KSJ_SetParam(g_nCurIndex, KSJ_GREEN, Val(Gain.Text))
    nRet = KSJ_SetParam(g_nCurIndex, KSJ_BLUE, Val(Gain.Text))
    
End Sub


Private Sub SetCapture_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    Dim RowSkip As KSJ_ADDRESSMODE
    Dim ColSkip As KSJ_ADDRESSMODE
    
    nRet = KSJ_CaptureSetFieldOfView(g_nCurIndex, Val(CaptureColStart.Text), Val(CaptureRowStart.Text), Val(CaptureColSize.Text), Val(CaptureRowSize.Text), KSJ_SKIPNONE, KSJ_SKIPNONE)
    
    Dim nTop As Long
    Dim nLeft As Long
    Dim nWidth As Long
    Dim nHeight As Long
    nRet = KSJ_CaptureGetFieldOfView(g_nCurIndex, nLeft, nTop, nWidth, nHeight, RowSkip, ColSkip)
    CaptureColStart.Text = Str(nLeft)
    CaptureColSize.Text = Str(nWidth)
    CaptureRowStart.Text = Str(nTop)
    CaptureRowSize.Text = Str(nHeight)
End Sub

Private Sub SetPreview_Click()
    If g_nCurIndex = -1 Then Exit Sub
    Dim nRet As Long
    Dim RowSkip As KSJ_ADDRESSMODE
    Dim ColSkip As KSJ_ADDRESSMODE
    
    nRet = KSJ_PreviewSetFieldOfView(g_nCurIndex, Val(PreviewColStart.Text), Val(PreviewRowStart.Text), Val(PreviewColSize.Text), Val(PreviewRowSize.Text), KSJ_SKIPNONE, KSJ_SKIPNONE)
    
    Dim nTop As Long
    Dim nLeft As Long
    Dim nWidth As Long
    Dim nHeight As Long
    nRet = KSJ_PreviewGetFieldOfView(g_nCurIndex, nLeft, nTop, nWidth, nHeight, RowSkip, ColSkip)
    PreviewColStart.Text = Str(nLeft)
    PreviewColSize.Text = Str(nWidth)
    PreviewRowStart.Text = Str(nTop)
    PreviewRowSize.Text = Str(nHeight)
End Sub

Private Sub Form_Unload(Cancel As Integer)
    KSJ_UnInit
End Sub



Private Sub Timer1_Timer()
    Dim fFrameRate As Single
    KSJ_PreviewGetFrameRate 0, fFrameRate
    VBDemoForm.Caption = "CatchBEST: " & Str(fFrameRate) & "Fps"
End Sub


