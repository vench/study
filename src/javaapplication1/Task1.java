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
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.event.ComponentAdapter;
import java.awt.Container;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;

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
        JFrame f = new JFrame("DemoFrame"); 
        f.setSize(new Dimension(640, 480));
        f.setLocation(200, 160);
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setResizable (false);
        init(f);
        f.setVisible(true);
         
      
    }
    
    
    private void init(JFrame f) {
        Container contentPane = f.getContentPane();
        contentPane.setLayout(null);
        JButton button = new JButton("Demo");
        button.setBounds (200, 100, 200, 30);
        contentPane.add(button);
    }
     
    
    
    
    
}
