/*************************************************
*
*	Ex 1.1.2
*	What happens when you omit:
*	public -	Compiles but throws a Runtime Error
*				Error: Main method not found in class Ex1_1_2, please define the main method as:
*					public static void main(String[] args)
*				or a JavaFX application class must extend javafx.application.Application
*	static -	Compiles but throws a Runtime Error
*				Error: Main method is not static in class Ex1_1_2, please define the main method as:
*					public static void main(String[] args)
*	void -		Error upon compiling
*				Ex1_1_2.java:22: error: invalid method declaration; return type required
*					public static main(String[] args)
*								  ^
*				1 error
*	args -		Error upon compiling
*				Ex1_1_2.java:22: error: invalid method declaration; return type required
*				public static main(String[])
*										   ^
*				1 error
*
*	Ex 1.1.4
*	Try to put string double quotes on two different lines
*	System.out.println("Hello,
*						World.");
*	Error upon compiling
*		Ex1_1.java:32: error: unclosed string literal
*               System.out.println("Works
*                                  ^
*		Ex1_1.java:33: error: unclosed string literal
*                                                  Right?");
*                                                        ^
*		Ex1_1.java:33: error: not a statement
*                                                  Right?");
*                                                       ^
*		3 errors
*
*	Ex. 1.1.5
*	b. java Ex1_1 @!&^%
*		bash: !: event not found
*	d. java Ex1_1.java Bob
*		error: class found on application class path: Ex1_1
*
*************************************************/


public class Ex1_1
{
	public static void main(String[] args)
	{
		System.out.println("Works Right?");
	}
}
