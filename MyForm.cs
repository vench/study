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

        private MyPoint[] listPoints;

        private int sizePoints;

        private actions mode;

        private Rectangle rectOfDraw;

        private bool allowDot;
 
        private SettingsForm settingsForm;

        private SettingsData settingsData;

        private Timer timer = new Timer();



        public MyForm()
        {

            settingsData = new SettingsData();    
            actionClearPoints();
            
            // SET EVENTS
            Paint += new PaintEventHandler(Form1_Paint);
            this.Click += new EventHandler (Form1_Click); 

            initializeComponent();

            Text = "Рисуем линии";
            SetBounds(0,0, MIN_WIDTH, MIN_HEIGHT);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(MIN_WIDTH, MIN_HEIGHT);
            StartPosition = FormStartPosition.CenterScreen;


            // TIMER
            timer.Interval = 100;
            timer.Enabled = false;
            timer.Tick += new EventHandler(timer1_Tick);

            // KeyEvents
            KeyPreview = true;
            KeyUp += new KeyEventHandler(Form1_KeyDown);
        }

        private void Form1_Paint(object sender,PaintEventArgs e) {
           // Console.WriteLine("Form1_Paint");

            Graphics g = e.Graphics;   
            rectOfDraw = new Rectangle(120, 10, this.Width - 140, this.Height - 50); 
            g.DrawRectangle(Pens.Black, rectOfDraw); 

            if(allowDot) {
                g.DrawString("Режим рисования точек", 
                    SystemFonts.DefaultFont, Brushes.Black, new PointF(130,15));
            }
            if(timer.Enabled) {
                g.DrawString("Скорость точек: " + settingsData.PointSpeed, 
                    SystemFonts.DefaultFont, Brushes.Black, new PointF(130,15));
            }

            // POINTS
            var takeList = listPoints.Take(sizePoints); 
            PointF[] arPoints = new PointF[sizePoints];
            int n = 0;
            int ps = settingsData.PointSize / 2;
            foreach(var point in takeList) {  
                e.Graphics.FillEllipse(settingsData.PointBrush, 
                        new Rectangle((int)point.X-ps, (int)point.Y-ps, settingsData.PointSize, settingsData.PointSize));
                arPoints[n ++] = point.Point;
            } 
            
            if(sizePoints >= 3) {

                switch(mode) {
                    case actions.Curved:
                        g.DrawClosedCurve(settingsData.LinePen, arPoints);
                        break;
                    case actions.Filled:                      
                        g.FillClosedCurve(settingsData.LineBrush, arPoints);
                        break;
                    case actions.Polygone:
                        //TODO
                       // g.DrawPolygon(Pens.Blue, arPoints); 
                        g.DrawCurve(settingsData.LinePen, arPoints);
                        break;
                    case actions.Bize:
                        //TODO  
                        g.DrawBeziers(settingsData.LinePen, arPoints);
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
                    listPoints[sizePoints] = new MyPoint(me.X, me.Y);
                    sizePoints ++;
                    if(sizePoints >= listPoints.Length) {
                        var tmp = new MyPoint[listPoints.Length * 2];
                        listPoints.CopyTo(tmp, 0);
                        listPoints = tmp;
                    }
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
                        timer.Enabled = false;
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
                        actionClearPoints();
                        break;    
                    case "Движение": 
                        actionTimerSwitch();
                        break;

                    default:
                        mode = actions.None;
                        break;
                }
                //MessageBox.Show(b.Text);
            }            
        }

        private void actionClearPoints() {
            timer.Enabled = false;
            allowDot = false;
            listPoints = new MyPoint[10];
            sizePoints = 0; 
            mode = actions.None; 
            Refresh();
        }

        private void actionTimerSwitch() {
            timer.Enabled = !timer.Enabled;
            allowDot = false;
            Refresh();
        }
    
        private void Settings_FromClose(Object sender, FormClosedEventArgs e) {
            settingsForm = null;
            Refresh();
        }

         private void timer1_Tick(object sender, EventArgs e) { 

             if(sizePoints == 0) {
                 return;
             } 

            if(!settingsData.PointRandomDirection) {
                
                int speed  =settingsData.PointSpeed;
                
                for(int i = 0; i < sizePoints; i ++) {
                    //
                    var point = listPoints[i].Point;
                    float x = point.X + (settingsData.PointDirectionX * speed);
                    float y = point.Y + (settingsData.PointDirectionY * speed);
                    if(!rectOfDraw.Contains((int)x, (int)point.Y)) {
                        settingsData.PointDirectionX = -1 * settingsData.PointDirectionX;
                    }  
        
                    if(!rectOfDraw.Contains((int)point.X, (int)y)) { 
                        settingsData.PointDirectionY = -1 * settingsData.PointDirectionY;
                    } 
                }
                for(int i = 0; i < sizePoints; i ++) { 
                    var point = listPoints[i].Point;
                    point.X = point.X + (settingsData.PointDirectionX * speed);
                    point.Y = point.Y + (settingsData.PointDirectionY * speed);
                    listPoints[i].Point = point;
                }    
            } else { 
                for(int i = 0; i < sizePoints; i ++) {
                   listPoints[i].Speed = settingsData.PointSpeed;
                   listPoints[i].updatePoint(rectOfDraw);
                }
            } 
 
             Refresh();
         }


         private void Form1_KeyDown(object sender, KeyEventArgs e) {
             System.Console.WriteLine(e.KeyCode);
             switch (e.KeyCode)
             {                 
                 case Keys.Space:
                     actionTimerSwitch();
                    break; 
                 case Keys.Escape:
                    actionClearPoints();
                    break;   
                case Keys.Up:
                    settingsData.PointSpeed ++;
                    break;   
                case Keys.Down:
                    settingsData.PointSpeed --;
                    break;  
             }

             e.Handled = true;
         }

        
    }


}