namespace myApp.Model {


    
    using System;
    using System.Collections.Generic;
    class Word {
        public string EnWord;
        public List<string> RuWords = new List<string>();

        public bool IsAdjective;

        public bool IsNoun;

        public Word(string word) {
            this.EnWord = word;
        }

        public object[] AsRow() {
            return new object[]{EnWord,String.Join(",", RuWords),IsAdjective,IsNoun};
        }
    }
}