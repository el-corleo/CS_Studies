import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution_5
{
	public static void main(String[] args)
	{
		System.out.println(repeatedString("aba", 10));
		System.out.println(repeatedString("a", 100000000));
		System.out.println(repeatedString("abaabssa", 100000000));
		System.out.println(repeatedString("abaabss", 100000000));
		System.out.println(repeatedString("abbss", 100000000));
		System.out.println(repeatedString("cd", 100));
	}
	
	static long repeatedString(String s, long n) {
        long num_A = findA(s);
       
        long remainder = n % s.length();
        if (remainder == 0)
            num_A = (n/s.length()) * num_A;
        else
            num_A = (n/s.length()) * num_A + findA(s.substring(0, (int) remainder));
    
        return num_A;
    }

    private static long findA(String s_copy)
    {
        long num_A = 0;

        while (s_copy.contains("a"))
        {
            if (s_copy.startsWith("a"))
                num_A++;
            s_copy = s_copy.substring(1);
        }

        return num_A;
    }
}