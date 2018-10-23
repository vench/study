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
            updateForm();

            answersPanel.Size = new Size(300,300);
            Controls.Add(answersPanel);
        }


        private void updateForm() {
            answersPanel.Controls.Clear();

            if(hasNextQuestion()) {
                currentWord = getNext();
                var answersList = randomAnswersByWord(currentWord);
                
                Label lbwor = new Label();
                lbwor.Text = "Осталось еще " + countQuestion  + 
                    " вопросов\nПеревод для слова: " + currentWord.EnWord;
                lbwor.SetBounds(10, 10, 300, 50);
                answersPanel.Controls.Add(lbwor);
 
                comboBoxAnswer.SetBounds(10, 60, 200, 30);
                comboBoxAnswer.Items.Clear(); 
                comboBoxAnswer.Items.AddRange(answersList.ToArray());
                answersPanel.Controls.Add(comboBoxAnswer);

                Button btn = new Button();
                btn.Text = "Ответ";
                btn.SetBounds(10, 110, 200, 30);
                btn.Click += new EventHandler(newQuestButton_Click);
                answersPanel.Controls.Add(btn);

            } else {
                var result = camputeResult();
                Label label = new Label();
                label.SetBounds(10, 10, 300, 200);
                label.Text = "Тест пройден. Спасибо!"+
                "\nВаш результат: " + result + " верных ответа из " 
                + countControlQuestion + ".";
                answersPanel.Controls.Add(label);

                Console.WriteLine("Test end");    
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