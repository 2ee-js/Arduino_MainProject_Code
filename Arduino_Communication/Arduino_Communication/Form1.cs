using System.IO.Ports; ///imprort�� �Ȱ���

namespace Arduino_Communication
{
    partial class Form1 : Form
    {
        private SerialPort _serialPort;
        String serial_data;
        public Form1()
        {
            InitializeComponent();
            String[] portNames = SerialPort.GetPortNames();
            foreach (String portName in portNames)
            {
                this.textBox_PortNumber.Text = portName;
            }
            this._serialPort = new SerialPort();
        }

        private void _serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            //throw new NotImplementedException();
            this.serial_data = this._serialPort.ReadLine();
            string[] parsingData = this.serial_data.Split(',');
            //�µ��� ������
            string str_temperature = parsingData[0];
            //������ ������
            string str_humidity = parsingData[1];

            float float_temperature;
            float float_humidity;
            float.TryParse(str_temperature, out float_temperature);
            float.TryParse(str_humidity, out float_humidity);

            this.label_temperature.Invoke(new Action(() =>
            {
                label_temperature.Text = str_temperature;
            }));
            this.label_humidity.Invoke(new Action(() =>
            {
                label_humidity.Text = str_humidity;
            }));
            this.progressBar_Temperature.Invoke(new Action(() =>
            {
                progressBar_Temperature.Value = (int)float_temperature;
            }));
            this.progressBar_Humidity.Invoke(new Action(() =>
            {
                progressBar_Humidity.Value = (int)float_humidity;
            }));
        }

        private void button_PortOpen_Click(object sender, EventArgs e)
        {
            if (this._serialPort.IsOpen)
            {
                this.textBox_PortNumber.Text = "�̹� ��Ʈ�� ���� �ֽ��ϴ�.";
            }
            else
            {
                String temporary = this.textBox_PortNumber.Text;
                if (temporary.Equals(String.Empty))
                {
                    Console.WriteLine("��Ʈ�ѹ��� �Է��� �ȵǾ����ϴ�.");
                    return;
                }
                else
                {   ///�Ƶ��̳� �ø��� ��� �⺻ ����
                    this._serialPort.PortName = this.textBox_PortNumber.Text; ///COM3
                    this._serialPort.BaudRate = 115200;
                    this._serialPort.DataBits = 8;
                    this._serialPort.StopBits = StopBits.One;
                    this._serialPort.Parity = Parity.None;
                    this._serialPort.DataReceived += _serialPort1_DataReceived;
                    this._serialPort.Open();
                }
            }
        }

        private void button_Relay_On_Click(object sender, EventArgs e)
        {
            this._serialPort.WriteLine("SW_ON");
        }

        private void button_Relay_Off_Click(object sender, EventArgs e)
        {
            this._serialPort.WriteLine("SW_OFF");
        }
    }
}