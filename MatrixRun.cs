namespace myApp {

    using System;
    using Math;
    using System.Collections.Generic;

    class MatrixRun : AbRunnable
    {
     
        Dictionary<string,Matrix> context;

        protected override void beforeRun() {
            Console.WriteLine( @"
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Программа работа с матрицами
Для справки введите help   
Для выхода введите exit или нажмите Ctrl + C          
            ");

            context = new Dictionary<string, Matrix>();
        }

        protected override void run()
        {  

            var line = Console.ReadLine();
            ClearCurrentConsoleLine(); 

            switch(line.Trim().ToLower()){    
                case "help": case "?":
                    showHelpInfo();
                    break;
                
                case "exit":  
                    Stop();   
                    break;  

                default:
                    tryInterpret(line);
                    break;     
            }
        }  

        private string readToken(ref int i, ref string input, Func<char,bool> compare) {
            string token = "";
            while(i < input.Length && compare(input[i])) {
                token += input[i];
                i ++;
            }
            i --;
            return token;
        }

        private void tryInterpret(string line) {
            List<AbToken> tokens = new List<AbToken>();
            for(int i = 0; i < line.Length; i ++) {
                if(isChar(line[i])) {
                    var t =  new VariableToken(readToken(ref i, ref line, isChar), context);
                    tokens.Add(t);
                } else if(isOperator(line[i])) {
                    var t =  new OperatorToken(readToken(ref i, ref line, isOperator), context);
                    tokens.Add(t);
                } else if(isDiagonal(line[i])) {
                    var t =  new DiagonalToken(readToken(ref i, ref line, isDiagonal));
                    tokens.Add(t);                    
                } else if(line[i] == '(') {
                    string token = "";
                    i ++;
                    while(i < line.Length &&  line[i] != ')') {
                        token += line[i];
                        i ++;
                    }
                    i --;

                    var t = new MatrixToken(token);
                    tokens.Add(t);
                }  
            }

            //eval
            if(tokens.Count > 0) {
                var ar = tokens.ToArray();
                for (int i = 0; i < ar.Length - 2; i+= 3) {
                    var left = ar[i];
                    var center = ar[i+1];
                    var rignt = ar[i+2];

                    if(center is OperatorToken) { 
                        var test =  center.Eval(left, rignt); 
                        Console.WriteLine(test);
                    } else {
                        Console.WriteLine(left.Eval());
                    }

                }
            }

        }  

        private bool isDiagonal(char c) {             
            return Char.IsDigit(c); 
        }

        private bool isOperator(char c) {
            switch(c) {
                case '*': case '+': case '-':case '=':   
                return true;
            }
            return false;
        }

        private bool isChar(char c) { 
            return Char.IsLetter(c);
        }

        private void inputMatrix() {
           /* Console.Clear();
            Console.WriteLine(@"
                Введите матрицу m{0}:
                -------------------------------
                ", list.Count);
            var line = Console.ReadLine();
            Matrix m = Matrix.Parse(line);
            list.Add(m); */
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

        private void showHelpInfo() {
            Console.WriteLine(@"
Список доступных команд:

Ввод матрицы:
NameMatrix=(0 1 2, 3 4 5)

Операция над матрицей:
(0 1 2, 3 4 5)*1

Операция над матрицей в переменной:
NameMatrix*1

Операция над матрицей двумя матрицами:
NameMatrix*NameMatrix1

Вывод матрицы:
NameMatrix
");
        }

        private void ClearCurrentConsoleLine() {
            Console.SetCursorPosition(0, Console.CursorTop - 1);
            int currentLineCursor = Console.CursorTop;
            Console.SetCursorPosition(0, Console.CursorTop);
            Console.Write(new string(' ', Console.WindowWidth)); 
            Console.SetCursorPosition(0, currentLineCursor);
        }
    }
}