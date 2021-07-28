/*
* Complexity: O(N^2)
* Unstable because of long range swaps that will change previous ordering
*
* Algorithm:
*	- set index = 0
*	- while index < arr.length
		- set min = {highest possible}
*		- scan rest of list and compare each remaining element to min
*			- each time a lesser is found, set min = {that element's index}
*	 	- swap arr[index] with arr[min]
*
* Invariant: after each pass, elements at index <= last sorted are all in
* sorted order
*/
package sorts;

public class SelectionSort<T extends Comparable<T>>
{	
	public static <T extends Comparable<T>> T[] sort(T[] arr)
	{
		int min;
		for (int i = 0; i < arr.length; i++)
		{
			// set to highest possible
			min = arr.length-1;
			// find min element
			for (int j = i; j < arr.length; j++)
				if (arr[j].compareTo(arr[min]) < 0)
					min = j;
			// swap with i-th element
			T tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		
		return arr;
	}
}