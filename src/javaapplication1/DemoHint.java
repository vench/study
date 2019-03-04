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

/**
 *
 * @author vench
 */
public class DemoHint {
    
    /**
     * 
     */
    public static final int PORT = 4445;
    
    public static final int MAX_SIZE = 2048;
    
    /**
     * 
     * @param i
     * @return 
     */
    public static byte[] intToByteAr(int i ) {
        byte[] b = new byte[4];
        b[0] = (byte)(i & 0xff);
        b[1] = (byte)((i >> 8) & 0xff);
        b[2] = (byte)((i >> 16) & 0xff);
        b[3] = (byte)((i >> 24) & 0xff);
        return b;   
    }
    
    /**
     * 
     * @param b
     * @return 
     */
    public static int byteArToInt(byte[] b) {
        int i = ((0xFF & b[3]) << 24) | ((0xFF &  b[2]) << 16) | ((0xFF & b[1]) << 8) | (0xFF & b[0]); 
        return i;
    }
    
    /**
     * 
     * @param demo
     * @param socket
     * @param address
     * @throws IOException 
     */
    public static void sendDemo(Demo demo, DatagramSocket socket, InetAddress address) throws IOException {
        final ByteArrayOutputStream baos = new ByteArrayOutputStream(6400);
        final ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(demo);
        final byte[] data = baos.toByteArray();
        //byte[] size = intToByteAr(data.length);
            
        //DatagramPacket packetSize = new DatagramPacket(size, 4, address, DemoHint.PORT);
        //socket.send(packetSize);

        DatagramPacket packetData = new DatagramPacket(data, data.length, address, DemoHint.PORT);
        socket.send(packetData);
    }
    
    public static Demo readDemo(DatagramSocket socket) throws IOException, ClassNotFoundException {
        byte[] sizeBuf = new byte[4];
        DatagramPacket packetSize = new DatagramPacket(sizeBuf, 4);
        socket.receive(packetSize);
        int size = DemoHint.byteArToInt(sizeBuf);
        
        //System.out.println("Server read size: " + size);
                
        byte[] dataBuf = new byte[size];
        DatagramPacket packetData = new DatagramPacket(dataBuf, size);
        socket.receive(packetData);
                
        ByteArrayInputStream in = new ByteArrayInputStream(dataBuf);
        ObjectInputStream is = new ObjectInputStream(in);
                
        Demo dem =  (Demo)is.readObject();
        return dem;
    }
}
