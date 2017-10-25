import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class PostParam
 */
@WebServlet("/PostParam")
public class PostParam extends HttpServlet {
private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#service(HttpServletRequest request, 
HttpServletResponse response)
	 */
protected void service(HttpServletRequest request, 
HttpServletResponse response) throws ServletException, 
IOException {
// TODO Auto-generated method stub
		PrintWriter pw = response.getWriter();
		Enumeration e = request.getParameterNames();
		while(e.hasMoreElements()) {
			String pname = (String)e.nextElement();
			pw.print(pname + " = ");
			String pvalue = request.getParameter(pname);
			pw.println(pvalue);
		}
		pw.close();
	}
}
