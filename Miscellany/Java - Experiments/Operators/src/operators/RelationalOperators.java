/*
Relational Operators
	- Less than & Less than or equal to
	- Greater than & Greater than or equal to
*/
package operators;

public class RelationalOperators extends Operators
{
	public RelationalOperators(){ System.out.println("\nRELATIONAL OPERATORS"); }

	// Less than & Less than or equal to 
	public static void ltOps()
	{
		System.out.println("Less than & Less than or equal to");
		System.out.println("i < 2 is " + (i < 2));
		System.out.println("i <= 2 is " + (i <= 2));
		System.out.println("d < 2 is " + (d < 2));
		System.out.println("d <= 2 is " + (d <= 2));
		//System.out.println("tf < 2 is " + (tf < 2));
		//System.out.println("s < 2 is " + (s < 2));
		String s2 = "a";
		//System.out.println("s < s2 is " + (s < s2));
	}

	// Greater than & Greater than or equal to 
	public static void gtOps()
	{
		System.out.println("Greater than & Greater than or equal to");
		System.out.println("i > 2 is... OH, IT'S ALL THE SAME AS LESS THAN, BUT OPPOSITE!");
		System.out.println("Don't believe? Try for yourselves.");
	}
}