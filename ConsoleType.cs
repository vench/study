using System;

namespace myApp {
    class ConsoleType {

        private bool isRun;


        public ConsoleType() {
            //Console.WriteLine("ConsoleType::constructor");
            isRun = false;
        }  


        public void Run() { 
            isRun = true; 
            showRunMessage();

            do {
                consoleReadKey();   
            } while(isRun); 
        }  

        public void Stop() {
            isRun = false;        
        }

        private void consoleReadKey() {
            var key = Console.ReadKey();
            Console.WriteLine("\n");
            
            switch(key.Key){
                case ConsoleKey.D1:
                commonInfoAboutTypes(); 
                break;  
                case ConsoleKey.D2:
                selectFromList(); 
                break;
                case ConsoleKey.D3:
                interTypeName(); 
                break;   
                case ConsoleKey.D4:
                showRunMessage(); 
                break; 
                case ConsoleKey.D0:
                Stop(); 
                break;   
            } 
        }

        private void interTypeName() {
            Console.WriteLine("interTypeName");
        }

        private void selectFromList() {
            Console.WriteLine("selectFromList");
        }

        private void commonInfoAboutTypes() {
            Console.WriteLine("commonInfoAboutTypes");
        }


        private void showRunMessage() {
               Console.WriteLine("Информация по типам:");
               Console.WriteLine("\t1 - Общая информация по типам");
               Console.WriteLine("\t2 - Выбрать из списка");
               Console.WriteLine("\t3 - Ввести имя типа");
               Console.WriteLine("\t4 - Параметры консоли");
               Console.WriteLine("\t0 - Выход из программы");
        }

    }    

}