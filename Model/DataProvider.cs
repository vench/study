namespace myApp.Model {

    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Xml.Serialization;
    using System.Runtime.Serialization.Formatters.Binary;

    class DataProvider {

        const string FILE_DATA_XML = "data_1.xml";
        const string FILE_DATA_BIN = "data_1.bin";
 

        private Wrapper wrapper;

        private bool useXml = true;

        public DataProvider() {
            Search = "";
            wrapper = new Wrapper();
        }

        protected virtual void OnDataLoad(EventArgs e)
        {
            EventHandler handler = DataLoad;
            if (handler != null)
            {
                handler(this, e);
            }
        }

        public event EventHandler DataLoad;


        public void Save() {
            if(useXml) {
                saveXml();                
            }  else {
                saveBin();
            }            
        }


        public void Load() {
            if(useXml) {
                loadXml();
            } else {
                loadBin();
            }
            FireDataUpdate();  
        } 

        public void FireDataUpdate() {
            OnDataLoad(EventArgs.Empty);
        }
 

        public string Search { get; set; }

        public List<Country> ListCountries {
            get {
                if(Search.Trim().Length > 0) {
                    List<Country>  countries = new List<Country>();
                    foreach(var item in wrapper.ListCountries) {
                        if(item != null && item.Name.Contains(Search)) {
                            countries.Add(item);
                        }
                    }    
                    return countries;
                }
                return wrapper.ListCountries;
            } 
            set {
                wrapper.ListCountries = value;
            }
        }


        private void saveBin() {
            FileStream stream = new FileStream(FILE_DATA_BIN, FileMode.Create); 
            BinaryFormatter fmt = new BinaryFormatter();
            fmt.Serialize(stream, wrapper);
            stream.Close();
        }


        private void saveXml() {             
            var ser = new XmlSerializer(typeof( Wrapper));
            TextWriter stream = new StreamWriter(FILE_DATA_XML);
            ser.Serialize(stream, wrapper);
            stream.Close();
        }

        private void loadXml() {
            if(!File.Exists(FILE_DATA_XML)) {
                return;
            }
            var ser = new XmlSerializer(typeof( Wrapper));
            Stream stream = new FileStream(FILE_DATA_XML,FileMode.Open);
            wrapper = (Wrapper)ser.Deserialize(stream);
            stream.Close();
 
        }

        private void loadBin() {
            if(!File.Exists(FILE_DATA_BIN)) {
                return;
            }
            FileStream stream = new FileStream(FILE_DATA_BIN, FileMode.Open); 
            BinaryFormatter fmt = new BinaryFormatter();
            wrapper = (Wrapper)fmt.Deserialize(stream); 
            stream.Close();
        }
    }

}