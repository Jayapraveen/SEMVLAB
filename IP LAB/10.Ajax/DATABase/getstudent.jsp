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
		
		ps = conn.prepareStatement("select * from students 
where rollno = ?");
		String RollNo = request.getParameter("q");
		ps.setString(1, RollNo);
		rs = ps.executeQuery();
		if(rs.next())
		{
			out.println("Student Name : " + rs.getString(2));
			out.println("<br/>");
			out.println("Branch : " + rs.getString(3));
		}
	}
	catch(Exception e)
	{
		out.println(e);
	}
	ps.close();
	rs.close();
	conn.close();
  	%>

</body>
</html>
