namespace myApp {

    using System;
    using Math;
    using System.Collections.Generic;

    class MatrixRun : AbRunnable
    {
     
        List<Matrix> list = new List<Matrix>();

        protected override void run()
        {
            
            Console.Clear();
            Console.WriteLine( @"
            Работа с матрицами
            
            -------------------------------
            1 - Ввод матрицы
            2 - Операции
            3 - Вывод результатов
            0 - Выход
            -------------------------------

            Список матриц:
            ");

            for(int i = 0; i < list.Count; i ++ ) {
                Console.WriteLine("\tm{0}", i);
            }

            var key = Console.ReadKey();
            switch(key.Key){
                case ConsoleKey.D1: inputMatrix(); break;  
                case ConsoleKey.D2:  break;
                case ConsoleKey.D3:  break;   
                
                case ConsoleKey.D0: 
                    Console.Clear();
                    Stop();   
                    break;   
            }
        }    

        private void inputMatrix() {
            Console.Clear();
            Console.WriteLine(@"
                Введите матрицу m{0}:
                -------------------------------
                ", list.Count);
            var line = Console.ReadLine();
            Matrix m = Matrix.Parse(line);
            list.Add(m);
        }


        private void Test() { 
            //
            Console.WriteLine("xxx");

            double[,] initData = {{1.0,2.0,3.0}, {1.0,0.0,0.0}, {0.0,0.0,0.0}};
             Math.Matrix m = new Math.Matrix(initData);
           // Console.WriteLine(m[0,1]);
             m[2,1] = 7.1;
             m[2,2] = 7.3;
             Console.WriteLine(m);

            double[,] initData1 = {{1,2}, {3,4}};
            Math.Matrix m1 = new Math.Matrix(initData1);
            double[,] initData2 = {{5,6}, {7,8}};
            Math.Matrix m2 = (Math.Matrix)initData2;

            Console.WriteLine(m1);
            Console.WriteLine(m2);
            Console.WriteLine("Суммирование матриц");
            Console.WriteLine(m1+m2);
            Console.WriteLine("Вычитание матриц");
            Console.WriteLine(m1-m2);
            Console.WriteLine("Умножение на скаляр");
            Console.WriteLine(m1*2);
            Console.WriteLine("Умножение матриц");

             double[,] initData3 = {{1,2,3}, {4,5,6}};
            Math.Matrix m3 = new Math.Matrix(initData3);
            double[,] initData4 = {{1,-4}, {-2,7}, {3, -1}};
            Math.Matrix m4 = new Math.Matrix(initData4); 
            Console.WriteLine(m3*m4);
            

            //GetUnity
            Math.Matrix m6 =  Math.Matrix.GetUnity(5);
            Console.WriteLine("IsDiagonal: {0}, IsUnity: {1}", m6.IsDiagonal, m6.IsUnity);
            Console.WriteLine(m6);

            Console.WriteLine("IsDiagonal: {0}, IsUnity: {1}", m1.IsDiagonal, m1.IsUnity);
            Console.WriteLine(m1);

            //Transpose
             Console.WriteLine(m4.Transpose());
            //Trace m6 == 5
            Console.WriteLine(m6.Trace());

            Math.Matrix mp = Math.Matrix.Parse("1 2 2, 3 4 4, 9 0 -1");
            Console.WriteLine(mp);

            Stop();
        }
    }
}