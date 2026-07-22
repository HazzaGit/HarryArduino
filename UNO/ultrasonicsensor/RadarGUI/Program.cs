// See https://aka.ms/new-console-template for more information

using System;
using System.Drawing;
using System.Windows.Forms;

namespace RadarGUI
{
    static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
            
            Application.Run(new RadarForm());

            
        }
    }


    public partial class RadarForm : Form
    {
        public RadarForm()
        {
            //InitializeComponent();
            this.Text = "Radar GUI";
            this.Size = new Size(800, 600);
            this.StartPosition = FormStartPosition.CenterScreen;
        }
    }

}

