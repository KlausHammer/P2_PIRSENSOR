namespace Styring_kamera
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
            this.Connect = new System.Windows.Forms.Button();
            this.Baud_rate = new System.Windows.Forms.ComboBox();
            this.Com_Port = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.RPM = new System.Windows.Forms.Label();
            this.helpProvider1 = new System.Windows.Forms.HelpProvider();
            this.label4 = new System.Windows.Forms.Label();
            this.Grader_input = new System.Windows.Forms.NumericUpDown();
            this.Send_Info = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Receive_data = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.But_Sensor1 = new System.Windows.Forms.Button();
            this.But_Sensor2 = new System.Windows.Forms.Button();
            this.But_Sensor3 = new System.Windows.Forms.Button();
            this.fileSystemWatcher1 = new System.IO.FileSystemWatcher();
            this.But_Venstre = new System.Windows.Forms.Button();
            this.But_Højre = new System.Windows.Forms.Button();
            this.TimerVenstre = new System.Windows.Forms.Timer(this.components);
            this.TimerHøjre = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Grader_input)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).BeginInit();
            this.SuspendLayout();
            // 
            // Connect
            // 
            this.Connect.Location = new System.Drawing.Point(355, 44);
            this.Connect.Margin = new System.Windows.Forms.Padding(4);
            this.Connect.Name = "Connect";
            this.Connect.Size = new System.Drawing.Size(100, 28);
            this.Connect.TabIndex = 0;
            this.Connect.Text = "Connect";
            this.Connect.UseVisualStyleBackColor = true;
            this.Connect.Click += new System.EventHandler(this.Connect_Click);
            // 
            // Baud_rate
            // 
            this.Baud_rate.FormattingEnabled = true;
            this.Baud_rate.Items.AddRange(new object[] {
            "9600",
            "19200",
            "38400",
            "57600",
            "115200"});
            this.Baud_rate.Location = new System.Drawing.Point(16, 47);
            this.Baud_rate.Margin = new System.Windows.Forms.Padding(4);
            this.Baud_rate.Name = "Baud_rate";
            this.Baud_rate.Size = new System.Drawing.Size(160, 24);
            this.Baud_rate.TabIndex = 1;
            // 
            // Com_Port
            // 
            this.Com_Port.FormattingEnabled = true;
            this.Com_Port.Location = new System.Drawing.Point(185, 47);
            this.Com_Port.Margin = new System.Windows.Forms.Padding(4);
            this.Com_Port.Name = "Com_Port";
            this.Com_Port.Size = new System.Drawing.Size(160, 24);
            this.Com_Port.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(100, 27);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Baud Rate";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(276, 27);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "COM Port";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(103, 305);
            this.numericUpDown1.Margin = new System.Windows.Forms.Padding(4);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(80, 22);
            this.numericUpDown1.TabIndex = 5;
            this.numericUpDown1.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // RPM
            // 
            this.RPM.AutoSize = true;
            this.RPM.Location = new System.Drawing.Point(120, 285);
            this.RPM.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.RPM.Name = "RPM";
            this.RPM.Size = new System.Drawing.Size(38, 17);
            this.RPM.TabIndex = 6;
            this.RPM.Text = "RPM";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label4.Location = new System.Drawing.Point(130, 149);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 17);
            this.label4.TabIndex = 11;
            this.label4.Text = "Grader";
            // 
            // Grader_input
            // 
            this.Grader_input.Location = new System.Drawing.Point(114, 169);
            this.Grader_input.Margin = new System.Windows.Forms.Padding(4);
            this.Grader_input.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.Grader_input.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.Grader_input.Name = "Grader_input";
            this.Grader_input.Size = new System.Drawing.Size(80, 22);
            this.Grader_input.TabIndex = 12;
            // 
            // Send_Info
            // 
            this.Send_Info.Location = new System.Drawing.Point(104, 112);
            this.Send_Info.Margin = new System.Windows.Forms.Padding(4);
            this.Send_Info.Name = "Send_Info";
            this.Send_Info.Size = new System.Drawing.Size(100, 28);
            this.Send_Info.TabIndex = 13;
            this.Send_Info.Text = "Send Data";
            this.Send_Info.UseVisualStyleBackColor = true;
            this.Send_Info.Click += new System.EventHandler(this.Send_Info_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Receive_data);
            this.groupBox1.Location = new System.Drawing.Point(311, 169);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(175, 167);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Modtaget Data";
            // 
            // Receive_data
            // 
            this.Receive_data.Location = new System.Drawing.Point(8, 20);
            this.Receive_data.Margin = new System.Windows.Forms.Padding(4);
            this.Receive_data.Multiline = true;
            this.Receive_data.Name = "Receive_data";
            this.Receive_data.Size = new System.Drawing.Size(157, 139);
            this.Receive_data.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(493, 128);
            this.panel1.Margin = new System.Windows.Forms.Padding(4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(267, 246);
            this.panel1.TabIndex = 15;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.Panel1_Paint);
            // 
            // But_Sensor1
            // 
            this.But_Sensor1.BackColor = System.Drawing.SystemColors.Control;
            this.But_Sensor1.Location = new System.Drawing.Point(22, 335);
            this.But_Sensor1.Margin = new System.Windows.Forms.Padding(4);
            this.But_Sensor1.Name = "But_Sensor1";
            this.But_Sensor1.Size = new System.Drawing.Size(79, 37);
            this.But_Sensor1.TabIndex = 16;
            this.But_Sensor1.Text = "Sensor 1";
            this.But_Sensor1.UseVisualStyleBackColor = false;
            this.But_Sensor1.Click += new System.EventHandler(this.But_Sensor1_Click);
            // 
            // But_Sensor2
            // 
            this.But_Sensor2.Location = new System.Drawing.Point(109, 335);
            this.But_Sensor2.Margin = new System.Windows.Forms.Padding(4);
            this.But_Sensor2.Name = "But_Sensor2";
            this.But_Sensor2.Size = new System.Drawing.Size(79, 37);
            this.But_Sensor2.TabIndex = 17;
            this.But_Sensor2.Text = "Sensor 2";
            this.But_Sensor2.UseVisualStyleBackColor = true;
            this.But_Sensor2.Click += new System.EventHandler(this.But_Sensor2_Click);
            // 
            // But_Sensor3
            // 
            this.But_Sensor3.Location = new System.Drawing.Point(196, 335);
            this.But_Sensor3.Margin = new System.Windows.Forms.Padding(4);
            this.But_Sensor3.Name = "But_Sensor3";
            this.But_Sensor3.Size = new System.Drawing.Size(79, 37);
            this.But_Sensor3.TabIndex = 18;
            this.But_Sensor3.Text = "Sensor 3";
            this.But_Sensor3.UseVisualStyleBackColor = true;
            this.But_Sensor3.Click += new System.EventHandler(this.But_Sensor3_Click);
            // 
            // fileSystemWatcher1
            // 
            this.fileSystemWatcher1.EnableRaisingEvents = true;
            this.fileSystemWatcher1.SynchronizingObject = this;
            // 
            // But_Venstre
            // 
            this.But_Venstre.BackColor = System.Drawing.SystemColors.Control;
            this.But_Venstre.Location = new System.Drawing.Point(52, 199);
            this.But_Venstre.Margin = new System.Windows.Forms.Padding(4);
            this.But_Venstre.Name = "But_Venstre";
            this.But_Venstre.Size = new System.Drawing.Size(103, 71);
            this.But_Venstre.TabIndex = 19;
            this.But_Venstre.Text = "Venstre";
            this.But_Venstre.UseVisualStyleBackColor = false;
            this.But_Venstre.MouseDown += new System.Windows.Forms.MouseEventHandler(this.But_Venstre_MouseDown);
            this.But_Venstre.MouseUp += new System.Windows.Forms.MouseEventHandler(this.But_Venstre_MouseUp);
            // 
            // But_Højre
            // 
            this.But_Højre.BackColor = System.Drawing.SystemColors.Control;
            this.But_Højre.Location = new System.Drawing.Point(163, 199);
            this.But_Højre.Margin = new System.Windows.Forms.Padding(4);
            this.But_Højre.Name = "But_Højre";
            this.But_Højre.Size = new System.Drawing.Size(103, 71);
            this.But_Højre.TabIndex = 20;
            this.But_Højre.Text = "Højre";
            this.But_Højre.UseVisualStyleBackColor = false;
            this.But_Højre.MouseDown += new System.Windows.Forms.MouseEventHandler(this.But_Højre_MouseDown);
            this.But_Højre.MouseUp += new System.Windows.Forms.MouseEventHandler(this.But_Højre_MouseUp);
            // 
            // TimerVenstre
            // 
            this.TimerVenstre.Tick += new System.EventHandler(this.TimerVenstre_Tick);
            // 
            // TimerHøjre
            // 
            this.TimerHøjre.Tick += new System.EventHandler(this.TimerHøjre_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(776, 385);
            this.Controls.Add(this.But_Højre);
            this.Controls.Add(this.But_Venstre);
            this.Controls.Add(this.But_Sensor3);
            this.Controls.Add(this.But_Sensor2);
            this.Controls.Add(this.But_Sensor1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Send_Info);
            this.Controls.Add(this.Grader_input);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.RPM);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Com_Port);
            this.Controls.Add(this.Baud_rate);
            this.Controls.Add(this.Connect);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Grader_input)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Connect;
        private System.Windows.Forms.ComboBox Baud_rate;
        private System.Windows.Forms.ComboBox Com_Port;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label RPM;
        private System.Windows.Forms.HelpProvider helpProvider1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown Grader_input;
        private System.Windows.Forms.Button Send_Info;
        public System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox Receive_data;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button But_Sensor1;
        private System.Windows.Forms.Button But_Sensor2;
        private System.Windows.Forms.Button But_Sensor3;
        private System.IO.FileSystemWatcher fileSystemWatcher1;
        private System.Windows.Forms.Button But_Højre;
        private System.Windows.Forms.Button But_Venstre;
        private System.Windows.Forms.Timer TimerVenstre;
        private System.Windows.Forms.Timer TimerHøjre;
    }
}

