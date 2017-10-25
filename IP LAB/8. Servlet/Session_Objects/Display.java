import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class Display
 */
@WebServlet("/Display")
public class Display extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, 
HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, 
HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try{  
	        response.setContentType("text/html");  
	        PrintWriter out = response.getWriter();  
	          
	        HttpSession session=request.getSession(false);  
	        String name = 
(String)session.getAttribute("uname");  
	        out.print("Hello " + name);  
	        out.close();  
		}
		catch(Exception e){
			System.out.println(e);
		}  
	}

}
