package servlet;

import models.Registration;
import models.User;
import models.Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/db/more-role")
public class DbShowMoreRoleServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        try {
            List<User> users = Util.loadMoreRoleRegistration(Util.getConnection());
            req.setAttribute("users", users);

        } catch (Exception  e) {
            resp.getWriter().println(e.toString());
            return;
        }

        req.setAttribute("title", "List all");
        req.getRequestDispatcher("/list_more_role.jsp").forward(req, resp);

    }
}
