<%@ page import="java.util.Date"%>
<%@ page import="java.util.List"%>
<%
String title = (String) request.getAttribute("title");
List<Date> dates = (List<Date>)request.getAttribute("dates");
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
        <th>date</th>
    </tr>
    <% for (Date date : dates) { %>
        <tr>
         <td><%=date%></td>
         </tr>
    <% } %>
    </table>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>