namespace KSJDemoCSharp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.PictureBox_PREVIEWWND = new System.Windows.Forms.PictureBox();
            this.Label__DEVICENUM = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.ComboBox_DEVICE_LIST = new System.Windows.Forms.ComboBox();
            this.NumericUpDown_EXPOSURE_TIME_MS = new System.Windows.Forms.NumericUpDown();
            this.NumericUpDown_EXPOSURE_LINES = new System.Windows.Forms.NumericUpDown();
            this.NumericUpDown_GAIN = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Button_PREVIEW_FOV_SET = new System.Windows.Forms.Button();
            this.TextBox_PREIVEW_ROW_SIZE = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.TextBox_PREIVEW_ROW_START = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.TextBox_PREIVEW_COL_SIZE = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.TextBox_PREVIEW_COL_START = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.CheckBox_SET_CALLBACKEX = new System.Windows.Forms.CheckBox();
            this.CheckBox_SET_CALLBACK = new System.Windows.Forms.CheckBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.Button_CAPTURE_FOV_SET = new System.Windows.Forms.Button();
            this.TextBox_CAPTURE_ROW_SIZE = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.TextBox_CAPTURE_ROW_START = new System.Windows.Forms.TextBox();
            this.label14 = new System.Windows.Forms.Label();
            this.TextBox_CAPTURE_COL_SIZE = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.TextBox_CAPTURE_COL_START = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.CheckBox_SAVE = new System.Windows.Forms.CheckBox();
            this.TextBox_ERROR_INFO = new System.Windows.Forms.TextBox();
            this.TextBox_ELAPSE_TIME = new System.Windows.Forms.TextBox();
            this.ProgressBar_EXPOSURE = new System.Windows.Forms.ProgressBar();
            this.Label_EXPOSURE_TIME_RANGE = new System.Windows.Forms.Label();
            this.Label_EXPOSURE_LINES_RANGE = new System.Windows.Forms.Label();
            this.Label_FOV_RANGE = new System.Windows.Forms.Label();
            this.Label_GAIN_RANGE = new System.Windows.Forms.Label();
            this.Label_EXPOSURE_TIME_REAL = new System.Windows.Forms.Label();
            this.CheckBox_PREVIEWSTART = new System.Windows.Forms.CheckBox();
            this.ListView_FUNCTION = new System.Windows.Forms.ListView();
            this.Timer_GET_FRAME_RATE = new System.Windows.Forms.Timer(this.components);
            this.Button_CAPTURE = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.FrameRate = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox_TriggerMethod = new System.Windows.Forms.ComboBox();
            this.label17 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.comboBox_TriggerMode = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_PREVIEWWND)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_EXPOSURE_TIME_MS)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_EXPOSURE_LINES)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_GAIN)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameRate)).BeginInit();
            this.SuspendLayout();
            // 
            // PictureBox_PREVIEWWND
            // 
            this.PictureBox_PREVIEWWND.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.PictureBox_PREVIEWWND.Location = new System.Drawing.Point(10, 25);
            this.PictureBox_PREVIEWWND.Name = "PictureBox_PREVIEWWND";
            this.PictureBox_PREVIEWWND.Size = new System.Drawing.Size(555, 602);
            this.PictureBox_PREVIEWWND.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.PictureBox_PREVIEWWND.TabIndex = 0;
            this.PictureBox_PREVIEWWND.TabStop = false;
            // 
            // Label__DEVICENUM
            // 
            this.Label__DEVICENUM.AutoSize = true;
            this.Label__DEVICENUM.Location = new System.Drawing.Point(583, 28);
            this.Label__DEVICENUM.Name = "Label__DEVICENUM";
            this.Label__DEVICENUM.Size = new System.Drawing.Size(71, 12);
            this.Label__DEVICENUM.TabIndex = 1;
            this.Label__DEVICENUM.Text = "Device Num:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(583, 104);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(95, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "Exposure Lines:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(583, 65);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(113, 12);
            this.label3.TabIndex = 3;
            this.label3.Text = "Exposure Time(ms):";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(880, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 4;
            this.label4.Text = "Range(ms):";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(880, 103);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 12);
            this.label5.TabIndex = 5;
            this.label5.Text = "Range:";
            // 
            // ComboBox_DEVICE_LIST
            // 
            this.ComboBox_DEVICE_LIST.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBox_DEVICE_LIST.FormattingEnabled = true;
            this.ComboBox_DEVICE_LIST.Location = new System.Drawing.Point(679, 25);
            this.ComboBox_DEVICE_LIST.Name = "ComboBox_DEVICE_LIST";
            this.ComboBox_DEVICE_LIST.Size = new System.Drawing.Size(439, 20);
            this.ComboBox_DEVICE_LIST.TabIndex = 8;
            this.ComboBox_DEVICE_LIST.SelectedIndexChanged += new System.EventHandler(this.ComboBox_DEVICE_LIST_SelectedIndexChanged);
            // 
            // NumericUpDown_EXPOSURE_TIME_MS
            // 
            this.NumericUpDown_EXPOSURE_TIME_MS.Location = new System.Drawing.Point(705, 61);
            this.NumericUpDown_EXPOSURE_TIME_MS.Name = "NumericUpDown_EXPOSURE_TIME_MS";
            this.NumericUpDown_EXPOSURE_TIME_MS.Size = new System.Drawing.Size(120, 21);
            this.NumericUpDown_EXPOSURE_TIME_MS.TabIndex = 10;
            this.NumericUpDown_EXPOSURE_TIME_MS.ValueChanged += new System.EventHandler(this.NumericUpDown_EXPOSURE_TIME_MS_ValueChanged);
            // 
            // NumericUpDown_EXPOSURE_LINES
            // 
            this.NumericUpDown_EXPOSURE_LINES.Location = new System.Drawing.Point(705, 100);
            this.NumericUpDown_EXPOSURE_LINES.Name = "NumericUpDown_EXPOSURE_LINES";
            this.NumericUpDown_EXPOSURE_LINES.Size = new System.Drawing.Size(120, 21);
            this.NumericUpDown_EXPOSURE_LINES.TabIndex = 11;
            this.NumericUpDown_EXPOSURE_LINES.ValueChanged += new System.EventHandler(this.NumericUpDown_EXPOSURE_LINES_ValueChanged);
            // 
            // NumericUpDown_GAIN
            // 
            this.NumericUpDown_GAIN.Location = new System.Drawing.Point(705, 175);
            this.NumericUpDown_GAIN.Name = "NumericUpDown_GAIN";
            this.NumericUpDown_GAIN.Size = new System.Drawing.Size(120, 21);
            this.NumericUpDown_GAIN.TabIndex = 16;
            this.NumericUpDown_GAIN.ValueChanged += new System.EventHandler(this.NumericUpDown_GAIN_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(880, 174);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(41, 12);
            this.label6.TabIndex = 14;
            this.label6.Text = "Range:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(583, 175);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 12);
            this.label7.TabIndex = 13;
            this.label7.Text = "Gain:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(583, 213);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(65, 12);
            this.label8.TabIndex = 18;
            this.label8.Text = "FOV Range:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Button_PREVIEW_FOV_SET);
            this.groupBox1.Controls.Add(this.TextBox_PREIVEW_ROW_SIZE);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.CheckBox_PREVIEWSTART);
            this.groupBox1.Controls.Add(this.TextBox_PREIVEW_ROW_START);
            this.groupBox1.Controls.Add(this.label12);
            this.groupBox1.Controls.Add(this.TextBox_PREIVEW_COL_SIZE);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.TextBox_PREVIEW_COL_START);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Location = new System.Drawing.Point(585, 246);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(503, 111);
            this.groupBox1.TabIndex = 19;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Preivew";
            // 
            // Button_PREVIEW_FOV_SET
            // 
            this.Button_PREVIEW_FOV_SET.Location = new System.Drawing.Point(331, 64);
            this.Button_PREVIEW_FOV_SET.Name = "Button_PREVIEW_FOV_SET";
            this.Button_PREVIEW_FOV_SET.Size = new System.Drawing.Size(166, 23);
            this.Button_PREVIEW_FOV_SET.TabIndex = 28;
            this.Button_PREVIEW_FOV_SET.Text = "Set Preview Field Of View";
            this.Button_PREVIEW_FOV_SET.UseVisualStyleBackColor = true;
            this.Button_PREVIEW_FOV_SET.Click += new System.EventHandler(this.Button_PREVIEW_FOV_SET_Click);
            // 
            // TextBox_PREIVEW_ROW_SIZE
            // 
            this.TextBox_PREIVEW_ROW_SIZE.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_PREIVEW_ROW_SIZE.Location = new System.Drawing.Point(256, 61);
            this.TextBox_PREIVEW_ROW_SIZE.Name = "TextBox_PREIVEW_ROW_SIZE";
            this.TextBox_PREIVEW_ROW_SIZE.Size = new System.Drawing.Size(57, 21);
            this.TextBox_PREIVEW_ROW_SIZE.TabIndex = 27;
            this.TextBox_PREIVEW_ROW_SIZE.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_PREIVEW_ROW_SIZE_KeyPress);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(169, 64);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(59, 12);
            this.label11.TabIndex = 26;
            this.label11.Text = "Row Size:";
            // 
            // TextBox_PREIVEW_ROW_START
            // 
            this.TextBox_PREIVEW_ROW_START.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_PREIVEW_ROW_START.Location = new System.Drawing.Point(256, 20);
            this.TextBox_PREIVEW_ROW_START.Name = "TextBox_PREIVEW_ROW_START";
            this.TextBox_PREIVEW_ROW_START.Size = new System.Drawing.Size(57, 21);
            this.TextBox_PREIVEW_ROW_START.TabIndex = 25;
            this.TextBox_PREIVEW_ROW_START.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_PREIVEW_ROW_START_KeyPress);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(169, 23);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(65, 12);
            this.label12.TabIndex = 24;
            this.label12.Text = "Row Start:";
            // 
            // TextBox_PREIVEW_COL_SIZE
            // 
            this.TextBox_PREIVEW_COL_SIZE.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_PREIVEW_COL_SIZE.Location = new System.Drawing.Point(104, 61);
            this.TextBox_PREIVEW_COL_SIZE.Name = "TextBox_PREIVEW_COL_SIZE";
            this.TextBox_PREIVEW_COL_SIZE.Size = new System.Drawing.Size(57, 21);
            this.TextBox_PREIVEW_COL_SIZE.TabIndex = 23;
            this.TextBox_PREIVEW_COL_SIZE.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_PREIVEW_COL_SIZE_KeyPress);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 64);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(59, 12);
            this.label10.TabIndex = 22;
            this.label10.Text = "Col Size:";
            // 
            // TextBox_PREVIEW_COL_START
            // 
            this.TextBox_PREVIEW_COL_START.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_PREVIEW_COL_START.Location = new System.Drawing.Point(104, 20);
            this.TextBox_PREVIEW_COL_START.Name = "TextBox_PREVIEW_COL_START";
            this.TextBox_PREVIEW_COL_START.Size = new System.Drawing.Size(57, 21);
            this.TextBox_PREVIEW_COL_START.TabIndex = 21;
            this.TextBox_PREVIEW_COL_START.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_PREVIEW_COL_START_KeyPress);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(17, 23);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(65, 12);
            this.label9.TabIndex = 20;
            this.label9.Text = "Col Start:";
            // 
            // CheckBox_SET_CALLBACKEX
            // 
            this.CheckBox_SET_CALLBACKEX.Appearance = System.Windows.Forms.Appearance.Button;
            this.CheckBox_SET_CALLBACKEX.AutoSize = true;
            this.CheckBox_SET_CALLBACKEX.Location = new System.Drawing.Point(200, 21);
            this.CheckBox_SET_CALLBACKEX.Name = "CheckBox_SET_CALLBACKEX";
            this.CheckBox_SET_CALLBACKEX.Size = new System.Drawing.Size(93, 22);
            this.CheckBox_SET_CALLBACKEX.TabIndex = 45;
            this.CheckBox_SET_CALLBACKEX.Text = "SetCallbackEx";
            this.CheckBox_SET_CALLBACKEX.UseVisualStyleBackColor = true;
            this.CheckBox_SET_CALLBACKEX.CheckedChanged += new System.EventHandler(this.CheckBox_SET_CALLBACKEX_CheckedChanged);
            // 
            // CheckBox_SET_CALLBACK
            // 
            this.CheckBox_SET_CALLBACK.Appearance = System.Windows.Forms.Appearance.Button;
            this.CheckBox_SET_CALLBACK.AutoSize = true;
            this.CheckBox_SET_CALLBACK.Location = new System.Drawing.Point(54, 21);
            this.CheckBox_SET_CALLBACK.Name = "CheckBox_SET_CALLBACK";
            this.CheckBox_SET_CALLBACK.Size = new System.Drawing.Size(81, 22);
            this.CheckBox_SET_CALLBACK.TabIndex = 44;
            this.CheckBox_SET_CALLBACK.Text = "SetCallback";
            this.CheckBox_SET_CALLBACK.UseVisualStyleBackColor = true;
            this.CheckBox_SET_CALLBACK.CheckedChanged += new System.EventHandler(this.CheckBox_SET_CALLBACK_CheckedChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.Button_CAPTURE_FOV_SET);
            this.groupBox2.Controls.Add(this.TextBox_CAPTURE_ROW_SIZE);
            this.groupBox2.Controls.Add(this.label13);
            this.groupBox2.Controls.Add(this.TextBox_CAPTURE_ROW_START);
            this.groupBox2.Controls.Add(this.label14);
            this.groupBox2.Controls.Add(this.TextBox_CAPTURE_COL_SIZE);
            this.groupBox2.Controls.Add(this.label15);
            this.groupBox2.Controls.Add(this.TextBox_CAPTURE_COL_START);
            this.groupBox2.Controls.Add(this.label16);
            this.groupBox2.Location = new System.Drawing.Point(585, 363);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(503, 111);
            this.groupBox2.TabIndex = 29;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Capture";
            // 
            // Button_CAPTURE_FOV_SET
            // 
            this.Button_CAPTURE_FOV_SET.Location = new System.Drawing.Point(331, 64);
            this.Button_CAPTURE_FOV_SET.Name = "Button_CAPTURE_FOV_SET";
            this.Button_CAPTURE_FOV_SET.Size = new System.Drawing.Size(166, 23);
            this.Button_CAPTURE_FOV_SET.TabIndex = 28;
            this.Button_CAPTURE_FOV_SET.Text = "Set Capture Field Of View";
            this.Button_CAPTURE_FOV_SET.UseVisualStyleBackColor = true;
            this.Button_CAPTURE_FOV_SET.Click += new System.EventHandler(this.Button_CAPTURE_FOV_SET_Click);
            // 
            // TextBox_CAPTURE_ROW_SIZE
            // 
            this.TextBox_CAPTURE_ROW_SIZE.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_CAPTURE_ROW_SIZE.Location = new System.Drawing.Point(256, 61);
            this.TextBox_CAPTURE_ROW_SIZE.Name = "TextBox_CAPTURE_ROW_SIZE";
            this.TextBox_CAPTURE_ROW_SIZE.Size = new System.Drawing.Size(57, 21);
            this.TextBox_CAPTURE_ROW_SIZE.TabIndex = 27;
            this.TextBox_CAPTURE_ROW_SIZE.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox10_KeyPress);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(169, 64);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(59, 12);
            this.label13.TabIndex = 26;
            this.label13.Text = "Row Size:";
            // 
            // TextBox_CAPTURE_ROW_START
            // 
            this.TextBox_CAPTURE_ROW_START.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_CAPTURE_ROW_START.Location = new System.Drawing.Point(256, 20);
            this.TextBox_CAPTURE_ROW_START.Name = "TextBox_CAPTURE_ROW_START";
            this.TextBox_CAPTURE_ROW_START.Size = new System.Drawing.Size(57, 21);
            this.TextBox_CAPTURE_ROW_START.TabIndex = 25;
            this.TextBox_CAPTURE_ROW_START.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_CAPTURE_ROW_START_KeyPress);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(169, 23);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(65, 12);
            this.label14.TabIndex = 24;
            this.label14.Text = "Row Start:";
            // 
            // TextBox_CAPTURE_COL_SIZE
            // 
            this.TextBox_CAPTURE_COL_SIZE.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_CAPTURE_COL_SIZE.Location = new System.Drawing.Point(104, 61);
            this.TextBox_CAPTURE_COL_SIZE.Name = "TextBox_CAPTURE_COL_SIZE";
            this.TextBox_CAPTURE_COL_SIZE.Size = new System.Drawing.Size(57, 21);
            this.TextBox_CAPTURE_COL_SIZE.TabIndex = 23;
            this.TextBox_CAPTURE_COL_SIZE.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_CAPTURE_COL_SIZE_KeyPress);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(17, 64);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(59, 12);
            this.label15.TabIndex = 22;
            this.label15.Text = "Col Size:";
            // 
            // TextBox_CAPTURE_COL_START
            // 
            this.TextBox_CAPTURE_COL_START.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.TextBox_CAPTURE_COL_START.Location = new System.Drawing.Point(104, 20);
            this.TextBox_CAPTURE_COL_START.Name = "TextBox_CAPTURE_COL_START";
            this.TextBox_CAPTURE_COL_START.Size = new System.Drawing.Size(57, 21);
            this.TextBox_CAPTURE_COL_START.TabIndex = 21;
            this.TextBox_CAPTURE_COL_START.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.TextBox_CAPTURE_COL_START_KeyPress);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(17, 23);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(65, 12);
            this.label16.TabIndex = 20;
            this.label16.Text = "Col Start:";
            // 
            // CheckBox_SAVE
            // 
            this.CheckBox_SAVE.AutoSize = true;
            this.CheckBox_SAVE.Location = new System.Drawing.Point(585, 489);
            this.CheckBox_SAVE.Name = "CheckBox_SAVE";
            this.CheckBox_SAVE.Size = new System.Drawing.Size(48, 16);
            this.CheckBox_SAVE.TabIndex = 30;
            this.CheckBox_SAVE.Text = "Save";
            this.CheckBox_SAVE.UseVisualStyleBackColor = true;
            // 
            // TextBox_ERROR_INFO
            // 
            this.TextBox_ERROR_INFO.BackColor = System.Drawing.SystemColors.Menu;
            this.TextBox_ERROR_INFO.Location = new System.Drawing.Point(585, 567);
            this.TextBox_ERROR_INFO.Name = "TextBox_ERROR_INFO";
            this.TextBox_ERROR_INFO.Size = new System.Drawing.Size(222, 21);
            this.TextBox_ERROR_INFO.TabIndex = 32;
            // 
            // TextBox_ELAPSE_TIME
            // 
            this.TextBox_ELAPSE_TIME.BackColor = System.Drawing.SystemColors.Menu;
            this.TextBox_ELAPSE_TIME.Location = new System.Drawing.Point(825, 567);
            this.TextBox_ELAPSE_TIME.Name = "TextBox_ELAPSE_TIME";
            this.TextBox_ELAPSE_TIME.Size = new System.Drawing.Size(147, 21);
            this.TextBox_ELAPSE_TIME.TabIndex = 33;
            // 
            // ProgressBar_EXPOSURE
            // 
            this.ProgressBar_EXPOSURE.Location = new System.Drawing.Point(585, 525);
            this.ProgressBar_EXPOSURE.Name = "ProgressBar_EXPOSURE";
            this.ProgressBar_EXPOSURE.Size = new System.Drawing.Size(387, 23);
            this.ProgressBar_EXPOSURE.TabIndex = 34;
            // 
            // Label_EXPOSURE_TIME_RANGE
            // 
            this.Label_EXPOSURE_TIME_RANGE.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_EXPOSURE_TIME_RANGE.Location = new System.Drawing.Point(951, 61);
            this.Label_EXPOSURE_TIME_RANGE.Name = "Label_EXPOSURE_TIME_RANGE";
            this.Label_EXPOSURE_TIME_RANGE.Size = new System.Drawing.Size(108, 21);
            this.Label_EXPOSURE_TIME_RANGE.TabIndex = 35;
            this.Label_EXPOSURE_TIME_RANGE.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // Label_EXPOSURE_LINES_RANGE
            // 
            this.Label_EXPOSURE_LINES_RANGE.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_EXPOSURE_LINES_RANGE.Location = new System.Drawing.Point(951, 100);
            this.Label_EXPOSURE_LINES_RANGE.Name = "Label_EXPOSURE_LINES_RANGE";
            this.Label_EXPOSURE_LINES_RANGE.Size = new System.Drawing.Size(108, 21);
            this.Label_EXPOSURE_LINES_RANGE.TabIndex = 36;
            this.Label_EXPOSURE_LINES_RANGE.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // Label_FOV_RANGE
            // 
            this.Label_FOV_RANGE.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_FOV_RANGE.Location = new System.Drawing.Point(705, 209);
            this.Label_FOV_RANGE.Name = "Label_FOV_RANGE";
            this.Label_FOV_RANGE.Size = new System.Drawing.Size(178, 21);
            this.Label_FOV_RANGE.TabIndex = 37;
            this.Label_FOV_RANGE.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // Label_GAIN_RANGE
            // 
            this.Label_GAIN_RANGE.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_GAIN_RANGE.Location = new System.Drawing.Point(951, 171);
            this.Label_GAIN_RANGE.Name = "Label_GAIN_RANGE";
            this.Label_GAIN_RANGE.Size = new System.Drawing.Size(108, 21);
            this.Label_GAIN_RANGE.TabIndex = 38;
            this.Label_GAIN_RANGE.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // Label_EXPOSURE_TIME_REAL
            // 
            this.Label_EXPOSURE_TIME_REAL.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Label_EXPOSURE_TIME_REAL.Location = new System.Drawing.Point(705, 137);
            this.Label_EXPOSURE_TIME_REAL.Name = "Label_EXPOSURE_TIME_REAL";
            this.Label_EXPOSURE_TIME_REAL.Size = new System.Drawing.Size(178, 21);
            this.Label_EXPOSURE_TIME_REAL.TabIndex = 39;
            this.Label_EXPOSURE_TIME_REAL.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // CheckBox_PREVIEWSTART
            // 
            this.CheckBox_PREVIEWSTART.Appearance = System.Windows.Forms.Appearance.Button;
            this.CheckBox_PREVIEWSTART.AutoSize = true;
            this.CheckBox_PREVIEWSTART.Location = new System.Drawing.Point(383, 23);
            this.CheckBox_PREVIEWSTART.Name = "CheckBox_PREVIEWSTART";
            this.CheckBox_PREVIEWSTART.Size = new System.Drawing.Size(57, 22);
            this.CheckBox_PREVIEWSTART.TabIndex = 40;
            this.CheckBox_PREVIEWSTART.Text = "Preview";
            this.CheckBox_PREVIEWSTART.UseVisualStyleBackColor = true;
            this.CheckBox_PREVIEWSTART.CheckedChanged += new System.EventHandler(this.CheckBox_PREVIEWSTART_CheckedChanged);
            // 
            // ListView_FUNCTION
            // 
            this.ListView_FUNCTION.GridLines = true;
            this.ListView_FUNCTION.Location = new System.Drawing.Point(1124, 25);
            this.ListView_FUNCTION.Name = "ListView_FUNCTION";
            this.ListView_FUNCTION.Size = new System.Drawing.Size(358, 273);
            this.ListView_FUNCTION.TabIndex = 42;
            this.ListView_FUNCTION.UseCompatibleStateImageBehavior = false;
            // 
            // Timer_GET_FRAME_RATE
            // 
            this.Timer_GET_FRAME_RATE.Tick += new System.EventHandler(this.Timer_GET_FRAME_RATE_Tick);
            // 
            // Button_CAPTURE
            // 
            this.Button_CAPTURE.Location = new System.Drawing.Point(689, 481);
            this.Button_CAPTURE.Name = "Button_CAPTURE";
            this.Button_CAPTURE.Size = new System.Drawing.Size(87, 30);
            this.Button_CAPTURE.TabIndex = 43;
            this.Button_CAPTURE.Text = "Capture";
            this.Button_CAPTURE.UseVisualStyleBackColor = true;
            this.Button_CAPTURE.Click += new System.EventHandler(this.Button_CAPTURE_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.CheckBox_SET_CALLBACKEX);
            this.groupBox3.Controls.Add(this.CheckBox_SET_CALLBACK);
            this.groupBox3.Location = new System.Drawing.Point(1124, 319);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(358, 55);
            this.groupBox3.TabIndex = 46;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Callback";
            // 
            // FrameRate
            // 
            this.FrameRate.Location = new System.Drawing.Point(1296, 468);
            this.FrameRate.Maximum = new decimal(new int[] {
            65536,
            0,
            0,
            0});
            this.FrameRate.Name = "FrameRate";
            this.FrameRate.Size = new System.Drawing.Size(120, 21);
            this.FrameRate.TabIndex = 52;
            this.FrameRate.ValueChanged += new System.EventHandler(this.FrameRate_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(1159, 470);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(131, 12);
            this.label1.TabIndex = 51;
            this.label1.Text = "Fixed Frame Rate(HW):";
            // 
            // comboBox_TriggerMethod
            // 
            this.comboBox_TriggerMethod.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_TriggerMethod.FormattingEnabled = true;
            this.comboBox_TriggerMethod.Location = new System.Drawing.Point(1241, 432);
            this.comboBox_TriggerMethod.Name = "comboBox_TriggerMethod";
            this.comboBox_TriggerMethod.Size = new System.Drawing.Size(214, 20);
            this.comboBox_TriggerMethod.TabIndex = 50;
            this.comboBox_TriggerMethod.SelectedIndexChanged += new System.EventHandler(this.comboBox_TriggerMethod_SelectedIndexChanged);
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(1144, 435);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(89, 12);
            this.label17.TabIndex = 49;
            this.label17.Text = "TriggerMethod:";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(1144, 403);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(77, 12);
            this.label18.TabIndex = 48;
            this.label18.Text = "TriggerMode:";
            // 
            // comboBox_TriggerMode
            // 
            this.comboBox_TriggerMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_TriggerMode.FormattingEnabled = true;
            this.comboBox_TriggerMode.Location = new System.Drawing.Point(1241, 400);
            this.comboBox_TriggerMode.Name = "comboBox_TriggerMode";
            this.comboBox_TriggerMode.Size = new System.Drawing.Size(214, 20);
            this.comboBox_TriggerMode.TabIndex = 47;
            this.comboBox_TriggerMode.SelectedIndexChanged += new System.EventHandler(this.comboBox_TriggerMode_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1494, 668);
            this.Controls.Add(this.FrameRate);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox_TriggerMethod);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.comboBox_TriggerMode);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.Button_CAPTURE);
            this.Controls.Add(this.ListView_FUNCTION);
            this.Controls.Add(this.Label_EXPOSURE_TIME_REAL);
            this.Controls.Add(this.Label_GAIN_RANGE);
            this.Controls.Add(this.Label_FOV_RANGE);
            this.Controls.Add(this.Label_EXPOSURE_LINES_RANGE);
            this.Controls.Add(this.Label_EXPOSURE_TIME_RANGE);
            this.Controls.Add(this.ProgressBar_EXPOSURE);
            this.Controls.Add(this.TextBox_ELAPSE_TIME);
            this.Controls.Add(this.TextBox_ERROR_INFO);
            this.Controls.Add(this.CheckBox_SAVE);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.NumericUpDown_GAIN);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.NumericUpDown_EXPOSURE_LINES);
            this.Controls.Add(this.NumericUpDown_EXPOSURE_TIME_MS);
            this.Controls.Add(this.ComboBox_DEVICE_LIST);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Label__DEVICENUM);
            this.Controls.Add(this.PictureBox_PREVIEWWND);
            this.Name = "Form1";
            this.Text = "KSJDemoCSharp";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox_PREVIEWWND)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_EXPOSURE_TIME_MS)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_EXPOSURE_LINES)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NumericUpDown_GAIN)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameRate)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox PictureBox_PREVIEWWND;
        private System.Windows.Forms.Label Label__DEVICENUM;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox ComboBox_DEVICE_LIST;
        private System.Windows.Forms.NumericUpDown NumericUpDown_EXPOSURE_TIME_MS;
        private System.Windows.Forms.NumericUpDown NumericUpDown_EXPOSURE_LINES;
        private System.Windows.Forms.NumericUpDown NumericUpDown_GAIN;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox TextBox_PREIVEW_COL_SIZE;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox TextBox_PREVIEW_COL_START;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button Button_PREVIEW_FOV_SET;
        private System.Windows.Forms.TextBox TextBox_PREIVEW_ROW_SIZE;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox TextBox_PREIVEW_ROW_START;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button Button_CAPTURE_FOV_SET;
        private System.Windows.Forms.TextBox TextBox_CAPTURE_ROW_SIZE;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox TextBox_CAPTURE_ROW_START;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox TextBox_CAPTURE_COL_SIZE;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox TextBox_CAPTURE_COL_START;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.CheckBox CheckBox_SAVE;
        private System.Windows.Forms.TextBox TextBox_ERROR_INFO;
        private System.Windows.Forms.TextBox TextBox_ELAPSE_TIME;
        private System.Windows.Forms.ProgressBar ProgressBar_EXPOSURE;
        private System.Windows.Forms.Label Label_EXPOSURE_TIME_RANGE;
        private System.Windows.Forms.Label Label_EXPOSURE_LINES_RANGE;
        private System.Windows.Forms.Label Label_FOV_RANGE;
        private System.Windows.Forms.Label Label_GAIN_RANGE;
        private System.Windows.Forms.Label Label_EXPOSURE_TIME_REAL;
        private System.Windows.Forms.CheckBox CheckBox_PREVIEWSTART;
        private System.Windows.Forms.ListView ListView_FUNCTION;
        private System.Windows.Forms.Timer Timer_GET_FRAME_RATE;
        private System.Windows.Forms.Button Button_CAPTURE;
        private System.Windows.Forms.CheckBox CheckBox_SET_CALLBACK;
        private System.Windows.Forms.CheckBox CheckBox_SET_CALLBACKEX;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.NumericUpDown FrameRate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox_TriggerMethod;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.ComboBox comboBox_TriggerMode;
    }
}

