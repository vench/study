package models;

public class User {

    private int id;
    private String login;
    private int countRegistrations;

    public User() {}
    public User(int id) {
        this.id = id;
    }
    public User(String login) {
        this.login = login;
    }
    public User(int id, String login) {
        this.id = id;
        this.login = login;
    }

    public int getId() {
        return id;
    }

    public String getLogin() {
        return login;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setLogin(String login) {
        this.login = login;
    }


    public int getCountRegistrations() {
        return countRegistrations;
    }

    public void setCountRegistrations(int countRegistrations) {
        this.countRegistrations = countRegistrations;
    }
}
