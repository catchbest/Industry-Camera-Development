

Public Class Form1
    Public g_nCurIndex As Integer

    Private Sub Form_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim nRet As Integer
        Dim nDeviceNum As Integer
        Dim i As Integer
        Dim nSerials As Integer
        Dim DeviceType As KSJ_DEVICETYPE
        Dim wFirmwareVersion As Integer

        nRet = KSJ_Init
        nDeviceNum = KSJ_DeviceGetCount
        DeviceNum.Text = "find " + Str(nDeviceNum) + " device"

        If nDeviceNum <> 0 Then
            For i = 0 To nDeviceNum - 1 Step 1
                nRet = KSJ_DeviceGetInformation(i, DeviceType, nSerials, wFirmwareVersion)
                Combo_Device_List.Items.Add(Str(i) + ", DeviceType:" + Str(DeviceType) + ", Serials" + Str(nSerials))
            Next i

            Combo_Device_List.SelectedIndex = 0
        End If

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Combo_Device_List.SelectedIndexChanged
        Dim nRet As Integer
        nRet = KSJ_PreviewStart(g_nCurIndex, False)
        g_nCurIndex = Combo_Device_List.SelectedIndex
        UpdateInterface()
    End Sub

    Public Function UpdateInterface()
        Dim nMin As Integer
        Dim nMax As Integer
        Dim nCur As Integer
        Dim nRet As Integer
        nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE, nMin, nMax)
        nRet = KSJ_GetParam(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE, nCur)
        ExposureTime.Text = Str(nCur)
        TimeRange.Text = Str(nMin) + "-" + Str(nMax)

        nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE_LINES, nMin, nMax)
        nRet = KSJ_GetParam(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE_LINES, nCur)
        ExposureLines.Text = Str(nCur)
        LinesRange.Text = Str(nMin) + "-" + Str(nMax) + "ms"

        nRet = KSJ_GetParamRange(g_nCurIndex, KSJ_PARAM.KSJ_RED, nMin, nMax)
        nRet = KSJ_GetParam(g_nCurIndex, KSJ_PARAM.KSJ_RED, nCur)
        Gain.Text = Str(nCur)
        GainRange.Text = Str(nMin) + "-" + Str(nMax)

        Dim nTop As Integer
        Dim nLeft As Integer
        Dim nWidth As Integer
        Dim nHeight As Integer
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

    End Function

    Private Function GetRealExposureTime()
        Dim nRet As Long
        Dim fExposureTimeMs As Single
        nRet = KSJ_ExposureTimeGet(g_nCurIndex, fExposureTimeMs)
        ExposureReal.Text = "Exp Time:" + Str(fExposureTimeMs) + "ms"
    End Function

    Private Sub ExposureTime_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExposureTime.TextChanged
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Long
        nRet = KSJ_SetParam(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE, Val(ExposureTime.Text))
        GetRealExposureTime()
    End Sub

    Private Sub ExposureLines_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExposureLines.TextChanged
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Long
        nRet = KSJ_SetParam(g_nCurIndex, KSJ_PARAM.KSJ_EXPOSURE_LINES, Val(ExposureLines.Text))
        GetRealExposureTime()
    End Sub

    Private Sub Gain_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Gain.TextChanged
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Long
        nRet = KSJ_SetParam(g_nCurIndex, KSJ_PARAM.KSJ_RED, Val(Gain.Text))
        nRet = KSJ_SetParam(g_nCurIndex, KSJ_PARAM.KSJ_GREEN, Val(Gain.Text))
        nRet = KSJ_SetParam(g_nCurIndex, KSJ_PARAM.KSJ_BLUE, Val(Gain.Text))
    End Sub

    Private Sub SetPreview_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SetPreview.Click
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Long
        Dim RowSkip As KSJ_ADDRESSMODE
        Dim ColSkip As KSJ_ADDRESSMODE

        nRet = KSJ_PreviewSetFieldOfView(g_nCurIndex, Val(PreviewColStart.Text), Val(PreviewRowStart.Text), Val(PreviewColSize.Text), Val(PreviewRowSize.Text), KSJ_ADDRESSMODE.KSJ_SKIPNONE, KSJ_ADDRESSMODE.KSJ_SKIPNONE)

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

    Private Sub Check_Preview_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Check_Preview.CheckedChanged
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Integer
        If Check_Preview.Checked = True Then
            nRet = KSJ_PreviewSetPos(g_nCurIndex, PreviewWnd.Handle.ToInt32, 0, 0, PreviewWnd.Width, PreviewWnd.Height)
            nRet = KSJ_PreviewStart(g_nCurIndex, True)
        Else
            nRet = KSJ_PreviewStart(g_nCurIndex, False)
        End If
    End Sub

    Private Sub SetCapture_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SetCapture.Click
        If g_nCurIndex = -1 Then Exit Sub
        Dim nRet As Integer
        Dim RowSkip As KSJ_ADDRESSMODE
        Dim ColSkip As KSJ_ADDRESSMODE

        nRet = KSJ_CaptureSetFieldOfView(g_nCurIndex, Val(CaptureColStart.Text), Val(CaptureRowStart.Text), Val(CaptureColSize.Text), Val(CaptureRowSize.Text), KSJ_ADDRESSMODE.KSJ_SKIPNONE, KSJ_ADDRESSMODE.KSJ_SKIPNONE)

        Dim nTop As Integer
        Dim nLeft As Integer
        Dim nWidth As Integer
        Dim nHeight As Integer
        nRet = KSJ_CaptureGetFieldOfView(g_nCurIndex, nLeft, nTop, nWidth, nHeight, RowSkip, ColSkip)
        CaptureColStart.Text = Str(nLeft)
        CaptureColSize.Text = Str(nWidth)
        CaptureRowStart.Text = Str(nTop)
        CaptureRowSize.Text = Str(nHeight)
    End Sub

    Private Sub Capture_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Capture.Click, Capture.Click
        If g_nCurIndex = -1 Then Exit Sub

        Dim nRet As Integer
        Dim pRgbData() As Byte
        Dim nRgbDataSize As Integer

        Dim nBitCount As Integer
        Dim nCaptureWidth As Integer
        Dim nCaptureHeight As Integer

        nRet = KSJ_CaptureGetSizeEx(g_nCurIndex, nCaptureWidth, nCaptureHeight, nBitCount)

        nRgbDataSize = nCaptureWidth * nCaptureHeight * (nBitCount / 8)
        ReDim pRgbData(nRgbDataSize)

        nRet = KSJ_CaptureRgbData(g_nCurIndex, pRgbData)

        Dim nTotalBytes As Integer
        Dim pHeader() As Byte
        KSJ_HelperGetBmpFileHeaderSize(nBitCount, nTotalBytes)
        ReDim pHeader(nTotalBytes)
        KSJ_HelperGetBmpFileHeader(nCaptureWidth, nCaptureHeight, nBitCount, pHeader)
        Dim image As Byte() = pHeader.Concat(pRgbData).ToArray
        Dim ms As New IO.MemoryStream(image)

        If SaveBmp.Checked = True Then
            nRet = KSJ_HelperSaveToBmp(pRgbData, nCaptureWidth, nCaptureHeight, nBitCount, "Capture.bmp")
        End If

        Dim g8 As Cognex.VisionPro.CogImage8Grey
        g8 = New Cognex.VisionPro.CogImage8Grey(Bitmap.FromStream(ms))
        CaptureWnd.Image = g8

    End Sub

    Private Sub Form_Closed(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles MyBase.FormClosed
        KSJ_UnInit()
    End Sub
End Class
