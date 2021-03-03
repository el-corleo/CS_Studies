import java.util.Scanner;

public class ScannerExample
{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Write something! ");
		String str = scanner.nextLine();
		
		String str_2 = reverse(str);
			
		System.out.println(str_2);
		
		System.out.print("Type in two single digit integers to add! ");
		int[] numsToAdd = extractNums(scanner.nextLine());
		
		System.out.println(numsToAdd[0]+numsToAdd[1]);
		
		System.out.println("Type in any two integers to add! ");
		numsToAdd[0] = scanner.nextInt();
		numsToAdd[1] = scanner.nextInt();
		scanner.close();
		
		System.out.println(numsToAdd[0]+numsToAdd[1]);
	}
	
	public static int[] extractNums(String str){
		int[] numsToAdd = new int[2];
		
		numsToAdd[0] = Integer.parseInt(str.substring(0,1)); 
		numsToAdd[1] = Integer.parseInt(str.substring(1)); 
		
		return numsToAdd;
	}
	
	public static String reverse(String str){
		String str_2 = "";
		
		for (int i = str.length()-1; i >= 0; i--)
			str_2 += str.substring(i, i+1);
		
		return str_2;
	}
}