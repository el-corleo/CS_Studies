/*
* https://www.hackerrank.com/challenges/picking-numbers/problem
* Very good one for thininking about edge cases
*/

import java.util.*;

public class Solution18
{
	public static void main(String[] args)
	{
		List<Integer> a = new ArrayList<Integer>();
		a.add(1); a.add(1); a.add(1); a.add(1); a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		a.add(1); a.add(1);	a.add(1); a.add(1);	a.add(1);
		
		
		System.out.println(pickingNumbers(a));
	}
	
	public static int pickingNumbers(List<Integer> a)
	{
		Collections.sort(a);

		// find longest run
		int sentinel = a.get(0);
		int longest = 2;
		int run = 1, aux_run = 0;

		for (int i = 1; i < a.size(); i++)
		{
			if (a.get(i) == sentinel)          
			{ 
				run++;
				if (i+1 == a.size()) return run;
			}
			else if (a.get(i) == sentinel+1)    { run++; aux_run++; }
			else
			{
				// reset longest if need be
				longest = (run > longest) ? run : longest;
				// if just one higher than current sentinel's partner
				// include current sentinel's partner's run
				if (a.get(i)==sentinel+2)
				{
					run = Math.max(aux_run,1)+1;
					sentinel++;
					aux_run = 1;
				}
				else
				{
					run = 1;
					sentinel = a.get(i);
					aux_run = 0;
				}
			}
		}

		return longest;
    }
}