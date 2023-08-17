namespace Arduino_Communication
{
    partial class Form1 : Form ///  ' : ' 는 자바에서 extends와 같은 의미 즉 상속의 의미이다.
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            label1 = new Label();
            label2 = new Label();
            progressBar_Temperature = new ProgressBar();
            progressBar_Humidity = new ProgressBar();
            label_temperature = new Label();
            label_humidity = new Label();
            button_Relay_On = new Button();
            button_PortOpen = new Button();
            button_Relay_Off = new Button();
            label3 = new Label();
            textBox_PortNumber = new TextBox();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("맑은 고딕", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(141, 82);
            label1.Name = "label1";
            label1.Size = new Size(52, 28);
            label1.TabIndex = 0;
            label1.Text = "온도";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("맑은 고딕", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(141, 293);
            label2.Name = "label2";
            label2.Size = new Size(52, 28);
            label2.TabIndex = 1;
            label2.Text = "습도";
            // 
            // progressBar_Temperature
            // 
            progressBar_Temperature.Location = new Point(224, 76);
            progressBar_Temperature.Name = "progressBar_Temperature";
            progressBar_Temperature.Size = new Size(592, 34);
            progressBar_Temperature.TabIndex = 2;
            // 
            // progressBar_Humidity
            // 
            progressBar_Humidity.Location = new Point(224, 282);
            progressBar_Humidity.Name = "progressBar_Humidity";
            progressBar_Humidity.Size = new Size(592, 39);
            progressBar_Humidity.TabIndex = 3;
            // 
            // label_temperature
            // 
            label_temperature.AutoSize = true;
            label_temperature.Font = new Font("맑은 고딕", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label_temperature.Location = new Point(862, 82);
            label_temperature.Name = "label_temperature";
            label_temperature.Size = new Size(79, 28);
            label_temperature.TabIndex = 4;
            label_temperature.Text = "온도 값";
            // 
            // label_humidity
            // 
            label_humidity.AutoSize = true;
            label_humidity.Font = new Font("맑은 고딕", 15F, FontStyle.Regular, GraphicsUnit.Point);
            label_humidity.Location = new Point(862, 293);
            label_humidity.Name = "label_humidity";
            label_humidity.Size = new Size(79, 28);
            label_humidity.TabIndex = 5;
            label_humidity.Text = "습도 값";
            // 
            // button_Relay_On
            // 
            button_Relay_On.Location = new Point(379, 496);
            button_Relay_On.Name = "button_Relay_On";
            button_Relay_On.Size = new Size(100, 23);
            button_Relay_On.TabIndex = 6;
            button_Relay_On.Text = "Relay SW On";
            button_Relay_On.UseVisualStyleBackColor = true;
            button_Relay_On.Click += button_Relay_On_Click;
            // 
            // button_PortOpen
            // 
            button_PortOpen.Location = new Point(504, 434);
            button_PortOpen.Name = "button_PortOpen";
            button_PortOpen.Size = new Size(100, 23);
            button_PortOpen.TabIndex = 7;
            button_PortOpen.Text = "아두이노연결";
            button_PortOpen.UseVisualStyleBackColor = true;
            button_PortOpen.Click += button_PortOpen_Click;
            // 
            // button_Relay_Off
            // 
            button_Relay_Off.Location = new Point(504, 496);
            button_Relay_Off.Name = "button_Relay_Off";
            button_Relay_Off.Size = new Size(100, 23);
            button_Relay_Off.TabIndex = 8;
            button_Relay_Off.Text = "Relay SW Off";
            button_Relay_Off.UseVisualStyleBackColor = true;
            button_Relay_Off.Click += button_Relay_Off_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(376, 422);
            label3.Name = "label3";
            label3.Size = new Size(99, 15);
            label3.TabIndex = 9;
            label3.Text = "Port 상태 (Mega)";
            // 
            // textBox_PortNumber
            // 
            textBox_PortNumber.Location = new Point(376, 440);
            textBox_PortNumber.Name = "textBox_PortNumber";
            textBox_PortNumber.Size = new Size(100, 23);
            textBox_PortNumber.TabIndex = 10;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1065, 601);
            Controls.Add(textBox_PortNumber);
            Controls.Add(label3);
            Controls.Add(button_Relay_Off);
            Controls.Add(button_PortOpen);
            Controls.Add(button_Relay_On);
            Controls.Add(label_humidity);
            Controls.Add(label_temperature);
            Controls.Add(progressBar_Humidity);
            Controls.Add(progressBar_Temperature);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private ProgressBar progressBar_Temperature;
        private ProgressBar progressBar_Humidity;
        private Label label_temperature;
        private Label label_humidity;
        private Button button_Relay_On;
        private Button button_PortOpen;
        private Button button_Relay_Off;
        private Label label3;
        private TextBox textBox_PortNumber;
    }
}