package org.rajalakshmi.webservices.calc.client;

import org.rajalakshmi.webservices.calc.Calculator;
import org.rajalakshmi.webservices.calc.CalculatorService;

public class CalcClient {

public static void main(String[] args) {
	int a = 10;
	int b = 20;
	CalculatorService calcService = new CalculatorService();
	Calculator calc = calcService.getCalculatorPort();
	System.out.println(a + " + " + b + " = " + calc.add(a, b));
	System.out.println(a + " - " + b + " = " + calc.sub(a, b));
}

}
