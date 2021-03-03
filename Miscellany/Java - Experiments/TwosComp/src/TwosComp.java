import java.util.Scanner;
import binaryCalc.BinaryCalc;

public class TwosComp
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		// choose num to convert, must not be negative
		System.out.print("Choose number to make negative: ");
		int num = -1;
		while (num < 0) // ensures not negative
			num = scan.nextInt();
		String binNum = BinaryCalc.altConvert(num);
		scan.close();
		
		// print to console
		// method one
		System.out.println(num + " in binary is: " + binNum);
		System.out.println("Converted to -" + num + " using Two's Complement it is:   "
							+ twosCompConverter(binNum));
		// method two
		System.out.println("Alternatively, you could add 2^32 to -" + num + " to get: " 
							+ BinaryCalc.altConvert((long) Math.pow(2,32)-num).substring(32));
	}
	
	/*
	Take String num (which is a binary String) as input
	Produce a string for its negative counterpart using Two's Complement
	*/
	public static String twosCompConverter(String num)
	{
		int[] twoComp = new int[num.length()];
		for (int i = num.length()-1; i >= 0; i--)
		{			
			if (Integer.parseInt(num.substring(i, i+1)) == 1)
			{
				twoComp[i] = 1;
				// copy, then flip all remaining
				for (int j = i-1; j >=0; j--)
				{
					twoComp[j] = (Integer.parseInt(num.substring(j, j+1))==0) ? 1 : 0;
				}
				i = -1;
			}
			else
			{
				// just copy
				twoComp[i] = Integer.parseInt(num.substring(i, i+1));
			}
		}
		
		// reform string
		String str = "";
		for (int i = 0; i < twoComp.length; i++)
		{
			str += twoComp[i];
		}
		
		return str;
	}
}