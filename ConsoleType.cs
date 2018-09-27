using System;
using System.Reflection;

namespace myApp {
    class ConsoleType : AbRunnable {
  
        protected override void beforeRun() {
            showRunMessage();
        }

        protected override void run() {  
            consoleReadKey();              
        }  
 
        private void consoleReadKey() {
            var key = Console.ReadKey(); 
            
            switch(key.Key){
                case ConsoleKey.D1: commonInfoAboutTypes();  break;  
                case ConsoleKey.D2: selectFromList();         break;
                case ConsoleKey.D3: interTypeName();          break;   
                case ConsoleKey.D4: showRunMessage();         break; 
                case ConsoleKey.D0: 
                    Console.Clear();
                    Stop();   
                    break;   
            } 
        }

        private void interTypeName() {
            Console.WriteLine("interTypeName");
        }

        private void commonInfoAboutTypes() {            
            (new CommonInfo()).Run();
            showRunMessage();           
        }

        private void showSelectFromListMessage() {
            Console.Clear();
            Console.WriteLine("Выберете тип из списка:");
            Console.WriteLine(
            @"
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

        private void selectFromList() {
            
            showSelectFromListMessage();

            bool localRun = true;
            
            do {
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
                    case ConsoleKey.D0: localRun = false; break;
                }    
            } while(localRun);

            showRunMessage();
        }

        private void showAboutType(Type t) {
            Console.WriteLine( t.FullName );
                        Console.WriteLine("Нажмите любую клавишу, чтобы вернуться в меню");
                        Console.ReadKey();
                        showSelectFromListMessage();
        }


        private void showRunMessage() {
            Console.Clear();
            Console.WriteLine(@"Информация по типам:
                        1 - Общая информация по типам
                        2 - Выбрать из списка
                        3 - Ввести имя типа
                        4 - Параметры консоли
                        0 - Выход из программы");
        }
    }    

}