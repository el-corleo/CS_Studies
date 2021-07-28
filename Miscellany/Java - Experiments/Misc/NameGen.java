import java.util.*;
import java.lang.Math;

public class NameGen
{
	private static int NAME_LEN;
	private static int NUM_NAMES;
	private final static Random r = new Random();
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		while (true)
		{
			System.out.println("Name Length: ");
			NAME_LEN = scan.nextInt();
			if (NAME_LEN == -1) break;
			System.out.println("Number of Names to choose from: ");
			NUM_NAMES = scan.nextInt();
			
			String[] names = {"dorothy", "patricia", "elizabeth", "edwina", "athena", "constance", "melissa", "elysian", "eidos", "aryastark", "danaerys", "gwendolyn", "gweneviere"};
			// pick NUM_NAMES random names to put together
			String[] names_to_use = new String[NUM_NAMES];
			for (int i = 0; i < NUM_NAMES; i++)
				names_to_use[i] = names[r.nextInt(names.length)];
			generateNames(names_to_use);
		}
	}

	/* Walk through and print out all possible combinations
	* There should be a roughly equal distribution of letters to names
	* e.g., if length = 8, then letters taken for each name is 8/names.length
	*/	
	private static void generateNames(String[] names)
	{		
		// determine how many letters to extract from each name
		int letters = NAME_LEN/NUM_NAMES;
		int remainder = NAME_LEN%NUM_NAMES;
			
		int[] num_letters_by_name = new int[NUM_NAMES];
		
		int add_rem = r.nextInt(NUM_NAMES); // adds remainder to random name
		for (int i = 0; i < NUM_NAMES; i++)
		{
			if (remainder-- > 0)	num_letters_by_name[i] = letters + 1;
			else 					num_letters_by_name[i] = letters;
			
		}
		
		// combine letters
		int name = r.nextInt(NUM_NAMES); //select a starting name
		String franken_name = "";
		for (int i = 0; i < NUM_NAMES; i++)
		{
			franken_name += getName(names[name], num_letters_by_name[name]);
			name = (name+1)%NUM_NAMES;
		}
		
		System.out.println(franken_name);
	}
	
	private static String getName(String name, int letters_needed)
	{
		if (name.length()-letters_needed<1)
			letters_needed = 0; // if name is too short, just use fragment of name
		
		int start_ind = r.nextInt(name.length()-letters_needed);
		int end_ind = start_ind + letters_needed;
		return name.substring(start_ind, end_ind);
	}
	
	/* 
	*	returns the result of (n!/k!(n-k)! | n = name length, k = num letters to choose)
	*/
	private static int getArraySize(int name_len, int letters_needed)
	{
		// to avoid nasty unnecessary factorial calculations, simplify first
		int n_fact = 1;
		int k_fact = 1;
		// n!/(n-k)!
		int fact_cut_off = name_len - letters_needed;
		for (int i = name_len; i > fact_cut_off; i--)
			n_fact *= i;
		// k!
		for (int i = letters_needed; i > 1; i--)
			k_fact *= i;
		// n!/k!(n-k)!		
		return n_fact/k_fact;
	}
}