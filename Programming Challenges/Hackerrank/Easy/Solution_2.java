
// https://www.hackerrank.com/challenges/2d-array/problem?h_r=next-challenge&h_v=zen
public class Solution
{
  public static void main (String[] args)
  {
    int[][] arr_0 = {{1,1,1,0,0,0}, {0,1,0,0,0,0}, {1,1,1,0,0,0}, {0,0,2,4,4,0}, {0,0,0,2,0,0}, {0,0,1,2,4,0}};
	int[][] arr_1 = {{0,-4,-6,0,-7,-6}, {-1,-2,-6,-8,-3,-1}, {-8,-4,-2,-8,-8,-6}, {-3,-1,-2,-5,-7,-4}, {-3,-5,-3,-6,-6,-6}, {-3,-6,0,-8,-6,-7}};
	
	System.out.println(hourglassSum(arr_0));
	System.out.println(hourglassSum(arr_1));
  }
  
   static int hourglassSum(int[][] arr) {
        int highest = Integer.MIN_VALUE;
        int[] sums = new int[16];
        int r = 0, c = 0;

        // traverse all sixteen hourglasses, sum them
        for (int i = 0; i < sums.length; i++)
        {   
            // sum up all relevant values
            sums[i] =   arr[r][c] + arr[r][c+1] + arr[r][c+2]
                        + arr[r+1][c+1]
                        + arr[r+2][c] + arr[r+2][c+1] + arr[r+2][c+2];

            // increment  r and/or c values
            c = ++c % 4;
            r = (c == 0) ? r+1 : r;
			System.out.println("Indexes: (" + r + "," + c +")");
			System.out.println(c==0);
        }

        // find highest
        for (int i : sums)
            highest = (i > highest) ? i : highest;
        
        return highest;
    }
}