package modules;

import javax.ejb.Stateless;

@Stateless
public class EJBDemoBean implements EJBDemo {
    public boolean login(String login, String password) {
        return false;
    }

    public String getMessage(String login) {
        return null;
    }
}
