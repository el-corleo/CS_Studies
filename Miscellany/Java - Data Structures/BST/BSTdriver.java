import java.util.Scanner;
import bst.BST;

public class BSTdriver
{
	public static void main(String[] args)
	{
		BST bst = new BST();
		Scanner scan = new Scanner(System.in);
		
		int i;
		while ((i = scan.nextInt()) >= 0)
			bst.add(i);
		
		bst.printTree();
		
		scan.close();
	}
}