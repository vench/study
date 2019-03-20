package servlet;

import modules.EJBDemo;
import modules.IHelloWorld;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import javax.ejb.EJB;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @EJB
    private EJBDemo loginServ;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {
        req.setAttribute("title", "Login");
        req.setAttribute("message", loginServ.getMessage("x"));
        req.getRequestDispatcher("/login.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        String login = req.getParameter("login");
        String password = req.getParameter("password");

        String result = "";
        if(loginServ.login(login, password)) {
            result = "The session has been successfully opened.";
        } else {
            result = "Login failed.";
        }

        req.setAttribute("title", "Login");
        req.setAttribute("result", result);
        req.setAttribute("message", loginServ.getMessage("x"));
        req.getRequestDispatcher("/login.jsp").forward(req, resp);
    }
}
