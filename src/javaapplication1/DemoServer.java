/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 */
public class DemoServer extends Thread {
    
    private final DatagramSocket socket;
    private boolean running; 
      
    
    public DemoServer() throws SocketException {
        socket = new DatagramSocket(DemoHint.PORT);
    }
 
    @Override
    public void run() {
        running = true;
        
        System.out.println("Server read size: " + DemoHint.MAX_SIZE);
                
        
        
 
        while (running) {
            try { 
                
                byte[] dataBuf = new byte[DemoHint.MAX_SIZE];
                DatagramPacket packetData = new DatagramPacket(dataBuf, DemoHint.MAX_SIZE);
                socket.receive(packetData);
                
                ByteArrayInputStream in = new ByteArrayInputStream(dataBuf);
                ObjectInputStream is = new ObjectInputStream(in); 
                Demo dem =  (Demo)is.readObject();
                is.close();
                
                System.out.println("Server in: " + dem);
                if("end".equals(dem.getName())) {
                    running = false; 
                }  
                
                Demo responce = new Demo("server", "responce", new Date(), 2);
                send(responce, packetData.getAddress(), packetData.getPort());
                
                
            } catch (IOException  | ClassNotFoundException ex) {
                Logger.getLogger(DemoServer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        socket.close();
    }
    
    public void send(Demo demo, InetAddress address, int port) throws IOException {
        final ByteArrayOutputStream baos = new ByteArrayOutputStream(6400);
        final ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(demo);
        final byte[] data = baos.toByteArray(); 

        DatagramPacket packetData = new DatagramPacket(data, data.length, address, port);
        socket.send(packetData); 
    }
}
