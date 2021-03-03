/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 2.3.1
*	What happens if you call factorial() with a negative value of n?
*	With a large value of, say, 35?
*		[- if n < 0, then it goes into an inifinite loop and ends in stackoverflow]
*		[- if n is large, then long overflow; if n > 65, then 0, until it reaches 39525]
*
*	Ex 2.3.3
*	Give the sequence of integers printed by a call to ex233(6):
*		public static void ex233(int n)
*		{
*			if (n <= 0) return;
*			StdOut.println(n);
*			ex233(n-2);
*			ex233(n-3);
*			StdOut.println(n);
*		}
*
*	Ex 2.3.4
*	Give the value of ex234(6) :
*		public static String ex234(int n)
*		{
*			if (n <= 0) return "";
*			return ex234(n-3) + n + ex234(n-2) + n;
*		}
*	[Note: it returns a String, not an int...]
*
*	Ex 2.3.8
*	Consider the following recursive function:
*		public static int mystery(int a, int b)
*		{
*			if (b == 0) return 0;
*			if (b % 2 == 0) return mystery(a+a, b/2);
*			return mystery(a+a, b/2) + a;
*		}
*
*	What are the values of mystery(2, 25) and mystery(3, 11)? Given positive
*	integers a and b, describe what value mystery(a, b) computes. Then answer the
*	same question, but replace + with * and return 0 with return 1.
*
*	Ex 2.3.15
*	Binary representation. Write a program that takes a positive integer n (in
*	decimal) as a command-line argument and prints its binary representation. Recall,
*	in Program 1.3.7, that we used the method of subtracting out powers of 2. Now, use
*	the following simpler method: repeatedly divide 2 into n and read the remainders
*	backward. First, write a while loop to carry out this computation and print the bits
*	in the wrong order. Then, use recursion to print the bits in the correct order.
*
*	Ex 2.3.17
*	Permutations. Write a program Permutations that takes an integer command-line argument
*	n and prints all n! permutations of the n letters starting at a (assume that n is no
*	greater than 26). A permutation of n elements is one of the n! possible orderings of the 
*	elements. As an example, when n = 3, you should get the following output (but do not 
*	worry about the order in which you enumerate them):
*		bca cba cab acb bac abc
*
*	Ex 2.3.18
*	Permutations of size k. Modify Permutations from the previous exercise so that it takes 
*	two command-line arguments n and k, and prints all P(n, k) = n!/ (n-k)! permutations 
*	that contain exactly k of the n elements. Below is the desired output when k = 2 and n = 4 
*	(again, do not worry about the order):
*		ab ac ad ba bc bd ca cb cd da db dc
*
*	Ex 2.3.21
*	Hamming distance. The Hamming distance between two bit strings of length n is equal to 
*	the number of bits in which the two strings differ. Write a program that reads in an 
*	integer k and a bit string s from the command line, and prints all bit strings that have 
*	Hamming distance at most k from s. For example, if k is 2 and s is 0000, then your program 
*	should print:
*		0011 0101 0110 1001 1010 1100
*	Hint : Choose k of the bits in s to flip.
*
*************************************************/
import java.util.Scanner;

public class Ex2_3
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// factorial
		//ex_2_3_1();

		// recursion trace
		//ex_2_3_3();

		// recursion trace rd. 2
		//ex_2_3_4();

		// more recursion
		//ex_2_3_8();

		// binary representation
		//ex_2_3_15();
		
		// permute alpha up to n
		//ex_2_3_17();
		
		// permute k alpha from n
		//ex_2_3_18();
		
		// hamming distance
		ex_2_3_21();
	}

	private static void ex_2_3_1()
	{
		// negative
		//System.out.println(factorial(-3));
		// large
		for (int i = 60; i < 1000000000; i++)
			System.out.println(i + ": " + factorial(i));
	}

	private static long factorial(int n)
	{
		if (n == 1)	return 1;
		return n * factorial(n-1);
	}

	private static void ex_2_3_3()
	{
		ex233(6);
	}

	private static void ex233(int n)
	{
		if (n <= 0) return;
		System.out.println(n);
		ex233(n-2);
		ex233(n-3);
		System.out.println(n);
	}

	private static void ex_2_3_4()
	{
		System.out.println(ex234(6));
	}

	/*
		ex234(3) + 6 + ex234(4) + 6
		ex234(0) + 3 + ex234(1) + 3 + 6 + ex234(1) + 4 + ex234(2) + 4 + 6
		etc.
		311361142246	
	*/
	private static String ex234(int n)
	{
		if (n <= 0) return "";
		return ex234(n-3) + n + ex234(n-2) + n;
	}

	private static void ex_2_3_8()
	{
		System.out.println(mystery(2, 25));
		System.out.println(mystery(3, 11));
		System.out.println(mystery_two(2, 25));
		System.out.println(mystery_two(3, 11));
		
	}
	
	/*
		2, 25 -> 50
		return (4, 12) + 2
		return (8, 6)
		return (16, 3)
		return (32, 1) + 16
		return 32

		3, 11 -> 33
		return (6, 5) + 3
		return (12, 2) + 6
		return (24, 1)
		return 24
	*/
	private static int mystery(int a, int b)
	{
		if (b == 0) return 0;
		if (b % 2 == 0) return mystery(a+a, b/2);
		return mystery(a+a, b/2) + a;
	}
	
	private static int mystery_two(int a, int b)
	{
		if (b == 0) return 1;
		if (b % 2 == 0) return mystery(a*a, b/2);
		return mystery(a*a, b/2) * a;
	}

	private static void ex_2_3_15()
	{
		int n = sc.nextInt();

		String bin_equivalent = "";

		while(n > 0) { bin_equivalent += n%2; n /= 2; }

		// reverse order
		System.out.println(bin_equivalent);

		// correct order
		reverse_str(bin_equivalent);
		System.out.println();
	}

	private static void reverse_str(String s)
	{
		if (s.length() == 0)	return;
		reverse_str(s.substring(1));
		System.out.print(s.substring(0,1));

	}

	private static void ex_2_3_17()
	{
		// highest letter
		// practical limit is n=10, any larger and heap runs out or integer overflow on fact
		int n = sc.nextInt();
		
		// create collection of useable letters
		char[] letters = new char[n];
		for (int i = 0; i < n; i++) { letters[i] = (char) ('a' + i); }

		String[] perms = get_perms("", letters, 0);

		for (String s : perms)	System.out.println(s);
	}

	// k parameter allows for P(n,k), but k is actually n-k
	private static String[] get_perms(String head, char[] letters, int k)
	{
		// base case if letters array is of size 0
		// returns head, which is a string built up from the letters of the array
		// 	on the way down the recursive call stack
		if (letters.length == k)	return new String[]{ head }; 

		// allocate memory for an array of appropriate length
		// 	i.e., letters.length!
		String[] perms = new String[fact(letters.length, k)];
		// indexer for place in permutation array
		int ind = 0;
		// for each character in the array, add it to the head and get the permutations
		//	of the array minus that character
		for (int i = 0; i < letters.length; i++)
		{
			// the recursive call with new extended head and minus the letter added to the head
			String[] char_perms = get_perms(""+head+letters[i], remove_head(letters[i], letters), k);
			// add to list of perms for all characters in letters array
			for (String s : char_perms)	perms[ind++] = s;
		}
		return perms;
	}

	// remove specific character from letters array, return new array
	private static char[] remove_head(char head, char[] letters)
	{
		char[] new_arr = new char[letters.length-1];
		int ind = 0;
		for (char c : letters)
			if (c != head)	new_arr[ind++] = c;
		return new_arr;
	}

	// calculate factorial
	private static int fact(int n, int k)
	{
		if (n < 2)	return 1;
		else if (n==k)	return 1;
		else		return n * fact(n-1, k);
	}

	private static void ex_2_3_18()
	{
		int n = sc.nextInt();
		int k = sc.nextInt();

		// create collection of useable letters
		char[] letters = new char[n];
		for (int i = 0; i < n; i++) { letters[i] = (char) ('a' + i); }

		String[] perms = get_perms("", letters, n-k);

		for (String s : perms)	System.out.println(s);
	}

	/*
	Hamming distance. The Hamming distance between two bit strings of length n is equal to 
*	the number of bits in which the two strings differ. Write a program that reads in an 
*	integer k and a bit string s from the command line, and prints all bit strings that have 
*	Hamming distance at most k from s. For example, if k is 2 and s is 0000, then your program 
*	should print:
*		0011 0101 0110 1001 1010 1100
	*/
	private static void ex_2_3_21()
	{
		int hamming_dist = sc.nextInt();
		String seq = sc.next();
		StringBuilder new_seq;
		
		// impossible
		if (hamming_dist >= seq.length())	System.out.println("No such sequence.");
		
		// flip k bits
		for (int i = 0; i <= seq.length()-hamming_dist; i++)
		{
			new_seq = new StringBuilder(seq);
			flip_k_bits(new_seq, hamming_dist, i);
		}
	}
	
	private static void flip_k_bits(StringBuilder seq, int hamming_dist, int start_ind)
	{
		// base case
		if (hamming_dist == 0)	{ System.out.println(seq); return; }
		
		// flip bit
		seq.setCharAt(start_ind, (seq.charAt(start_ind)=='0' ? '1' : '0'));
		for (int i = start_ind+1; i < seq.length(); i++)	flip_k_bits(seq, hamming_dist-1, start_ind+1);
	}
}
/*
2 0000

flip(String new_seq, int hamming_dist, int start_ind) 
flip(0000, 2, 0)
	flip(1000, 1, 1)
		flip(1100, 0, 2)
			1100
	flip(1000, 1, 2)
		flip(1010, 0, 3)
			1010
	flip(1000, 1, 3)
		flip(1001, 0, 4)
			1001
flip(0000, 2, 1)
	flip(0100, 1, 2)
		flip(0110, 0, 3)
			0110
flip(0000, 2, 2)
*/