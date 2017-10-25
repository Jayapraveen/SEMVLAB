import java.io.IOException;
import java.io.PrintWriter;
import java.sql.DriverManager;
import java.sql.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class StudentDetails
 */
@WebServlet("/StudentDetails")
public class StudentDetails extends HttpServlet {
	private static final long serialVersionUID = 1L;
	Connection connection = null ;

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, 
HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String connectionURL = "jdbc:mysql://localhost:3306/student";
			connection = DriverManager.getConnection(connectionURL, "root", "vijay");
		}
		catch(ClassNotFoundException e) {
			out.println(e);
		}
		catch(Exception e) {
			out.println(e);
		}
 		String mrollno = request.getParameter("rollno") ;
 		try {
 			PreparedStatement ps = connection.prepareStatement("select * from student where rollno = ?") ;
			ps.setString(1, mrollno) ;
			ResultSet rs = ps.executeQuery() ;
 
			out.println("<html>");
			out.println("<body>");
			out.println("<head>");
			out.println("<title>Student Details</title>");
			out.println("</head>");
			out.println("<body>");
			out.println("<center><b>Student Details</b></center>");
			out.println("<table border = 1 align=center>");
 
			while(rs.next())
			{
				out.println("<tr><td>Roll No. : </td>");
				out.println("<td>" + rs.getString("rollno") + "</td></tr>");
				out.println("<tr><td>Name : </td>");
				out.println("<td>" + rs.getString("sname") + "</td></tr>");
				out.println("<tr><td>Branch : </td>");
				out.println("<td>" + rs.getString("Branch") +"</td></tr>");
				out.println("<tr><td>10th Mark : </td>");
				out.println("<td>" + rs.getString("sslc") + "</td></tr>");
				out.println("<tr><td>12th Mark : </td>");
				out.println("<td>" + rs.getString("hsc") + "</td></tr>");
			}
			out.println("</table>");
			out.println("</body>");
			out.println("</html>");
 		}
 		catch (Exception e){
 			out.println(e);
 		}
	}
}
