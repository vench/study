package modules;

import javax.ejb.Stateful;

@Stateful
public class EJBDemoBean implements EJBDemo {

    final private static String adminLogin = "root";
    final private static String adminPassword = "password";

    private int sessionAttempts = 0;

    public boolean login(String login, String password) {
        if(login.equals(adminLogin) && password.equals(adminPassword)) {
            sessionAttempts = 3;
            return true;
        }
        return false;
    }

    public String getMessage(String login) {
        if(sessionAttempts == 0) {
            return "Session is closed";
        }
        sessionAttempts --;
        return "Session is open {" + (sessionAttempts+1) + "}";
    }
}
