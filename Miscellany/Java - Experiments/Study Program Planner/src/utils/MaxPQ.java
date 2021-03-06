package utils;

public class MaxPQ<T extends Comparable<T>>
{
	private T[] heap;
	private int CAPACITY;
	private int last = 0;
	private boolean hasMax = false;

	public MaxPQ(boolean hasMax)
	{
		this.hasMax = hasMax;
		CAPACITY = 2; 
		heap = (T[]) new Comparable[CAPACITY+1];
	}
	public MaxPQ(int max_cap)
	{
		this.hasMax = true;
		CAPACITY = max_cap;
		heap = (T[]) new Comparable[CAPACITY+1]; 
	}

	// accessors & mutators
	public void insert(T new_entry)
	{
		// Grow if this item would increase beyond capacity
		// Or if hasMax, then delMin() or skip depending on value
		if (last == CAPACITY)
		{
			if (!hasMax)									resize(CAPACITY*2);
			// do not add if at max capacity and is less than min
			else if (new_entry.compareTo(heap[last]) < 0)	return;
			else											delMin();	
		}
		// Shrink if contents only fill 1/4 of array
		else if (!hasMax && CAPACITY/4 > last)
		{ resize(CAPACITY/2); }

		heap[++last] = new_entry;
		swim(last);

	}
	
	public T getMax() { return heap[1]; }

	public T delMax()
	{
		T tmp = getMax();
		heap[1] = heap[last--];
		sink(1);
		return tmp;
	}
	
	public boolean isEmpty() { return last == 0; }
	
	// private helper methods
	private void sink(int k)
	{
		while (2*k <= last)
		{
			int j = 2*k;
			if (j < last && less(j, j+1))	j++;
			if (!less(k, j))				break;
			exch(k, j);
			k = j;
		}
	}
	
	private void swim(int k)
	{
		while (k > 1 && less(k/2,k))
		{	
			exch(k, k/2);
			k = k/2;
		}
	}

	private boolean less(int a, int b)
	{ return heap[a].compareTo(heap[b]) < 0; }
	
	private void exch(int a, int b)
	{ T tmp = heap[a]; heap[a] = heap[b]; heap[b] = tmp; }
	
	private void delMin()
	{ heap[last--] = null; }
	
	private void resize(int cap)
	{
		CAPACITY = cap;
		T[] tmp = (T[]) new Comparable[CAPACITY+1];
		for (int i = 0; i <= last; i++)
			tmp[i] = heap[i];
		heap = tmp;
	}
}