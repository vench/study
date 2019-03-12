/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * https://stackoverflow.com/questions/22371487/clean-way-to-stop-rmi-server
 * @author vench
 */
public class DemoServerImpl extends UnicastRemoteObject  implements RMIDateTime {
    
    private static final long serialVersionUID = 1L; 
    
    private boolean doShutdown;
    
    public DemoServerImpl() throws RemoteException {
        super(); 
        
        doShutdown = true;           
    }

    @Override
    public String getDate() throws RemoteException {
        return DemoHint.getStrDate();
    }

    @Override
    public String getTime() throws RemoteException {
        return DemoHint.getStrTime();
    }

    @Override
    public boolean stop() throws RemoteException { 
        if(doShutdown) {
            doShutdown = false;
            return true;
        } 
        return false;
    } 
    
    public String getServiceName() {
        return "DemoServerImpl";
    }
    
    public boolean isDoShutdown() {
        return doShutdown;
    }
    
}
