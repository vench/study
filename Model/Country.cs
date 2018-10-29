namespace myApp {

    using System; 

    [Serializable]
    public class Country {

        
        private string name = "";

        private string capital = "";
        
        private int population = 0;
        
        private int size = 0;

        private string imageSrc = "";

        public Country() {}

        
        public Country(string name) {
            this.name = name;
        }

        public Country(string name, string capital) : this(name) {
            this.capital = capital;
        }

        public Country(string name, string capital, int population, int size) 
        : this(name, capital) {
            this.population = population;
            this.size = size;
        }

        [System.ComponentModel.DisplayName("Название")]
        public string Name {
            get {
                return name;
            }
            set {
                name = value;
            }
        }

        [System.ComponentModel.DisplayName("Столица")]
        [System.ComponentModel.Description("Столица страны")]
        public string Capital {
            get {
                return capital;
            }
            set {
                capital = value;
            }
        }

        [System.ComponentModel.DisplayName("Популяция")]
        [System.ComponentModel.Description("Популяция населения в стране")]
        public int Population {
            get {
                return population;
            }
            set {
                population = value;
            }
        }

        [System.ComponentModel.DisplayName("Размер")]
        [System.ComponentModel.Description("Размер страны в квадратных километрах")]
        public int Size {
            get {
                return size;
            }
            set {
                size = value;
            }
        }

        [System.ComponentModel.DisplayName("Флаг")]
        [System.ComponentModel.Description("Национальный флаг")]
        [System.ComponentModel.DefaultValue("./data/flag.png")]
        public string ImageSrc {
            get {
                return imageSrc;
            }
            set {
                imageSrc = value;
            }
        }
    }
}