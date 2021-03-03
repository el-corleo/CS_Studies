// https://www.hackerrank.com/challenges/apple-and-orange/problem?h_r=next-challenge&h_v=zen

public class Solution_9 {

    // Complete the countApplesAndOranges function below.
    static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {
        // set range
        int[] apple_range = {s-a, t-a};
        int[] orange_range = {-(b-s), -(b-t)};
        int apples_in_range = 0;
        int oranges_in_range = 0;

        // apples
        for (int app : apples)
            if (app >= apple_range[0] && app <= apple_range[1])
                apples_in_range++;
    
        // oranges
        for (int org : oranges)
            if (org >= orange_range[0] && org <= orange_range[1])
                oranges_in_range++;
        
        System.out.println(apples_in_range +"\n"+ oranges_in_range);

    }

    public static void main(String[] args) {
        countApplesAndOranges(7, 11, 5, 15, new int[]{-2,2,1}, new int[]{-6,5});
    }
}
