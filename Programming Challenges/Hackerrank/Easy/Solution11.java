/*
* https://www.hackerrank.com/challenges/between-two-sets/problem?h_r=next-challenge&h_v=zen
* find number of integers between (inclusive) highest int in array a and lowest int in array b
* sample inputs
* a = {3,9,6}	|	b = {36,72}
* a = {2,4}		|	b = {16,32,96}
* a = {2}		|	b = {20,30,12}
* a = {3,4}		|	b = {24,48}
* a = {51}		|	b = {50}
* a = {2,3,6}	|	b = {42,84}
* a = {1}		|	b = {72,48}
* a = {10}		|	b = {100}
*/

import java.util.*;

public class Solution11
{
	public static void main(String[] args)
	{
		List<Integer> a = new ArrayList<Integer>();
		List<Integer> b = new ArrayList<Integer>();
		
		a.add(3);
		a.add(9);
		a.add(6);
		
		b.add(36);
		b.add(72);
		
		int total = getTotalX(a,b);
		System.out.println(total);
	}
	
	public static int getTotalX(List<Integer> a, List<Integer> b) {
        Collections.sort((ArrayList) a);
        Collections.sort((ArrayList) b);

		int total = 0;
        int lcm = a.get(a.size()-1);
		int orig_lcm = lcm; // to keep track of multiples
        int lowest_hi = b.get(0);

        // finds least common multiple for all lower elements
        for (int i : a)
            while (lcm%i != 0){
				lcm += orig_lcm;
				if (lcm > lowest_hi) return total;
			}
		
		orig_lcm = lcm; // resets to new lcm

        // check if all numbers in upper array are divisible by lcm
        for (int i : b)
            if (i%lcm !=0) return total;
		
        // find multiples of lcm <= lowest_hi that divide evenly
        boolean works = true;
		while(lcm <= lowest_hi)
        {
            for (int i : b)
                if (i%lcm !=0) works = false;
    
			if (works)
				total++;
            
			// increase highest_low
            lcm += orig_lcm;
			// reset bool
			works = true;
        }

        return total;
    }

}