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
    using System.Windows.Forms.DataVisualization.Charting;

    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {
          
        private DataGridView wDataGridView = new DataGridView();
        private BindingNavigator wBindingNavigator = new BindingNavigator(true);
        
        private BindingSource wBindingNavigatorBindingSource = new BindingSource();
 
        private Chart chart = new Chart(); 

        private PictureBox pictureBox = new PictureBox();

        private PropertyGrid propertyGrid = new PropertyGrid();

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
                     
           wBindingNavigatorBindingSource.DataSource = bindingList;  
           wDataGridView.DataSource = wBindingNavigatorBindingSource; 

           chart.DataSource = wBindingNavigatorBindingSource;
        }

        private void Form1_Load(System.Object sender, System.EventArgs e)
        { 
            SetupDataGridView();
            dataProvider.Load();
        }


	private void SetupDataGridView() { 

        Controls.Add(wBindingNavigator);
		Controls.Add(wDataGridView);
        Controls.Add(propertyGrid);
        Controls.Add(pictureBox);
        Controls.Add(chart);

        wBindingNavigator.BindingSource = wBindingNavigatorBindingSource;
        wBindingNavigator.Items.Add( new ToolStripButton("Save", null, saveDataButton_Click));
     
        wDataGridView.SelectionChanged += new EventHandler(Data_Grid_changeSelect);
        wDataGridView.ColumnHeadersDefaultCellStyle.BackColor = Color.Navy;
        wDataGridView.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
        wDataGridView.ColumnHeadersDefaultCellStyle.Font =
            new Font(wDataGridView.Font, FontStyle.Bold);
 
        wDataGridView.Location = new Point(0, wBindingNavigator.Height);
        wDataGridView.Size = new Size(500, 250);
        wDataGridView.AutoSizeRowsMode =
            DataGridViewAutoSizeRowsMode.DisplayedCellsExceptHeaders;
        wDataGridView.ColumnHeadersBorderStyle =
            DataGridViewHeaderBorderStyle.Single;
        wDataGridView.CellBorderStyle = DataGridViewCellBorderStyle.Single;
        wDataGridView.GridColor = Color.Black;
        wDataGridView.RowHeadersVisible = false; 
        wDataGridView.ReadOnly = true;  
        wDataGridView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        wDataGridView.MultiSelect = false; 

        propertyGrid.Location  = new Point(wDataGridView.Right, wDataGridView.Bottom); 
        pictureBox.Location = new Point(wDataGridView.Right, wDataGridView.Top);
     
        //Series barSeries = new Series(); 
        //barSeries.ChartType = SeriesChartType.Bar; 
       // barSeries.ChartTypeName = "xx";
       // chart.Series.Add(barSeries);

        double[] xData = new double[] {1,2,3,4,5 };
        double[] yData = new double[] {6,7,3,4,5 };

        chart.Location = new Point(0, wDataGridView.Bottom);

        pictureBox.Location = new Point(wDataGridView.Right, wDataGridView.Top);
        pictureBox.Size = new Size(propertyGrid.Width, wDataGridView.Height);
        pictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
        pictureBox.ImageLocation = "https://pbs.twimg.com/profile_images/2881220369/2b27ac38b43b17a8c5eacfc443ce3384_400x400.jpeg";
        
        //ChartArea area = new ChartArea("First");
        
       // chart.Series.Add("Series2");
      //  chart.Series["Series2"].ChartType = SeriesChartType.Column;
      //  chart.Series["Series2"].Points.AddY(20);
       // chart.Series["Series2"].ChartArea = "ChartArea1";
       // chart.ChartAreas.Add(area);
        /* 
            //Create a series using the data
            Series barSeries = new Series();
            barSeries.Points.DataBindXY(xData, yData);
            //Set the chart type, Bar; horizontal bars
            barSeries.ChartType = SeriesChartType.Bar;
            //Assign it to the required area
            barSeries.ChartArea = "First";
            //Add the series to the chart
            chart.Series.Add(barSeries);
            //Vertical bar chart
            //create another area and add it to the chart
            ChartArea area2 = new ChartArea("Second");
            chart.ChartAreas.Add(area2);
            //Create the series using just the y data
            Series barSeries2 = new Series();
            barSeries2.Points.DataBindY(yData);
            //Set the chart type, column; vertical bars
            barSeries2.ChartType = SeriesChartType.Column;
            barSeries2.ChartArea = "Second";
            //Add the series to the chart
            chart.Series.Add(barSeries2);
       // chart.Titles.Add("График");
        
       // this.chart
    */
    } 
   

	private void Data_Grid_changeSelect(object sender, EventArgs e)
    { 
        propertyGrid.SelectedObject = wBindingNavigatorBindingSource.Current;
        var country = (Country)propertyGrid.SelectedObject;
        if(country == null) {
            return;
        }
        try { 
            pictureBox.Load( country.ImageSrc);
        } catch(Exception er) {
            Console.WriteLine("Exception: " + er.Message);
        } 
    }

    private void saveDataButton_Click(object sender, EventArgs e) { 
        dataProvider.Save();
        MessageBox.Show("Данные успешно сохранены"); 
    }
 
 
 
 


  
    
    }





    

}