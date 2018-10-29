namespace myApp {

    using System.Windows.Forms; 
    using myApp.Model;
    using System;
    class SearchForm : Form{

        private DataProvider dataProvider;

        private TextBox textBox;
        public SearchForm(DataProvider dataProvider) {
            Text = "Форма поиска";

            this.dataProvider = dataProvider;

            SetBounds(0,0, 320, 140);
            MaximumSize = new System.Drawing.Size(320, 140);
            MinimumSize = new System.Drawing.Size(320, 140);
            StartPosition = FormStartPosition.CenterScreen; 

            //

            Label label1 = new Label();
            label1.SetBounds(20, 20, 220, 25);
            label1.Text = "Введите фразу дял поиска";
            Controls.Add(label1);

            textBox = new TextBox();
            textBox.Text = dataProvider.Search;
            textBox.SetBounds(20, 50, 220, 25);
            Controls.Add(textBox);

            Button button = new Button(); 
            button.Text = "Поиск";
            button.Click += new EventHandler(Button_Click);
            button.SetBounds(20, 80, 120, 25);
            Controls.Add(button);

        }


        private void Button_Click(object sender, EventArgs e) {
            //dataProvider.ListCountries.Add(new Country());
            dataProvider.Search = textBox.Text;

            dataProvider.FireDataUpdate();
            Close();
        }
    }
}