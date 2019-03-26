package modules;

import com.company.History;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.concurrent.ConcurrentHashMap;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.ejb.Stateful;

/**
 *
 * @author vench
 */
@Stateful
public class EJBHistoryBean implements EJBHistory {

    private History history;
    private static Map<String,String> mapSessions = new HashMap<String, String>();

    public EJBHistoryBean() throws RemoteException, NotBoundException {
        Registry registry = LocateRegistry.getRegistry("localhost", 6600);
        history = (History)registry.lookup("HistoryImpl");
    }


    @Override
    public String[] getHistory(String login, String name) {
        if(mapSessions.containsKey(login)) {
            try {
                return history.getHistory(name);
            } catch (RemoteException ex) {
                Logger.getLogger(EJBHistoryBean.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return new String[]{mapSessions.keySet().toString()};
    }

    @Override
    public String[] getHistory(String login, int code) {
        if(mapSessions.containsKey(login)) {
            try {
                return history.getHistory(code);
            } catch (RemoteException ex) {
                Logger.getLogger(EJBHistoryBean.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return new String[]{mapSessions.keySet().toString()};
    }

    @Override
    public boolean login(String login, String password) {
        try {
            boolean result = history.login(login, password);
            if(result) {
                mapSessions.put(login, login);
                return  true;
            }
        } catch (RemoteException ex) {
            Logger.getLogger(EJBHistoryBean.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    @Override
    public boolean logout(String login) {
        if(mapSessions.containsKey(login)) {
            mapSessions.remove(login);
            try {
                history.logout();
            } catch (RemoteException ex) {
                Logger.getLogger(EJBHistoryBean.class.getName()).log(Level.SEVERE, null, ex);
            }
            return  true;
        }
        return false;
    }
}
