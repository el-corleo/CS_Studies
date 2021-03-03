/*
* TODO: explain purpose of structure
*/

package structs;

public class Stack<T>
{
	private class Node<U>
	{
		public Node next;
		public U data;
	}

	private Node<T> first;
	
	public Stack() { first = null; }
	
	// modification methods
	public T pop()
	{
		T priorFirst = first.data;
		first = first.next;
		return priorFirst;
	}
		
	public void push(T val)
	{
		Node newFirst = new Node();
		newFirst.data = val;
		newFirst.next = first;
		first = newFirst;
	}
	
	// inspection methods
	public T peek() { return first.data; }

	public boolean isEmpty() { return first == null; }
	
	public void iterate()
	{
		Node n = first;
		while (n != null)
		{
			System.out.println(n.data);
			n = n.next;
		}
	}
}