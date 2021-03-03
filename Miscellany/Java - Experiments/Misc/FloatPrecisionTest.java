public class FloatPrecisionTest{
	public static void main(String[] args)
	{
		// Float precision demo
		float f = 1.0F;
		System.out.println("FLOAT PRECISION");
		for(int i = 0; i < 50; i++) { System.out.println(f = f*0.1F); }
		
		// Double precision demo
		double d = 1.0D;
		System.out.println("DOUBLE PRECISION");
		for(int i = 0; i < 325; i++) { System.out.println(d = d*0.1D); }
	}
}