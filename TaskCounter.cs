namespace myApp {
    // TaskCounter.cs

    using System;
    using System.IO;
    using System.Threading;
    using System.Threading.Tasks;
    using System.Diagnostics; 
    using System.Collections.Concurrent;
    using System.Collections.Generic;
    class TaskCounter
    {


        const string directory = "./data/"; 
        const int run_all = 3;
        public const int run_seq = 1;
        public const int run_par = 2;


        private int typeRun;

        private CancellationTokenSource tokenSource;
        private Task task;

        private Thread thread = null;

        public event EventHandler TaskComplited;

        private Dictionary<string, int> lastResult;

        private long lastTimeSequential = 0;

        private long lastTimeParallel = 0;

        private long lastTime = 0;

        public TaskCounter() { }

        public bool Stop() {
            if(IsRun) {

                try {
                    thread.Abort();
                } catch (Exception e) {  
                    Console.WriteLine(e);
                }    
               
                thread = null;
                return true;
            }
            return false;
        }

        public bool IsRun {
            get {
                return (task != null && thread != null) ;
            }
        }

        public long LastTimeSequential{
            get {
                return lastTimeSequential;
            }
        }

        public long LastTime{
            get {
                return lastTime;
            }
        }

        public long LastTimeParallel{
            get {
                return lastTimeParallel;
            }
        }

        public bool Run() {
            return Run(run_all);
        }    

        public bool Run(int typeRun) {
            if(IsRun) {
                return false;
            }    
            tokenSource = new CancellationTokenSource(); 

            this.typeRun = typeRun;
            task = new Task(runTask, tokenSource.Token);   
            task.Start(); 
            return true;
        }

        public Dictionary<string,int> LastResult {
            get {
                return lastResult;
            }
        }

        protected virtual void OnTaskComplited(EventArgs e){
            EventHandler handler = TaskComplited;
            if (handler != null)
            {
                handler(this, e);
            }
        }


         private  void runTask() {
            thread = Thread.CurrentThread;
            Stopwatch stopwatch = new Stopwatch();

            if((typeRun & run_seq) > 0) {
                stopwatch.Start();
                readFilesSequential();
                stopwatch.Stop();
                lastTimeSequential = lastTime = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("Sequential loop time in milliseconds: {0}",
                                    lastTimeSequential);
                                
            }
          
            stopwatch.Reset();
            if((typeRun & run_par) > 0) {
                stopwatch.Start();
                readFilesParallel();
                stopwatch.Stop();
                lastTimeParallel = lastTime = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("Parallel loop time in milliseconds: {0}",
                                    lastTimeParallel);
            }

            thread = null;  
            OnTaskComplited(EventArgs.Empty);                  
        }



        private  void readFilesSequential() {
            var dict = new Dictionary<string,int>();

            if (! Directory.Exists(directory)) {
                Console.WriteLine("The directory does not exist.");
                return;
             }

            String[] files = Directory.GetFiles(directory);
            foreach(var file in files) {
                Console.WriteLine(file);
                try  {  
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
            } 
            lastResult = dict;
            Console.WriteLine("Word count {0:N0}", dict.Count);
        }

        private  void readFilesParallel() {
            
            var dict = new ConcurrentDictionary<string,int>();
      
            if (! Directory.Exists(directory)) {
                Console.WriteLine("The directory does not exist.");
                return;
            }

            String[] files = Directory.GetFiles(directory);
            Parallel.For(0, files.Length,
                index => {   
                var fileName = files[index];
                Console.WriteLine(fileName);
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

            lastResult = new Dictionary<string, int>( dict);

            Console.WriteLine("Word count {0:N0}", dict.Count);
        }
    }
}