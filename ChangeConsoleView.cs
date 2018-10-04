namespace myApp {
    
    
    using System;
    
    class ChangeConsoleView : AbRunnable
    {
        protected override void run()
        {
            
            Console.Clear();
            Console.WriteLine(@"
                Настройка  консоли:
                1 - цвет фона красный
                2 - цвет фона синий
                3 - цвет фона белый

                4 - цвет текста красный
                5 - цвет текста синий
                6 - цвет текста белый                

                0 - выход в меню
            ");


            var key = Console.ReadKey(); 
            
            switch(key.Key){
                case ConsoleKey.D1: 
                    Console.BackgroundColor = ConsoleColor.Red;   
                    break;  
                case ConsoleKey.D2:   
                    Console.BackgroundColor = ConsoleColor.Blue; 
                break;
                case ConsoleKey.D3:   
                    Console.BackgroundColor = ConsoleColor.White; 
                break; 
                case ConsoleKey.D4: 
                    Console.ForegroundColor = ConsoleColor.Red;   
                    break;  
                case ConsoleKey.D5:   
                    Console.ForegroundColor = ConsoleColor.Blue; 
                break;
                case ConsoleKey.D6:   
                    Console.ForegroundColor = ConsoleColor.White; 
                break;  
                
                case ConsoleKey.D0:  
                    Stop();   
                    break;   
            } 
        }
    }
}