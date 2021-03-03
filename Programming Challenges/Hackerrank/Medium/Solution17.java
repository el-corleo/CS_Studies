/*
* https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/

import java.util.*;

public class Solution17
{
	public static void main(String[] args)
	{
		int[] scores = {100,100,50,40,40,20,10};
		int[] alice = {5,25,50,120};
		climbingLeaderboard(scores, alice);
	}
	
	static int[] climbingLeaderboard(int[] scores, int[] alice)
	{
        // determine ranks
        ArrayList<Integer> ranks = new ArrayList<Integer>();
        int score = scores[0]; // gatekeeper score for next rank
        ranks.add(-1); // padding to make rank calc more intuitive
        ranks.add(score);
        for (int ind = 0; ind < scores.length; ind++)
            if (scores[ind] < score)
            {
                ranks.add(scores[ind]);
                score = scores[ind];
            }

        // see where Alice fits in
        int[] results = new int[alice.length];
        int oth_ind = ranks.size()-1;
        for (int ind = 0; ind < alice.length; ind++)
            for (; oth_ind > 0; oth_ind--)
                // alice ranked lower
                if (alice[ind] < ranks.get(oth_ind))
                {
                    results[ind] = oth_ind+1;
                    break;
                }
                // alice ranked same
                else if (alice[ind] == ranks.get(oth_ind))
                {
                    results[ind] = oth_ind;
                    break;
                }
                // alice number 1
                else if (alice[ind] > ranks.get(1)){
                    results[ind] = 1;
                    break;
                }

        return results;
    }
}