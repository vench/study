package servlet;

import models.Registration;
import models.Util;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/db/all")
public class DbShowAllServlet  extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        try {
            List<Registration> registrations = Util.loadAllRegistration(Util.getConnection());
            req.setAttribute("registrations", registrations);

        } catch (Exception  e) {
            resp.getWriter().println(e.toString());
            return;
        }

        req.setAttribute("title", "List all");
        req.getRequestDispatcher("/list_all.jsp").forward(req, resp);

    }
}
