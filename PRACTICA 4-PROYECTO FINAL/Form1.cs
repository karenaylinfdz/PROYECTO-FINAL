using System;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;
namespace ESCALERA
{
    public partial class Form1 : Form
    {
        SerialPort serialPort1;
        PictureBox[] leds;
        public Form1()
        {
            InitializeComponent();
            leds = new PictureBox[] { pictureBox1, pictureBox2, pictureBox3, pictureBox4, pictureBox5 };

            serialPort1 = new SerialPort("COM3", 9600);
            serialPort1.DataReceived +=
            SerialPort_DataReceived;

            try
            {
                serialPort1.Open();
            }
            catch
            {
                MessageBox.Show("No se pudo abrir el puerto COM3");
            }
        }

        private void
        SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            string data =
            serialPort1.ReadLine().Trim(); //Lee línea del Arduino

            if (int.TryParse(data, out int valor))
            {
                this.Invoke(new Action(() =>
                {
                    UpdateLeds(valor);
                }));


            }

        }

        private void UpdateLeds(int num)
        {

            for (int i = 0; i < leds.Length; i++)
            {
                if (i < num)
                    leds[i].BackColor = Color.Red;
                else
                    leds[i].BackColor = Color.Gray;
            }




        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void buttonON1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("AON");
        }

        private void buttonOFF1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("AOFF");
        }

        private void buttonON2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("BON");
        }

        private void buttonOFF2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("BOFF");
        }

        private void buttonON3_Click(object sender, EventArgs e)
        {
            serialPort1.Write("CON");
        }

        private void buttonOFF3_Click(object sender, EventArgs e)
        {
            serialPort1.Write("COFF");
        }
    }
}
