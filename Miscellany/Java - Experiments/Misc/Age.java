public class Age
{
	public static void main(String[] args)
	{
		for (int s = 1; s <= 100; s++)
			for (int m = 1; m <= 100; m++)
				if ((s == m + 5) && (s + 3 == 2 * m + 6))
					System.out.println("She is " + s + " and he is " + m);
	}
}