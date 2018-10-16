namespace myApp {

    using System.Drawing;

    class SettingsData {

        private int penSize;
 

        private Color pointColor;

        private Brush pointBrush;

        private int pointSize = 10;

        private int lineSize = 1;

        private Color lineColor = Color.Black;

        private int pointSpeed = 15;

        private bool pointRandomDirection;

        private int pointDirectionX =1;

        private int pointDirectionY =1;

        private Brush lineBrush;

        private Pen linePen;
        public SettingsData() {
            //TODO
        }

        public int PointDirectionX {
            set {
                pointDirectionX = value;
            }
            get {
                return pointDirectionX;
            }
        }

        public int PointDirectionY {
            set {
                pointDirectionY = value;
            }
            get {
                return pointDirectionY;
            }
        }

        public bool PointRandomDirection {
            get {
                return pointRandomDirection;
            }
            set {
                pointRandomDirection = value;
            }
        }

        public int PointSpeed {
            set {
                pointSpeed = value;
            }
            get {
                return pointSpeed;
            }
        }

        public Color LineColor {
            get {
               // System.Console.WriteLine(lineColor);
                return lineColor;
            }
            set {
                if(lineColor != value) {
                    lineBrush = null;
                    linePen = null;
                }
                lineColor = value;
            }
        }

        public int LineSize{
            get {
                return lineSize;
            }
            set {
                if(lineSize != value) { 
                    linePen = null;
                }
                lineSize = value;
            }
        }

        public int PointSize {
            get { 
                return pointSize;
            }
            set {
                pointSize = value;
            }
        }    


        public Pen LinePen {
            get {
                if(linePen == null) {
                    linePen = new Pen(LineColor, LineSize);
                }
                return linePen;
            }
        }

        public Brush LineBrush{
            get {
                if(lineBrush == null) {
                    lineBrush = new SolidBrush(LineColor);
                }
                return lineBrush;
            }    
        }

        public Brush PointBrush {
            get {
                if(pointBrush == null) {
                    pointBrush = new SolidBrush(PointColor);
                }  
                return pointBrush;
            }
        }

        public Color PointColor {
            get {
                if(pointColor == null || pointColor == Color.Empty) {
                    pointColor = Color.Blue;
                }
                return pointColor;
            }
            set {
                if(value != pointColor) {
                    pointBrush = null;
                }
                pointColor = value;
            }
        }

 

        public int PenSize {
            get { 
                return penSize;
            }
            set {
                penSize = value;
            }
        }

    }
}