/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;


import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author vench
 */
public class MyFrame extends Frame{
 
    
    public MyFrame(String title) {
        super(title); 
         
    }
    
    public void paint(Graphics g) { 
        Graphics2D g2 = (Graphics2D)g; 
                
        int w = getWidth();
        int h = getHeight();
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
                g2.draw(new Line2D.Double(rx, ry,rw, rh));
            } else if(r > 0.33) {
                g2.draw(new Ellipse2D.Double(rx, ry,rw, rh));
            } else {
                g2.draw(new Rectangle2D.Double(rx, ry,rw, rh));
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
