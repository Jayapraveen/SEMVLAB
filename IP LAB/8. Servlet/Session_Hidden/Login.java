import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Login
 */
@WebServlet("/Login")
public class Login extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, 
HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, 
HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try{  
			response.setContentType("text/html");  
	        PrintWriter out = response.getWriter();  
	          
	        String name = request.getParameter("uname");  
	        out.print("Welcome " + name);  
	          
	        //creating form that have invisible textfield  
	        out.print("<form method = 'post' action = 'Display'>");  
	        out.print("<input type = 'hidden' name = 'uname' value = '"+ name +"'>");  
	        out.print("<input type = 'submit' value = 'Display'>");  
	        out.print("</form>");  
	        out.close();  
		}
		catch(Exception e){
			System.out.println(e);
		}  
	}
}
