using System;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;

namespace Styring_kamera // HUSK endline hvis der bruges readline
{
    public class SerialPortCom
    {
        private string _baudrate = string.Empty;
        private string _comport = string.Empty;
        private SerialPort SerialPort1 = new SerialPort();
        private Form1 f1;


        public string BaudRate
        {
            get { return _baudrate; }
            set { _baudrate = value; }
        }

        public string ComPort
        {
            get { return _comport; }
            set { _comport = value; }
        }





        public SerialPortCom(string baud, string portComport, Form1 myform)
        {
            f1 = myform;
            _baudrate = baud;
            _comport = portComport;

            //   SerialPort1.DataReceived += new SerialDataReceivedEventHandler(SerialPort1_DataReceived);
            SerialPort1.DataReceived += SerialPort1_DataReceived;
        }



        public SerialPortCom(Form1 myform)
        {
            f1 = myform;
            _baudrate = string.Empty;
            _comport = "COM1";
            // SerialPort1.DataReceived += new SerialDataReceivedEventHandler(SerialPort1_DataReceived);
            SerialPort1.DataReceived += SerialPort1_DataReceived;

        }

        void SerialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            updateFormGUI(SerialPort1.ReadLine());

        }
        private void updateFormGUI(string s)
        {
            f1.Serielmodtaget(s);
        }


        public void SetPortNameValues(object obj)
        {

            foreach (string str in SerialPort.GetPortNames())
            {
                ((ComboBox)obj).Items.Add(str);
            }
        }

        public bool OpenPort()
        {
            try
            {
                //first check if the port is already open
                //if its open then close it
                if (SerialPort1.IsOpen == true) SerialPort1.Close();

                //set the properties of our SerialPort Object
                SerialPort1.BaudRate = int.Parse(_baudrate); //BaudRate
                SerialPort1.PortName = _comport; //PortName

                //now open the port
                SerialPort1.Open();
                //return true
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Fejl ved åbning af com port");
                return false;
            }
        }

        public void WriteData(string msg)
        {
            if (!(SerialPort1.IsOpen == true)) SerialPort1.Open();
            SerialPort1.Write(msg);
        }

    }
}