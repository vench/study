/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
 
//import java.util.concurrent.Semaphore;

/**
 *
 * @author vench
 */
public class DataBase {
     
    private int readers;
    private int writers; 
    
    private final Semaphore sem; 
    private final Semaphore sem1; 
    
    public DataBase() {
        sem = new Semaphore(1); 
        sem1 = new Semaphore(1); 
    }
    
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public  void startRead(String name) throws InterruptedException {
        
        // Ждем когда писатель перестал читать
        sem.acquire();  
        readers ++;
        sem.release(); 
        System.out.println("reader " + name + " begin read");  
    }
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public  void endRead(String name) throws InterruptedException {
        System.out.println("reader " + name + " commit read");
        
        sem1.acquire();
        readers --;
        sem1.release(); 
    }
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public void startWrite(String name) throws InterruptedException { 
        
        // Ждем свою очередь
        sem.acquire(); 
        
        // Ждем что все читатели перестали читать
        boolean run = true;
        while(run) {
            sem1.acquire();
            if(readers == 0) {
                run = false;
            }
            sem1.release();
        } 
        writers ++;
        System.out.println("writer " + name + " begin write");        
    }
    
    /**
     * 
     * @param name 
     * @throws java.lang.InterruptedException 
     */
    public void endWrite(String name) throws InterruptedException {
        System.out.println("writer " + name + " commit write"); 
        writers --; 
        
        // Освободим очередь
        sem.release(1); 
    }
}
