package org.rajalakshmi.webservices.database;

import javax.xml.ws.Endpoint;

public class StudEndPointPublisher {

public static void main(String[] args) {
Endpoint.publish("http://localhost:8090/WSDB/Student", 
new Student());
}

}
