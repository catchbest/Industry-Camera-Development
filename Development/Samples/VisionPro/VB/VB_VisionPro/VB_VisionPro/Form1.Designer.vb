<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.CaptureWnd = New Cognex.VisionPro.Display.CogDisplay()
        Me.Combo_Device_List = New System.Windows.Forms.ComboBox()
        Me.ExposureTime = New System.Windows.Forms.TextBox()
        Me.PreviewWnd = New System.Windows.Forms.PictureBox()
        Me.DeviceNum = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.ExposureLines = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.TimeRange = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.LinesRange = New System.Windows.Forms.TextBox()
        Me.ExposureReal = New System.Windows.Forms.TextBox()
        Me.Check_Preview = New System.Windows.Forms.CheckBox()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.SetPreview = New System.Windows.Forms.Button()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.PreviewRowSize = New System.Windows.Forms.TextBox()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.PreviewColSize = New System.Windows.Forms.TextBox()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.PreviewRowStart = New System.Windows.Forms.TextBox()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.PreviewColStart = New System.Windows.Forms.TextBox()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.GainRange = New System.Windows.Forms.TextBox()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Gain = New System.Windows.Forms.TextBox()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.FovRange = New System.Windows.Forms.TextBox()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.SetCapture = New System.Windows.Forms.Button()
        Me.Label13 = New System.Windows.Forms.Label()
        Me.CaptureRowSize = New System.Windows.Forms.TextBox()
        Me.Label14 = New System.Windows.Forms.Label()
        Me.CaptureColSize = New System.Windows.Forms.TextBox()
        Me.Label15 = New System.Windows.Forms.Label()
        Me.CaptureRowStart = New System.Windows.Forms.TextBox()
        Me.Label16 = New System.Windows.Forms.Label()
        Me.CaptureColStart = New System.Windows.Forms.TextBox()
        Me.Capture = New System.Windows.Forms.Button()
        Me.SaveBmp = New System.Windows.Forms.CheckBox()
        CType(Me.CaptureWnd, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PreviewWnd, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'CaptureWnd
        '
        Me.CaptureWnd.ColorMapLowerClipColor = System.Drawing.Color.Black
        Me.CaptureWnd.ColorMapLowerRoiLimit = 0.0R
        Me.CaptureWnd.ColorMapPredefined = Cognex.VisionPro.Display.CogDisplayColorMapPredefinedConstants.None
        Me.CaptureWnd.ColorMapUpperClipColor = System.Drawing.Color.Black
        Me.CaptureWnd.ColorMapUpperRoiLimit = 1.0R
        Me.CaptureWnd.Location = New System.Drawing.Point(31, 296)
        Me.CaptureWnd.MouseWheelMode = Cognex.VisionPro.Display.CogDisplayMouseWheelModeConstants.Zoom1
        Me.CaptureWnd.MouseWheelSensitivity = 1.0R
        Me.CaptureWnd.Name = "CaptureWnd"
        Me.CaptureWnd.OcxState = CType(resources.GetObject("CaptureWnd.OcxState"), System.Windows.Forms.AxHost.State)
        Me.CaptureWnd.Size = New System.Drawing.Size(517, 315)
        Me.CaptureWnd.TabIndex = 0
        '
        'Combo_Device_List
        '
        Me.Combo_Device_List.FormattingEnabled = True
        Me.Combo_Device_List.Location = New System.Drawing.Point(713, 12)
        Me.Combo_Device_List.Name = "Combo_Device_List"
        Me.Combo_Device_List.Size = New System.Drawing.Size(392, 20)
        Me.Combo_Device_List.TabIndex = 2
        '
        'ExposureTime
        '
        Me.ExposureTime.Location = New System.Drawing.Point(726, 59)
        Me.ExposureTime.Name = "ExposureTime"
        Me.ExposureTime.Size = New System.Drawing.Size(100, 21)
        Me.ExposureTime.TabIndex = 6
        '
        'PreviewWnd
        '
        Me.PreviewWnd.Location = New System.Drawing.Point(31, 12)
        Me.PreviewWnd.Name = "PreviewWnd"
        Me.PreviewWnd.Size = New System.Drawing.Size(517, 268)
        Me.PreviewWnd.TabIndex = 7
        Me.PreviewWnd.TabStop = False
        '
        'DeviceNum
        '
        Me.DeviceNum.AutoSize = True
        Me.DeviceNum.Location = New System.Drawing.Point(605, 15)
        Me.DeviceNum.Name = "DeviceNum"
        Me.DeviceNum.Size = New System.Drawing.Size(83, 12)
        Me.DeviceNum.TabIndex = 8
        Me.DeviceNum.Text = "Device Number"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(607, 62)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(113, 12)
        Me.Label2.TabIndex = 9
        Me.Label2.Text = "Exposure Time(ms):"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(607, 103)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(95, 12)
        Me.Label3.TabIndex = 11
        Me.Label3.Text = "Exposure Lines:"
        '
        'ExposureLines
        '
        Me.ExposureLines.Location = New System.Drawing.Point(726, 100)
        Me.ExposureLines.Name = "ExposureLines"
        Me.ExposureLines.Size = New System.Drawing.Size(100, 21)
        Me.ExposureLines.TabIndex = 10
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(893, 62)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(65, 12)
        Me.Label4.TabIndex = 13
        Me.Label4.Text = "Range(ms):"
        '
        'TimeRange
        '
        Me.TimeRange.Enabled = False
        Me.TimeRange.Location = New System.Drawing.Point(973, 59)
        Me.TimeRange.Name = "TimeRange"
        Me.TimeRange.Size = New System.Drawing.Size(100, 21)
        Me.TimeRange.TabIndex = 12
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(893, 103)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(41, 12)
        Me.Label5.TabIndex = 15
        Me.Label5.Text = "Range:"
        '
        'LinesRange
        '
        Me.LinesRange.Enabled = False
        Me.LinesRange.Location = New System.Drawing.Point(973, 100)
        Me.LinesRange.Name = "LinesRange"
        Me.LinesRange.Size = New System.Drawing.Size(100, 21)
        Me.LinesRange.TabIndex = 14
        '
        'ExposureReal
        '
        Me.ExposureReal.Location = New System.Drawing.Point(726, 141)
        Me.ExposureReal.Name = "ExposureReal"
        Me.ExposureReal.Size = New System.Drawing.Size(250, 21)
        Me.ExposureReal.TabIndex = 16
        '
        'Check_Preview
        '
        Me.Check_Preview.Appearance = System.Windows.Forms.Appearance.Button
        Me.Check_Preview.AutoSize = True
        Me.Check_Preview.Location = New System.Drawing.Point(607, 373)
        Me.Check_Preview.Name = "Check_Preview"
        Me.Check_Preview.Size = New System.Drawing.Size(57, 22)
        Me.Check_Preview.TabIndex = 17
        Me.Check_Preview.Text = "Preview"
        Me.Check_Preview.UseVisualStyleBackColor = True
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.SetPreview)
        Me.GroupBox1.Controls.Add(Me.Label11)
        Me.GroupBox1.Controls.Add(Me.PreviewRowSize)
        Me.GroupBox1.Controls.Add(Me.Label12)
        Me.GroupBox1.Controls.Add(Me.PreviewColSize)
        Me.GroupBox1.Controls.Add(Me.Label10)
        Me.GroupBox1.Controls.Add(Me.PreviewRowStart)
        Me.GroupBox1.Controls.Add(Me.Label9)
        Me.GroupBox1.Controls.Add(Me.PreviewColStart)
        Me.GroupBox1.Location = New System.Drawing.Point(609, 237)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(496, 121)
        Me.GroupBox1.TabIndex = 18
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Preview"
        '
        'SetPreview
        '
        Me.SetPreview.Location = New System.Drawing.Point(44, 86)
        Me.SetPreview.Name = "SetPreview"
        Me.SetPreview.Size = New System.Drawing.Size(200, 23)
        Me.SetPreview.TabIndex = 33
        Me.SetPreview.Text = "Set Preview Field Of View"
        Me.SetPreview.UseVisualStyleBackColor = True
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Location = New System.Drawing.Point(289, 58)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(59, 12)
        Me.Label11.TabIndex = 32
        Me.Label11.Text = "Row Size:"
        '
        'PreviewRowSize
        '
        Me.PreviewRowSize.Location = New System.Drawing.Point(364, 55)
        Me.PreviewRowSize.Name = "PreviewRowSize"
        Me.PreviewRowSize.Size = New System.Drawing.Size(100, 21)
        Me.PreviewRowSize.TabIndex = 31
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.Location = New System.Drawing.Point(42, 58)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(59, 12)
        Me.Label12.TabIndex = 30
        Me.Label12.Text = "Col Size:"
        '
        'PreviewColSize
        '
        Me.PreviewColSize.Location = New System.Drawing.Point(117, 55)
        Me.PreviewColSize.Name = "PreviewColSize"
        Me.PreviewColSize.Size = New System.Drawing.Size(100, 21)
        Me.PreviewColSize.TabIndex = 29
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(289, 25)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(65, 12)
        Me.Label10.TabIndex = 28
        Me.Label10.Text = "Row Start:"
        '
        'PreviewRowStart
        '
        Me.PreviewRowStart.Location = New System.Drawing.Point(364, 22)
        Me.PreviewRowStart.Name = "PreviewRowStart"
        Me.PreviewRowStart.Size = New System.Drawing.Size(100, 21)
        Me.PreviewRowStart.TabIndex = 27
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(42, 25)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(65, 12)
        Me.Label9.TabIndex = 26
        Me.Label9.Text = "Col Start:"
        '
        'PreviewColStart
        '
        Me.PreviewColStart.Location = New System.Drawing.Point(117, 22)
        Me.PreviewColStart.Name = "PreviewColStart"
        Me.PreviewColStart.Size = New System.Drawing.Size(100, 21)
        Me.PreviewColStart.TabIndex = 25
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(893, 180)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(41, 12)
        Me.Label6.TabIndex = 22
        Me.Label6.Text = "Range:"
        '
        'GainRange
        '
        Me.GainRange.Enabled = False
        Me.GainRange.Location = New System.Drawing.Point(973, 177)
        Me.GainRange.Name = "GainRange"
        Me.GainRange.Size = New System.Drawing.Size(100, 21)
        Me.GainRange.TabIndex = 21
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(607, 180)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(35, 12)
        Me.Label7.TabIndex = 20
        Me.Label7.Text = "Gain:"
        '
        'Gain
        '
        Me.Gain.Location = New System.Drawing.Point(726, 177)
        Me.Gain.Name = "Gain"
        Me.Gain.Size = New System.Drawing.Size(100, 21)
        Me.Gain.TabIndex = 19
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(607, 213)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(65, 12)
        Me.Label8.TabIndex = 24
        Me.Label8.Text = "FOV Range:"
        '
        'FovRange
        '
        Me.FovRange.Enabled = False
        Me.FovRange.Location = New System.Drawing.Point(726, 210)
        Me.FovRange.Name = "FovRange"
        Me.FovRange.Size = New System.Drawing.Size(100, 21)
        Me.FovRange.TabIndex = 23
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.SetCapture)
        Me.GroupBox2.Controls.Add(Me.Label13)
        Me.GroupBox2.Controls.Add(Me.CaptureRowSize)
        Me.GroupBox2.Controls.Add(Me.Label14)
        Me.GroupBox2.Controls.Add(Me.CaptureColSize)
        Me.GroupBox2.Controls.Add(Me.Label15)
        Me.GroupBox2.Controls.Add(Me.CaptureRowStart)
        Me.GroupBox2.Controls.Add(Me.Label16)
        Me.GroupBox2.Controls.Add(Me.CaptureColStart)
        Me.GroupBox2.Location = New System.Drawing.Point(609, 413)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(496, 121)
        Me.GroupBox2.TabIndex = 34
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Capture"
        '
        'SetCapture
        '
        Me.SetCapture.Location = New System.Drawing.Point(44, 86)
        Me.SetCapture.Name = "SetCapture"
        Me.SetCapture.Size = New System.Drawing.Size(200, 23)
        Me.SetCapture.TabIndex = 33
        Me.SetCapture.Text = "Set Capture Field Of View"
        Me.SetCapture.UseVisualStyleBackColor = True
        '
        'Label13
        '
        Me.Label13.AutoSize = True
        Me.Label13.Location = New System.Drawing.Point(289, 58)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(59, 12)
        Me.Label13.TabIndex = 32
        Me.Label13.Text = "Row Size:"
        '
        'CaptureRowSize
        '
        Me.CaptureRowSize.Location = New System.Drawing.Point(364, 55)
        Me.CaptureRowSize.Name = "CaptureRowSize"
        Me.CaptureRowSize.Size = New System.Drawing.Size(100, 21)
        Me.CaptureRowSize.TabIndex = 31
        '
        'Label14
        '
        Me.Label14.AutoSize = True
        Me.Label14.Location = New System.Drawing.Point(42, 58)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(59, 12)
        Me.Label14.TabIndex = 30
        Me.Label14.Text = "Col Size:"
        '
        'CaptureColSize
        '
        Me.CaptureColSize.Location = New System.Drawing.Point(117, 55)
        Me.CaptureColSize.Name = "CaptureColSize"
        Me.CaptureColSize.Size = New System.Drawing.Size(100, 21)
        Me.CaptureColSize.TabIndex = 29
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.Location = New System.Drawing.Point(289, 25)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(65, 12)
        Me.Label15.TabIndex = 28
        Me.Label15.Text = "Row Start:"
        '
        'CaptureRowStart
        '
        Me.CaptureRowStart.Location = New System.Drawing.Point(364, 22)
        Me.CaptureRowStart.Name = "CaptureRowStart"
        Me.CaptureRowStart.Size = New System.Drawing.Size(100, 21)
        Me.CaptureRowStart.TabIndex = 27
        '
        'Label16
        '
        Me.Label16.AutoSize = True
        Me.Label16.Location = New System.Drawing.Point(42, 25)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(65, 12)
        Me.Label16.TabIndex = 26
        Me.Label16.Text = "Col Start:"
        '
        'CaptureColStart
        '
        Me.CaptureColStart.Location = New System.Drawing.Point(117, 22)
        Me.CaptureColStart.Name = "CaptureColStart"
        Me.CaptureColStart.Size = New System.Drawing.Size(100, 21)
        Me.CaptureColStart.TabIndex = 25
        '
        'Capture
        '
        Me.Capture.Location = New System.Drawing.Point(607, 555)
        Me.Capture.Name = "Capture"
        Me.Capture.Size = New System.Drawing.Size(75, 23)
        Me.Capture.TabIndex = 35
        Me.Capture.Text = "Capture"
        Me.Capture.UseVisualStyleBackColor = True
        '
        'SaveBmp
        '
        Me.SaveBmp.AutoSize = True
        Me.SaveBmp.Location = New System.Drawing.Point(775, 559)
        Me.SaveBmp.Name = "SaveBmp"
        Me.SaveBmp.Size = New System.Drawing.Size(66, 16)
        Me.SaveBmp.TabIndex = 36
        Me.SaveBmp.Text = "SaveBmp"
        Me.SaveBmp.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1144, 643)
        Me.Controls.Add(Me.SaveBmp)
        Me.Controls.Add(Me.Capture)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.FovRange)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.GainRange)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Check_Preview)
        Me.Controls.Add(Me.Gain)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.ExposureReal)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.LinesRange)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.TimeRange)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.ExposureLines)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.DeviceNum)
        Me.Controls.Add(Me.PreviewWnd)
        Me.Controls.Add(Me.ExposureTime)
        Me.Controls.Add(Me.Combo_Device_List)
        Me.Controls.Add(Me.CaptureWnd)
        Me.Name = "Form1"
        Me.Text = "VB.net_VisionPro"
        CType(Me.CaptureWnd, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PreviewWnd, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents CaptureWnd As Cognex.VisionPro.Display.CogDisplay
    Friend WithEvents Combo_Device_List As System.Windows.Forms.ComboBox
    Friend WithEvents ExposureTime As System.Windows.Forms.TextBox
    Friend WithEvents PreviewWnd As System.Windows.Forms.PictureBox
    Friend WithEvents DeviceNum As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents ExposureLines As System.Windows.Forms.TextBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents TimeRange As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents LinesRange As System.Windows.Forms.TextBox
    Friend WithEvents ExposureReal As System.Windows.Forms.TextBox
    Friend WithEvents Check_Preview As System.Windows.Forms.CheckBox
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents GainRange As System.Windows.Forms.TextBox
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Gain As System.Windows.Forms.TextBox
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents FovRange As System.Windows.Forms.TextBox
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents PreviewRowSize As System.Windows.Forms.TextBox
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents PreviewColSize As System.Windows.Forms.TextBox
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents PreviewRowStart As System.Windows.Forms.TextBox
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents PreviewColStart As System.Windows.Forms.TextBox
    Friend WithEvents SetPreview As System.Windows.Forms.Button
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents SetCapture As System.Windows.Forms.Button
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents CaptureRowSize As System.Windows.Forms.TextBox
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents CaptureColSize As System.Windows.Forms.TextBox
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents CaptureRowStart As System.Windows.Forms.TextBox
    Friend WithEvents Label16 As System.Windows.Forms.Label
    Friend WithEvents CaptureColStart As System.Windows.Forms.TextBox
    Friend WithEvents Capture As System.Windows.Forms.Button
    Friend WithEvents SaveBmp As System.Windows.Forms.CheckBox

End Class
