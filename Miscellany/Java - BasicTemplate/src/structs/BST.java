/*
* TODO: explain purpose of structure
* implement a Red-Black BST
*/

package structs;

public class BST<T extends Comparable<T>>
{
	private class Node<U extends Comparable<U>>
	{
		public U data;
		public Node left, right;
		public Node(U val) { data = val; }
	}
	
	private Node<T> root;
	
	public BST(){}
	
	public void add(T val)
	{
		if (root == null) root = new Node(val);
		else add(root, val);
	}
	
	private void add(Node node, T val)
	{
		if (node.data.compareTo(val) >= 0)
		{
			if (node.left == null) node.left = new Node(val);
			else add(node.left, val);
		} else
		{
			if (node.right == null)	node.right = new Node(val);
			else add(node.right, val);
		}
	}
	
	public boolean isInTree(T val)
	{
		if (root == null) return false;
		else return isInTree(root, val);
	}
	
	private boolean isInTree(Node node, T val)
	{
		if (node == null) return false;
		else if (node.data == val) return true;
		else return (node.data.compareTo(val) >= 0) ? isInTree(node.left, val) : isInTree(node.right, val);
		
	}
	
	public void printTree() { if (root != null) printTree(root); }
	
	private void printTree(Node node)
	{
		if (node != null) {
			printTree(node.left);
			System.out.println(node.data);
			printTree(node.right);
		}
	}
}