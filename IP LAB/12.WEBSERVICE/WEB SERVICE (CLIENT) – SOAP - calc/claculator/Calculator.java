package org.rajalakshmi.webservices.calc;

import javax.jws.WebService;

@WebService

public class Calculator {	
	
	public int add(int a, int b)
	{
		return (a + b);
	}
	
	public int sub(int a, int b)
	{
		return (a - b);
	}
}
