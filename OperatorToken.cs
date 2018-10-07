namespace myApp {

    using System.Collections.Generic;
    class OperatorToken : AbToken {

        private Dictionary<string,Math.Matrix> context;

        public OperatorToken(string name) : base(name) {}

        public OperatorToken(string name, Dictionary<string,Math.Matrix> context) : base(name) {
            this.context = context;
        }

    

        public override object Eval() {
            throw new System.Exception("Метод недоступен");
        }

        public override object Eval( AbToken left, AbToken right) {
            
            if (this.token == ".") { 
                return EvalMethod( left.Eval(), right.getToken());
            }
            
            var b = right.Eval();             
            
            if(this.token == "=" && b is Math.Matrix) {
                context[left.getToken()] = (Math.Matrix)b;
                return b;
            } 
            
            var a = left.Eval();
            
            if(a is Math.Matrix && b is Math.Matrix) {
                return EvalVal((Math.Matrix)a, (Math.Matrix)b);
            }
            if(a is int && b is Math.Matrix ) {
                return EvalVal((Math.Matrix)b, (int)a);
            }
            if(b is int && a is Math.Matrix ) {
                return EvalVal((Math.Matrix)a, (int)b);
            }
            if(b is int && a is int ) {
                return EvalVal((int)a, (int)b);
            }            

            throw new System.Exception("Операция недопустима для данных объектов");
        }

        private object EvalMethod(object a, string method) {
            if( a is Math.Matrix) {
                switch(method) {
                    case "T":
                        return ((Math.Matrix)a).Transpose();
                }
                    
            }
            return a;
        }

        private object EvalVal(int a, int b) {
            switch(this.token) {
                 case "+":
                    return a + b;   
                 case "-":
                    return a - b;
                 case "*":
                    return a * b;
            }
            throw new System.Exception("Операция недопустима для данных объектов");
        } 

        private object EvalVal(Math.Matrix a, int b) {
            switch(this.token) {   
                 case "*":
                    return a * b;
            }
            throw new System.Exception("Операция недопустима для данных объектов");
        }    

        private object EvalVal(Math.Matrix a, Math.Matrix b) {
            switch(this.token) {
                 case "+":
                    return a + b;   
                 case "-":
                    return a - b;
                 case "*":
                    return a * b;
            }
            throw new System.Exception("Операция недопустима для данных объектов");
        }

    }

}