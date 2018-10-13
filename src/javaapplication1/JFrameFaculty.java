/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.Dimension;
import javax.swing.JFrame;

/**
 *
 * @author vench
 */
public class JFrameFaculty extends JFrame {
    
    
    
    public JFrameFaculty() {
        super("JFrameFaculty");
        
        setSize(new Dimension(480, 320));
        setLocation(200, 160);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setResizable (false); 
        initComponents();
    }
    
    private void initComponents() {
    }
}
