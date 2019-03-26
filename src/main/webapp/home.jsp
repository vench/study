<%
String title = (String) request.getAttribute("title");
String login = (String) request.getAttribute("login");
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>

    <% if( login == null) { %>
        <p>You must has been authorized.</p>
        <p><a href="/SimpleServlet/login">Go to login page</a></p>

    <% }  else { %>

        <p>Your login: <strong>${login}</strong></p>
        <p><a href="/SimpleServlet/history">Go to history page</a></p>
        <p><a href="/SimpleServlet/logout">Logout</a></p>
    <% } %>

</body>
</html>