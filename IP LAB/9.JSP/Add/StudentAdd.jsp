<%@ page language="java" contentType="text/html; 
charset=ISO-8859-1" pageEncoding="ISO-8859-1" import="java.sql.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Student-Add</title>
</head>
<body>
<%
	Connection connection = null;
	Class.forName("com.mysql.jdbc.Driver");
	String connectionURL = "jdbc:mysql://localhost:3306/rec";
	connection = DriverManager.getConnection
(connectionURL, "root", "admin");
	String sql="insert into student values (?,?,?,?,?)";
	PreparedStatement ps = connection.prepareStatement(sql);
	ps.setString(1, request.getParameter("rollno"));
	ps.setString(2, request.getParameter("sname"));
	ps.setString(3, request.getParameter("branch"));
	ps.setString(4, request.getParameter("sslc"));
	ps.setString(5, request.getParameter("hsc"));
	ps.executeQuery();
	out.println("Record Inserted Successfully...!");
	ps.close();
	connection.close();
%>
</body>
</html>
