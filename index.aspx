<%@ Page Language="C#" %> 
<%@ Import Namespace="System.Data" %> 
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en"> 
    <head> 
    <title>Code behind Arrrrrrrrrrgh</title> 
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 

    <script runat="server"> 
    private void Page_Load(Object sender, EventArgs e) 
    { 
     DisplayServerDetails(); 
     DisplayRequestDetails(); 

    } 

    private void DisplayServerDetails() 
     { 
     serverName.Text = Environment.MachineName; 
     operatingSystem.Text = Environment.OSVersion.Platform.ToString(); 
     operatingSystemVersion.Text = Environment.OSVersion.Version.ToString(); 
     } 

     private void DisplayRequestDetails() 
     { 
     requestedPage.Text = Request.Url.AbsolutePath; 
     requestIP.Text = Request.UserHostAddress; 
     requestUA.Text = Request.UserAgent; 
     } 

    </script> 

    </head> 

    <body> 
    <form method="post" runat="server"> 
     <table width="450px" border="1px"> 
      <tr> 
       <td colspan="2"><strong>Server Details</strong></td> 
      </tr> 
      <tr> 
       <td>Server Name:</td> 
       <td> 
        <asp:Label id="serverName" runat="server"></asp:Label></td> 
      </tr> 
      <tr> 
       <td>Operating System:</td> 
       <td> 
        <asp:Label id="operatingSystem" runat="server"></asp:Label> 
       </td> 
      </tr> 
      <tr> 
       <td>Operating System Version:</td> 
       <td> 
        <asp:Label id="operatingSystemVersion" runat="server"> 
        </asp:Label> 
       </td> 
      </tr> 
     </table> 
     <br> 
     <table width="450px" border="1px"> 
      <tr> 
       <td colspan="2"><strong>Request Details</strong></td> 
      </tr> 
      <tr> 
       <td>Page Requested:</td> 
       <td> 
        <asp:Label id="requestedPage" runat="server"></asp:Label> 
       </td> 
      </tr> 
      <tr> 
       <td>Request From:</td> 
       <td> 
        <asp:Label id="requestIP" runat="server"></asp:Label> 
       </td> 
      </tr> 
      <tr> 
       <td>User Agent:</td> 
       <td> 
        <asp:Label id="requestUA" runat="server"></asp:Label> 
       </td> 
      </tr> 
     </table> 
     </form> 
    </body> 
