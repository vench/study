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

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();
        String title = "Title value";
        out.println(Util.headWithTitle(title) +
                "<body>\n" +
                "<h1>" + title + "</h1>\n" +
                "<p><a href='test'>Go to form</a></p>\n" +
                "</body></html>");

    }
}