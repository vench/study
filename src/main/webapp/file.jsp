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
        <form enctype="multipart/form-data" method="POST">
        <input placeholder="Select file" name="file" type="file"/>
        <button type="submit">Submit</button>
        </form>
    </div>
    <div>
    <pre>${result}</pre>
    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>