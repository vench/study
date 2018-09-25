using System;


/**
>> Запускаем
> dotnet build --runtime ubuntu.16.04-x64
> dotnet run
 */
namespace myApp
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        
            //Console.WriteLine("Press any key to exit.");
           
           // char s = Console.ReadKey().KeyChar;
            ConsoleType ct = new ConsoleType();
            ct.Run();
        
        }

    }
}
