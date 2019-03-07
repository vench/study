/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.GregorianCalendar;

/**
 *
 * @author vench
 */
public class Task1ServerHandler extends Thread {
    Socket s;
    private final int id;
    
    public Task1ServerHandler(int id, Socket s) { 
        this.id = id;
        this.s = s;
 
        setDaemon(true);
        setPriority(NORM_PRIORITY); 
    }
    
    @Override
     public void run()
    {
        try
        {  
            
            InputStream is = s.getInputStream(); 
            OutputStream os = s.getOutputStream();  
            
            while(!s.isClosed()){
                byte buf[] = new byte[1024]; 
                int r = is.read(buf);
                
                String command = new String(buf, 0, r);
                System.out.println("command : " + command);
                String result = "";
                GregorianCalendar c = new GregorianCalendar();
                switch(command) {
                    case "date":  
                        result =  calendarGet(c, GregorianCalendar.YEAR) + "." + 
                                  calendarGet(c, GregorianCalendar.MONTH, 1) + "." + 
                                  calendarGet(c, GregorianCalendar.DATE)
                                ;
                        break;

                    case "time": 
                        result =  calendarGet(c, GregorianCalendar.HOUR) + ":" + 
                                  calendarGet(c,  GregorianCalendar.MINUTE);
                        break;
                }
                os.write(result.getBytes()); 
                os.flush();
            }
            s.close();
        } catch(IOException e) {
            Logger.getLogger(Task1.class.getName()).log(Level.SEVERE, null, e);
        } 
    }
     
     /**
      * 
      * @param c
      * @param type
      * @return 
      */
    private String  calendarGet(Calendar c, int type) { 
        return calendarGet(c, type, 0);
    }
         
    /**
     * 
     * @param c
     * @param type
     * @param append
     * @return 
     */
    private String  calendarGet(Calendar c, int type, int append) {
        int i =  c.get(type) + append;
        return i <= 9 ? "0" + i : i + "";
    }
}
