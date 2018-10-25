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
    using myApp.Model; 


    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {
         
        private Panel buttonPanel = new Panel();
        private DataGridView wDataGridView = new DataGridView();
        private Button addNewRowButton = new Button();
        private Button deleteRowButton = new Button();
        private Button saveDataButton = new Button();
 	    private Button startTestButton = new Button();
        private Button statButton = new Button();

        private FormTest formTest;
        private FormStat formStat;
        private DataProvider dataProvider;

        public MyForm()
        { 
			this.Load += new EventHandler(Form1_Load);

            Text = "Мой словарь";
            SetBounds(0,0, 800, 600);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(800, 600);
            StartPosition = FormStartPosition.CenterScreen;  
			
            dataProvider = new DataProvider();
            dataProvider.DataLoad += new EventHandler(Form1_DataLoad);              
        }

        private void Form1_DataLoad(System.Object sender, System.EventArgs e) {
            System.Console.WriteLine("Load: " + dataProvider.List.Count); 
 
           
           dataProvider.ListCountries.Add(new Country("Россия", "Москва", 146, 17125187));  
           dataProvider.ListCountries.Add(new Country("Франция")); 
           dataProvider.ListCountries.Add(new Country("Германия")); 

           var bindingList = new BindingList<Country>(dataProvider.ListCountries);
           wDataGridView.DataSource = bindingList;
        }

        private void Form1_Load(System.Object sender, System.EventArgs e)
        {
            SetupLayout();
            SetupDataGridView();
            dataProvider.Load();
        }


	private void SetupDataGridView() {
		this.Controls.Add(wDataGridView);
 

        wDataGridView.ColumnHeadersDefaultCellStyle.BackColor = Color.Navy;
        wDataGridView.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
        wDataGridView.ColumnHeadersDefaultCellStyle.Font =
            new Font(wDataGridView.Font, FontStyle.Bold);
 
        wDataGridView.Location = new Point(0, 0);
        wDataGridView.Size = new Size(800, 250);
        wDataGridView.AutoSizeRowsMode =
            DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        wDataGridView.ColumnHeadersBorderStyle =
            DataGridViewHeaderBorderStyle.Single;
        wDataGridView.CellBorderStyle = DataGridViewCellBorderStyle.Single;
        wDataGridView.GridColor = Color.Black;
        wDataGridView.RowHeadersVisible = false; 
          
        wDataGridView.SelectionMode =
            DataGridViewSelectionMode.FullRowSelect;
        wDataGridView.MultiSelect = false;
        wDataGridView.Dock = DockStyle.Fill;
 
        wDataGridView.CellFormatting += new
            DataGridViewCellFormattingEventHandler(
            songsDataGridView_CellFormatting); 
	}


    private void songsDataGridView_CellFormatting(object sender,
        System.Windows.Forms.DataGridViewCellFormattingEventArgs e)
    {
        if (e != null)  {
            if (wDataGridView.Columns[e.ColumnIndex].Name == "Release Date")
            {
                if (e.Value != null) {
                    try
                    {
                        e.Value = DateTime.Parse(e.Value.ToString())
                            .ToLongDateString();
                        e.FormattingApplied = true;
                    }
                    catch (FormatException)
                    {
                        Console.WriteLine("{0} is not a valid date.", e.Value.ToString());
                    }
                }
            }
        }
    }


    private void statButton_Click(object sender, EventArgs e) { 
        if (formStat == null || formStat.Disposing) {
            formStat = new FormStat(dataProvider);
            formStat.FormClosed += new FormClosedEventHandler(stat_FromClose);
        }
        formStat.Show();
    }

    private void test_FromClose(Object sender, FormClosedEventArgs e) {
        formTest = null;
    }

    private void stat_FromClose(Object sender, FormClosedEventArgs e) {
        formStat = null;
    }
    private void startTestButton_Click(object sender, EventArgs e) {	   
        if (formTest == null || formTest.Disposing) {
            formTest = new FormTest(dataProvider);
            formTest.FormClosed += new FormClosedEventHandler(test_FromClose);
        }  
        formTest.Show();
	}

	private void addNewRowButton_Click(object sender, EventArgs e)
    { 
       var list = (BindingList<Country>)wDataGridView.DataSource;
       list.Add(new Country(""));          
    }

    private void saveDataButton_Click(object sender, EventArgs e) {
       /* List<Word> list = new List<Word>();
        foreach (var row in wDataGridView.Rows.OfType<DataGridViewRow>())  {
            
            string word = row.Cells[0].FormattedValue.ToString().Trim();
            if(word.Length == 0) {
                continue;
            }
            bool IsAdjective, IsNoun;
            Boolean.TryParse(row.Cells[2].FormattedValue.ToString(), out IsAdjective);
            Boolean.TryParse(row.Cells[3].FormattedValue.ToString(), out IsNoun);

            list.Add( new Word(
                   word,
                   row.Cells[1].FormattedValue.ToString(),
                   row.Cells[4].FormattedValue.ToString(),
                   IsAdjective,
                   IsNoun
                   ) 
           );           
        }   
 
        dataProvider.Save();
        MessageBox.Show("Данные успешно сохранены"); */

        Console.WriteLine(dataProvider.ListCountries.Count);
                
    }

	private void deleteRowButton_Click(object sender, EventArgs e)
    {
        if (wDataGridView.SelectedRows.Count > 0 &&
            wDataGridView.SelectedRows[0].Index !=
            wDataGridView.Rows.Count - 1)
        {
            wDataGridView.Rows.RemoveAt(
                wDataGridView.SelectedRows[0].Index);
        }
    }

	private void SetupLayout() {
		this.Size = new Size(600, 500);

        addNewRowButton.Text = "Добавить строку";
        addNewRowButton.Location = new Point(10, 10);
        addNewRowButton.Click += new EventHandler(addNewRowButton_Click);

        deleteRowButton.Text = "Удалить строку";
        deleteRowButton.Location = new Point(100, 10);
        deleteRowButton.Click += new EventHandler(deleteRowButton_Click);

        saveDataButton.Text = "Сохранить словарь";
        saveDataButton.Location = new Point(190, 10);
        saveDataButton.Click += new EventHandler(saveDataButton_Click);
		
		startTestButton.Text = "Начать тест";
        startTestButton.Location = new Point(410, 10);
        startTestButton.Size = new Size(160, 22);
        startTestButton.Click += new EventHandler(startTestButton_Click);

        statButton.Text = "Статистика";
        statButton.Location = new Point(600, 10);
        statButton.Size = new Size(160, 22);
        statButton.Click += new EventHandler(statButton_Click);

        buttonPanel.Controls.Add(statButton);
		buttonPanel.Controls.Add(saveDataButton);
        buttonPanel.Controls.Add(startTestButton);
        buttonPanel.Controls.Add(addNewRowButton);
        buttonPanel.Controls.Add(deleteRowButton);
        buttonPanel.Height = 50;
        buttonPanel.Dock = DockStyle.Bottom;

        Controls.Add(buttonPanel);
	}
 


  
    
    }





    

}