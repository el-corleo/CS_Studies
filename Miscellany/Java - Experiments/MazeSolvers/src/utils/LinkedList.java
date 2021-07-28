public class LinkedList
{
	private static class SLLNode<T>
	{
		private T data;
		private SLLNode next;
		
		public SLLNode(T val) {	data = val;	}
		
		public T getData() { return data; }
		
		public void setData(T val) { data = val; }
		
		public SLLNode getNext() { return next;	}
		
		public void setNext(SLLNode newNext) { next = newNext; }
	}
	
	private static class DLLNode<T>
	{
		private T data;
		private DLLNode prev, next;
		
		public DLLNode(T val) { data = val; }
		
		public T getData() { return data; }
		
		public void setData(T val) { data = val; }
		
		public DLLNode getPrev() { return prev;	}
		
		public void setPrev(DLLNode newPrev) { prev = newPrev; }
		
		public DLLNode getNext() { return next;	}
		
		public void setNext(DLLNode newNext) { next = newNext; }
	}
	
	public static void main(String[] args)
	{
		/*
		Nodes, pointers
		Singly linked, doubly linked
		*/
		
		// Singly linked
		SLLNode<Integer> first = new SLLNode<Integer>(-1);
		SLLNode<Integer> newFirst;
		for (int i = 0; i < 10; i ++)
		{
			newFirst = new SLLNode<Integer>(i);
			newFirst.setNext(first);
			first = newFirst;
		}
		
		// traverse(first);
		
		// Doubly linked
		DLLNode<Integer> start = new DLLNode<Integer>(10);
		DLLNode<Integer> end = start;
		DLLNode<Integer> toAdd;
		for (int i = 9; i > 0; i--)
		{
			toAdd = new DLLNode<Integer>(i);	// make new node
			start.setPrev(toAdd); 				// set new node to start's prev node
			toAdd.setNext(start);				// set new node's next to start
			start = toAdd;						// set start to new node
		}
		
		traverse(start);
		rev_trav(end);
	}
	
	private static void traverse(SLLNode first)
	{
		System.out.println("Singly Linked List Traversal:");
		SLLNode n = first;
		while(n != null)
		{
			System.out.println(n.getData());
			n = n.getNext();
		}
	}
	
	private static void traverse(DLLNode start)
	{
		System.out.println("Doubly Linked List Traversal [Forward]:");
		DLLNode n = start;
		while(n != null)
		{
			System.out.println(n.getData());
			n = n.getNext();
		}
	}
	
	private static void rev_trav(DLLNode end)
	{
		System.out.println("Doubly Linked List Traversal [Backward]:");
		DLLNode n = end;
		while(n != null)
		{
			System.out.println(n.getData());
			n = n.getPrev();
		}
	}
}