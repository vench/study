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

        const string directory = "./data/"; 
        
        static void Main(string[] args)
        {
              
           // Application.Run (new MyForm ());
            
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            readFilesSequential();
            stopwatch.Stop();
            Console.WriteLine("Sequential loop time in milliseconds: {0}",
                                stopwatch.ElapsedMilliseconds);

          
            stopwatch.Reset();
            stopwatch.Start();
            readFilesParallel();
            stopwatch.Stop();
            Console.WriteLine("Parallel loop time in milliseconds: {0}",
                                stopwatch.ElapsedMilliseconds);
        }



        private static void readFilesSequential() {
            var dict = new Dictionary<string,int>();

            if (! Directory.Exists(directory)) {
                Console.WriteLine("The directory does not exist.");
            return;
             }

            String[] files = Directory.GetFiles(directory);
            foreach(var file in files) {

                    //
try   {  
                    using (StreamReader sr = new StreamReader(file)) { 
                 
                    while(!sr.EndOfStream) {
                        string line = sr.ReadLine(); 
 
                        var words = line.Split(' '); 
                        foreach(var word in words) { 
                            var pword = word.Trim().ToLower();
                            if(pword.Length > 0) {
                                 if(dict.ContainsKey(pword)) {
                                     dict[pword] ++;
                                 } else {
                                     dict[pword] = 1;
                                 }
                            } 
                        }
                    } 
                    }
                } catch (Exception e) {  
                    Console.WriteLine(e);
                } 
                    //



            } 
            Console.WriteLine("Word count {0:N0}", dict.Count);
        }

        private static void readFilesParallel() {
            
            var dict = new ConcurrentDictionary<string,int>();

      
      if (! Directory.Exists(directory)) {
         Console.WriteLine("The directory does not exist.");
         return;
      }

      String[] files = Directory.GetFiles(directory);
      Parallel.For(0, files.Length,
            index => {   
                var fileName = files[index];

                try   {  
                    using (StreamReader sr = new StreamReader(fileName)) { 
                 
                    while(!sr.EndOfStream) {
                        string line = sr.ReadLine(); 
 
                        var words = line.Split(' '); 
                        foreach(var word in words) { 
                            var pword = word.Trim().ToLower();
                            if(pword.Length > 0) {
                                dict.AddOrUpdate(pword, 
                                (string k)=>{ return 1; }, 
                                (string k,  int val) => {return val + 1;});
                            } 
                        }
                    } 
                    }
                } catch (Exception e) {  
                    Console.WriteLine(e);
                }  
            }); 
            Console.WriteLine("Word count {0:N0}", dict.Count);
        }

    }
}
