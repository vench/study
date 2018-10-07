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
        
        Task[] t1 = {new Task1(), new Task2(), new Task3(), new Task4()};
        
        for (Task t11 : t1) {  
            System.out.println("============================================");
            System.out.println(t11.getTitle());
            System.out.println("============================================");
            t11.run();
        }
    }
    
    
    
    
}
