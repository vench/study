/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
 
import java.net.URL;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 *
 * @author vench
 * 
 * Написать пример приложения, производящего обмен данными по протоколу
TCP/IP. Клиент приложения должен реализовать следующий алгоритм
работы:
установить соединение с сервером приложения;
последовательно послать серверу приложения строки «date» и «time».
Сервер в ответ на первый запрос должен вернуть текущую дату в виде
строки, например, «29.11.2012». На второй запрос сервер должен
вернуть текущее время в виде строки, например, «11:46».(Для
получения числа, месяца, года, часа и минут можно воспользоваться
классом java.util.GregorianCalendar);
разорвать соединение с сервером.
 */
public class Task1 {
     
    final public static int PORT = 9999; 
    private Task1Server server;
    
    public Task1() {
                   
    }
    
    public void exec() {
        runServer();
        runClient(); 
        runClient(); 
        runClient(); 
        server.end();
    }
    
    private void runServer()  {
        server = new Task1Server(PORT);
        server.start();
    }
    
    private void runClient() {
        
        try {
            Socket s = new Socket("localhost", PORT);
            for(String str : new String[]{"date", "time"}) {
                s.getOutputStream().write(str.getBytes());
                
                
                
                byte[] buf = new byte[2048];
                int r = s.getInputStream().read(buf);
                String data = new String(buf, 0, r);
                System.out.println("Result: " + str + " => " + data);
                
                
            } 
            
        } catch (IOException ex) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, ex);
        } 

            
    } 
}
