using System;
using System.Drawing;
using System.Windows.Forms;

 
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics; 
using System.Collections.Concurrent;
using System.Collections.Generic;

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
            Application.Run (new MyForm ());  
        } 
    }
}
