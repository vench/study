namespace myApp.Model {

    using System;
    using System.Collections.Generic;

    [Serializable]
    public class Wrapper {

        public List<Word> ListWord;

        public List<Statistica> ListStat;

        public List<Country> ListCountries;

        public Wrapper() {
            ListStat = new List<Statistica>();
            ListWord = new List<Word>();
            ListCountries = new List<Country>();
        }
    }
}