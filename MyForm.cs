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
    private DataGridView songsDataGridView = new DataGridView();
    private Button addNewRowButton = new Button();
    private Button deleteRowButton = new Button();
 
	private Button startTestButton = new Button();



        public MyForm()
        { 
			this.Load += new EventHandler(Form1_Load);

            Text = "Мой словарь";
            SetBounds(0,0, 800, 600);
            MaximumSize = new System.Drawing.Size(SystemInformation.VirtualScreen.Width,SystemInformation.VirtualScreen.Height);
            MinimumSize = new System.Drawing.Size(800, 600);
            StartPosition = FormStartPosition.CenterScreen;  
			
			          
        }


    private void Form1_Load(System.Object sender, System.EventArgs e)
    {
        SetupLayout();
        SetupDataGridView();
        PopulateDataGridView();
    }


	private void SetupDataGridView() {
		this.Controls.Add(songsDataGridView);

        songsDataGridView.ColumnCount = 4;

        songsDataGridView.ColumnHeadersDefaultCellStyle.BackColor = Color.Navy;
        songsDataGridView.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
        songsDataGridView.ColumnHeadersDefaultCellStyle.Font =
            new Font(songsDataGridView.Font, FontStyle.Bold);

        songsDataGridView.Name = "songsDataGridView";
        songsDataGridView.Location = new Point(8, 8);
        songsDataGridView.Size = new Size(800, 250);
        songsDataGridView.AutoSizeRowsMode =
            DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        songsDataGridView.ColumnHeadersBorderStyle =
            DataGridViewHeaderBorderStyle.Single;
        songsDataGridView.CellBorderStyle = DataGridViewCellBorderStyle.Single;
        songsDataGridView.GridColor = Color.Black;
        songsDataGridView.RowHeadersVisible = false;
       // songsDataGridView.AutoSize = true;
        //songsDataGridView.

        songsDataGridView.Columns[0].Name = "Слово";
        songsDataGridView.Columns[1].Name = "Переводы";
        songsDataGridView.Columns[2].Name = "Прилогательное";
        songsDataGridView.Columns[3].Name = "Существительное"; 
        songsDataGridView.Columns[2].ValueType =  typeof(bool);
        songsDataGridView.Columns[3].ValueType =  typeof(bool);
       // songsDataGridView.Columns[4].DefaultCellStyle.Font =
       //     new Font(songsDataGridView.DefaultCellStyle.Font, FontStyle.Italic);

        songsDataGridView.SelectionMode =
            DataGridViewSelectionMode.FullRowSelect;
        songsDataGridView.MultiSelect = false;
        songsDataGridView.Dock = DockStyle.Fill;
 
        songsDataGridView.CellFormatting += new
            DataGridViewCellFormattingEventHandler(
            songsDataGridView_CellFormatting); 
	}


    private void songsDataGridView_CellFormatting(object sender,
        System.Windows.Forms.DataGridViewCellFormattingEventArgs e)
    {
        if (e != null)
        {
            if (this.songsDataGridView.Columns[e.ColumnIndex].Name == "Release Date")
            {
                if (e.Value != null)
                {
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

	private void PopulateDataGridView()
    {
 

        Dictionary<string, Word> dic = new Dictionary<string, Word>();
        dic.Add("test", new Word("Test"));
        dic.Add("best", new Word("Best"));


        songsDataGridView.Rows.Add(dic["test"].AsRow());
        songsDataGridView.Rows.Add(dic["best"].AsRow());
  

    }


	private void startTestButton_Click(object sender, EventArgs e) {
		MessageBox.Show("Start test");
	}

	private void addNewRowButton_Click(object sender, EventArgs e)
    {
        this.songsDataGridView.Rows.Add();
    }


	private void deleteRowButton_Click(object sender, EventArgs e)
    {
        if (this.songsDataGridView.SelectedRows.Count > 0 &&
            this.songsDataGridView.SelectedRows[0].Index !=
            this.songsDataGridView.Rows.Count - 1)
        {
            this.songsDataGridView.Rows.RemoveAt(
                this.songsDataGridView.SelectedRows[0].Index);
        }
    }

	private void SetupLayout() {
		this.Size = new Size(600, 500);

        addNewRowButton.Text = "Add Row";
        addNewRowButton.Location = new Point(10, 10);
        addNewRowButton.Click += new EventHandler(addNewRowButton_Click);

        deleteRowButton.Text = "Delete Row";
        deleteRowButton.Location = new Point(100, 10);
        deleteRowButton.Click += new EventHandler(deleteRowButton_Click);

		
		startTestButton.Text = "Start test";
        startTestButton.Location = new Point(190, 10);
        startTestButton.Click += new EventHandler(startTestButton_Click);

		buttonPanel.Controls.Add(startTestButton);
        buttonPanel.Controls.Add(addNewRowButton);
        buttonPanel.Controls.Add(deleteRowButton);
        buttonPanel.Height = 50;
        buttonPanel.Dock = DockStyle.Bottom;

        this.Controls.Add(this.buttonPanel);
	}
 


  
    
    }





    

}