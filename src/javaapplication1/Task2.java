/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.awt.event.ActionEvent;
import java.net.MalformedURLException;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author vench Написать пример приложения, производящего обмен данными по
 * протоколу UDP. Приложение должно пересылать объект класса Demo, содержащего
 * следующие данные: идентификатор отправителя (id), имяid), имя отправителя
 * (id), имяname), текстовое сообщение (id), имяmessage) и время отправления
 * (id), имяdate). В соответствии с этим назначением класс Demo должен иметь
 * следующие атрибуты:
 */
public class Task2 {

    public void exec() {
        try {
            initServer();
            sendClient();
        } catch (SocketException | UnknownHostException ex) {
            Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /**
     * 
     * @throws SocketException 
     */
    private void initServer() throws SocketException {
        try {
            DemoServerImpl s = new DemoServerImpl();
            System.out.println("Initializing " + s.getServiceName());
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind(s.getServiceName(), s);

            // TODO loop stop
            new Thread(() -> {
                while (s.isDoShutdown()) {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                try {
                    registry.unbind(s.getServiceName());
                    UnicastRemoteObject.unexportObject(registry, true);
                    //System.exit(0);
                } catch (RemoteException | NotBoundException ex) {
                    Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                }
            }).start();

        } catch (RemoteException ex) {
            Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
        }

        System.out.println("Server has been started...");
    }

    /**
     * 
     * @throws SocketException
     * @throws UnknownHostException 
     */
    private void sendClient() throws SocketException, UnknownHostException {

        String objectName = "rmi://localhost/DemoServerImpl";

        System.setProperty("java.rmi.server.hostname", "127.0.0.1");

        JFrame f = new JFrame();
        f.setBounds(100, 100, 320, 240);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton b1 = new JButton("Get date");
        b1.setBounds(10, 10, 100, 22);
        JButton b2 = new JButton("Get time");
        b2.setBounds(110, 10, 100, 22);
        JButton b3 = new JButton("Stop");
        b3.setBounds(210, 10, 100, 22);
        JLabel tx = new JLabel();
        tx.setText("");
        tx.setBounds(10, 100, 300, 40);
        b1.addActionListener((ActionEvent ae) -> {
            try {
                RMIDateTime bs = (RMIDateTime) Naming.lookup(objectName);
                String date = bs.getDate();
                tx.setText(date);
            } catch (NotBoundException | MalformedURLException | RemoteException ex) {
                Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                tx.setText(ex.getMessage());
            }
        });
        b2.addActionListener((ActionEvent ae) -> {
            try {
                RMIDateTime bs = (RMIDateTime) Naming.lookup(objectName);
                String time = bs.getTime();
                tx.setText(time);
            } catch (NotBoundException | MalformedURLException | RemoteException ex) {
                Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                tx.setText(ex.getMessage());
            }
        });
        b3.addActionListener((ActionEvent ae) -> {
            try {
                RMIDateTime bs = (RMIDateTime) Naming.lookup(objectName);
                if (bs.stop()) {
                    tx.setText("Has been stoped");

                }
            } catch (NotBoundException | MalformedURLException | RemoteException ex) {
                Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                tx.setText(ex.getMessage());
            }
        });
        JPanel panel = new JPanel();
        panel.setLayout(null);
        panel.add(b1);
        panel.add(tx);
        panel.add(b2);
        panel.add(b3);
        f.getContentPane().add(panel);
        f.setVisible(true);

    }
}
