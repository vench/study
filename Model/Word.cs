namespace myApp.Model {


    
    using System;
    using System.Collections.Generic;

    [Serializable]
    public class Word {
        public string EnWord;
        public string[] RuWords;

        public bool IsAdjective;

        public bool IsNoun;

        public string Note;


        public Word() {}

        public Word(string word) {
            this.EnWord = word;
        }

        public Word(string word, string ruWords) : this(word) {            
            this.RuWords = ruWords.Split(',');
        }

        public Word(string word, string ruWords, string note) : this(word, ruWords) {
            this.Note = note;
        }

        public Word(string word, string ruWords, string note, bool IsAdjective, bool IsNoun)
        : this(word, ruWords, note) {
            this.IsNoun = IsNoun;
            this.IsAdjective = IsAdjective;
        }

        public static object[] AsRow(Word w) {
            if(w.RuWords == null) {
                w.RuWords = new string[0];
            }
            return new object[]{
                 w.EnWord,
                 String.Join(",", w.RuWords),
                 w.IsAdjective,
                 w.IsNoun, 
                 w.Note
            };
        }
    }
}