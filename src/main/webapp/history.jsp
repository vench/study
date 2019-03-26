<%@ page import="java.util.List"%>
<%
String title = (String) request.getAttribute("title");
String uLogin = (String) request.getAttribute("uLogin");
String uId = (String) request.getAttribute("uId");
List<String> listHistory = (List<String>)request.getAttribute("listHistory");
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>
    <div>
        <form method="GET">
        <input value="<%=uLogin%>" placeholder="Input login" name="u_login"/>
        <input value="<%=uId%>" placeholder="Input id" name="u_id"/>
        <button type="submit">Search</button>
        </form>
    </div>
    <div>
     <% for (String item : listHistory) { %>
        <p>- <%=item%></p>
    <% } %>

    </div>

    <p><a href="/SimpleServlet/">To home</a></p>
</body>
</html>