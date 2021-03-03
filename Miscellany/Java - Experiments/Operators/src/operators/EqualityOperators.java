/*
Primitive Equality Operators
	- Equality
	- Non-equality
*/
package operators;

public class EqualityOperators extends Operators
{
	public EqualityOperators(){	System.out.println("\nEQUALITY OPERATORS"); }
	
	// Equality
	public static void eqOps()
	{
		System.out.println("Equals");
		System.out.println("i == 2 is " + (i == 2));
		System.out.println("d == 2 is " + (d == 2));
		System.out.println("d == i is " + (d == i));
		System.out.println("(d - 2.2) == i is " + ((d - 2.2) == i));
		System.out.println("tf is " + tf);
		System.out.println("tf == false is " + (tf == false));
		String s2 = new String("Words, just words--oh, and punctuation, too!");
		System.out.println("s == s2 " + (s == s2));
		s2 = s;
		System.out.println("s == s2 " + (s == s2));
		s = "Bobo McGee";
		System.out.println("s is " + (s));
		System.out.println("s2 is " + (s2));
	}
	
	// Non-equality
	public static void nonEqOps()
	{
		System.out.println("Does Not Equal");
		System.out.println("i != 2 is " + (i != 2));
		System.out.println("d != 2 is " + (d != 2));
		System.out.println("d != i is " + (d != i));
		System.out.println("(d - 2.2) != i is " + ((d - 2.2) != i));
		System.out.println("!tf is " + !tf);
		System.out.println("tf != false is " + (tf != false));
		String s2 = "Words, just words--oh, and punctuation, too!"; // diff declaration
		System.out.println("s != s2 " + (s != s2));
		s2 = s;
		System.out.println("s != s2 " + (s != s2));
		s = "Bobo McGee";
		System.out.println("s is " + (s));
		System.out.println("s2 is " + (s2));
	}
}