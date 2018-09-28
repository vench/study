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
                case ConsoleKey.D1: execRunnable(new CommonInfo()); break;  
                case ConsoleKey.D2: execRunnable(new SelectInfoFromList()); break;
                case ConsoleKey.D3: execRunnable(new InputTypeName()); break;   
                case ConsoleKey.D4: showRunMessage();  break; 
                case ConsoleKey.D0: 
                    Console.Clear();
                    Stop();   
                    break;   
            } 
        }

        private void execRunnable(Runnable r) {
            r.Run();
            showRunMessage();
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