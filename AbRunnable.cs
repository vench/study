namespace myApp {

    abstract class AbRunnable : Runnable {

        private bool isRun = false;

        public  void Run() {
            beforeRun();
            isRun = true;
            while(isRun) {
               run();     
            }
            afterRun();
        }

        public  void Stop() {
            isRun = false;
        }

        abstract protected void run();
        protected virtual void beforeRun() {}
        protected virtual void afterRun() {}
    }
}    