/*************************************************
*	All use Scanner instead of Command Line arguments
*
*	Ex 1.4.1
*	Write a program that declares, creates, and initializes an array a[] of length
*   1000 and accesses a[1000] . Does your program compile? What happens when you
*   run it?
*   
*   Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 1000 out of bounds for length 1000
*	at Ex1_4.ex_1_4_1(Ex1_4.java:60)
*   at Ex1_4.main(Ex1_4.java:54)
*
*	Ex 1.4.2
*	Describe and explain what happens when you try to compile a program with
*   the following statement:
*
*       int n = 1000;
*       int[] a = new int[n*n*n*n];
*
*   Exception in thread "main" java.lang.NegativeArraySizeException: -727379968
*	at Ex1_4.ex_1_4_2(Ex1_4.java:76)
*	at Ex1_4.main(Ex1_4.java:64)
*
*	Ex 1.4.3
*	Given two vectors of length n that are represented with one-dimensional
*   arrays, write a code fragment that computes the Euclidean distance between them
*   (the square root of the sums of the squares of the differences between corresponding elements).
*
*	Ex 1.4.4
*	Write a code fragment that reverses the order of the values in a one-dimensional
*   string array. Do not create another array to hold the result. Hint : Use
*   the code in the text for exchanging the values of two elements.
*
*	Ex 1.4.5
*	What is wrong with the following code fragment?
*
*       int[] a;
*       for (int i = 0; i < 10; i++)
*       a[i] = i * i;
*
*   Memory is never declared for array a.
*
*	Ex 1.4.6
*	Write a code fragment that prints the contents of a two-dimensional boolean array,
*   using * to represent true and a space to represent false . Include row and column indices.
*
*	Ex 1.4.7
*   What does the following code fragment print?
*
*       int[] a = new int[10];
*       for (int i = 0; i < 10; i++)
*           a[i] = 9 - i;
*       for (int i = 0; i < 10; i++)
*           a[i] = a[a[i]];
*       for (int i = 0; i < 10; i++)
*           System.out.println(a[i]);
*
*   Halfway through, half of the array has already been overwritten...	
*
*	Ex 1.4.8
*	Which values does the following code put in the array a[] ?
*
*       int n = 10;
*       int[] a = new int[n];
*       a[0] = 1;
*       a[1] = 1;
*       for (int i = 2; i < n; i++)
*           a[i] = a[i-1] + a[i-2];
*
*   Fibonacci sequence
*
*	Ex 1.4.9
*	What does the following code fragment print?
*
*       int[] a = { 1, 2, 3 };
*       int[] b = { 1, 2, 3 };
*       System.out.println(a == b);
*
*   false   
*
*	Ex 1.4.10
*	Write a program Deal that takes an integer command-line argument n and
*   prints n poker hands (five cards each) from a shuffled deck, separated by blank lines.
*
*	Ex 1.4.12
*	Write a program DiscreteDistribution that takes a variable number of
*	integer command-line arguments and prints the integer i with probability proportional
*	to the ith command-line argument.
*
*	Ex 1.4.14
*	Write a code fragment to print the transposition (rows and columns exchanged)
*	of a square two-dimensional array. For the example spreadsheet array in
*	the text, you code would print the following:
*
*		99 98 92 94 99 90 76 92 97 89
*		85 57 77 32 34 46 59 66 71 29
*		98 78 76 11 22 54 88 89 24 38
*
*************************************************/
import java.util.Scanner;
import java.util.ArrayList;

public class Ex1_4
{
	static Scanner sc;
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Array index out of bounds error
		//ex_1_4_1();

        // Integer overflow
        //ex_1_4_2();

        // Euclidean distance
        //ex_1_4_3();

        // In-place reversal of array order
        //ex_1_4_4();

        // Print out boolean array
        //ex_1_4_6();

        // Mirror array
        //ex_1_4_7();

        // Fibonacci
        //ex_1_4_8();

        // Relational op on arrays
        //ex_1_4_9();

        // n hands of poker from shuffled deck
        //ex_1_4_10();
		
		// Probabilistic printing
		//ex_1_4_12();
		
		// Matrix transposition
		ex_1_4_14();
	}

	private static void ex_1_4_1()
	{
        int[] a = new int[1000];
        a[1000] = 10;
	}

    private static void ex_1_4_2()
    {
        int n = 1000;
        int[] a = new int[n*n*n*n];
    }

    private static void ex_1_4_3()
    {
        int[] n_1 = {sc.nextInt(), sc.nextInt()};
        int[] n_2 = {sc.nextInt(), sc.nextInt()};

        // compute the distance
        int x = Math.abs(n_1[0]-n_2[0]);
        int y = Math.abs(n_1[1]-n_2[1]);

        double dist = Math.sqrt(x*x+y*y);
        
        System.out.println(dist);
    }

    private static void ex_1_4_4()
    {
        int len = sc.nextInt();
        int[] array = new int[len];
        for (int i = 0; i < len; i++)
            array[i] = sc.nextInt();

        for (int ind = 0; ind < len/2; ind++)
        {
            int tmp = array[ind];
            array[ind] = array[len-ind-1];
            array[len-ind-1] = tmp;
        }
        
        for (int i : array)
            System.out.print(i + " ");
    }

    private static void ex_1_4_6()
    {
        boolean[][] array = {{true,false},{false,true}};

        for (int i = 0; i < array.length; i++)
        {
            for (int j = 0; j < array[0].length; j++)
                System.out.print(array[i][j] ? "*" : " ");
            System.out.println();
        }
    }

    private static void ex_1_4_7()
    {
        int[] a = new int[10];
        for (int i = 0; i < 10; i++)
            a[i] = 9 - i;
        for (int i = 0; i < 10; i++)
            a[i] = a[a[i]];
        for (int i = 0; i < 10; i++)
            System.out.println(a[i]);
    }

    private static void ex_1_4_8()
    {
        int n = 10;
        int[] a = new int[n];
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i < n; i++)
        {
            a[i] = a[i-1] + a[i-2];
            System.out.println(a[i]);
        }
    }

    private static void ex_1_4_9()
    {
        int[] a = { 1, 2, 3 };
        int[] b = { 1, 2, 3 };
        System.out.println(a == b);
    }


    /*
     * Alternative shuffle:
     * import java.util.*
     *
     * List deck = new ArrayList();
     * deck.add() ALL CARDS
     * Collections.shuffle(deck);
     */
    private static void ex_1_4_10()
    {
        // create shuffled deck
        int[] deck = new int[52];
        /* 1-13 = Spades
         * 14-26 = Hearts
         * 27-40 = Clubs
         * 41-52 = Diamonds 
         */
        deck[0] = 1;
        for (int i = 1; i < deck.length; i++)
            deck[i] = deck[i-1] + 1;
		
        // shuffle
        for (int i = 0; i < deck.length; i++)
            swap(deck, i, (int) (Math.random()*52));

        // deal n hands
        int n = sc.nextInt();
		while (n > 10) n = sc.nextInt();
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            for (int cards = 0; cards < 5; cards++, ind++)
            {
				// 1-13 = Spades
                if (deck[ind] < 14)			print_card(deck, ind, "-S");
				// 14-26 = Hearts
				else if (deck[ind] < 27)	print_card(deck, ind, "-H");
				// 27-40 = Clubs
				else if (deck[ind] < 41)	print_card(deck, ind, "-C");
				// 41-52 = Diamonds
				else						print_card(deck, ind, "-D");
            }
            System.out.println();
        }
    }

    private static void swap(int[] deck, int i, int j)
    {
        int card = deck[i];
        deck[i] = deck[j];
        deck[j] = card;
    }
	
	private static void print_card(int[] deck, int ind, String suit)
	{
		String card = "";
		int num = deck[ind]%13;
		switch (num)
		{
			case 0:					card += "K"+suit+"  "; break;
			case 1:					card += "A"+suit+"  "; break;
			case 2:	case 3: case 4: 
			case 5:	case 6: case 7: 
			case 8: case 9:			card += num +suit+"  "; break;
			case 10:				card += num +suit+" "; break;
			case 11:				card += "J"+suit+"  "; break;
			case 12:				card += "Q"+suit+"  "; break;
		}
        System.out.print(card);
	}

	private static void ex_1_4_12()
	{
		// store user input numbers in an ArrayList
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		int n = sc.nextInt();
		int sum = 0;
		while (n >= 0)
		{
			numbers.add(n);
			sum += n;
			n = sc.nextInt();
		}
		
		// print out integer i with a probability of ArrayList.get(i)/sum
		for (int i = 0; i < numbers.size(); i++)
		{
			double prob = numbers.get(i)/(1.0*sum);
			double rand = Math.random();
			if (rand <= prob)	System.out.print(i + " ");
		}
	}
	
	private static void ex_1_4_14()
	{
		// make 2D array
		// TODO make a matrix generator
		int[][] two_d_arr =	{{99, 98, 92, 94, 99, 90, 76, 92, 97, 89},
							{85, 57, 77, 32, 34, 46, 59, 66, 71, 29},
							{98, 78, 76, 11, 22, 54, 88, 89, 24, 38}};
		
		// transpose
		for (int i = 0; i < two_d_arr[0].length; i++)
		{
			for (int j = 0; j < two_d_arr.length; j++)
				System.out.print(two_d_arr[j][i]+" ");
			System.out.println();
		}
	}
}