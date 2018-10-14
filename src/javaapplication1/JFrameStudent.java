/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.util.List;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 *
 * @author vench
 */
public class JFrameStudent extends JFrame {
    
     private final List<AbPerson> showList;
    
    
    public JFrameStudent(List<AbPerson> showList) {
        super("Student Data");
        this.showList = showList;
        
        setSize(new Dimension(340, 180));
        setLocation(300, 160);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setResizable (false); 
        initComponents();
    }
    
    private void initComponents() {
        Container contentPane = getContentPane(); 
        GroupLayout layout = new GroupLayout(contentPane);
        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);
        contentPane.setLayout(layout); 
        
        JLabel label1 = new JLabel("Name");
        label1.setBounds(10, 10, 150, 30);
        contentPane.add(label1);
        
        JTextField text1 = new JTextField();
        text1.setBounds(10, 40, 150, 30);
        contentPane.add(text1);
        
        
        //
        JLabel label2 = new JLabel("Age");
        label2.setBounds(180, 10, 150, 30);
        contentPane.add(label2);
        
        JTextField text2 = new JTextField();
        text2.setBounds(180, 40, 150, 30);
        contentPane.add(text2);
        
        //
        JLabel label3 = new JLabel("");
        label3.setVisible(false);
        label3.setBounds(10, 110, 200, 50);
        contentPane.add(label3);
                
        JButton button = new JButton("Accept");
        button.setBounds (10, 80, 100, 30);
        button.addActionListener((ActionEvent ae) -> {
            if("".equals(text1.getText())) {
                label3.setText("Name is empty");
                label3.setForeground(Color.red);
                label3.setVisible(true);
                return;
            }
            if("".equals(text2.getText())) {
                label3.setText("Age is empty");
                label3.setForeground(Color.red);
                label3.setVisible(true);
                return;
            } 
            try {
            int age = Integer.parseInt(text2.getText());
            showList.add(new Student(text1.getText(), age));
            
            label3.setText("Accepted");
            label3.setForeground(Color.green);
            label3.setVisible(true);
            } catch(NumberFormatException e) {
                label3.setText("Age is not number");
                label3.setForeground(Color.red);
                label3.setVisible(true);
            }
        });
        contentPane.add(button);
        
        JButton button1 = new JButton("Clear");
        button1.setBounds (120, 80, 100, 30);
        button1.addActionListener((ActionEvent ae) -> {
            text1.setText("");
            text2.setText("");
            
        });
        contentPane.add(button1);
        
        JButton button2 = new JButton("Close");
        button2.setBounds (230, 80, 100, 30);
        button2.addActionListener((ActionEvent ae) -> {
            setVisible(false);
        });
        contentPane.add(button2);
    }
}
