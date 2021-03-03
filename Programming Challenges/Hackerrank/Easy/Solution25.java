/*
* https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
*/

public class Solution25
{
	public static void main(String[] args)
	{
		int[] h = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
		String word = "abc";
		System.out.println(designerPdfViewer(h, word));
	}
	
	static int designerPdfViewer(int[] h, String word) {
        // 'a' = 97
        int tallest = 0;
        for (int i = 0; i < word.length(); i++)
            tallest = (h[word.charAt(i)-97] > tallest) ? h[word.charAt(i)-97] : tallest;
        
        return tallest * word.length();
    }
}