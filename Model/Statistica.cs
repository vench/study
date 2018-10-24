namespace myApp {

    using System;

    [Serializable]
    public class Statistica {

        public int CountQuestion;

        public int CountCorrectQuestion;

        public Statistica(){}

        public Statistica(int CountQuestion, int CountCorrectQuestion){
            this.CountQuestion = CountQuestion;
            this.CountCorrectQuestion = CountCorrectQuestion;
        }


    }
}