/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.event.WindowAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.WindowEvent;
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
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.event.ComponentAdapter;

/**
 *
 * @author vench
 */
public class Task1 extends AbTask {
     
    
    /**
     * 
     * @return 
     */
    @Override
    public String getTitle() {
        return "Рисуем c awt";
    }
    
    @Override
    public void run() {
         MyFrame f = new MyFrame("Main window");
         f.setBounds(100, 100, 640, 480);  
         f.setVisible(true);  
         f.addWindowListener(new WindowAdapter(){ 
             @Override
             public void windowClosing(WindowEvent we) { 
                 f.setVisible(false); 
                 System.exit(0); 
             }     
        });
    }
     
        
        
    
}
