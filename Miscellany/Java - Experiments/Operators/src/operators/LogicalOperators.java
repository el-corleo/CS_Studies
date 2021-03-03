/*
LOGICAL OPERATORS
	- And
	- Or (Inclusive vs. Exclusive)
	- Negation
*/
package operators;

public class LogicalOperators extends Operators
{
	public LogicalOperators(){ System.out.println("\nLOGICAL OPERATORS"); }
	
	public static void logOps()
	{
		System.out.println("i == 2 && i == 3 is " + (i == 2 && i == 3));
		System.out.println("i == 2 || i == 3 is " + (i == 2 || i == 3));
		System.out.println("!(i == 2 && i == 3) is " + (!(i == 2 && i == 3)));
		System.out.println("!(i == 2 || i == 3) is " + (!(i == 2 || i == 3)));
		System.out.println("XOR i == 2 ^ i == 3 is " + (i == 2 ^ i == 3));
		System.out.println("XOR i == 2 ^ d == 4.2 is " + (i == 2 ^ d == 4.2));
		System.out.println("XOR i == 2 and d == 4.2 is " + ((i == 2 || d == 4.2) && !(i == 2 && d == 4.2)));
		System.out.println("tf == (i == 2) is " + (tf == (i == 2)));
		System.out.println("!tf is " + !tf);
		//System.out.println("!s is " + !s);
	}
}