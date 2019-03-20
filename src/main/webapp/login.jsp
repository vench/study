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
        <input placeholder="Input login" name="login"/>
        <input placeholder="Input password" name="password"/>
        <button type="submit">Submit</button>
        </form>
    </div>
    <div>
    <pre>${result}</pre>

    <h3>Message</h3>
    <p>${message}</p>
    <p><a href="">refresh</a></p>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>