namespace myApp {

    using System;

    class MatrixRun : AbRunnable
    {



        
        public MatrixRun()
        {

        }

        protected override void run()
        {
            //
            Console.WriteLine("xxx");

            double[,] initData = {{1.0,2.0,3.0}, {1.0,0.0,0.0}, {0.0,0.0,0.0}};
             Math.Matrix m = new Math.Matrix(initData);
           // Console.WriteLine(m[0,1]);
             m[2,1] = 7.1;
             m[2,2] = 7.3;
             Console.WriteLine(m);

            Stop();
        }
    }
}