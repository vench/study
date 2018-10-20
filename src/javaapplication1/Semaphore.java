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
public class Semaphore {
    
    private final int cap;
    private int size;
    
    public Semaphore(int cap) {
        this.cap = cap;
        this.size = 0;
    }
    
    
    public synchronized void acquire() throws InterruptedException {
        acquire(1);
    }
    
    public synchronized void acquire(int i) throws InterruptedException {
        if(size + i > cap) {
            wait();
        }
        size += i; 
    }
    
    public synchronized void release() throws InterruptedException {
        release(1);
    }
    
    public synchronized void release(int i) throws InterruptedException {
        if(size - i < 0) {
            throw new InterruptedException("Todo");
        }
        size -= i;
        notify();
    }
}
