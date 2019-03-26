package modules;

import javax.ejb.Local;

@Local
public interface EJBHistory {
    String[] getHistory(String login, String name);
    String[] getHistory(String login, int code);
    boolean login(String login, String password);
    boolean logout(String login);
}
