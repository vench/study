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
public class DataBase {
    
    private int readers;
    
    private int writers;
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public synchronized void startRead(String name) throws InterruptedException {
        if(readers > 2) {
            wait();
        }
        if( writers > 0) {
            wait();
        }
        System.out.println("Start read: " + name + ", readers: " + readers);
        
        readers ++;
    }
    
    /**
     * 
     * @param name 
     */
    public synchronized void endRead(String name) {
        System.out.println("End read: " + name);
        
        readers --;
        notify();
    }
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public synchronized void startWrite(String name) throws InterruptedException {
        if(writers > 0) {
            wait();
        }
        System.out.println("Start write: " + name); 
        writers ++;
    }
    
    /**
     * 
     * @param name 
     */
    public synchronized void endWrite(String name) {
        System.out.println("End write: " + name);
        writers --;
        notify();
    }
}
