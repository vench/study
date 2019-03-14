package servlet.utilites;

import java.util.StringTokenizer;

public class Util {
    public static String headWithTitle(String title) {
        return("<!DOCTYPE html>\n" +
                "<html>\n" +
                "<head><title>" + title + "</title></head>\n");
    }

    public static int countWords(String sentence) {
        if (sentence == null || sentence.length() == 0) {
            return 0;
        }
        StringTokenizer tokens = new StringTokenizer(sentence);
        return tokens.countTokens();
    }

}
