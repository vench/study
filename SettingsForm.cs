namespace myApp {
    
    using System.Windows.Forms;
    using System;

    class SettingsForm : Form {

        private TextBox textBoxPointSize;

        private TextBox textBoxLineSize;


        private SettingsData settingsData;

        public SettingsForm(SettingsData settingsData) {
            this.settingsData = settingsData;
            initializeComponent();

            Text = "Настройки программы";
            SetBounds(0,0, 320, 280);
            MaximumSize = new System.Drawing.Size(320, 280);
            MinimumSize = new System.Drawing.Size(320, 280);
            StartPosition = FormStartPosition.CenterScreen;
        }


        private void initializeComponent() {
            //TODO

            Label l1 = new Label();
            l1.Text = "толщина линий";
            l1.SetBounds(10, 20, 120, 25);
            Controls.Add (l1);
            textBoxLineSize = new TextBox();
            textBoxLineSize.Text = settingsData.LineSize + "";
            textBoxLineSize.SetBounds(10, 50, 120, 25);
            Controls.Add (textBoxLineSize);

            Label l2 = new Label();
            l2.Text = "размер точек";
            l2.SetBounds(180, 20, 120, 25);
            Controls.Add (l2);
            textBoxPointSize = new TextBox();
            textBoxPointSize.Text = settingsData.PointSize + "";
            textBoxPointSize.SetBounds(180, 50, 120, 25);
            Controls.Add (textBoxPointSize);

            Label l3 = new Label();
            l3.Text = "цвет точек и линий";
            l3.SetBounds(10, 120, 120, 25);
            Controls.Add (l3);
 

            Label l4 = new Label();
            l4.Text = "характер движения";
            l4.SetBounds(180, 120, 120, 25);
            Controls.Add (l4);
            //случайный или с сохранением фигуры, 
 
            Button b = new Button ();
            b.Text = "Сохранить";
            b.SetBounds(10, 200, 100, 25);
            b.Click += new EventHandler (Button_Click);
            Controls.Add (b);
        }



        private void Button_Click(object sender, EventArgs e) {

            int n;
            if(int.TryParse(textBoxPointSize.Text, out n)){
                settingsData.PointSize = n;
            }
            

            Close();
        }

    }
}