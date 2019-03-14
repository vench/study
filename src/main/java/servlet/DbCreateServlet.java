package servlet;

import models.Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import javax.servlet.RequestDispatcher;


@WebServlet("/db/create")
public class DbCreateServlet  extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        try {
            Util.createDataBase(Util.getConnection());
        } catch (Exception  e) {
            resp.getWriter().println(e.toString());
            return;
        }


        RequestDispatcher dispatcher = getServletContext()
                .getRequestDispatcher("/");
        dispatcher.forward(req, resp);

    }
}
