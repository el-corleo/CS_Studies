/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 1.2.2
*	theta = args[0]
*	sin(theta)^2+cos(theta)^2 = 1
*
*	Ex 1.2.5
*	XOR
*
*	Ex 1.2.7
*	Auto conversion from int to string for printing
*
*	Ex 1.2.9
*	printing chars
*
*	Ex 1.2.10
*	int overflow
*
*	Ex 1.2.11
*	double
*
*	Ex 1.2.13
*	floating point imprecision
*
*	Ex 1.2.14
*	x = args[1], y = args[2]
*	Write a program that takes two positive integers as command-line
*	arguments and prints true if either evenly divides the other.
*
*	Ex 1.2.15
*	sides[0] = args[3], sides[1] = args[4], sides[2] = args[5], 
*	Write a program that takes three positive integers as command-line
*	arguments and prints false if any one of them is greater than or 
*	equal to the sum of the other two and true otherwise.
*
*	Ex 1.2.16
*	operator precedence
*	unexpected results when using
*		double force = G * mass1 * mass2 / r * r;
*	to calculate force
*
*	Ex 1.2.18
*	Write a program that takes two integer command-line
*	arguments x and y and prints the Euclidean distance
*	from the point (x, y) to the origin (0, 0).
*
*	Ex 1.2.19
*	Write a program w/ two int inputs that prints a random
*	number with their range, inclusive
*
*	Ex 1.2.23
*	Write a program that takes two integer command-line arguments m and
*	d and prints true if day d of month m is between 3/20 and 6/20, false otherwise.
*
*	Ex 1.2.26
*	Write a program that converts from Cartesian
* 	to polar coordinates. Your program should accept two double commandline
* 	arguments x and y and print the polar coordinates r and theta. Use the
* 	method Math.atan2(y, x) to compute the arctangent value of y/x that is
* 	in the range from -pi to pi.
*
*	Ex 1.2.34 
*	Write a program that takes three integer command-line arguments
*	and prints them in ascending order. Use Math.min() and Math.max().
*
*	Ex 1.2.35
*	Write a program to print the instructions for drawing the
*	dragon curves of order 0 through 5.
*************************************************/
import java.util.Scanner;

public class Ex1_2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Ex 1.2.2");
		double theta = sc.nextDouble();
		System.out.println(Math.sin(theta)*Math.sin(theta)+Math.cos(theta)*Math.cos(theta));
		
		// XOR operator for booleans
		System.out.println("\nEx 1.2.5");
		System.out.println(true ^ true);
		System.out.println(false ^ true);
		System.out.println(true ^ false);
		System.out.println(false ^ false);
		
		//auto conversion from int to String
		System.out.println("\nEx 1.2.7");
		System.out.println(2 + "bc");		//2bc
		System.out.println(2 + 3 + "bc");	//5bc
		System.out.println((2+3) + "bc");	//5bc
		System.out.println("bc" + (2+3));	//bc5
		System.out.println("bc" + 2 + 3);	//bc23
		
		//char
		System.out.println("\nEx 1.2.9");
		System.out.println('b'); 				//b
		System.out.println('b' + 'c');			//197
		System.out.println((char) ('a' + 4));	//e

		//int overflow
		System.out.println("\nEx 1.2.10");
		int i = 2147483647;
		System.out.println(i);		//2147483647
		System.out.println(i+1);	//-2147483648
		System.out.println(2-i);	//-2147483645
		System.out.println(-2-i);	//2147483647
		System.out.println(2*i);	//-2
		System.out.println(4*i);	//-4

		//double
		System.out.println("\nEx 1.2.11");
		double d = 3.14159;
		System.out.println(d);				//3.14159
		System.out.println(d+1);			//4.14159
		System.out.println(8/(int) d);		//2
		System.out.println(8/d);			//2.5464812403910124
		System.out.println((int) (8/d));	//2

		//floating point imprecision
		System.out.println("\nEx 1.2.13");
		System.out.println(Math.sqrt(2) * Math.sqrt(2) == 2);	//false
		
		// input and test
		System.out.println("\nEx 1.2.14");
		int x = sc.nextInt();
		int y = sc.nextInt();
		if ((x%y == 0) || (y%x == 0))
			System.out.println(true);
		
		// input and test
		System.out.println("\nEx 1.2.15");
		int[] sides = {sc.nextInt(), sc.nextInt(), sc.nextInt()};
		boolean is_triangle = true;
		for (int ind = 0; ind < 3; ind++)
			if ((sides[(ind+1)%3]+sides[(ind+2)%3])<sides[ind])
				is_triangle = false;
		System.out.println(is_triangle);
		
		// operator precedence
		System.out.println("\nEx 1.2.16");
		final double G = 9.18;
		double mass1 = 120.1;
		double mass2 = 120.2;
		double r = 10.5;
		System.out.println("wrong: " + (G * mass1 * mass2 / r * r));
		System.out.println("right: " + ((G * mass1 * mass2) / (r * r)));

		// Euclidean dist from origin
		System.out.println("\nEx 1.2.18");
		x = sc.nextInt();
		y = sc.nextInt();
		System.out.println(Math.sqrt(x*x+y*y));
		
		// Random num within range, inclusive
		System.out.println("\nEx 1.2.19");
		int lo = 0;
		int hi = 0;
		while (hi-lo <= 0)	{ lo = sc.nextInt(); hi = sc.nextInt(); }
		int range = hi - lo + 1;
		System.out.println(Math.random()*range+lo);
		
		// Check date
		System.out.println("\nEx 1.2.23");
		int m = -1;
		int day = -1;
		while (m < 1 || m > 12)		m = sc.nextInt();
		while (day < 1 || day > 31)	day = sc.nextInt();
		switch (m)
		{
			case 3:
				if (day < 20)	System.out.println(false);
				else			System.out.println(true);
				break;
			case 4:
				if (day > 30)	System.out.println("INVLAID");
				else			System.out.println(true);
				break;
			case 5:
				System.out.println(true);
				break;
			case 6:
				if (day > 20)	System.out.println(false);
				else			System.out.println(true);
				break;
			default:
				System.out.println(false);
		}
		
		// Cartesian to Polar coords
		System.out.println("\nEx 1.2.26");
		double x_p = sc.nextDouble();
		double y_p = sc.nextDouble();
		r = Math.sqrt(x_p*x_p + y_p*y_p);
		theta = Math.atan2(y_p, x_p);
		System.out.println("Radius=" + r + " Theta=" + theta);
		
		// Ascending order
		System.out.println("\nEx 1.2.34");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int[] rank = { Math.max(Math.max(a,b),c), (a==b && a==c) ? a : 0, Math.min(Math.min(a,b),c)};
		if (rank[0] != a && rank[2] != a)	rank[1] = a;
		if (rank[0] != b && rank[2] != b)	rank[1] = b;
		if (rank[0] != c && rank[2] != c)	rank[1] = c;
		System.out.println("\n"+rank[0]+" "+rank[1]+" "+rank[2]);

		// Dragon curves
		System.out.println("\nEx 1.2.35");
		int order = sc.nextInt();
		while (order < 1 || order > 15)	order = sc.nextInt();
		System.out.println(build_string(order));
	}
	
	public static String build_string(int N)
	{
		String result = "F";
		for (int i = 0; i < N; i++)
		{
			String rev_str = "";
			for (int j = result.length()-1; j >= 0; j--)
			{
				if (result.charAt(j) == 'F') 		rev_str += "F";
				else if (result.charAt(j) == 'L')	rev_str += "R";
				else								rev_str += "L";
			}
			
			result += "L" + rev_str;
		}
		
		return result;
	}
}

