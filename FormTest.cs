namespace myApp {

    using System.Windows.Forms;
    using System.Collections.Generic;
    using myApp.Model;
    using System;
    using System.Drawing;
    class FormTest : Form  {
 
        const int COUNT_QUESTION = 5;
        const int COUNT_ANSWERS_VARIANT = 3;


        private Dictionary<string, string> answers;
        private DataProvider dataProvider;
        private int countQuestion;

        private int countControlQuestion;
        private Panel answersPanel = new Panel();
        
        private ComboBox comboBoxAnswer = new ComboBox();
        private Label nextAnswer = new Label();
        private Button btnNextQuest = new Button();
        private Word currentWord;

        public FormTest(DataProvider dataProvider) {
            this.dataProvider = dataProvider;

            Text = "Тест";
            SetBounds(0,0, 400, 300);
            MaximumSize = new System.Drawing.Size(400, 300);
            MinimumSize = new System.Drawing.Size(400, 300);
            StartPosition = FormStartPosition.CenterScreen;

            //init test

            answers = new Dictionary<string, string>();
            countQuestion = countControlQuestion 
                = Math.Min(COUNT_QUESTION, dataProvider.List.Count);   
            dataProvider.List.Shuffle();  
            
            initComponents();
            updateForm();
        }

        private void initComponents() {
            answersPanel.Size = new Size(300,300);
            Controls.Add(answersPanel);
        
            btnNextQuest.Text = "Ответ";
            btnNextQuest.SetBounds(10, 160, 200, 30);
            btnNextQuest.Click += new EventHandler(newQuestButton_Click);
        
            comboBoxAnswer.SetBounds(10, 80, 200, 30);

            nextAnswer.SetBounds(10, 10, 500, 90); 
            nextAnswer.Font = new Font("Arial", 12,FontStyle.Bold);
        }



        private void updateForm() {
            answersPanel.Controls.Clear();

            if(hasNextQuestion()) {
                currentWord = getNext();
                var answersList = randomAnswersByWord(currentWord);
                             
                nextAnswer.Text = "Осталось еще " + countQuestion  + 
                    " вопросов\n\nПеревод для слова: " + currentWord.EnWord;
     
                comboBoxAnswer.SelectedIndex = -1;
                comboBoxAnswer.Items.Clear();  
                comboBoxAnswer.Items.AddRange(answersList.ToArray());
                
                answersPanel.Controls.Add(comboBoxAnswer);
                answersPanel.Controls.Add(nextAnswer);
                answersPanel.Controls.Add(btnNextQuest);

            } else {
                var result = camputeResult(); 
                nextAnswer.Text = "Тест пройден. Спасибо!"+
                "\n\nВаш результат:\n\n" + result + " верных ответа из " 
                + countControlQuestion + ".";
                answersPanel.Controls.Add(nextAnswer);

                Button btn = new Button();
                btn.Text = "Продолжить";
                btn.SetBounds(10, 110, 200, 30);
                btn.Click += new EventHandler(exitButton_Click);
                answersPanel.Controls.Add(btn);  

                dataProvider.ListStat.Add(new Statistica(countControlQuestion, result)); 
            }
        }

        private int camputeResult() {
            int result = 0;
            for(int i = 0; i < countControlQuestion; i ++) {
                var word  = dataProvider.List[i];
                var ans = answers[word.EnWord]; 
                if(word.RuWords.Isset(ans)) {
                    result ++; 
                }
            }
            return result;
        }


        private void exitButton_Click(object sender, EventArgs e) {
            Close();
        }
        private void newQuestButton_Click(object sender, EventArgs e) {
            var answ = comboBoxAnswer.SelectedItem != null ?
                 comboBoxAnswer.SelectedItem.ToString() + "" : "";
            answers[currentWord.EnWord] = answ;
            updateForm();
        }

        private List<string> randomAnswersByWord(Word word) {
            List<string> list = new List<string>();
            list.Add(word.RuWords[0]);
            var i = 0;
            while(list.Count < COUNT_ANSWERS_VARIANT) { 
                var ruWord = dataProvider.List[i].RuWords[0];
                i ++;
                if(word.RuWords[0] == ruWord) { 
                    continue;
                }
                list.Add(ruWord);                
            } 
            list.Shuffle();
            return list;
        }


        private bool hasNextQuestion() {
            return countQuestion > 0;
        }

        private Word getNext() {
            countQuestion --;
            Console.WriteLine(countQuestion);
            return dataProvider.List[countQuestion];
        }


    }

    static class Extensions {

        private static Random rng = new Random();  

        public static bool Isset<T>(this IList<T> list, T val) {
               
            foreach(T item in list) { 
                
                if(val .Equals(item)) {
                    return true;
                }
            }    
            return false;
        }

        public static void Shuffle<T>(this IList<T> list)  
        {  
            int n = list.Count;  
            while (n > 1) {  
                n--;  
                int k = rng.Next(n + 1);  
                T value = list[k];  
                list[k] = list[n];  
                list[n] = value;  
            }  
        }
    }
}