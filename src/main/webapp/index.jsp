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
    <p><a href="/SimpleServlet/test">To test</a></p>
</body>
</html>