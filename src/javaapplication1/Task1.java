/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
 
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.io.Writer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javaapplication1.math.Matrix;
import javaapplication1.math.MatrixException;

/**
 *
 * @author vench
 */
public class Task1 extends AbTask {
    
    
    final private static String FILE_NAME = "matrix.txt";
    
    /**
     * 
     * @return 
     */
    @Override
    public String getTitle() {
        return "Работа с классом Matrix";
    }
    
    @Override
    public void run() {
        try {
            // ADD Matrix
            Matrix A = new Matrix(5, 5);
            Matrix B = new Matrix(5, 5);
            for(int i = 0; i < 5; i ++) {
                A.set(i, i, 1);
                B.set(0, i, 2);
                B.set(i, 0, 2);
            }
            
            System.out.println(A.output());
            Matrix M = A.add(B);
            System.out.println(M.output());
            
            //  Save 
            try (Writer writer = new BufferedWriter(new OutputStreamWriter(
              new FileOutputStream(FILE_NAME), "utf-8"))) {
                M.write(writer);
            } catch (Exception ex) {
                Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            // Load
            try (Reader reader = new BufferedReader(new InputStreamReader(
              new FileInputStream(FILE_NAME), "utf-8"))) {
                Matrix.read(reader);
            } catch (Exception ex) {
                Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            
        } catch (MatrixException ex) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
        }
      
    }
    
    
}
