package servlet;

import com.company.History;
import modules.EJBHistory;
import modules.EJBHistoryBean;
import servlet.utilites.Util;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.List;
import java.util.Arrays;
import javax.ejb.EJB;
import javax.servlet.annotation.WebServlet;
import modules.IHelloWorld;

@WebServlet("/test")
public class TestServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;
    
    @EJB 
    private IHelloWorld hello;

    @EJB
    private EJBHistory history;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws  IOException,ServletException {

        String title = "title";


        String[] res = history.getHistory("test", "test");
        List<String> strList = Arrays.asList(  res );
        req.setAttribute("title", hello.sayHello(title));
        req.setAttribute("result", strList);
        req.getRequestDispatcher("/common.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws  IOException,ServletException {

        String result = "";
        String value = req.getParameter("value");

        if(value == null || value.length() == 0) {
            result = "Value is empty";
        } else {
            try {
                int i = Integer.parseInt(value);
                result = "" + (i + 1);
            } catch (NumberFormatException e) {
                result = value + " => " + Util.countWords(value);
            }
        }

        req.setAttribute("result", result);
        req.setAttribute("title", hello.sayHello("Title"));
        req.getRequestDispatcher("/common.jsp").forward(req, resp);
    }
}

