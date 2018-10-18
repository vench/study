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
    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {

        enum actions  {None, Bize, Curved, Filled, Polygone};

        const int MIN_WIDTH = 640;
        const int MIN_HEIGHT = 480;
        private MyPoint[] listPoints;
        private int sizePoints;
        private int pointActiveIndex =-1;
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
            Click += new EventHandler (Form1_Click); 
            MouseDown += new MouseEventHandler (Form1_MouseDown);
            MouseUp += new MouseEventHandler (Form1_MouseUp);
            MouseMove += new MouseEventHandler (Form1_MouseMove);

            // TIMER
            timer.Interval = 100;
            timer.Enabled = false;
            timer.Tick += new EventHandler(timer1_Tick);

            // KeyEvents
            KeyPreview = true;
            KeyUp += new KeyEventHandler(Form1_KeyDown);

            // INIT
            initializeComponent();

            Text = "Рисуем линии";
            SetBounds(0,0, MIN_WIDTH, MIN_HEIGHT);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(MIN_WIDTH, MIN_HEIGHT);
            StartPosition = FormStartPosition.CenterScreen;            
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
            PointF[] arPoints = new PointF[sizePoints];            
            int ps = settingsData.PointSize / 2;
            for(int i = 0; i < sizePoints; i ++) { 
                if(pointActiveIndex == i) {
                    e.Graphics.FillEllipse(Brushes.Red, 
                         listPoints[i].getRectangle(settingsData.PointSize+2));
                }  
                e.Graphics.FillEllipse(settingsData.PointBrush, 
                         listPoints[i].getRectangle(settingsData.PointSize));
                       
                arPoints[i] = listPoints[i].Point;
            } 
            
            if(sizePoints > 1) {
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
                        if(arPoints.Length == 4) {
                            g.DrawBeziers(settingsData.LinePen, arPoints);
                        }                        
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
                        allowDot = false;
                        mode = actions.Curved;
                        Refresh();
                        break;      
                    case "Ломаная":
                        allowDot = false;
                        mode = actions.Polygone;
                        Refresh();
                        break;
                    case "Безье":
                        allowDot = false;
                        mode = actions.Bize;
                        Refresh();
                        break;
                    case "Заполненная":
                        allowDot = false;
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


         protected override bool ProcessCmdKey(ref Message msg, Keys keyData) {
             if(Keys.Right == keyData || Keys.Left == keyData  || Keys.Down == keyData  || Keys.Up == keyData) { 
                    return HandledKeys(keyData);
             }
             return base.ProcessCmdKey(ref msg, keyData);
         }    
         private void Form1_KeyDown(object sender, KeyEventArgs e) {
            // System.Console.WriteLine(e.KeyCode);  
            e.Handled = HandledKeys(e.KeyCode);  
         }


        private bool HandledKeys(Keys key) {
            switch (key)
             {                 
                 case Keys.Space:
                     actionTimerSwitch();
                    return true; 
                 case Keys.Escape:
                    actionClearPoints();
                    return true;  
                case Keys.Up:
                    if(timer.Enabled) {
                        settingsData.PointSpeed ++;
                    } else {
                        pointsMoveTo(0, -1);
                    } 
                    return true;    
                case Keys.Down:
                    if(timer.Enabled) {
                        settingsData.PointSpeed --;
                    }  else {
                        pointsMoveTo(0, 1);
                    }
                    return true; 
                case Keys.Left:
                    if(timer.Enabled) {
                        settingsData.PointSpeed --;
                    } else {
                        pointsMoveTo(-1, 0);
                    }                  
                    return true;    
                case Keys.Right:
                    if(timer.Enabled) {
                        settingsData.PointSpeed ++;
                    }  else {
                        pointsMoveTo(1, 0);
                    }
                    return true;    
                case Keys.Oemplus:
                    if(timer.Enabled) {
                        settingsData.PointSpeed ++;
                    }  
                    return true;  
                case Keys.OemMinus:
                    if(timer.Enabled) {
                        settingsData.PointSpeed --;
                    }  
                    return true;  
            }

            return false;
        } 
        

        private void pointsMoveTo(int x, int y) {
            if(sizePoints == 0) {
                return;
            }

            if(pointActiveIndex >= 0) {
                listPoints[pointActiveIndex].X += x;
                listPoints[pointActiveIndex].Y += y;
            } else {
                for(int i = 0; i < sizePoints; i ++) {
                    listPoints[i].X += x;
                    listPoints[i].Y += y;
                }
            }           

            Refresh();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e) {
            if(allowDot || sizePoints == 0) {
                return;
            }  

            timer.Enabled = false;
 
            for(int i = 0; i < sizePoints; i ++) {
                var r = listPoints[i].getRectangle(settingsData.PointSize );
                if(r.Contains(e.Location.X, e.Location.Y)) {
                    pointActiveIndex = i; 
                    Refresh();
                    return;
                }
            }
            pointActiveIndex = -1;
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e) {
           // System.Console.WriteLine("Form1_MouseUp");
            pointActiveIndex = -1;
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e) {
            
            if(pointActiveIndex  >= 0) {
                listPoints[pointActiveIndex].X = e.X;
                listPoints[pointActiveIndex].Y = e.Y;
                Refresh();
            }
        } 
        
    }

}