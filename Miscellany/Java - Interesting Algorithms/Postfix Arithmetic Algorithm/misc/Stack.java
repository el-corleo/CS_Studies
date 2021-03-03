package misc;

public class Stack<T>
{
	private class Node<U>
	{
		public Node next;
		public U data;
	}

	private Node<T> first;
	
	public Stack() { }
	
	public T pop()
	{
		T priorFirst = first.data;
		first = first.next;
		return priorFirst;
	}
	
	public T peek() { return first.data; }
	
	public void push(T val)
	{
		Node newFirst = new Node();
		newFirst.data = val;
		newFirst.next = first;
		first = newFirst;
	}
	
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
