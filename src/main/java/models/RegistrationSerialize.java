package models;

import java.util.Date;
import java.util.StringTokenizer;


public class RegistrationSerialize {

    public static Registration stringToRegistration(String s) {
        StringTokenizer tokens = new StringTokenizer(s);
        if(tokens.countTokens() != 4) {
            return null;
        }

        User u = new User();
        u.setLogin(tokens.nextToken());
        Registration r = new Registration();
        r.setUser(u);
        r.setRole(tokens.nextToken());
        r.setDate(
                stringDateAndTimeToDate(tokens.nextToken(), tokens.nextToken())
        );
        return r;
    }

    public static String registrationToString(Registration r) {
        return r.getUser().getLogin() + " " + r.getRole() + " " + dateToDateString(r.getDate()) + " " + dateToTimeString(r.getDate());
    }

    public static String dateToDateString( Date date) {
        return "";
    }

    public static String dateToTimeString( Date date) {

        return "";
    }

    public static Date stringDateAndTimeToDate(String date, String time) {
        return new Date();
    }
}
