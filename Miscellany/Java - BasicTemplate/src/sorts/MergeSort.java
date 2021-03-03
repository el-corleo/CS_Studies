/*
* Complexity: O(N lg N)
* Stable so long as merge breaks ties taking from left in ascending,
* right in descending
*
* Algorithm:
* 	- Call mergeSort recursively to split larger array into subarrays
*	until subarray is of size 1
*	- Merge all subarrays, comparing each element within and sorting them as you merge
*
*	Notes: "divide and conquer" algorithm
*/
package sorts;

import java.util.ArrayList;

public class MergeSort
{
	public static void sort(Comparable[] arr) {	mergeSort(arr, arr.length); }

	private static void mergeSort(Comparable[] arr, int size)
	{
		// base case: stop splitting, start merging
		if (size < 2) return;
		
		// split into subarrays
		int mid = size/2;
		Comparable[] left = new Comparable[mid];
		Comparable[] right = new Comparable[size-mid];
		
		for (int i = 0; i < mid; i++)
			left[i] = arr[i];
		for (int i = mid; i < size; i++)
			right[i-mid] = arr[i];
		
		// recursively split into smaller arrays
		mergeSort(left, mid);
		mergeSort(right, size-mid);
		
		// merge
		merge(arr, left, right, mid, size-mid);
	}

	@SuppressWarnings("unchecked")
	private static void merge(Comparable[] arr, Comparable[] left, Comparable[] right, int l_size, int r_size)
	{
		// compare elements for both lists
		// placing lower at index k
		// increasing i if left is lower or j if right is lower
		int i = 0, j = 0, k = 0;
		while (i < l_size && j < r_size)
		{
			if (left[i].compareTo(right[j]) <= 0)
				arr[k++] = left[i++];
			else
				arr[k++] = right[j++];
		}
		
		// previous loop breaks before all elements are in array
		// these loops ensure that all elements are correctly appended
		while (i < l_size)
			arr[k++] = left[i++];
		while (j < r_size)
			arr[k++] = right[j++];
	}
}