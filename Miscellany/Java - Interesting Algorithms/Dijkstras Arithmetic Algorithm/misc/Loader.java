package misc;

import java.util.Scanner;
import java.io.*;

public class Loader
{
	Scanner scan;
	public Loader()
	{
		try { scan = new Scanner(new File("assets/probs.txt")); }
		catch (FileNotFoundException e) { System.out.println("Sorry, no such file!"); }
	}
	
	public String getNext() { return (scan.hasNext()) ? scan.nextLine() : "Sorry, nothing in here!"; }
	
	public boolean hasNext() {return scan.hasNext(); }
	
	public void destroy() { scan.close(); }
}