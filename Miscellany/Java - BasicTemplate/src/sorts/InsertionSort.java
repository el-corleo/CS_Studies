/*
* Complexity: O(N^2); Ω(N)
* Stable because retains relative order when comparing different aspect of an ADT
*
* Algorithm:
*	- set sorted_index = 1
*	- sort while sorted_index < arr.length
*		- set value = arr[sorted_index]
*		- set to_sort_ind = sorted_index - 1
*		- compare to value at arr[to_sort_ind] while to_sort_ind >= 0
*			- if value is less
*				- set arr[to_sort_ind + 1] = arr[to_sort_ind], to_sort_ind--
*			- else
*				- break (you found a value lower)
*		- set arr[to_sort_ind + 1] = value, index++
*
* Invariant: at the end of each pass, all elements in the array less than and equal to
* the index are in sorted order
*/

package sorts;

public class InsertionSort
{
	public static void sort(Comparable[] arr)
	{
		// started at first unsorted element and work up
		for(int i = 1; i < arr.length; i++)
		{
			// store unsorted element
			Comparable value = arr[i];
			// set index for highest index in sorted subarray
			int j = i - 1;
			// compare unsorted element, shifting greater elements up
			// until finding a lesser or equal element
			while(j >= 0 && arr[j].compareTo(value) > 0){
				// shift element in j up to j+1
                arr[j + 1] = arr[j];
				// decrement index for subsequent comparison
                j--;
            }
			// insert unsorted element into correct spot
			// while leaving the lesser element found at j alone
            arr[j + 1] = value;
        }
	}
}