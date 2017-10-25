package org.rajalakshmi.webservices.calc;

import javax.xml.ws.Endpoint;

public class CalcEndPointPublisher {

	public static void main(String[] args) {

	Endpoint.publish("http://localhost:8080/CalcWS/Calculator", 
new Calculator());
	}

}
