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


        enum actions  {DOT, CLEAR, DEFAULT};

        const int MIN_WIDTH = 640;
        const int MIN_HEIGHT = 480;

        List<PointF> listPoints;

        private actions mode;

        private Rectangle rectOfDraw;
 

        public MyForm()
        {

            listPoints = new  List<PointF>();   
            
            // SET EVENTS
            Paint += new PaintEventHandler(Form1_Paint);
            this.Click += new EventHandler (Form1_Click); 

            initializeComponent();

            Text = "Рисуем линии";
            SetBounds(0,0, MIN_WIDTH, MIN_HEIGHT);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(MIN_WIDTH, MIN_HEIGHT);
            StartPosition = FormStartPosition.CenterScreen;
        }

        private void Form1_Paint(object sender,PaintEventArgs e) {
            Console.WriteLine("Form1_Paint");

            Graphics g = e.Graphics; 
              
           // g.Clear(Color.White);
            var p = new Pen(Color.Black, 1);
            rectOfDraw = new Rectangle(120, 10, this.Width - 140, this.Height - 50); 
            g.DrawRectangle(p, rectOfDraw); 
/**//*
            foreach(var point in listPoints) {
                Console.WriteLine("Draw point");
                e.Graphics.DrawRectangle(p, point.X, point.Y, 10, 10);
            }*/
            if(listPoints.Count > 0) {

                switch(mode) {
                    case actions.DOT:
                        break;
                    case actions.DEFAULT:

                        break;    
                }
                Console.WriteLine(listPoints);
                g.FillClosedCurve(Brushes.ForestGreen, listPoints.ToArray());
            }
                
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
        }
 

        private void Form1_Click(object sender, EventArgs e) {
            if(e is MouseEventArgs) {
                var me = (MouseEventArgs)e;
                if(rectOfDraw.Contains(me.Location.X, me.Location.Y)) {
                    Console.WriteLine("Click to rect");
                    listPoints.Add(new PointF(me.X, me.Y)); //me.Location
                }
                Console.WriteLine(me.Location);
                Refresh();
            } 
        }

        private void Button_Click(object sender, EventArgs e)
        {
            if(sender is Button) {
                var b = (Button)sender;
                switch(b.Text) {
                    case "Точки":
                        mode = actions.DOT;
                        Refresh();
                        break;
                    case "Очистить":
                        listPoints.Clear(); 
                        mode = actions.CLEAR;
                        Refresh();
                        break;    
                    default:
                        mode = actions.DEFAULT;
                        break;
                }
                //MessageBox.Show(b.Text);
            }            
        }
    }
}