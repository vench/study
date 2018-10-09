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
import javaapplication1.math.Vector;
import javaapplication1.math.MatrixException;

/**
 *
 * @author vench
 */
public class Task1 extends AbTask {
    
    
    final private static String FILE_NAME = "matrix.txt";
    final private static String FILE_NAME2 = "vector.txt";
    
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
            save(M, FILE_NAME);
            
            // Load
            Matrix M1 = load(FILE_NAME);
            System.out.println(M1.output());
            
            
            // Vector
            Vector v = new Vector(10);
            System.out.println(v.output());
            for(int i = 0; i < 10; i ++) {
                v.set(i, 1./(i + 1));
            }
            
            System.out.println(v.output());
            
            Vector vvv1 = new Vector(new double[]{1,2,3});
            Vector vvv2 = new Vector(new double[]{3,4,5});
            System.out.println(vvv1.add(vvv2).output()); //[4,6,8]
            
            //  Save 
            save(v, FILE_NAME2);
            
            // Load
            Matrix v1 = load(FILE_NAME2);
            System.out.println(v1.output());  
            
            // Cos
            Vector vv1 = new Vector( new double[]{1, 2} ); 
            Vector vv2 = new Vector( new double[]{1, 2} );
            Vector vv3 = new Vector( new double[]{2, 0} );
            
            System.out.println(vv1.cos(vv2)); // -> 1
            System.out.println(vv1.cos(vv3)); // -> .45
            
        } catch (MatrixException ex) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
        }
      
    }
    
    
    private void save(Matrix M, String fileName) {
        try (Writer writer = new BufferedWriter(new OutputStreamWriter(
              new FileOutputStream(fileName), "utf-8"))) {
                M.write(writer);
            } catch (Exception ex) {
                Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
            }
    }
    
    private Matrix load(String fileName) {
        try (Reader reader = new BufferedReader(new InputStreamReader(
              new FileInputStream(fileName), "utf-8"))) {
                return Matrix.read(reader); 
            } catch (Exception ex) {
                Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
            }
        return null;
    }
    
    
}
