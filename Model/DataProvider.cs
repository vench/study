namespace myApp.Model {

    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Xml.Serialization;
    using System.Runtime.Serialization.Formatters.Binary;

    class DataProvider {

        const string FILE_DATA_XML = "data1.xml";
        const string FILE_DATA_BIN = "data1.bin";
 

        private Wrapper wrapper;

        private bool useXml = true;

        public DataProvider() {
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
            OnDataLoad(EventArgs.Empty);
        }


        public List<Word> List {
            get {
                return wrapper.ListWord;
            }
            set {
                wrapper.ListWord = value;
            }
        }

        public List<Statistica> ListStat {
            get {
                return wrapper.ListStat;
            }
            set {
                wrapper.ListStat = value;
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