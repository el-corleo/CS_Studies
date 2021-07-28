package utils;

import java.util.Scanner;
import java.io.*;

public class FileLoader
{
	private Scanner scanFileHandle, scanFileLoader;
	
	public FileLoader()
	{
		System.out.print("Input filename (inlclude extension [e.g., example.txt]): ");
		scanFileHandle = new Scanner( System.in );
		
		while (scanFileLoader == null)
		{
			String filename = scanFileHandle.nextLine();
			try	{ scanFileLoader = new Scanner(new File("assets/" + filename)); }
			catch (FileNotFoundException e) { System.out.print("Sorry, no such file!\nTry again: "); }
		}
		
		System.out.println("File Loaded.");
	}
	
	public String getNext() { return (scanFileLoader.hasNext()) ? scanFileLoader.nextLine() : "Sorry,nothing in here!"; }
	
	public boolean hasNext() { return scanFileLoader.hasNext(); }
	
	public void destroy()
	{
		scanFileHandle.close(); 
		scanFileLoader.close(); 
	}
}