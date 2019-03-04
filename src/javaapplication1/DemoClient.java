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
import java.net.UnknownHostException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vench
 */
public class DemoClient {
    private final DatagramSocket socket;
    private final InetAddress address;
 
    private byte[] buf;
 
    public DemoClient() throws SocketException, UnknownHostException {
        socket = new DatagramSocket();
        address = InetAddress.getByName("localhost"); 
    }
 
    public Demo sendDemo(Demo demo) {
        try {
            send(demo);
             
                
            
            byte[] dataBuf = new byte[DemoHint.MAX_SIZE];
            DatagramPacket packetData = new DatagramPacket(dataBuf, DemoHint.MAX_SIZE);
            socket.receive(packetData);
             
            ByteArrayInputStream in = new ByteArrayInputStream(dataBuf);
            ObjectInputStream is = new ObjectInputStream(in); 
            Demo dem =  (Demo)is.readObject();
           // is.close();
            System.out.println(dem);
            
            return dem;/* */
        } catch (IOException ex) {
            Logger.getLogger(DemoClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(DemoClient.class.getName()).log(Level.SEVERE, null, ex);
        }/**/
        return null;
    }
 
    public void close() {
        socket.close();
    }
    
    public void send(Demo demo) throws IOException {
        final ByteArrayOutputStream baos = new ByteArrayOutputStream(6400);
        final ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(demo);
        final byte[] data = baos.toByteArray(); 

        DatagramPacket packetData = new DatagramPacket(data, data.length, address, DemoHint.PORT);
        socket.send(packetData); 
    }
}
