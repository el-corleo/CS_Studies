/*
* TODO: explain purpose of structure
*/

package structs;

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
}