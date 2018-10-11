namespace myApp {

    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Data;
    using System.Drawing;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows.Forms; 
    ///usr/lib/mono/gac/System.Windows.Forms/4.0.0.0__b77a5c561934e089/System.Windows.Forms.dll
    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {

        const int MIN_WIDTH = 640;
        const int MIN_HEIGHT = 480;

        public MyForm()
        {

            Paint += new PaintEventHandler(Form1_Paint);

            initializeComponent();

            Text = "Main frame";
            SetBounds(0,0, MIN_WIDTH, MIN_HEIGHT);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(MIN_WIDTH, MIN_HEIGHT);
            StartPosition = FormStartPosition.CenterScreen;
        }

        void Form1_Paint(object sender,PaintEventArgs e) {
            Graphics g = e.Graphics;
            
            // Set up the arc.  
   var p = new Pen(Color.MediumBlue, 3);
   var r = new Rectangle(100, 100, 200, 100);
   float startAngle = 0.0f;
   float sweepAngle = 90.0f;

   // Draw the arc.
            g.DrawArc(p, r, startAngle, sweepAngle);
            Console.WriteLine("xxxx");
        }

        private void initializeComponent() {
 
            string[] list = new string[]{"Точки", "Параметры", "Кривая", "Ломаная", "Безье", "Заполненная", "Движение", "Очистить"};

            for(int i = 0; i < list.Length; i ++){
                Button b = new Button ();
                b.Text = list[i];
                b.SetBounds(10, 10 + i * 35, 100, 25);
                b.Click += new EventHandler (Button_Click);
                Controls.Add (b);
            } 

            //Canvas myCanvas = new Canvas();
        }
 
        private void Button_Click(object sender, EventArgs e)
        {
            MessageBox.Show(sender.GetType().Name, e.ToString());
        }
    }
}