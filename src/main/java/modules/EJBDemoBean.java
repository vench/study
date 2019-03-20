package modules;

import javax.ejb.Stateful;
import java.util.HashMap;
import java.util.Map;

@Stateful
public class EJBDemoBean implements EJBDemo {

    final private static String adminLogin = "root";
    final private static String adminPassword = "password";

    private Map<String,Integer> sessionAttempts = new HashMap<String, Integer>();

    public boolean login(String login, String password) {
        if(login.equals(adminLogin) && password.equals(adminPassword)) {
            sessionAttempts.put(adminLogin, 3);
            return true;
        }
        sessionAttempts.put(adminLogin, 0);
        return false;
    }

    public String getMessage(String login) {
        int value;
        if(!sessionAttempts.containsKey(login) || (value = sessionAttempts.get(login)) == 0) {
            return "Session is closed";
        }
        value --;
        sessionAttempts.put(login, value);
        return "Session is open {" + (value+1) + "}";
    }
}
