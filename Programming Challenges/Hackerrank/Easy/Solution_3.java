//https://www.hackerrank.com/challenges/tutorial-intro/problem

public class Solution_3
{
	public static void main(String[] args)
	{
		int[] arr = {1,4,5,7,9,12};
		
		System.out.println(introTutorial(9, arr));
	}
	
	 // Complete the introTutorial function below.
    static int introTutorial(int V, int[] arr) {
        // binary search
        int lo = 0, hi = arr.length-1, mid = 0;

        while(hi >= lo)
        {
			mid = (hi+lo)/2;
			System.out.println(mid);
			
            if (arr[mid] == V)        return mid;
            else if (arr[mid] > V)    hi = mid - 1;
            else                      lo = mid + 1;
        }

        // item not in the array, because who knows if that guarantee
        // that V is in the array is trustworthy!
        return -1001;
    }
}