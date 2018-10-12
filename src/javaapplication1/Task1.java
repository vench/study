/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.BasicStroke;
import java.awt.BorderLayout;
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
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

/**
 *
 * @author vench
 */
public class Task1 extends AbTask {
     
    
    final private String LABEL_STUDENT_DATA = "Student Data";
    final private String LABEL_FACULTY_DATA ="Faculty Data";
    final private String LABEL_PRINT_LIST ="Print the list";
    
    
    private List<AbPerson> showList;
    
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
        JFrame f = new JFrame("DS&A. Assignment 1"); 
        f.setSize(new Dimension(480, 320));
        f.setLocation(200, 160);
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setResizable (false);
        init(f);
        f.setVisible(true); 
    }
    
    
    private void init(JFrame f) {
        
        showList = new ArrayList<>(); 
        JList jList = new JList(showList.toArray()); 
        
        ActionListener actionListener = new ActionListener() {
            
            public void actionPerformed(ActionEvent ae) {
                 switch(ae.getActionCommand()) {
                    case LABEL_FACULTY_DATA:
                         showList.add(new Teacher("xxxx"));
                         break;
                    case LABEL_STUDENT_DATA:
                          showList.add(new Student("xxxx"));
                         break;
                    case LABEL_PRINT_LIST: 
                         jList.setListData(showList.toArray());
                         break;                        
                 }
             
                System.out.println(ae.getActionCommand() +" -> "+ showList.size());
            }
        };
        
        Container contentPane = f.getContentPane(); 
        GroupLayout layout = new GroupLayout(contentPane);
        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);
        contentPane.setLayout(layout); 
        
        
        JButton button = new JButton(LABEL_STUDENT_DATA);
        button.setBounds (10, 10, 150, 30);
        button.addActionListener(actionListener);
        contentPane.add(button);
        JButton button1 = new JButton(LABEL_FACULTY_DATA); 
        button1.setBounds (160, 10, 150, 30);
        button1.addActionListener(actionListener);
        contentPane.add(button1);
        JButton button2 = new JButton(LABEL_PRINT_LIST);
        button2.setBounds (310, 10, 150, 30);
        button2.addActionListener(actionListener);
        contentPane.add(button2);
        
        
        JScrollPane listScroller = new JScrollPane(jList);
        listScroller.setBounds(10, 50, 450, 220); 
        contentPane.add(listScroller); 
    }

        

        
}
     
    
    
    
    

