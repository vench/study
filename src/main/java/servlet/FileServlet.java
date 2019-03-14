package servlet;

import models.Registration;
import models.RegistrationSerialize;
import models.Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.sql.Connection;


@WebServlet("/file")
@MultipartConfig
public class FileServlet extends HttpServlet {

    private static final long serialVersionUID = 10L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws IOException, ServletException {

        req.setAttribute("title", "File upload");
        req.getRequestDispatcher("/file.jsp").forward(req, resp);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        Part filePart = req.getPart("file");
        InputStream is = filePart.getInputStream();

        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(is));
            if (is != null) {
                String str;

                try {
                    Connection conn = Util.getConnection();
                    while ((str = reader.readLine()) != null) {
                        Registration r = RegistrationSerialize.stringToRegistration(str);
                        if (r != null) {
                            Util.persists(conn, r);
                            resp.getWriter().println(r);
                        }
                    }
                } catch (Exception e) {
                    resp.getWriter().println(e.toString());
                }
            }
        } finally {
            try { is.close(); } catch (Throwable ignore) {}

            resp.getWriter().println("DONE");
            // TODO redirect
        }

    }
}