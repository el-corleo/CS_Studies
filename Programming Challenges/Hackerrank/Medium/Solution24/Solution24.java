/*
* https://www.hackerrank.com/challenges/bigger-is-greater/problem
*/

import java.util.*;
import java.io.*;

public class Solution24
{
	public static void main(String[] args)
	{
		try{
			Scanner sc = new Scanner(new File("Sol_24_in.txt"));
			ArrayList<String> in = new ArrayList<String>();
			while (sc.hasNext()) in.add(sc.nextLine());

			sc = new Scanner(new File("Sol_24_out.txt"));
			ArrayList<String> out = new ArrayList<String>();
			while (sc.hasNext()) out.add(sc.nextLine());

			sc.close();
			
			for (int i = 0; i < in.size(); i++)
				System.out.println("i = " + i + " | " + biggerIsGreater(in.get(i)).equals(out.get(i)));
		} catch(Exception e){}
		
	}
	
	static String biggerIsGreater(String w)
	{
		boolean possible = false; // if no rearrangments possible, don't look for them

		// search from the end for the first non-ascending letter
		int first_nonasc_ind = 0;
		for (int hi = w.length()-1; hi > first_nonasc_ind; hi--)
			if (w.charAt(hi) > w.charAt(hi-1)) { first_nonasc_ind = hi-1;	possible = true; }
		
		if (possible)
		{
			// swap first non-ascending w/ character higher but closest in rank to it
			int swap_ind = first_nonasc_ind+1;
			for (int hi = swap_ind; hi < w.length(); hi++)
				if (w.charAt(hi) < w.charAt(swap_ind) && w.charAt(hi) > w.charAt(first_nonasc_ind))
					swap_ind = hi;
			w = swap(w, swap_ind, first_nonasc_ind);				
		
			// sort from lowest->highest rank from index after first_nonasc_ind
			w = sort(w, first_nonasc_ind+1);
		}
		
		return (possible) ? w : "no answer";
	}
	
	// selection sort
	static String sort(String w, int init_ind)
	{
		for (int i = init_ind; i < w.length()-1; i++)
		{
			int lowest = w.charAt(i);
			int swap_ind = i;
			for (int j = i+1; j < w.length(); j++)
				if (w.charAt(j) < lowest) { lowest = w.charAt(j); swap_ind = j; }
			if (swap_ind != i)	w = swap(w, swap_ind, i);
		}
			
		return w;
	}
	
	// swaps two characters in a given string and returns a new string
	static String swap(String w, int hi_ind, int lo_ind)
	{
		return w.substring(0,lo_ind) + w.charAt(hi_ind) + w.substring(lo_ind+1,hi_ind) + w.charAt(lo_ind) + w.substring(hi_ind+1);
	}
}


