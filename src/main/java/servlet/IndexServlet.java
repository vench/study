package servlet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import  servlet.utilites.Util;

@WebServlet("/")
public class IndexServlet extends HttpServlet {

    private static final long serialVersionUID = 1L;



    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        String login =  (String)req.getSession().getAttribute("login");

        req.setAttribute("title", "Title");
        req.setAttribute("login", login);
       // resp.getWriter().println(login);
        req.getRequestDispatcher("/home.jsp").forward(req, resp);

    }
}