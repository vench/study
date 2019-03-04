/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author vench
 */
public class Demo implements Serializable {
    public static int last;
    private int id;
    private String name;
    private String message;
    private Date date;
    
    /**
     * Свойства класса, помеченные модификатором transient, не сериализуются.
     */
    private transient int temp;

    public Demo(int id, String name, String message, Date date, int temp) {
        this.id = id;
        this.name = name;
        this.message = message;
        this.date = date;
        this.temp = temp;
    }
    
    public Demo(String name, String message, Date date, int temp) {
        this.id = last ++;
        this.name = name;
        this.message = message;
        this.date = date;
        this.temp = temp;
    }
    
    public String getName() {
        return name;
    }
    
    
    public String toString() {
        return "Demo #id " + id;
    }
    
    
}
