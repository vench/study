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
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

@WebServlet("/db/all")
public class DbShowAllServlet  extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        try {
            Date startDate = null;
            String value = req.getParameter("start_date");
            if(value != null) {
                try {
                    SimpleDateFormat mdyFormat = new SimpleDateFormat("dd.MM.yyyy");
                    startDate = mdyFormat.parse(value.trim());
                } catch (ParseException e) { }
            }
            List<Registration> registrations = Util.loadAllRegistration(Util.getConnection(), startDate);
            req.setAttribute("registrations", registrations);

        } catch (Exception  e) {
            resp.getWriter().println(e.toString());
            return;
        }

        req.setAttribute("title", "List all");
        req.getRequestDispatcher("/list_all.jsp").forward(req, resp);

    }
}
