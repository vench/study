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


        enum actions  {None, Bize, Curved, Filled, Polygone};

        const int MIN_WIDTH = 640;
        const int MIN_HEIGHT = 480;

        List<PointF> listPoints;

        private actions mode;

        private Rectangle rectOfDraw;

        private bool allowDot;
 
        private SettingsForm settingsForm;

        private SettingsData settingsData;

        public MyForm()
        {

            settingsData = new SettingsData();    
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
            var p = new Pen(settingsData.FontColor, 1);
            rectOfDraw = new Rectangle(120, 10, this.Width - 140, this.Height - 50); 
            g.DrawRectangle(p, rectOfDraw); 

            if(allowDot) {
                g.DrawString("Редим рисования точек", 
                    SystemFonts.DefaultFont, Brushes.Black, new PointF(130,15));
            }

            // POINTS

            foreach(var point in listPoints) { 
                e.Graphics.FillEllipse(settingsData.PointBrush, 
                        new Rectangle((int)point.X, (int)point.Y, settingsData.PointSize, settingsData.PointSize));
            } 
            
            if(listPoints.Count >= 3) {

                switch(mode) {
                    case actions.Curved:
                        g.DrawClosedCurve(Pens.Blue, listPoints.ToArray());
                        break;
                    case actions.Filled:                      
                        g.FillClosedCurve(Brushes.Blue, listPoints.ToArray());
                        break;
                    case actions.Polygone:
                        //TODO
                       // g.DrawPolygon(Pens.Blue, listPoints.ToArray()); 
                        g.DrawCurve(Pens.Blue, listPoints.ToArray());
                        break;
                    case actions.Bize:
                        //TODO  
                        g.DrawBeziers(Pens.Blue, listPoints.ToArray());
                        break;   
                    case actions.None: 
                        break;    
                }  
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
            if(!allowDot) {
                return;
            }
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
                        allowDot = !allowDot; 
                        Refresh();
                        break;
                    case "Параметры":
                        if (settingsForm == null || settingsForm.Disposing) {
                            settingsForm = new SettingsForm(settingsData);
                            settingsForm.FormClosed += new FormClosedEventHandler(Settings_FromClose);
                        }                        
                        settingsForm.Show();
                        break;    
                    case "Кривая":
                        mode = actions.Curved;
                        Refresh();
                        break;      
                    case "Ломаная":
                        mode = actions.Polygone;
                        Refresh();
                        break;
                    case "Безье":
                        mode = actions.Bize;
                        Refresh();
                        break;
                    case "Заполненная":
                        mode = actions.Filled;
                        Refresh();
                        break;
                    case "Очистить":
                        listPoints.Clear();  
                        mode = actions.None;
                        Refresh();
                        break;    
                    default:
                        mode = actions.None;
                        break;
                }
                //MessageBox.Show(b.Text);
            }            
        }
    
        private void Settings_FromClose(Object sender, FormClosedEventArgs e) {
            settingsForm = null;
        }
    }


}