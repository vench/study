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
            set {
                point.X = value;
            }
        }

        public float Y {
            get {
                return point.Y;
            }
            set {
                point.Y = value;
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

        public Rectangle getRectangle(int size) {
              return new Rectangle((int)X-size/2, (int)Y-size/2, size, size);            
        }

        public void updatePoint(Rectangle r) {
            var rnd = new System.Random(abs((int)(X + Y)));
            var sp = rnd.Next(speed/ 2, speed*2);
            float x = point.X + (directionX * sp);
            float y = point.Y + (directionY * sp);
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

        public static int abs(int n) {
            if(n < 0) {
                return -n;
            }
            return n;
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