namespace myApp {

    using System.Windows.Forms;
    using System.Collections.Generic;
    using myApp.Model;
    using System;
    using System.Drawing;
    class FormStat : Form {
        
        private DataProvider dataProvider;

        public FormStat(DataProvider dataProvider) {
            this.dataProvider = dataProvider;

            Text = "Статистика";
            SetBounds(0,0, 400, 300);
            MaximumSize = new System.Drawing.Size(400, 300);
            MinimumSize = new System.Drawing.Size(400, 300);
            StartPosition = FormStartPosition.CenterScreen;


            // data
            int sumNoun = 0, sumAdjective = 0, sumWordCount = 0;
            foreach(var word in dataProvider.List) {
                if( word.IsNoun) {
                    sumNoun ++;
                }
                if(word.IsAdjective) {
                    sumAdjective ++;
                }
                sumWordCount += word.EnWord.Length;                
            }

            int sumTest =0, minTest=-1, maxTest=-1;
            foreach(var stat in dataProvider.ListStat) {
                if(minTest == -1 || minTest > stat.CountCorrectQuestion) {
                    minTest = stat.CountCorrectQuestion;
                }
                if(maxTest == -1 || maxTest < stat.CountCorrectQuestion) {
                    maxTest = stat.CountCorrectQuestion;
                }
                sumTest += stat.CountCorrectQuestion;
            }

            Label label = new Label();
            label.SetBounds(10, 10, 390, 290);
            label.Font = new Font("Arial", 12);
            label.Text = "Всего слов: " + dataProvider.List.Count + 
                 "\n\nВсего существительных: " + sumNoun + 
                 "\n\nВсего прилагательных: " + sumAdjective +
                 "\n\nСредняя длинна слов: " + (int)(sumWordCount / dataProvider.List.Count) + 
                 
                 "\n\n\n\nПройдено тестов: " + dataProvider.ListStat.Count + 
                 "\n\nСредняя оценка: " + (int)(sumTest / dataProvider.ListStat.Count) + 
                 "\n\nЛучшая оценка: " + maxTest + 
                 "\n\nХудшая оценка: " + minTest 
                 
                 ;
            Controls.Add(label);
        }


         



    }
}