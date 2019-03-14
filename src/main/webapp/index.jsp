<%
String title = (String) request.getAttribute("title");
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>

    <p><a href="/SimpleServlet/db/create">Db create</a></p>
    <p><a href="/SimpleServlet/file">Upload file</a></p>
    <p><a href="/SimpleServlet/db/all">Show all</a></p>
    <p><a href="/SimpleServlet/db/more-role">Show more role</a></p>
    <p><a href="/SimpleServlet/db/more-date">Show date more one</a></p>
    <p><a href="/SimpleServlet/test">To test</a></p>
</body>
</html>