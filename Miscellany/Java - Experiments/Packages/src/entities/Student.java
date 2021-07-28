package entities;

public class Student {
	private String getFood() {
		return "Pizza";
	}
	
	public String getInfo() {
		return this.getFood();
	}
}