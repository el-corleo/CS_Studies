import misc.*;

public class Postfix
{	
	private static Stack<Integer> num_stack;
	
	private static void solve(String prob)
	{
		// traverse string push num to stack until reaching an operator
		int i_ind = -1;
		char ch;
		while((ch=prob.charAt(++i_ind)) != '|')
		{
			if (prob.charAt(i_ind) == '+')
			{
				int i_a = num_stack.pop();
				int i_b = num_stack.pop();
				num_stack.push(i_a+i_b);
			} else if (prob.charAt(i_ind) == '-')
			{
				int i_a = num_stack.pop();
				int i_b = num_stack.pop();
				num_stack.push(i_a-i_b);
			} else if (prob.charAt(i_ind) == '*')
			{
				int i_a = num_stack.pop();
				int i_b = num_stack.pop();
				num_stack.push(i_a*i_b);
			} else if (prob.charAt(i_ind) == '/')
			{
				int i_a = num_stack.pop();
				int i_b = num_stack.pop();
				num_stack.push(i_a/i_b);
			} else	num_stack.push(Character.getNumericValue(prob.charAt(i_ind)));
		}
		System.out.println("The answer is " + num_stack.pop());
	}
	
	public static void main(String[] args)
	{
		Loader mp = new Loader();
		num_stack = new Stack<Integer>();
		
		while(mp.hasNext())
			solve(mp.getNext());
		
		mp.destroy();
	}
}