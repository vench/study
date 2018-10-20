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
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        DataBase db = new DataBase();
        
        for(int i = 0; i < 4; i ++) { 
            (new Writer( "Writer " + i, db)).start();
            (new Reader( "Reader " + i, db)).start();
        }
    }
    
    
    
    
}
