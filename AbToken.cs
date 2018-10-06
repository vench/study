namespace myApp  {
    abstract class AbToken {

        protected string token;
        public AbToken(string token) {
            this.token = token;
        }

        public string getToken() {
            return token;
        }
        public abstract object Eval();

        public abstract object Eval(AbToken left, AbToken fight);

    }
}