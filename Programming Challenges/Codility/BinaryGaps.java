public class BinaryGaps
{
	private static int binGap(int n)
	{
		int largest_gap = 0;
		int cnt = 0;
		boolean counting = false;
		while(n > 0)
		{
			// bin val = 1
			if (n%2==1)
			{	
				if (!counting)			counting = true;
				else if (cnt > largest_gap)	largest_gap = cnt;
				cnt = 0; // reset cnt
			}
			// bin val = 0
			else
			{ cnt++; }
			// get next binary val
			n /= 2; 
		}

		return largest_gap;
	}

	public static void main(String[] args)
	{
		System.out.println(binGap(Integer.parseInt(args[0])));
	}
}
