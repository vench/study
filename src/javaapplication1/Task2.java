/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.net.MalformedURLException;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 * Написать пример приложения, производящего обмен данными по протоколу UDP.
Приложение должно пересылать объект класса Demo, содержащего следующие
данные: идентификатор отправителя (id), имяid), имя отправителя (id), имяname), текстовое
сообщение (id), имяmessage) и время отправления (id), имяdate). В соответствии с этим
назначением класс Demo должен иметь следующие атрибуты:
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
    
    private void initServer() throws SocketException { 
        try {
             DemoServerImpl s = new DemoServerImpl();  
             System.out.println("Initializing " + s.getServiceName()); 
             Registry registry = LocateRegistry.createRegistry(1099);
             registry.rebind(s.getServiceName(), s);
             
             // TODO loop stop
             new Thread(new Runnable() {
                 @Override 
                 public void run() {
                     while(s.isDoShutdown()) {
                         try {
                             Thread.sleep(1000);
                         } catch (InterruptedException ex) {
                             Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                         }
                     }
                     try {
                         registry.unbind(s.getServiceName());
                         UnicastRemoteObject.unexportObject(registry, true);
                         System.exit(0);
                     } catch (RemoteException | NotBoundException ex) {
                         Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
                     }
                 }
             }).start();  
             
        } catch (RemoteException ex) {
            Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
        } 
       
       System.out.println("Server has been started...");
    }
    
    private void sendClient() throws SocketException, UnknownHostException{
         RMIDateTime bs;
         String objectName = "rmi://localhost/DemoServerImpl";
        try {
            System.setProperty("java.rmi.server.hostname", "127.0.0.1");
            bs = (RMIDateTime) Naming.lookup(objectName);
            String date = bs.getDate();
            System.out.println("Get date: " + date);
            
            String time = bs.getTime();
            System.out.println("Get time: " + time);
            
            if(bs.stop()) {
                System.out.println("Server has been stopped...");
            }
            
        } catch (NotBoundException | MalformedURLException | RemoteException ex) {
            Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
        }
    } 
}
