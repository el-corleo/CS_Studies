/*
* https://www.hackerrank.com/challenges/encryption/problem
*/

public class Solution23
{
	public static void main(String[] args)
	{
		String s = "wclwfoznbmyycxvaxagjhtexdkwjqhlojykopldsxesbbnezqmixfpujbssrbfhlgubvfhpfliimvmnny";
		System.out.println(s.length());
		System.out.println(encryption(s));
	}
	
	static String encryption(String s) {
		// determine rows & cols
        int rows = (int) Math.sqrt(s.length());
		int cols = (int) (Math.sqrt(s.length())+0.5f);
		if (rows<cols)	rows = (cols*rows >= s.length()) ? rows : rows+1;
		else 			cols = (cols*rows >= s.length()) ? cols : cols+1;
				
		String encrypted = "";
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				int index = (cols*j)+i;
				if (index < s.length())	encrypted += s.substring(index, index+1);
			}
			encrypted += " ";
		}

		return encrypted;
    }
}