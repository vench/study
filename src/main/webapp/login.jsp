<%
String title = (String) request.getAttribute("title");
%>
<html>
<head>
    <title>${title}</title>
</head>
<body>
    <h1>${title} </h1>
    <div>
        <form method="POST">
        <input value="test" placeholder="Input login" name="login"/>
        <input value="test" type="password" placeholder="Input password" name="password"/>
        <button type="submit">Submit</button>
        </form>
    </div>
    <div>
    <pre>${result}</pre>
    </div>

    <p><a href="/SimpleServlet/">To home</a></p>
</body>
</html>