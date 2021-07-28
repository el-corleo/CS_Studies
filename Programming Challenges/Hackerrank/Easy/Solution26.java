/*
* https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
*/

public class Solution26
{
	public static void main(String[] args)
	{
		int[] c = {0,0,0,0,1,0};
		System.out.println(jumpingOnClouds(c));
	}
	
	static int jumpingOnClouds(int[] c) {
		int steps = 0, ind = 0;
        
        while (ind+1 < c.length)
        {
			// near end
            if ((ind+2) == c.length)    { steps++; break; }
            // not yet near end
			ind = (c[ind+2] == 1) ? ind+1 : ind+2;
            steps++;
        }
        
        return steps;
	}
}