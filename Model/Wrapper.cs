namespace myApp.Model {

    using System;
    using System.Collections.Generic;

    [Serializable]
    public class Wrapper {
 
        public List<Country> ListCountries;
        public Wrapper() {
            ListCountries = new List<Country>(); 
        }
    }
}