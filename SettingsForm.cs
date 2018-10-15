namespace myApp {
    
    using System.Windows.Forms;
    using System;

    class SettingsForm : Form {

        private TextBox textBoxPointSize;

        private TextBox textBoxLineSize;


        private SettingsData settingsData;

        private ColorDialog colorDialog;

        private Button buttonPointColor;

        private Button buttonLineColor;

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
            colorDialog = new ColorDialog(); 

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
            buttonPointColor = new Button ();
            buttonPointColor.Text = "точки";
            buttonPointColor.SetBounds(10, 140, 100, 25);
            buttonPointColor.Click += new EventHandler (Button_Click1);
            buttonPointColor.ForeColor = settingsData.PointColor; 
            Controls.Add (buttonPointColor);

            buttonLineColor = new Button ();
            buttonLineColor.Text = "точки";
            buttonLineColor.SetBounds(10, 160, 100, 25);
            buttonLineColor.Click += new EventHandler (Button_Click2);
            buttonLineColor.ForeColor = settingsData.LineColor; 
            Controls.Add (buttonLineColor);
          
 

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
            if(int.TryParse(textBoxLineSize.Text, out n)){
                settingsData.LineSize = n;
            }
            settingsData.PointColor = buttonPointColor.ForeColor;
            settingsData.LineColor = buttonLineColor.ForeColor;

            Close();
        }



        private void Button_Click2(object sender, EventArgs e) {
            colorDialog.Color = settingsData.LineColor; 
            if(colorDialog.ShowDialog() == DialogResult.OK) {
                buttonLineColor.ForeColor = colorDialog.Color;
            }
        }

        private void Button_Click1(object sender, EventArgs e) {
            colorDialog.Color = settingsData.PointColor; 
            if(colorDialog.ShowDialog() == DialogResult.OK) {
                buttonPointColor.ForeColor = colorDialog.Color;
            }
        }

    }
}