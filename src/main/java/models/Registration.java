package models;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Registration {
    private int id;
    private User user;
    private String role;
    private Date date;


    public Registration(){}

    public Registration(int id, String role, Date date, User user) {
        this.date = date;
        this.id = id;
        this.role = role;
        this.user = user;
    }

    public Registration(String role, Date date, User user) {
        this.date = date;
        this.role = role;
        this.user = user;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public Date getDate() {
        return date;
    }

    public String getRole() {
        return role;
    }

    public User getUser() {
        if(user == null) {
            user = new User("empty");
        }
        return user;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public void setUser(User user) {
        this.user = user;
    }


    public String getStringDate() {
        return new SimpleDateFormat("dd.MM.yyyy").format(getDate());
    }

    public String getStringTime() {
        return new SimpleDateFormat("HH.mm.ss").format(getDate());
    }

    @Override
    public String toString() {
        return user.getLogin() + " " + getRole() + " " + getDate();
    }
}
