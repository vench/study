/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author vench
 */
public class Writer extends Thread {
    
    private final DataBase dataBase;
    
    private final String name;
    
    public Writer(String name, DataBase dataBase) {
        this.name = name;
        this.dataBase = dataBase;
    }
    
    @Override
    public void run() {
        try {
            while(true) { 
                sleep(randomInt(500, 1000)); 
                System.out.println("writer " + name + " whant write");
                dataBase.startWrite(name);
                sleep(randomInt(500, 1000));
                dataBase.endWrite(name);
                        
            }
        } catch (InterruptedException ex) {
            System.out.println("Error Reader: " + name);
            System.out.println(ex.getMessage());
        }
    }
    
    private int randomInt(int min, int max) {
        return (int)(Math.random() * (max - min + 1)) + min;
    }
}
