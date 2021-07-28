/*
* https://www.hackerrank.com/challenges/kangaroo/problem
*
* input: x1 v1 x2 v2 expected result [space separated]
*
* Constraints:
* 0<=x1<x2<=10000
* 1<=v1<=10000
* 1<=v2<=10000
*
* Can two kangaroos starting at different points and leaping at different rates ever land at the same spot at the same time?
*/

public class Solution10
{
	public static void main(String[] args)
	{
		String result = kangaroo(21, 6, 47, 3);
	}
	
	private static boolean kangaroo(int x1, int v1, int x2, int v2) {  
		// if y-intercept greater and slope greater equal to, then impossible
		if (v1 <= v2) return false;
		
        while (true)
        {
			// recalculate for each time step
            x1 += v1;
            x2 += v2;
			// if equal, then possible
            if (x1==x2) return true;
			// if crossed, then impossible
            else if (x1>x2) return false;
        }
    }
}