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
using System.Text.RegularExpressions;
using System.Timers;
using System.Diagnostics;

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

        string senddata = "";
        private int retningmodtaget = 0;
        private string test_sensor1 = "";
        private string test_sensor2 = "";
        private string test_sensor3 = "\n";
       public bool sensor1 = false;
        public bool sensor2 = false;
       public bool sensor3 = false;
        private int isensor1 = 0;
        private int isensor2 = 0;
        private int isensor3 = 0;
        int radarposition = -125;

        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comm = new SerialPortCom(this);
            comm.SetPortNameValues(Com_Port);
            this.myDelegate = new AddDataDelegate(AddDataMethod);
            debugenabled();
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
                    
                    comm.OpenPort();
                    if (comm.OpenPort() == true)
                        Connect.Enabled = false;
                    else
                    {
                        System.Windows.Forms.MessageBox.Show("Kunne ikke åbne Com porten");
                    }

                }

            }
            catch(UnauthorizedAccessException)
            {
                System.Windows.Forms.MessageBox.Show("Ukendt Fejl");
            }


        }

        void Senddata()
        {
            retningmodtaget = 0;
            motor_grader = Convert.ToString(Grader_input.Value);
            motor_rpm = Convert.ToString(numericUpDown1.Value);
            senddata += " -grader ";
            senddata += motor_grader;
            senddata += " -rpm ";
            senddata += motor_rpm;
            senddata += test_sensor1;
            senddata += test_sensor2;
            senddata += test_sensor3;
            comm.WriteData(senddata);
            senddata = "";

        }

        private void debugenabled()
        {
            But_Sensor1.Visible = false;
            But_Sensor2.Visible = false;
            But_Sensor3.Visible = false;
            groupBox1.Visible = false;
            RPM.Visible = false;
            numericUpDown1.Visible = false;
        }



        private void Send_Info_Click(object sender, EventArgs e)
        {

            if (Connect.Enabled == false)
            Senddata();
            else
            {
                System.Windows.Forms.MessageBox.Show("Tilslut til enhed først");
            }
           
                //   ReloadForm2();
                //  Receive_data.Text = serialPort1.ReadLine();

                //    if (Receive_data.Text.Contains("-grader"))
                //   {

                //   sensor2 = true;
                //       sensor3 = true;
                //        panel1.Refresh();
                //    }
        }




        public void Serielmodtaget(string message)
        {

            messagereceived = message;

            Receive_data.Invoke(this.myDelegate, new Object[] { message });



        }

        public void AddDataMethod(String mystring)
        {
            Receive_data.Text = messagereceived;

            if (messagereceived.Contains("-grader"))
            {
                

                int midlertidig = messagereceived.IndexOf("-grader");
                midlertidig += 7;
                string test;

                
                if (messagereceived.Substring(midlertidig + 1, 1) == "-")
                {
                    int i = midlertidig + 1;
                    while (messagereceived.Substring(i, 1) != " " )
                    {
                        i++;
                    }

                    
                    i -= midlertidig;
                    test = messagereceived.Substring(midlertidig, i);
                    
                }
                else
                {

                    int i = midlertidig + 1;
                    while (messagereceived.Substring(i, 1) != " ")
                    {
                        i++;
                    }


                    i -= midlertidig;
                    test = messagereceived.Substring(midlertidig, i);

                }


                //   test = Regex.Match(test, @"\d+").Value;
                retningmodtaget = Convert.ToInt32(test);
                radarposition += retningmodtaget;
            }

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
            messagereceived = "";
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            comm.ClosePort();
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
            Pen radar = new Pen(Color.Lime);


            Rectangle rect = new Rectangle(center.X - radius, center.Y - radius, radius * 2, radius * 2);
            paper.DrawEllipse(pen, rect);
           paper.DrawPie(pen, rect, 0, -100); // Sensor 1
           paper.DrawPie(pen, rect, -50, -100); // Sensor 2
           paper.DrawPie(pen, rect, -100, -100); // Sensor 3

 

            if (sensor1 == true && sensor2 == false && sensor3 == false)
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
            paper.DrawPie(radar, rect, radarposition, 50); // Radar

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

        private void But_Venstre_MouseDown(object sender, MouseEventArgs e)
        {

            if (Connect.Enabled == false)
                TimerVenstre.Start();
            else
            {
                System.Windows.Forms.MessageBox.Show("Tilslut til enhed først");
            }
        }
   

        private void But_Venstre_MouseUp(object sender, MouseEventArgs e)
        {
            TimerVenstre.Stop();
            motor_grader = "0";
        }

        private void But_Højre_MouseDown(object sender, MouseEventArgs e)
        {
            if (Connect.Enabled == false)
                TimerHøjre.Start();
            else
            {
                System.Windows.Forms.MessageBox.Show("Tilslut til enhed først");
            }
        }

        private void But_Højre_MouseUp(object sender, MouseEventArgs e)
        {
            TimerHøjre.Stop();
            motor_grader = "0";
        }
      
 

        private void TimerHøjre_Tick(object sender, EventArgs e)
        {

                int grader = Convert.ToInt32(motor_grader);
                grader += 5;
                Grader_input.Text = Convert.ToString(grader);
                grader = 0;
                Senddata();

   
        }

        private void TimerVenstre_Tick(object sender, EventArgs e)
        {

                int grader = Convert.ToInt32(motor_grader);
                grader += -5;
                Grader_input.Text = Convert.ToString(grader);
                grader = 0;
                Senddata();
            

        }
    }
}


