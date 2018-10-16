namespace myApp {

    using System.Drawing;

    class MyPoint {

        private PointF point;

        private int speed = 10;

        private int directionX = -1;

        private int directionY = -1;


        public MyPoint(int x, int y) {
            point = new PointF(x, y);
        }
        public MyPoint(PointF point) {
            this.point = point;
        }

        public PointF Point {
            get {
                return point;
            } 
            set {
                point = value;
            }
        }

        public float X {
            get {
                return point.X;
            }
        }

        public float Y {
            get {
                return point.Y;
            }
        }

      
        public int Speed {
            get {
                return speed;
            }
            set {
                speed = value;
            }
        }


        public void updatePoint(Rectangle r) {

            float x = point.X + (directionX * speed);
            float y = point.Y + (directionY * speed);
            if(r.Contains((int)x, (int)point.Y)) {
                point.X = x;
            } else {
                directionX = -1 * directionX;
            }
 
            if(r.Contains((int)point.X, (int)y)) {
                point.Y = y;
            } else {
                directionY = -1 * directionY;
            }
        }


         public static PointF[] toArrayPoint(MyPoint[] input) {
             PointF[] ar = new PointF[input.Length];
             for(int i = 0; i < input.Length; i ++) {
                 ar[i] = input[i].Point;
             }
             return ar;
         }
    }
}