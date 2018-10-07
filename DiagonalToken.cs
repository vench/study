namespace myApp {
    class DiagonalToken  : AbToken {

        public DiagonalToken(string name) : base(name) {}


        public override object Eval() {
            int n;
            if(!int.TryParse(this.token, out n)) {
                n = 0;
            }
            return n;
        }

        public override object Eval( AbToken left, AbToken right) {
            throw new System.Exception("Метод недоступен");
        }    

    }
}