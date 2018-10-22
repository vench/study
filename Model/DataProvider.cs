namespace myApp.Model {

    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Xml.Serialization;
    using System.Runtime.Serialization.Formatters.Binary;

    class DataProvider {

        const string FILE_DATA_XML = "data.xml";
        const string FILE_DATA_BIN = "data.bin";

        private List<Word> list;


        public DataProvider() {
            list = new List<Word>();

            // TODO remove
            list.Add( new Word("Test", "Тест", "xx", true, true));
            list.Add(new Word("Best", "Лучший,замечательный"));

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
                saveXml();
                saveBin();
        }


        public void Load() {
            loadXml();
            loadBin();
            OnDataLoad(EventArgs.Empty);
        }


        public List<Word> List {
            get {
                return list;
            }
            set {
                list = value;
            }
        }


        private void saveBin() {
            FileStream stream = new FileStream("dict.bin", FileMode.Create); 
            BinaryFormatter fmt = new BinaryFormatter();
            fmt.Serialize(stream, list);
            stream.Close();
        }


        private void saveXml() {             
            var ser = new XmlSerializer(typeof( List<Word>));
            TextWriter stream = new StreamWriter(FILE_DATA_XML);
            ser.Serialize(stream, list);
            stream.Close();
        }

        private void loadXml() {
            if(!File.Exists(FILE_DATA_XML)) {
                return;
            }
            var ser = new XmlSerializer(typeof( List<Word>));
            Stream stream = new FileStream(FILE_DATA_XML,FileMode.Open);
            list = ( List<Word>)ser.Deserialize(stream);
            stream.Close();
 
        }

        private void loadBin() {
            if(!File.Exists(FILE_DATA_BIN)) {
                return;
            }
            // TODO
            
        }
    }

}