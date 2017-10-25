

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class HitCount
 */
@WebServlet("/HitCount")
public class HitCount extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private int hitCount; 
    /**
     * @see HttpServlet#HttpServlet()
     */
    public HitCount() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    public void init(ServletConfig config) throws 
    ServletException {
    		// TODO Auto-generated method stub
    		// Reset hit counter.
    		hitCount = 0;
    	}


	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
    	// This method executes whenever the servlet is hit 
    	// increment hitCount 
    	hitCount++; 
    	PrintWriter out = response.getWriter();
    	String title = "Total Number of Hits";
    	out.println("<html><body>"); 
    	out.println("<h1>" + title + "</h1>");
    	out.println("<h2>" + hitCount + "</h2>");
    	out.println("</body></html>");

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
}
