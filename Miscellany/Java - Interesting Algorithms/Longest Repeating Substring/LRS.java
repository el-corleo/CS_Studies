/**
 * Given a substring s_seq, you can use suffix sorting to determine longest repeating substr
 * i.e.,
 *	Only need to check adjacent entries for longest common subsequence
 * 
 * Given implementation of substrings in Java, this requires N space for the new substrings created
 *	- 	Potential optimization is to keep a single reference to the original string and then save indexes
 *		to the generated substrings; this, however, would require modification to the sorting algorithm
 */
 import java.util.Arrays;

public class LRS
{
	
	private static String sub_seq(String a, String b)
	{
		// choose shorter of two strings to be limit
		int i_len = (a.length() < b.length()) ? a.length() : b.length();
		String s_sub_seq = "";
		for (int i = 0; i < i_len; i++)
			if (a.charAt(i) == b.charAt(i))	s_sub_seq += a.charAt(i);
			else							break;
		
		return s_sub_seq;
	}
	
	public static void main(String[] args)
	{
		String s_seq = args[0];
		String[] s_arr_seq = new String[s_seq.length()];
		// list all substrings
		for (int i = 0; i < s_seq.length(); i++)
			s_arr_seq[i] = s_seq.substring(i);
		// sort
		Arrays.sort(s_arr_seq);
		String s_lrs = "";
		for (int i = 0; i < s_arr_seq.length-1; i++)
		{
			String s_sub_seq = sub_seq(s_arr_seq[i], s_arr_seq[i+1]);
			s_lrs = (s_sub_seq.length() > s_lrs.length()) ? s_sub_seq : s_lrs;
		}
		// Output result
		System.out.println(s_lrs);
	}
}