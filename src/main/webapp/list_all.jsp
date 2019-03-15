<%@page import="models.Registration"%>
<%@ page import="java.util.List"%>
<%
String title = (String) request.getAttribute("title");
List<Registration> registrations = (List<Registration>)request.getAttribute("registrations");
String start_date = (String) request.getParameter("start_date");
if(start_date == null) {
    start_date = "";
}
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>

    <div>

    <form>
    <input type="text" name="start_date" value="<%=start_date%>" >
    <button type="submit">Submit</button>
    </form>


    <table>
    <tr>
            <th>Login</th>
            <th>Rold</th>
            <th>Date</th>
            <th>Time</th>
        </tr>
    <% for (Registration item : registrations) { %>
        <tr>
         <td><%=item.getUser().getLogin()%></td>
         <td><%=item.getRole()%></td>
         <td><%=item.getStringDate()%></td>
         <td><%=item.getStringTime()%></td>
         </tr>
    <% } %>
    </table>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>