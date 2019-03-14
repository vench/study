package models;

import java.text.ParseException;
import java.text.SimpleDateFormat;
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

    /**
     * 16.09.2012 10:31:46
     * @param date
     * @param time
     * @return
     */
    public static Date stringDateAndTimeToDate(String date, String time) {
        SimpleDateFormat mdyFormat = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss");
        try {
            String sdate = date.trim() + " " + time.trim();
            return mdyFormat.parse(sdate);
        } catch (ParseException e) {

        }
        return new Date();
    }
}
