/*
* https://www.hackerrank.com/challenges/the-birthday-bar/problem?h_r=next-challenge&h_v=zen
* 
* how many subarrays of length m in s add up to d
* sample input
* s = {1,2,1,3,2} | m = 2 | d = 3
* s = {1,1,1,1,1,1} | m = 3 | d = 2
* s = {4} | m = 1 | d = 4
* s = {2,5,1,3,4,4,3,5,1,1,2,1,4,1,3,3,4,2,1} | m = 7 | d = 18
* s = {2,3,4,4,2,1,2,5,3,4,4,3,4,1,3,5,4,5,3,1,1,5,4,3,5,3,5,3,4,4,2,4,5,2,3,2,5,3,4,2,4,3,3,4,3,5,2,5,1,3,1,4,2,2,4,3,3,3,3,4,1,1,4,3,1,5,2,5,1,3,5,4,3,3,1,5,3,3,3,4,5,2} | m = 8 | d = 26
*
* O(n) possible if you do cumulative sum and subtract larger from smaller at m distance
*/

public class Solution12
{
	public static void main(String[] args)
	{
		int m = 2;
		int d = 3;
		List<Integer> s = new ArrayList<Integer>();
		s.add(1);
		s.add(2);
		s.add(1);
		s.add(3);
		s.add(2);
		System.out.println(totalSubs(s, d, m));
	}
	
	public static int totalSubs(List<Integer> s, int d, int m) {
		int total = 0;
		
        // check if m is greater than s.size()
        if (m > s.size()) return total;

        // check all subarrays of size m
        for (int i = 0; i+m <= s.size(); i++)
        {
            int sum = 0, j = 0;
            while (j < m && sum <= d)
            {
                sum += s.get(i+j);
                j++;
            }
			// iff j is of length m and sum equals d
            if (j == m && sum == d) total++;
        }

        return total;       
    }
}