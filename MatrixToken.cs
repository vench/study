namespace myApp {

    class MatrixToken : AbToken {

        public MatrixToken(string name) : base(name) {}

        public override object Eval() {
            return Math.Matrix.Parse(this.token);
        }

        public override object Eval( AbToken left, AbToken right) {
            throw new System.Exception("Метод недоступен");
        } 
    }    
}