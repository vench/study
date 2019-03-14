package servlet;


import models.Registration;
import models.Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import java.util.Date;


@WebServlet("/db/more-date")
public class DbMoreDateServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        try {
            List<Date> dates = Util.loadMoreDate(Util.getConnection());
            req.setAttribute("dates", dates);

        } catch (Exception  e) {
            resp.getWriter().println(e.toString());
            return;
        }

        req.setAttribute("title", "List more date");
        req.getRequestDispatcher("/list_more_date.jsp").forward(req, resp);

    }
}
