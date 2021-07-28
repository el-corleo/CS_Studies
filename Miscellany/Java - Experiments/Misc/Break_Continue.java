/*
* Illustrates usage of 'break;' and 'continue;' commands
* within the context of a loop
*/
public class Break_Continue{
	
	public static void main(String[] args){
		int sum_1 = 0, sum_2 = 0;
		for (int i = 1; i < Integer.parseInt(args[0]); i++){
			if (i%2 == 0){
				continue;
			} else {
				sum_1++;
			}
		}
		
		for (int i = 1; i < Integer.parseInt(args[0]); i++){
			if (i%2 == 0){
				break;
			} else {
				sum_2++;
			}
		}
		
		System.out.println(sum_1);
		System.out.println(sum_2);	
	}
}