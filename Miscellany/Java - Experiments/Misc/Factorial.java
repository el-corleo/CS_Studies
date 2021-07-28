public class Factorial
{
	public static void main(String[] args)
	{
		int fact = Integer.parseInt(args[0]);
		
		if (fact >= 0)
			System.out.println("Factorial of " + fact + " is " + factorial(fact));
		else
			System.out.println("Can't do that you cheeky bastard!");

		if (fact > 12)
			System.out.println("Factorial of " + fact + " is " + factorialLong((long) fact));
	}
	
	// @ fact = 13 is buggy due to bit overflow
	private static int factorial(int fact)
	{
		// termination condition
		if (fact == 0 || fact == 1)
			return 1;
		else
			return fact * factorial(fact - 1);
	}
	
	// @ fact = 21 is buggy due to bit overflow
	private static long factorialLong(long fact)
	{
		// termination condition
		if (fact == 0 || fact == 1)
			return 1;
		else
			return fact * factorialLong(fact - 1);
	}
}