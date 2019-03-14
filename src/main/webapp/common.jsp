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
        <input placeholder="Input text" name="value"/>
        <button type="submit">Submit</button>
        </form>
    </div>
    <div>
    <pre>${result}</pre>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>