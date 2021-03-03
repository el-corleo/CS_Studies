package entities;

public class GradStudent extends Student {
	private String getFood() {
		return "Taco";
	}
	
	public void teach(){
		System.out.println("Education!");
		getInfo();
	}
}