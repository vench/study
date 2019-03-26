package servlet;

import modules.EJBHistory;

import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

@WebServlet("/history")
public class HistoryServlet extends HttpServlet {

    @EJB
    private EJBHistory historyServ;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        String login =  (String)req.getSession().getAttribute("login");
        if(login == null) {
            resp.sendRedirect("/SimpleServlet/");
            return;
        }

        String uLogin = req.getParameter("u_login");
        String uId = req.getParameter("u_id");
        if(uLogin== null || uLogin.isEmpty()) {
            uLogin = login;
        }

        if(uId == null) {
            uId = "";
        }

        int uid = 0;
        try {
            uid = Integer.parseInt(uId);
        } catch (NumberFormatException ex) { }

        if(uid > 0) {
            String[] res = historyServ.getHistory(login, uid);
            req.setAttribute("listHistory", Arrays.asList(  res ));
        } else {
            String[] res = historyServ.getHistory(login, uLogin);
            req.setAttribute("listHistory", Arrays.asList(  res ));
        }

        req.setAttribute("title", "History");
        req.setAttribute("login", login);
        req.setAttribute("uLogin", uLogin);
        req.setAttribute("uId", uId);
        req.getRequestDispatcher("/history.jsp").forward(req, resp);
    }
}
