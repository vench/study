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
         Frame f = new Frame("Main window");
         f.setBounds(100, 100, 640, 480); 
 
         f.addComponentListener(new ComponentAdapter() {
             public void componentResized(ComponentEvent ce) { 
        drawFrame(f);
    }
             
             public void componentShown(ComponentEvent ce) { 
        drawFrame(f);
    }

});
    
         f.addWindowListener(new WindowAdapter(){
         
             public void windowClosing(WindowEvent we) { 
                 f.setVisible(false); 
                 System.exit(0); 
    }
         
         });
         f.setVisible(true);
         
      
    }
    
    
    
    /**
     * 
     * @param f 
     */
    private void drawFrame(Frame f) {
        
        Graphics2D g2 = (Graphics2D)f.getGraphics(); 
                
        int w = f.getWidth();
        int h = f.getHeight();
        g2.clearRect(0, 0, w, h);
        g2.setColor(Color.blue);
        g2.fillRect(0, 0, w, h);
                 
        for (int i = 0; i < 12; i ++) {
            g2.setColor(getRandomColor()); 
            g2.setStroke(new BasicStroke(randomInt(3,7))); 
            
            double r = Math.random();
                        
            int rw = randomInt(0, w);
            int rh = randomInt(0, h);
            int rx = randomInt(0, w-rw);
            int ry = randomInt(0, h-rh);
            
            if(r > 0.66) {
                g2.drawLine(rx, ry, rw, rh);
            } else if(r > 0.33) {
                g2.drawOval(rx, ry, rw, rh);
            } else {
                g2.drawRect(rx, ry, rw, rh);
            }            
        }         
    }
    
    private int randomInt(int min, int max) {
        return (int)(Math.random() * (max - min + 1)) + min;
    }
    
    private Color getRandomColor() {
        int r = randomInt(0, 255);
        int g = randomInt(0, 255);
        int b = randomInt(0, 255);
        return new Color(r, g, b);
    }
    
}
