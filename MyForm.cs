namespace myApp {

    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Data;
    using System.Drawing;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows.Forms;  
   // using System.Windows.Forms.DataVisualization.Charting;

    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {
          
        private Button buttonStartSeq = new Button(); 

         private Button buttonStartPar = new Button(); 
        private Button buttonCancell = new Button(); 

        private Label labelResult = new Label(); 
 
        private Chart chart = new Chart(2000,800); 

        private TaskCounter taskCounter;


        public MyForm()
        { 
            // TODO show stat
            
			Load += new EventHandler(Form1_Load); 

            Text = "Информация по текстам";
            SetBounds(0,0, 800, 600);
            MaximumSize = new System.Drawing.Size(800,600);
            MinimumSize = new System.Drawing.Size(800, 600);
            StartPosition = FormStartPosition.CenterScreen;  

            Resize += new EventHandler(Form_Resize); 
        }


        private void Form_Resize(Object sender, EventArgs e) {
            UpdateSize();
        }
         
 
 

        private void Form1_Load(Object sender, EventArgs e)
        { 
            SetupView(); 
        }


	    private void SetupView() { 
            Controls.Add(buttonStartPar);
            Controls.Add(buttonStartSeq);
            Controls.Add(buttonCancell);
            Controls.Add(chart);
            Controls.Add(labelResult);

            buttonStartSeq.Text = "Последовательно";
            buttonStartPar.Text = "Параллельно";
            buttonCancell.Text = "Отмена";

            buttonStartPar.SetBounds(10, 10, 100, 25);
            buttonStartSeq.SetBounds(10, 45, 100, 25);
            buttonCancell.SetBounds(10, 90, 100, 25);
            chart.SetBounds(220, 10, 400, 300);
            labelResult.SetBounds(10, 120, 160, 200);

            buttonStartSeq.Click += new EventHandler(buttonStartClick);
            buttonStartPar.Click += new EventHandler(buttonStartClick);
            buttonCancell.Click += new EventHandler(buttonCancellClick);

            labelResult.AutoSize = false; 
            labelResult.TextAlign = ContentAlignment.TopLeft;
            labelResult.Font = new Font("Serif",  12);

            chart.LegendY = "кол-во";
            chart.LegendX = "Слова";
            chart.Type = Chart.ChartType.Bars; 
        
            chart.Show(); 
        }
    
        private void UpdateSize() {
            // TODO
        }


        private void OnTaskComplited(Object sender, EventArgs e) {
            Console.WriteLine("");
            Console.WriteLine("OnTaskComplited...");
            
            
            labelResult.Text = String.Format(@"Кол-во слов: 

{0:N0}


Время:

{1:N0} ", 
                taskCounter.LastResult.Count, 
                taskCounter.LastTime);/* */


            //chart
            Controls.Remove(chart);
            Controls.Add(chart);
            
            chart.SetBounds(150, 10, 600, 400);

            List<KeyValuePair<string, int>> list = taskCounter.LastResult.ToList();
            list.Sort( delegate(KeyValuePair<string, int> a,
                    KeyValuePair<string, int> b){
                        return b.Value.CompareTo(a.Value);
                    }
            );


            List<int> listVal = new List<int>();
            List<string> listKey = new List<string>();
            
            foreach(var item in  list.Take(12)){
                listVal.Add(item.Value);
                listKey.Add(item.Key); 
            }

            chart.Values = listVal.ToArray();
            chart.Labels = listKey.ToArray();
            
            chart.Refresh();
            chart.Draw();
            chart.Show(); 
            Refresh();
        }

        private void buttonCancellClick(Object sender, EventArgs e) {
            Console.WriteLine("buttonCancellClick");
           ;
            if(taskCounter != null && !taskCounter.Stop()) {
                MessageBox.Show("Error stop");
            }
        }

        private void buttonStartClick(Object sender, EventArgs e) {
            Console.WriteLine("buttonStartClick");
            if(taskCounter == null) {
                taskCounter= new TaskCounter();
                taskCounter.TaskComplited += new EventHandler(OnTaskComplited);
            }
            
            var type = sender.Equals(buttonStartPar) ? 
                    TaskCounter.run_par : TaskCounter.run_seq;  

            if(!taskCounter.Run(type)) {
                MessageBox.Show("Error run");    
            }
        }
    
    }

}