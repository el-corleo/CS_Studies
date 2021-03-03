/*
* Complexity: O(N^4/3) (with proper skip amt)
* Unstable because of long range swaps that will change previous ordering
*
* Algorithm: (Same as Insertion Sort but with a variable index skip, e.g., 3x+1)
* 	- determine index skip amt
* 	- h-sort (i.e., elements @ every h-th index are sorted)
* 	- decrement skip amt and repeat until array is nearly in sorted order
*
* Trick: because insertion sort works in O(N) time for sorted arrays,
* sorting smaller subarrays first and then doing a full sort of the array
* leads to significantly faster sorting
*/
package sorts;

public class ShellSort
{
	public static void sort(Comparable[] arr)
	{
		int n = arr.length;
		int h = 1; // the index skip amt
		while (h < n/3) h = 3*h + 1; // set the skip amt to roughly n/3
		while (h >= 1) 
		{
			for (int i = h; i < n; i++) // h-sort
				for (int j = i; j >= h && (arr[j].compareTo(arr[j-h])<0); j -=h)
					swap(arr, j, j-h);
			h /= 3;
		}
	}
	
	public static void swap(Comparable[] arr, int i, int j)
	{
		Comparable temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}