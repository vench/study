<%@ page import="java.util.List"%>
<%
String title = (String) request.getAttribute("title");
List<String> result = (List<String>)request.getAttribute("result");
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
     <% for (String item : result) { %>
        <p>- <%=item%></p>
    <% } %>

    </div>

    <p><a href="/SimpleServlet/">To index</a></p>
</body>
</html>