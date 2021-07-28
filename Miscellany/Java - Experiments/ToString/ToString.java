public class ToString {
	// does not override the toString() method from the Object class
	private static class Test1 {
		// 'java.lang' doesn't need to be explicitly written
		// it's auto imported, if not using an auto import or
		// an import statement, then this notation is necessary
		java.lang.String s;
		
		public Test1(String s) {
			this.s = s;
		}
	}
	
	// overrides the toString() method from the Object class
	private static class Test2	{
		String s;
		
		public Test2(String s) {
			this.s = s;
		}
		
		@Override
		public String toString() {
			return this.s;
		}
	}
	
	private static class Test3 {
		String s;
		
		public Test3(String s) {
			this.s = s;
		}
		
		@Override
		public String toString() {
			return "You're a disappointment to your family.";	
		}

	}
	
	public static void main(String[] args) {
		Test1 t1 = new Test1("Bobo McGee");
		Test2 t2 = new Test2("Baba McGoo");
		Test3 t3 = new Test3("Bibi McGuu");

		// What will each print out?
		System.out.println(t1.toString());
		System.out.println(t2.toString());	
		System.out.println(t3.toString());	
	}
}