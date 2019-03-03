/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
 
import java.net.URL;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.*;

/**
 *
 * @author vench
 * 
 * На основе класса URL написать и отладить приложение, выводящее на консоль
текст страницы, адрес которой передается в качестве параметра вызова
приложения. Выводимый текст не должен содержать тегов, в частности не должен
включать заголовок страницы, ограниченный тегами <head...>…</head> и
<script....>...</script>.
 */
public class Task1 {
    
    private final String url;
    
    public Task1(String url) {
            this.url = url;        
    }
    
    public void parse() {
        try {
            URL u = new URL(url);
            //String initialString = "<html><head><title>Title</title></head><body><p>Test</p><script>Ball</script><p>tttt</p></body></html>";
            //InputStream targetStream = new ByteArrayInputStream(initialString.getBytes());
            BufferedReader in = new BufferedReader(new InputStreamReader(u.openStream()));
           // BufferedReader in = new BufferedReader(new InputStreamReader(targetStream));
            HtmlReader hr = new HtmlReader(in);
            System.out.println(hr.getText());
            
        } catch (IOException ex) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
