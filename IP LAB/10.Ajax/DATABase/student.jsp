<%@ page language="java" contentType="text/html; 
charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@ page import="java.sql.*"%> 

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">

<html>

<head>
<meta http-equiv="Content-Type" content="text/html; 
charset=ISO-8859-1">
<title>Student Details</title>

<script>

function showStudent(str)
{
	var xmlhttp;    

	if (str=="")
  	{  
		document.getElementById("txtHint").innerHTML="";
  		return;  
  	}
	if (window.XMLHttpRequest)
  	{// code for IE7+, Firefox, Chrome, Opera, Safari
  		xmlhttp=new XMLHttpRequest();
  	}
	else
  	{// code for IE6, IE5
  		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  	}

	xmlhttp.onreadystatechange=function()
  	{
  		if (xmlhttp.readyState==4 && xmlhttp.status==200)
{    
document.getElementById("txtHint").innerHTML = 
xmlhttp.responseText;    
}
  	}
	xmlhttp.open("GET","getstudent.jsp?q="+str,true);
	xmlhttp.send();
}
</script>
</head>
<body>
	<%
	Connection conn = null;
	PreparedStatement ps = null;
	ResultSet rs = null;
	
	try
	{
		Class.forName("com.mysql.jdbc.Driver");
		String URL = "jdbc:mysql://localhost:3306/rec";
		conn = DriverManager.getConnection(URL, "root", "admin");
	
		ps = conn.prepareStatement("select * from students");
		rs = ps.executeQuery();
	%>
	<form action="">
	Roll No. : 
	<select name = "RollNo" 
onchange = "showStudent(this.value)">
	<option value="">Select a Roll No.</option>
	<%
	while(rs.next())
	{
	%>
<option value=<%=rs.getString(1)%>>
<%=rs.getString(1)%>
</option>
	<%
	}
	%>
	</select>
	</form>
	<%
	}
	catch(Exception e)
	{
		out.println(e);
	}
	ps.close();
	rs.close();
	conn.close();
%>
<br>
<div id="txtHint">
Student information will be listed here..
</div>
</body>
</html>
