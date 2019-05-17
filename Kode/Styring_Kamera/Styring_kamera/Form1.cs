using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Drawing.Drawing2D;



namespace Styring_kamera

{

    

    public partial class Form1 : Form
    {

        SerialPortCom comm;
        public delegate void AddDataDelegate(String mystring);
        public AddDataDelegate myDelegate;

        public string messagereceived;
        string motor_grader = "";
        string motor_rpm = "";
        string retning = "";
        string senddata = "";
        private string test_sensor1 = "";
        private string test_sensor2 = "";
        private string test_sensor3 = "\n";
        bool sensor1 = false;
        bool sensor2 = false;
        bool sensor3 = false;
        private int isensor1 = 0;
        private int isensor2 = 0;
        private int isensor3 = 0;
        


        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comm = new SerialPortCom(this);
            comm.SetPortNameValues(Com_Port);
            this.myDelegate = new AddDataDelegate(AddDataMethod);
        }





        public void Connect_Click(object sender, EventArgs e)
        {
            motor_grader = Convert.ToString(Grader_input.Value);
            motor_rpm = Convert.ToString(numericUpDown1.Value);

            try
            {
                if(Baud_rate.Text=="" || Com_Port.Text=="")
                {
                    System.Windows.Forms.MessageBox.Show("Husk at vælg Seriel Settings");
                }
                else
                {

                    comm.BaudRate = Baud_rate.Text;
                    comm.ComPort = Com_Port.Text;
                    Connect.Enabled = false;
                    comm.OpenPort();

                }

            }
            catch(UnauthorizedAccessException)
            {
                System.Windows.Forms.MessageBox.Show("Ukendt Fejl");
            }



        }




        private void NumericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void Send_Info_Click(object sender, EventArgs e)
        {
            if (retning == "right" || retning == "left")
            { 

               motor_grader = Convert.ToString(Grader_input.Value);
               motor_rpm = Convert.ToString(numericUpDown1.Value);
               senddata = "-Retning ";
               senddata += retning;
               senddata += " -grader ";
               senddata += motor_grader;
               senddata += " -rpm ";
               senddata += motor_rpm;
               senddata += test_sensor1;
               senddata += test_sensor2;
               senddata += test_sensor3;
               comm.WriteData(senddata);
             //  Receive_data.Text = serialPort1.ReadLine();

            //    if (Receive_data.Text.Contains("-grader"))
             //   {

                 //   sensor2 = true;
             //       sensor3 = true;
            //        panel1.Refresh();
            //    }
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Husk at vælg en retning");
            }
        }

        private void Button_højre_Click(object sender, EventArgs e)
        {
            retning = "right";
            Button_venstre.Enabled = true;
            Button_højre.Enabled = false;
        }

        private void Button_venstre_Click(object sender, EventArgs e)
        {
            retning = "left";
            Button_venstre.Enabled = false;
            Button_højre.Enabled = true;
        }


        public void Serielmodtaget(string message)
        {

            messagereceived = message;

            Receive_data.Invoke(this.myDelegate, new Object[] { message });



        }

        public void AddDataMethod(String mystring)
        {
            Receive_data.Text = messagereceived;


            if (messagereceived.Contains("-Sensor1 ON"))
            {
                sensor1 = true;

            }
            else
            {
                sensor1 = false;
            }


            if (messagereceived.Contains("-Sensor2 ON"))
            {
                sensor2 = true;

            }
            else
            {
                sensor2 = false;
            }


            if (messagereceived.Contains("-Sensor3 ON"))
            {
                sensor3 = true;

            }
            else
            {
                sensor3 = false;
            }

            panel1.Refresh();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort1.Close();
        }


        private void Form1_Paint(object sender, PaintEventArgs e)
        {

        }

        public void Panel1_Paint(object sender, PaintEventArgs e)
        {

            int centerX = 120;
            int centerY = 120;
            int radius = 75;






            Point center = new Point(centerX, centerY);

            Graphics paper = e.Graphics;
            paper = panel1.CreateGraphics();
            Pen pen = new Pen(Color.Black);
            Brush Detection = new SolidBrush(Color.Red);
            Brush none = new SolidBrush(Color.White);


            Rectangle rect = new Rectangle(center.X - radius, center.Y - radius, radius * 2, radius * 2);
            paper.DrawEllipse(pen, rect);
           paper.DrawPie(pen, rect, 0, -100); // Sensor 1
           paper.DrawPie(pen, rect, -50, -100); // Sensor 2
       //    paper.FillPie(Detection, rect, 0, -150); // Sensor 2
           paper.DrawPie(pen, rect, -100, -100); // Sensor 3
            //    paper.FillPie(Detection, rect, 0, -250); // Sensor 3

          if(sensor1 == true && sensor2 == false && sensor3 == false)
            {
                paper.FillPie(Detection, rect, 0, -50); // Sensor 1

            }

            if (sensor1 == true && sensor2 == true && sensor3 == false)
            {
                paper.FillPie(Detection, rect, -50, -50); 

            }

            if (sensor1 == false && sensor2 == true && sensor3 == true)
            {
                paper.FillPie(Detection, rect, -100, -50); 

            }

            if (sensor1 == false && sensor2 == false && sensor3 == true)
            {
                paper.FillPie(Detection, rect, -200, 50);

            }

        }

        private void But_Sensor1_Click(object sender, EventArgs e)
        {

            if (isensor1 == 1)
            {
                But_Sensor1.BackColor = default(Color);
                isensor1 = 0;
                test_sensor1 = " ";
                return;
            }
            if ( isensor1 == 0)
            {
                But_Sensor1.BackColor = Color.Lime;
                isensor1 = 1;
                test_sensor1 = " -Sensor1 ON ";
                return;
            }
 
        }

        private void But_Sensor2_Click(object sender, EventArgs e)
        {


            if (isensor2 == 0)
            {
                But_Sensor2.BackColor = Color.Lime;
                isensor2 = 1;
                test_sensor2 = "-Sensor2 ON ";
                return;
            }
            if (isensor2 == 1)
            {
                But_Sensor2.BackColor = default(Color);
                isensor2 = 0;
                test_sensor2 = " ";
                return;
            }
        }

        private void But_Sensor3_Click(object sender, EventArgs e)
        {

            if (isensor3 == 0)
            {
                But_Sensor3.BackColor = Color.Lime;
                isensor3 = 1;
                test_sensor3 = "-Sensor3 ON \n";
                return;
            }
            if (isensor3 == 1)
            {
                But_Sensor3.BackColor = default(Color);
                isensor3 = 0;
                test_sensor3 = " \n";
                return;
            }
        }
    }
}


