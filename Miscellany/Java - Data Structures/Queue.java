/*
 * Queue  (FIFO structure) that uses a Singly Linked List data structure
 */
public class Queue<Type>
{	
	private SLLNode<Type> head;
	private int size = 0;
	
	public Queue() { head = new SLLNode<Type>(); }
	
	public void enqueue(Type t) { SLLNode<Type> old = new SLLNode<Type>(head.getData()); head = new SLLNode<Type>(t); head.setNext(old); size++; }
	
	public Type dequeue() { Type old = head.getData(); head = head.getNext(); return old; size--; }

	public int getSize() { return size; }

	public boolean isEmpty() { return size == 0; }
	
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
}