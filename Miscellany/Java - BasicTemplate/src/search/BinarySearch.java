/*
* Complexity: O(lg N)
*
* Algorithm: (Divide and Conquer)
* 	- set mid = average of endpoints
*	- compare arr[mid] to val
*		- if equal
*			- return mid index
*		- else if arr[mid] > val
*			- set end = mid - 1
*		- else
*			- set start = mid + 1
*/
package search;

public class BinarySearch
{
	/*
	* Parameters:
	*	- A sorted array
	*	- A value to search for
	* Returns:
	*	- index of val in arr
	*	- -1 if val not in arr
	*/
	public static int search(Comparable[] arr, Comparable val)
	{
		int start = 0, end = arr.length - 1;
		int mid = 0;

		while(start <= end)
		{
			// set midpoint
			mid = (start + end)/2;
		
			// compare val to item at mid
			// return if equal, else reset start/end
			if (arr[mid].compareTo(val) == 0)		return mid;
			else if (arr[mid].compareTo(val) > 0)	end = mid - 1;
			else 									start = mid + 1;
		}
		
		// val not in arr
		return -1;
	}
}