<%@ page language="java" contentType="text/html; 
charset=ISO-8859-1" pageEncoding="ISO-8859-1" 
import="java.sql.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Student-View All</title>
</head>
<body>
<center>
<h2>Student - View All</h2>
</center>
<hr>
<%
	Connection connection = null;
	Class.forName("com.mysql.jdbc.Driver");
	String connectionURL = "jdbc:mysql://localhost:3306/student";
	connection = DriverManager.getConnection
(connectionURL, "root", "vijay");
	Statement st = connection.createStatement();
	ResultSet rs = st.executeQuery("select * from student");
%>
<table border = "1" align = "center">
<tr>
<th>Roll No.</th>
<th>Student</th>
<th>Branch</th>
<th>10th Mark</th>
<th>12th Mark</th>
</tr>
<%
	while(rs.next())
	{
%>
	<tr>
		<td><%=rs.getString("rollno")%></td>
		<td><%=rs.getString("sname")%></td>
		<td><%=rs.getString("branch")%></td>
		<td><%=rs.getString("sslc")%></td>
		<td><%=rs.getString("hsc")%></td>
	</tr>
 
<%
	}
	rs.close();
	connection.close();
%>
</table>
</body>
</html>
