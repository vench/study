using System;
using System.Drawing;
using System.Windows.Forms;


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
