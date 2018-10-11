namespace myApp {

    using System;
    using Math;
    using System.Collections.Generic;

    class MatrixRun : AbRunnable
    {
     
        const string CURENT_VAL = "curent";

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
            //ClearCurrentConsoleLine(); 

            switch(line.Trim().ToLower()){    
                case "help": case "?":
                    showHelpInfo();
                    break;
                case "list":
                    showContextInfo();
                    break;
                
                case "exit":  
                    Stop();   
                    break;  

                default:
                    try {
                        tryInterpret(line);
                    } catch(Exception e) {
                        printConsole("Ошибка: " +e.Message);
                    }    
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
            if(tokens.Count > 2) {
                object result = null; 
                string valName = CURENT_VAL; 
                var ar = tokens.ToArray();
                for (int i = 0; i < ar.Length - 2; i+= 2) {
                    var left = ar[i];
                    var center = ar[i+1];
                    var rignt = ar[i+2];                    

                    if(center is OperatorToken) { 
                        result =  center.Eval(left, rignt);  

                        if(result is Matrix) { 
                            
                            if(left is VariableToken && center.getToken() == "=") {
                                valName = left.getToken();
                            }

                            context[valName] = (Matrix)result;
                            ar[i+2] = new VariableToken(valName, context);
                            continue;
                        } 

                    } else {
                        result = left.Eval(); 
                    }
                    break;
                }

                printConsole( result);
            } else  if(tokens.Count > 0) {
                printConsole(tokens[0].Eval());
            }
        }  


        private void printConsole(object o) {
            if(o is null) {
                return;
            }
            Console.WriteLine("> {0}", o);
        }

        private bool isDiagonal(char c) {             
            return Char.IsDigit(c); 
        }

        private bool isOperator(char c) {
            switch(c) {
                case '*': case '+': case '-':case '=': case '.':   
                return true;
            }
            return false;
        }

        private bool isChar(char c) { 
            return Char.IsLetter(c);
        }

         

 


        private void showContextInfo() {
            foreach(var item in context) {
                Console.WriteLine("> {0, -10} -> M({1} X {2})", 
                    item.Key, 
                    item.Value.Rows, 
                    item.Value.Columns);
            }
        }

        private void showHelpInfo() {
            Console.WriteLine(@"
Список доступных команд:
    >list - вывод всех матриц
    >help - это меню
    >curent - переменная последнего результата матрицы
Список формата:
    Ввод матрицы:
    >NameMatrix=(0 1 2, 3 4 5)

    Операция над матрицей:
    >(0 1 2, 3 4 5)*1

    Операция над матрицей в переменной:
    >NameMatrix*1

    Операция над матрицей двумя матрицами:
    >NameMatrix*NameMatrix1

    Вывод матрицы:
    >NameMatrix

    Транспонирование матрицы
    >NameMatrix.T
    
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