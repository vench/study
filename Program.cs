﻿using System;


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
         
            //ConsoleType ct = new ConsoleType();
            MatrixRun ct = new MatrixRun();
            ct.Run();
           
        }

    }
}
