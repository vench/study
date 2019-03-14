<%@page import="models.User"%>
<%@ page import="java.util.List"%>
<%
String title = (String) request.getAttribute("title");
List<User> users = (List<User>)request.getAttribute("users");
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>

    <div>



    <table>
    <tr>
        <th>Login</th>
        <th>Count</th>
    </tr>
    <% for (User item : users) { %>
        <tr>
         <td><%=item.getLogin()%></td>
         <td><%=item.getCountRegistrations()%></td>
         </tr>
    <% } %>
    </table>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>