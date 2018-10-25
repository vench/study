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
        private BindingNavigator wBindingNavigator = new BindingNavigator(true);
        
        private BindingSource wBindingNavigatorBindingSource = new BindingSource();
 
 
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
           var bindingList = new BindingList<Country>(dataProvider.ListCountries);
           wDataGridView.DataSource = bindingList;

           
           wBindingNavigatorBindingSource.DataSource = bindingList; 
        }

        private void Form1_Load(System.Object sender, System.EventArgs e)
        {
            SetupLayout();
            SetupDataGridView();
            dataProvider.Load();
        }


	private void SetupDataGridView() {

        

        Controls.Add(wBindingNavigator);

		Controls.Add(wDataGridView);


        wBindingNavigator.BindingSource = wBindingNavigatorBindingSource;
        wBindingNavigator.Items.Add( new ToolStripButton("Save", null, saveDataButton_Click));
     
        

        wDataGridView.ColumnHeadersDefaultCellStyle.BackColor = Color.Navy;
        wDataGridView.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
        wDataGridView.ColumnHeadersDefaultCellStyle.Font =
            new Font(wDataGridView.Font, FontStyle.Bold);
 
        wDataGridView.Location = new Point(0, wBindingNavigator.Height);
        wDataGridView.Size = new Size(800, 250);
        wDataGridView.AutoSizeRowsMode =
            DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        wDataGridView.ColumnHeadersBorderStyle =
            DataGridViewHeaderBorderStyle.Single;
        wDataGridView.CellBorderStyle = DataGridViewCellBorderStyle.Single;
        wDataGridView.GridColor = Color.Black;
        wDataGridView.RowHeadersVisible = false; 
          
        wDataGridView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        wDataGridView.MultiSelect = false;
        //wDataGridView.Dock = DockStyle.Fill; 

       // wBindingNavigator.Dock = DockStyle.Top;
       // wDataGridView.Dock = DockStyle.Top;

        
	}


    
 

     

   

	private void addNewRowButton_Click(object sender, EventArgs e)
    { 
       var list = (BindingList<Country>)wDataGridView.DataSource;
       list.Add(new Country(""));          
    }

    private void saveDataButton_Click(object sender, EventArgs e) { 
        dataProvider.Save();
        MessageBox.Show("Данные успешно сохранены"); 
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

          
        buttonPanel.Height = 50;
        buttonPanel.Dock = DockStyle.Bottom;

        Controls.Add(buttonPanel);
	}
 


  
    
    }





    

}