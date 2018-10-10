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
    ///usr/lib/mono/gac/System.Windows.Forms/4.0.0.0__b77a5c561934e089/System.Windows.Forms.dll
    //msbuild /property:Configuration=myApp.csproj
    //mono *.exe

    class MyForm : Form {

        public MyForm()
        {
            Button b = new Button ();
            b.Text = "Click Me!";
            b.Click += new EventHandler (Button_Click);
            Controls.Add (b);
        }
 
        private void Button_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Привет");
        }
    }
}