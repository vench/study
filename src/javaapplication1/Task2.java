/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.net.SocketException;
import java.net.UnknownHostException;
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
            //https://www.baeldung.com/udp-in-java

            initServer();
            sendClient();
        } catch (SocketException | UnknownHostException ex) {
            Logger.getLogger(Task2.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private void initServer() throws SocketException {
        DemoServer server =  new DemoServer();
        server.start();
        System.out.println("Server has been started...");
    }
    
    private void sendClient() throws SocketException, UnknownHostException{
        DemoClient client = new DemoClient();
        
        for(int i = 0; i < 10; i ++) {
            Demo res = client.sendDemo(new Demo("Test " + i, "Test", new Date(), 1));
            System.out.println("Client: " + res); 
        }
        
        
        
        System.out.println("Client has been started...");
        Demo res = client.sendDemo(new Demo("end", "Test", new Date(), 1));
        System.out.println("Client: " + res);
    } 
}
