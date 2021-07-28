package bst;

public class BST
{
	private class Node
	{
		public int data;
		public Node left, right;
		
		public Node(int val) { data = val; }
	}
	
	private Node root;
	
	public BST(){}
	
	public void add(int val)
	{
		if (root == null) root = new Node(val);
		else add(root, val);
	}
	
	private void add(Node node, int val)
	{
		if (node.data >= val)
		{
			if (node.left == null) node.left = new Node(val);
			else add(node.left, val);
		} else
		{
			if (node.right == null)	node.right = new Node(val);
			else add(node.right, val);
		}
	}
	
	public boolean isInTree(int val)
	{
		if (root == null) return false;
		else return isInTree(root, val);
	}
	
	private boolean isInTree(Node node, int val)
	{
		if (node == null) return false;
		else if (node.data == val) return true;
		else return (node.data >= val) ? isInTree(node.left, val) : isInTree(node.right, val);
		
	}
	
	public void printTree()
	{
		if (root != null) printTree(root);
	}
	
	private void printTree(Node node)
	{
		if (node != null) {
			printTree(node.left);
			System.out.println(node.data);
			printTree(node.right);
		}
	}
}