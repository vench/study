namespace myApp {

    using System;

    class InputTypeName : AbInfoType {
        protected override void beforeRun() {
             Console.Clear();
             Console.WriteLine("Введите имя типа:");    
        }

        protected override void run() {
            var line = Console.ReadLine(); 
            
            Type t = Type.GetType(line);
            if(t is Type) {
                showAboutType(t);
            } else {
                Console.WriteLine(@"
                Тип не найден, для продолжения нажмите любую клавишу...
                "); 
                Console.ReadKey();
            }
 
            Stop();
        }    
    }
}