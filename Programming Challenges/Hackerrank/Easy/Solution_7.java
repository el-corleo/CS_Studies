// https://www.hackerrank.com/challenges/mini-max-sum/problem

public class Solution_7 {

    // Complete the miniMaxSum function below.
    static void miniMaxSum(int[] arr) {
        long min = Long.MAX_VALUE, max = Long.MIN_VALUE;

        // add all numbers, track min and max
		// 5 choose 4, thus only 5 possibilities
        for (int ind = 0; ind < arr.length; ind++)
        {
            long sum = 0;
            for (int i = 0; i < 4; i++)
                sum += arr[(ind + i) % 5];
            
            min = (sum < min) ? sum : min;
            max = (sum > max) ? sum : max;
        }

        // print out results
        System.out.println(min + " " + max);
    }

    public static void main(String[] args) {
        int[] arr = {942381765, 627450398, 954173620, 583762094, 236817490};
		int[] arr_2 = {254961783, 604179258, 462517083, 967304281, 860273491};

        miniMaxSum(arr);
        miniMaxSum(arr_2);
    }
}