/*
* https://www.hackerrank.com/challenges/save-the-prisoner/problem
* 
*/

public class Solution19
{
	public static void main(String[] args)
	{
		int n = 352926151; // # prisoners
		int m = 380324688; // # candies
		int s = 94730870; // init seat
		System.out.println(saveThePrisoner(n,m,s));
	}
	
	public static int saveThePrisoner(int n, int m, int s) {
        // total left after max cycles through all prisoners
        int remain = m%n;
        // start from chair s, but subtract initial candy distributed to first chair
        // check if it overflows beyond total prisoners
        int ans = ((s+remain-1)%n);
        // if perfectly divisible, then ends on last prisoner
        return (ans==0)?n:ans;
    }
}