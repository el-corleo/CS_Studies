package binaryCalc;

public class BinaryCalc
{
	private static final int ARRAY_LENGTH = 32;
	
	public static void main(String[] args)
	{	
		// instantiate and populate array of ints to convert
		int[] toConvert = new int[args.length];
		for (int i = 0; i < args.length; i++)
			toConvert[i] = Integer.parseInt(args[i]);
		
		// convert and print to console
		for (int i : toConvert)
		{
			System.out.println("METHOD_1: " + i + " converts to " + convert(i) + " in binary.");
			System.out.println("METHOD_2: " + i + " converts to " + altConvert(i) + " in binary.");
		}
	}
	
	// less elegant way of converting int to binary
	public static String convert(int num)
	{
		int highest = 0;
		// find highest exponent
		while (Math.pow(2, highest+1) < num)
		{
			highest++;
		}
		
		// populate bitArray w/ relevant 1s and 0s
		int[] bitArray = new int[ARRAY_LENGTH];
		int sum = 0;
		for (int i = highest; i >= 0; i--)
		{
			sum += (Math.pow(2, i));
			if (sum > num && highest >=0)
			{
				sum -= (Math.pow(2, i));
				bitArray[i] = 0;
			}
			else
			{
				bitArray[i] = 1;
			}
		}
		
		// build binary string (array is in reverse order)
		String str = "";
		for (int i = ARRAY_LENGTH-1; i >= 0; i--)
		{
			str += bitArray[i];
		}			
		return str;
	}
	
	// more elegant way to convert int to binary
	public static String altConvert(int num)
	{
		int[] bitArray = new int[ARRAY_LENGTH];
		for(int i = 0; i < ARRAY_LENGTH; i++)
		{
			bitArray[i] = num % 2;
			num /= 2;
		}
		
		// build binary string (array is in reverse order)
		String str = "";
		for (int i = ARRAY_LENGTH-1; i >= 0; i--)
		{
			str += bitArray[i];
		}			
		return str;
	}
	
	// more elegant way to convert long to binary
	public static String altConvert(long num)
	{
		long[] bitArray = new long[ARRAY_LENGTH*2];
		for(int i = 0; i < ARRAY_LENGTH*2; i++)
		{
			bitArray[i] = num % 2;
			num /= 2;
		}
		
		// build binary string (array is in reverse order)
		String str = "";
		for (int i = ARRAY_LENGTH*2-1; i >= 0; i--)
		{
			str += bitArray[i];
		}			
		return str;
	}
}