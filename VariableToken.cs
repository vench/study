namespace myApp {

    using System.Collections.Generic;

    class VariableToken : AbToken {


        private Dictionary<string,Math.Matrix> context;

        public VariableToken(string name, Dictionary<string,Math.Matrix> context) : base(name) {
            this.context = context;
        }

        public VariableToken(string name) : base(name) {}

        public override object Eval() {
            if(context.ContainsKey(this.token)) {
                return context[this.token];
            }
            throw new System.Exception("Variable not declare");
        }

        public override object Eval( AbToken left, AbToken right) {
            throw new System.Exception("Operation not found");
        } 

    }
}