package com.company;

import java.rmi.Remote;
import java.rmi.RemoteException;
import javax.ejb.Local;

@Local
public interface History extends Remote {

    String[] getHistory (String name) throws RemoteException;
    String[] getHistory (int code) throws RemoteException;
    boolean login (String user, String password) throws RemoteException;
    boolean logout () throws RemoteException;
}

