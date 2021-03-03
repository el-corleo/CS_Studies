import java.util.*;
import search.*;
import sorts.*;
import structs.*;
import utils.*;

public class Main
{	
	private static long timer;
	
	public static void main(String[] args)
	{	
		FileLoader mp = new FileLoader();
		
		while(mp.hasNext())
			solve(mp.getNext());
		
		mp.destroy();
	}
	
	private static void solve(String prob)
	{ 
		Scanner scan = new Scanner(System.in);
		int ARR_SIZE = scan.nextInt();
		
		// Populate arrays
		Random rand = new Random();
		Integer[] selec_arr = new Integer[ARR_SIZE];
		for (int i = 0; i < selec_arr.length; i++)
			selec_arr[i] = rand.nextInt(10);
		// Integer[] insert_arr = selec_arr;			// shallow copy
		Integer[] insert_arr = new Integer[ARR_SIZE]; 	// deep copy
		for (int i = 0; i < insert_arr.length; i++)
			insert_arr[i] = selec_arr[i];
		Integer[] merge_arr = new Integer[ARR_SIZE];
		for (int i = 0; i < merge_arr.length; i++)
			merge_arr[i] = selec_arr[i];
		
		// Selection Sort
		timer = System.currentTimeMillis();
		SelectionSort.sort(selec_arr);
		System.out.println("Selection sort took " + (System.currentTimeMillis()-timer) + " milliseconds to complete.");
		
		// Insertion Sort
		timer = System.currentTimeMillis();
		InsertionSort.sort(insert_arr);
		System.out.println("Insertion sort took " + (System.currentTimeMillis()-timer) + " milliseconds to complete.");
		
		// Merge Sort
		timer = System.currentTimeMillis();
		MergeSort.sort(insert_arr);
		System.out.println("Merge sort took " + (System.currentTimeMillis()-timer) + " milliseconds to complete.");
	}
}