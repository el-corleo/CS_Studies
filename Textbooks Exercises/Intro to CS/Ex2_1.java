/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 2.1.1
*	Write a static method max3() that takes three int arguments and returns
*	the value of the largest one. Add an overloaded function that does the same thing
*	with three double values.
*	
*	Ex 2.1.2
*	Write a static method odd() that takes three boolean arguments and returns
*	true if an odd number of the argument values are true, and false otherwise.
*	
*	Ex 2.1.3
*	Write a static method majority() that takes three boolean arguments and
*	returns true if at least two of the argument values are true, and false otherwise.
*	Do not use an if statement.
*	
*	Ex 2.1.4
*	Write a static method eq() that takes two int arrays as arguments and returns true
*	if the arrays have the same length and all corresponding pairs of elements are equal,
*	and false otherwise.
*	
*	Ex 2.1.5
*	Write a static method areTriangular() that takes three double arguments
*	and returns true if they could be the sides of a triangle (none of them is greater
*	than or equal to the sum of the other two).
*	
*	Ex 2.1.6
*	Write a static method sigmoid() that takes a double argument x and returns the double 
*	value obtained from the formula 1 / (1 + e^-x ).
*	
*	Ex 2.1.7
*	Write a static method sqrt() that takes a double argument and returns the
*	square root of that number. Use Newton’s method (see Program 1.3.6) to compute
*	the result.
*	
*	Ex 2.1.9
*	Write a static method lg() that takes a double argument n and returns the
*	base-2 logarithm of n . You may use Java’s Math library.
*	
*	Ex 2.1.10
*	Write a static method lg() that takes an int argument n and returns the
*	largest integer not larger than the base-2 logarithm of n . Do not use the Math library.
* 	
*	Ex 2.1.11
*	Write a static method signum() that takes an int argument n and returns
*	-1 if n is less than 0, 0 if n is equal to 0, and +1 if n is greater than 0.
*
*	Ex 2.1.12
* 	Consider the static method duplicate() below.
*
*		public static String duplicate(String s)
*		{
*			String t = s + s;
*			return t;
*		}
*		
*	What does the following code fragment do?
*		
*		String s = "Hello";
*		s = duplicate(s);
*		String t = "Bye";
*		t = duplicate(duplicate(duplicate(t)));
*		StdOut.println(s + t);
*
*	Ex 2.1.14
*	The following checksum formula is widely used by banks and credit card
*	companies to validate legal account numbers:
*		
*		d_0 + f(d_1 ) + d_2 + f(d_3 ) + d_4 + f(d_5 ) + ... = 0 (mod 10)
*
*	The d_i are the decimal digits of the account number and f(d) is the sum of the
*	decimal digits of 2*d (for example, f(7) = 5 because 2 * 7 = 14 and 1 + 4 = 5). For
*	example, 17,327 is valid because 1 + 5 + 3 + 4 + 7 = 20, which is a multiple of
*	10. Implement the function f and write a program to take a 10-digit integer as a
*	command-line argument and print a valid 11-digit number with the given integer
*	as its first 10 digits and the checksum as the last digit.
*
*	Ex 2.1.16
*	Write a static method scale() that takes a double array as its argument
*	and has the side effect of scaling the array so that each element is between 0 and
*	1 (by subtracting the minimum value from each element and then dividing each
*	element by the difference between the minimum and maximum values). Use the
*	max() method defined in the table in the text, and write and use a matching min()
*	method.
*
*	Ex 2.1.17
*	Write a static method reverse() that takes an array of strings as its argument and 
*	returns a new array with the strings in reverse order. (Do not change the
*	order of the strings in the argument array.) Write a static method reverseInplace()
*	that takes an array of strings as its argument and produces the side effect of reversing 
*	the order of the strings in the argument array.
*
*	Ex 2.1.21
*	Write a static method multiply() that takes two square matrices of the
*	same dimension as arguments and produces their product (another square matrix
*	of that same dimension). Extra credit: Make your program work whenever the
*	number of columns in the first matrix is equal to the number of rows in the second
*	matrix.
*
*	Ex 2.1.22
*	Write a static method any() that takes a boolean array as its argument
*	and returns true if any of the elements in the array is true, and false otherwise.
*	Write a static method all() that takes an array of boolean values as its argument
*	and returns true if all of the elements in the array are true, and false otherwise.
*
*************************************************/
import java.util.Scanner;

public class Ex2_1
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// max3
		//ex_2_1_1();

		// odd num true
		//ex_2_1_2();
		
		// majority
		//ex_2_1_3();
		
		// equal arrays
		//ex_2_1_4();

		// are triangular
		//ex_2_1_5();

		// sigmoid
		//ex_2_1_6();
	
		// Newton-Rhapson sqrt
		//ex_2_1_7();
	
		// double lg() using Math lib
		//ex_2_1_9();

		// int lg() w/o using Math lib
		//ex_2_1_10();

		// signum()
		//ex_2_1_11();
		
		// What does this do?
		//ex_2_1_12();
		
		// luhn formula
		//ex_2_1_14();

		// normalize w/ max-min matching during input
		//ex_2_1_16();

		// reverse() & reverseInPlace() 
		//ex_2_1_17();

		// matrix multiplication 
		//ex_2_1_21();

		// any() & all()
		ex_2_1_22();
	}
	
	private static void ex_2_1_1()
	{
		int a = sc.nextInt();		
		int b = sc.nextInt();
		int c = sc.nextInt();
				
		System.out.println(max(a, b, c));

		double x = sc.nextDouble();		
		double y = sc.nextDouble();		
		double z = sc.nextDouble();
		
		System.out.println(max(x, y, z));
	}

	private static int max(int a, int b, int c)
	{
		if (a >= b && b >= c)	return a; 
		if (b >= a && a >= c)	return b; 
		return c; 
	}

	private static double max(double a, double b, double c)
	{
		if (a >= b && b >= c)	return a; 
		if (b >= a && a >= c)	return b; 
		return c; 
	}

	private static void ex_2_1_2()
	{	
		boolean[] args = { sc.nextBoolean(), sc.nextBoolean(), sc.nextBoolean() };
		int cnt = 0;
		for (boolean b : args)	if (b) cnt++; // check how many trues there are 

		if (cnt % 2 == 0)	System.out.print(false);
		else			System.out.print(true);
	}

	private static void ex_2_1_3()
	{
		boolean[] args = { sc.nextBoolean(), sc.nextBoolean(), sc.nextBoolean() };
		if ((args[0] && args[1]) || (args[1] && args[2]) || (args[0] && args[2]))	System.out.print(true);
		else										System.out.print(false);
	}

	private static void ex_2_1_4()
	{
		int num_trials = sc.nextInt();

		for (int i = 0; i < num_trials; i++)
		{
			int arr1_len = sc.nextInt();
			int arr2_len = sc.nextInt();
			int[] arr1 = new int[arr1_len];
			int[] arr2 = new int[arr2_len];

			populate_arr(arr1);
			populate_arr(arr2);

			System.out.println(eq(arr1, arr2));
		}
	}

	private static void populate_arr(int[] arr)
	{
		for (int i = 0; i < arr.length; i++)
			arr[i] = sc.nextInt();
	}

	private static boolean eq(int[] arr1, int[] arr2)
	{
		if (arr1.length != arr2.length)	return false;
		for (int i = 0; i < arr1.length; i++)
			if (arr1[i] != arr2[i])	return false;
		return true;
	}

	private static void ex_2_1_5()
	{
		double[] args = { sc.nextDouble(), sc.nextDouble(), sc.nextDouble() };
		for (int i = 0; i < args.length; i++)
			if (args[i]+args[(i+1)%args.length] < args[(i+2)%args.length])	{ System.out.println(false); return; }
		System.out.println(true);
	}

	private static void ex_2_1_6()
	{
		double x = sc.nextDouble();
		System.out.println(1 / (1 + Math.exp(-x)));
	}

	private static void ex_2_1_7()
	{
		double EPSILON = 1e-15;
		double num = sc.nextDouble();
		double guess = num;
		while (Math.abs(guess - (num/guess)) > EPSILON * guess)	{ guess = ((num/guess) + guess) / 2.0; }
		
		System.out.println(guess);
	}

	private static void ex_2_1_9()
	{
		double n = sc.nextDouble();
		double result = Math.log(n)/Math.log(2);
		System.out.println(result);
	}	

	private static void ex_2_1_10()
	{
		int n = sc.nextInt();
		// return the largest integer not larger than the base-2 logarithm of n
		int tot = 1;
		int exp = 0;
		while (tot < n)
		{
			if ((tot *= 2) > n)	break;	// if another iteration would push it beyond the limit, break
			exp++;				// else, increment the exponent counter
		}
		System.out.printf("Largest int not larger than log_2(n) = %d", exp);
	}

	private static void ex_2_1_11()
	{
		int n = sc.nextInt();

		if (n < 0)	System.out.println(-1);
		else if (n > 0)	System.out.println(+1);
		else		System.out.println(0);
	}
	
	private static void ex_2_1_12()
	{
		String s = "Hello";
		s = duplicate(s);
		String t = "Bye";
		t = duplicate(duplicate(duplicate(t)));
		System.out.println((s + t).equals("HelloHelloByeByeByeByeByeByeByeBye"));
	}
	
	private static String duplicate(String s)
	{
		String t = s + s;
		return t;
	}
	
	private static void ex_2_1_14()
	{
		long ten_dig_int = sc.nextLong();
		long cp_ten_dig = ten_dig_int;
		int dbl_cnt = 0;
		int checksum = 0;
		while (cp_ten_dig > 0)
		{
			if (dbl_cnt++ % 2 == 0)	checksum += dbl((int) (cp_ten_dig % 10));
			else					checksum += cp_ten_dig % 10;
			cp_ten_dig /= 10;
		}
		int off_by = checksum % 10;
		long new_ten_dig = (ten_dig_int * 10) + (10 - off_by);
		System.out.println(new_ten_dig);
	}
	
	private static int dbl(int d)
	{
		d *= 2;
		if (d < 10)	return d;
		else		return (d % 10) + (d % 100);
	}

	private static void ex_2_1_16()
	{
		int size = sc.nextInt();
		double min = Double.MAX_VALUE, max = Double.MIN_VALUE;
		double[] arr = new double[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = sc.nextDouble();
			min = (arr[i] < min) ? arr[i] : min;
			max = (arr[i] > max) ? arr[i] : max;
		 }
		// print out original array
		for (double d : arr) { System.out.print(d + " "); }
		System.out.println();
		// normalize
		scale(arr, min, max);
		// print out altered array
		for (double d : arr) { System.out.print(d + " "); }	
		System.out.println();
	}
	
	private static void scale(double[] arr, double min, double max)
	{
		for (int i = 0; i < arr.length; i++)	{ arr[i] = (arr[i] - min) / (max - min); }
	}

	private static void ex_2_1_17()
	{
		String[] arr_1 = { "a", "b", "c" };
		String[] arr_2 = reverse(arr_1);
		for (int i = 0; i < arr_1.length; i++)
		{
			System.out.println("ARR_1: " + arr_1[i]);
			System.out.println("ARR_2: " + arr_2[i]);
		}

		reverseInPlace(arr_1);		
		for (int i = 0; i < arr_1.length; i++)
			System.out.print(arr_1[i] + " ");
	}

	private static String[] reverse(String[] arr)
	{
		String[] arr_rev = new String[arr.length];
		for(int i = 0; i < arr.length; i++) { arr_rev[arr.length-1-i] = arr[i]; }
		return arr_rev; 
	}

	private static void reverseInPlace(String[] arr)
	{
		for(int i = 0; i < arr.length/2; i++)
		{
			String tmp_str = arr[i];
			arr[i] = arr[arr.length-1-i];
			arr[arr.length-1-i] = tmp_str;
		}
	}

	private static void ex_2_1_21()
	{
		// a x b 
		//int[][] mat_1 = {{1, 2, 3}, {4, 5, 6}}; 
		int[][] mat_1 = {{3, 4, 2}}; 
		// b x c
		//int[][] mat_2 = {{7, 8}, {9, 10}, {11, 12}}; 
		int[][] mat_2 = {{13, 9, 7, 15}, {8, 7, 4, 6}, {6, 4, 0, 3}}; 

		int[][] mat_3 = multiply(mat_1, mat_2);

		if (mat_3 == null)	{ System.out.println("Invalid Input"); return; }

		for(int r = 0; r < mat_3.length; r++)
		{
			for (int c = 0; c < mat_3[0].length; c++) { System.out.print(mat_3[r][c] + " "); }
			System.out.println();
		}
	}

	private static int[][] multiply(int[][] mat_1, int[][] mat_2)
	{
		// check for invalid matrices
		if (mat_1[0].length != mat_2.length)	return null;

		int[][] mat_result = new int[mat_1.length][mat_2[0].length];
	
		// mat_1's r by each of mat_2's c
		// BUGGY
		for (int r = 0; r < mat_1.length; r++)
		{
			for (int c = 0; c < mat_2[0].length; c++)
			{
				int sum = 0;
				for (int x = 0; x < mat_1[0].length; x++)
					sum += mat_1[r][x] * mat_2[x][c];
				mat_result[r][c] = sum;
			}
		}

		return mat_result;
	}

	private static void ex_2_1_22()
	{
		boolean[] arr_1 = { true, true };
		boolean[] arr_2 = { true, false };
		boolean[] arr_3 = { false, true };
		boolean[] arr_4 = { false, false };
		
		// returns true if any element is true; false otherwise
		System.out.println(any(arr_4));
		// returns true if all elements are true; false otherwise
		System.out.println(all(arr_4));

	}

	private static boolean any(boolean[] arr)
	{
		for (int i = 0; i < arr.length; i++) if (arr[i]) return true;
		return false;
	}	

	private static boolean all(boolean[] arr)
	{
		for (int i = 0; i < arr.length; i++) if (!arr[i]) return false;
		return true;
	}
}
