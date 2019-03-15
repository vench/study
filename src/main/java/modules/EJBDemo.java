package modules;

import javax.ejb.Local;

@Local
public interface EJBDemo {
    boolean login(String login, String password);
    String getMessage(String login);
}
