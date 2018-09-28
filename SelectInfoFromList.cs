namespace myApp {

    using System;
    using System.Collections.Generic;

    class SelectInfoFromList : AbInfoType {



        protected override void beforeRun() {
            showSelectFromListMessage();     
        }

        protected override void run() {
            var key = Console.ReadKey();
                Console.WriteLine("\n");
            
                switch(key.Key){
                    case ConsoleKey.D1:  showAboutType( typeof(uint) );  break;
                    case ConsoleKey.D2:  showAboutType( typeof(int) );  break;
                    case ConsoleKey.D3:  showAboutType( typeof(long) );  break;
                    case ConsoleKey.D4:  showAboutType( typeof(float) );  break;
                    case ConsoleKey.D5:  showAboutType( typeof(double) );  break;
                    case ConsoleKey.D6:  showAboutType( typeof(char) );  break;
                    case ConsoleKey.D7:  showAboutType( typeof(string) );  break;
                    case ConsoleKey.D8:  showAboutType( typeof(MyClass) );  break;
                    case ConsoleKey.D9:  showAboutType( typeof(MyStruct) );  break;
                    case ConsoleKey.D0: Stop(); break;
                }  

                showSelectFromListMessage();  
        }   

        private void showSelectFromListMessage() {
            Console.Clear(); 
            Console.WriteLine(
            @"
            Выберете тип из списка:    
              1 - uint
              2 - int
              3 - long
              4 - float
              5 - double
              6 - char
              7 - string
              8 - MyClass
              9 - MyStruct
              0 - Выход в главное меню");
        } 
    }
}