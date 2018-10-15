namespace myApp {

    using System.Drawing;

    class SettingsData {

        private int penSize;

        private Color fontColor;

        private Color pointColor;

        private Brush pointBrush;

        private int pointSize = 10;

        private int lineSize = 1;

        private Color lineColor;


        public SettingsData() {
            //TODO
        }

        public Color LineColor {
            get {
                return lineColor;
            }
            set {
                lineColor = value;
            }
        }

        public int LineSize{
            get {
                return lineSize;
            }
            set {
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


        public Color FontColor {
            get {
                if(fontColor == null) {
                    fontColor = Color.Black;
                }
                return fontColor;
            }
            set {
                fontColor = value;
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