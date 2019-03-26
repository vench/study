package servlet;

import modules.EJBDemo;
import modules.EJBHistory;

import javax.ejb.EJB;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet("/logout")
public class LogoutServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @EJB
    private EJBHistory history;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException {
        String loginKey = "login";
        String login =  (String)req.getSession().getAttribute(loginKey);
        if(login != null) {
            history.logout(login);
            req.getSession().removeAttribute(loginKey);
        }
        resp.sendRedirect("/SimpleServlet/");
    }
}
