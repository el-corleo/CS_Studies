/*
Arithmetic operators
	- Addition & Concatenation
	- Subtraction
	- Multiplication & Division
	- Modulo
*/
package operators;

public class ArithmeticOperators extends Operators
{
	public ArithmeticOperators(){ System.out.println("\nARITHMETIC OPERATORS"); }
	
	// Addition & Concatenation Operators
	public static void addOps()
	{
		System.out.println("Addition & Concatenation");
		System.out.println("i + 2 = " + (i + 2));
		System.out.println("d + 2 = " + (d + 2));
		System.out.println("d + i = " + (d + i));
		//System.out.println(tf + 2);
		System.out.println("s + 2 = " + (s + 2));
		System.out.println("s + 2 + 5 = " + (s + 2 + 5));
		System.out.println("2 + 5 + s = " + (2 + 5 + s));
	}
	
	// Subtraction Operators
	public static void subOps()
	{
		System.out.println("Subtraction");
		System.out.println("i - 4 = " + (i - 4));
		System.out.println("d - 4 = " + (d - 4));
		System.out.println("d - i = " + (d - i));
		//System.out.println(tf - 2);
		//System.out.println(s - 2);
		
	}
	
	// Multiplication & Division
	public static void multDivOps()
	{	
		System.out.println("Multiplication & Division");
		System.out.println("i * 5 = " + (i * 5));
		System.out.println("d * 5 = " + (d * 5));
		System.out.println("i * d = " + (i * d));
		//System.out.println(tf * 2);
		//System.out.println(s * 2);
		System.out.println("i / 5 = " + (i / 5));
		System.out.println("d / 5 = " + (d / 5));
		System.out.println("i / d = " + (i / d));
		//System.out.println(tf / 2);
		//System.out.println(s / 2);
	}
	
	// Modulo
	public static void modOps()
	{
		System.out.println("Modulo");
		System.out.println("i % 5 = " + (i % 5));
		System.out.println("5 % i = " + (5 % i));
		System.out.println("d % 5 = " + (d % 5));
		System.out.println("5 % d = " + (5 % d));
		System.out.println("i % d = " + (i % d));
		System.out.println("d % i = " + (d % i));
		//System.out.println(tf % 2);
		//System.out.println(s % 2);
	}
}