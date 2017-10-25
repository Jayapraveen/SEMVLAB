<%@ page language="java" contentType="text/html; 
charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">

<html>

<head>

<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">

<title>Get Name</title>

</head>

<body>

<%

String a[] = new String[62];
	String hint = new String();
	
	// Array with names
	
a[0] = "Rakesh Kumar B";
	a[1] = "Rama S";
	a[2] = "Revathy V";
	a[3] = "Sreyesh S";
	a[4] = "Sai Krishna K K";
	a[5] = "Sangeetha N";
	a[6] = "Sangita S";
	a[7] = "Shankar R";
	a[8] = "Saranya S";
	a[9] = "Sathya Preetha S";
	a[10] = "Sharafath Ahmed S";
	a[11] = "Sharmila S";
	a[12] = "Shobana M";
	a[13] = "Shravanthi S";
	a[14] = "Shyam S";
	a[15] = "Sivaram Subramanian S S";
	a[16] = "Sowmya M S";
	a[17] = "Sredhar S";
	a[18] = "Sridhar N";
	a[19] = "Srikanth G";
	a[20] = "Sriram N S";
	a[21] = "Sriram S";
	a[22] = "Sriram V";
	a[23] = "Sriranjani J";
	a[24] = "Srivarshini S P";
	a[25] = "Subhalakshmi R";
	a[26] = "Suchithra B";
	a[27] = "Sujatha V";
	a[28] = "Sumit Kumar N";
	a[29] = "Sundar S";
	a[30] = "Sundari Meenakshi S";
	a[31] = "Surandranath G";
	a[32] = "Sureka Devi R";
	a[33] = "Swaroop M";
	a[34] = "Swathi M";
	a[35] = "Swathi K M";
	a[36] = "Swathi R";
	a[37] = "Swathishree K";
	a[38] = "Syed Abdul Kaleem E";
	a[39] = "Thamizhkaavya M";
	a[40] = "Thilak Raj S";
	a[41] = "Thirumavalavan P";
	a[42] = "Udhaya Kumar A";
	a[43] = "Varshaa B";
	a[44] = "Varshitha K";
	a[45] = "Veda Vinothini E";
	a[46] = "Rahul Janardhanan";
	a[47] = "Venkateswari S";
	a[48] = "Vidhya Shree.V";
	a[49] = "Vignesh G";
	a[50] = "Vijaya Priya R";
	a[51] = "Vijayanarayanan V";
	a[52] = "Vinitha K";
	a[53] = "Yashwanth Rao P S R";
	a[54] = "Yogesh R";
	a[55] = "Adithya Sriram";
	a[56] = "Ramya V";
	a[57] = "Santhosh Kumar";
	a[58] = "Abishek S";
	a[59] = "Nagarjun Y";
	a[60] = "Hemavathi P";
	a[61] = "Prakash C";

// get the q parameter from URL
	String q = request.getParameter("q").toUpperCase();
 
	// lookup all hints from array if $q is different from "" 
	if (q.length()>0) {
		hint="";
		for(int i=0; i<a.length;i++) {
			if(a[i].length() >= q.length()) {
		  		if (q.equals(a[i].toUpperCase().substring(
0, q.length()))) {
		    	 	if (hint.equals("")) {
		       		hint = a[i];
} 
		       	else {
		       		hint = hint + ", " + a[i];
}
}
		  }
}
}
		
	// Output "no suggestion" if no hint was found or 
// output correct values 
if(hint.equals(""))
		out.println("no suggestion");
else
		out.println(hint);
%>

</body>
</html>
