/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 */
public abstract class AbTask implements Task {
 
    /**
     * 
     * @return 
     */
    protected int readInt() {
        byte[] data = new byte[100];          
        try {
            System.in.read(data); 
            return Integer.parseInt(new String(data).trim()); 
        } catch (IOException | NumberFormatException ex) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return 0;
    }
}
