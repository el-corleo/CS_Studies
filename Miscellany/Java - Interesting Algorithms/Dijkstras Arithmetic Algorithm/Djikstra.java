import misc.*;

public class Djikstra
{	
	private static Stack<Integer> num_stack;
	private static Stack<String> op_stack;
	
	private static void solve(String prob)
	{
		// traverse string, check each char, act accordingly
		int ind = 0;
		while (ind < prob.length())
		{			
			// isolate char
			String item = prob.substring(ind++, ind);
			// classify and process
			try { num_stack.push(Integer.parseInt(item)); } 						// if is number
			catch (Exception e) 
			{
				if (item.equals("+") || item.equals("*")) {	op_stack.push(item); } 	// if is operator
				else if (item.equals(")")) 											// if must compute
				{
					int a = num_stack.pop();
					int b = num_stack.pop();
					num_stack.push((op_stack.pop().equals("+")) ? a+b : a*b);
				}
			}
		}
		System.out.println("The answer is " + num_stack.pop());
	}
	
	public static void main(String[] args)
	{
		Loader mp = new Loader();
		num_stack = new Stack<Integer>();
		op_stack = new Stack<String>();
		
		while(mp.hasNext())
			solve(mp.getNext());
		
		mp.destroy();
	}
}