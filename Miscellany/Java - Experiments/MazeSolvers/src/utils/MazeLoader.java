/**
 * MazeLoader.java
 *
 * Loads a generated maze
 *
 * @EC
 * @09-2020
 * For AP CS A
 */
package utils;
 
import java.util.Scanner;
import java.io.File;

public class MazeLoader
{
	private static Scanner sc;
		
	public static String[] load(String filename)
	{
		String filepath = new File("").getAbsolutePath()+filename;
		String[] tmp_arr = new String[1000]; // will never exceed this length
		int line_cnt = 0;
		try { 
			sc = new Scanner(new File(filepath));
			while(sc.hasNext())	{ tmp_arr[line_cnt++] = sc.nextLine(); }
			String[] final_arr = new String[line_cnt];
			for (int i = 0; i < line_cnt-1; i++)
				final_arr[i] = tmp_arr[i];
			
			return final_arr;
		} catch (Exception e) { System.out.println(filepath + " not found"); }
		
		return null;
	}
}