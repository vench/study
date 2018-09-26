/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       // java.lang.
       java.io.FileReader in;
       
       java.io.File file = new java.io.File("test.properties");
        try {
            in = new java.io.FileReader(file);
            System.getProperties().load(in);
        } catch (Exception ex) {
            Logger.getLogger(JavaApplication1.class.getName()).log(Level.SEVERE, null, ex);
        } 
        System.out.println( System.getProperty("FOO") );
        
        Runtime r = Runtime.getRuntime();
        int x = 1024*1024;
        System.out.printf("%d %d %d \n", r.freeMemory() / x, r.totalMemory() / x, r.maxMemory() / x);
    
       /* Process exec;
        try {
            exec = r.exec("/usr/bin/gedit");
            exec.wait(1);
            exec.destroy();
        } catch (Exception ex) {
            Logger.getLogger(JavaApplication1.class.getName()).log(Level.SEVERE, null, ex);
        }*/
       
       int[] zz = {1,2,3};
        int[] clone = zz.clone();
        
        Object ob = new Object();
       
        System.out.println(zz.getClass().getCanonicalName());
        System.out.println(clone[1]);
        
        Class d = byte.class;
        Class dd = Byte.TYPE;
        
        Class xxx = new Byte("1").getClass();
        
        Byte bb = Byte.valueOf("010101", 2);
        System.out.println(bb);
        
        String sss = "12345абв";
        System.out.println(sss.length());
        
    }
    
}
