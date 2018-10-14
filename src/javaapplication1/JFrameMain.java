/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;

/**
 *
 * @author vench
 */
public class JFrameMain extends JFrame {
    
    final private String LABEL_STUDENT_DATA = "Student Data";
    final private String LABEL_FACULTY_DATA ="Faculty Data";
    final private String LABEL_PRINT_LIST ="Print the list";
    
    private List<AbPerson> showList;
    
    private JFrameFaculty frameFaculty;
    
    private JFrameStudent frameStudent;
    
    public JFrameMain(String title) {
        super(title); 
        
        setSize(new Dimension(480, 320));
        setLocation(200, 160);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setResizable (false); 
        initComponents();  
    }
    
    
    private void initComponents() {
        
        showList = new ArrayList<>(); 
        JList jList = new JList(showList.toArray()); 
        
        ActionListener actionListener = (ActionEvent ae) -> {
            switch(ae.getActionCommand()) {
                case LABEL_FACULTY_DATA: 
                    if(frameFaculty == null) {
                        frameFaculty = new JFrameFaculty(showList);
                    }
                    frameFaculty.setVisible(true);
                    break;
                case LABEL_STUDENT_DATA:
                    if(frameStudent == null) {
                        frameStudent = new JFrameStudent(showList);
                    }
                    frameStudent.setVisible(true);
                    break;
                case LABEL_PRINT_LIST:
                    jList.setListData(showList.toArray());
                    break;
            }
            
           // System.out.println(ae.getActionCommand() +" -> "+ showList.size());
        };
    
        Container contentPane = getContentPane(); 
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
    
    
    @Override
    public void dispose() {
        super.dispose();
        if(frameFaculty != null) {
            frameFaculty.dispose();
        }
        if(frameStudent != null) {
            frameStudent.dispose();
        }
    }
    
    
    
}
