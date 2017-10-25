package org.rajalakshmi.webservices.database;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.jws.WebService;
@WebService
public class Student {

public String DispStud (String rollNo)
{
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		String sName = null;
		try
		{
		Class.forName("com.mysql.jdbc.Driver");
		String URL = "jdbc:mysql://localhost:3306/rec";
		conn = DriverManager.getConnection(URL, "root", "admin");
		ps=conn.prepareStatement("select * from student where 
rollno=?");
		ps.setString(1, rollNo);
		rs = ps.executeQuery();
		if(rs.next())
		{
			sName = rs.getString(2);
		}
		else
		{
			sName = "Not Found...";
		}
		rs.close();
		ps.close();
		conn.close();
		return sName;
		}
		catch(Exception e)
		{
			System.out.println(e);
			return "Error..." ;
		}
	}
}
