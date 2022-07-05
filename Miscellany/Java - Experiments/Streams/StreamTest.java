import java.util.*;
import java.util.stream.Collectors;

public class StreamTest {
	private static class Gear {
		public Integer id;
		
		public Gear(Integer id) { this.id = id; }
	}
	
	private static class Cog {
		public Set<Gear> gears = new HashSet<>();
	}
	
	private static class Machine {
		public Set<Cog> cogs = new HashSet<>();
	}


	public static void main(String[] args) {
		// setup
		Set<Machine> machines = new HashSet<>();
		for (int i = 0; i < 10; i++) {
			Machine m = new Machine();
			Set<Cog> cogs = new HashSet<>();
			for (int j = 0; j < 10; j++) {
				Cog c = new Cog();
				Set<Gear> gears = new HashSet<>();
				for (int k = 0; k < 10; k++) {
					Gear g = new Gear(i*100 + j*10 + k);
					gears.add(g);
				}
				c.gears = gears;
				cogs.add(c);
			}
			m.cogs = cogs;
			machines.add(m);
		}
		
		List<Machine> evenIdMachines = machines.stream()
			.filter(
				m -> 
					m.cogs.stream()
						.flatMap(c -> c.gears.stream())
						.filter(g -> g.id == 111)
						.collect(Collectors.toList())
						.size()
					> 0)
			.collect(Collectors.toList());
			
		List<Machine> unique = machines.stream()
			.filter(
				m -> !evenIdMachines.contains(m))
			.collect(Collectors.toList());
			
		System.out.println(machines.size());
		System.out.println(evenIdMachines.size());
		System.out.println(unique.size());
		/*	
		for (Machine m : evenIdMachines) 
			for (Cog c : m.cogs)
				for (Gear g : c.gears)
					System.out.println(g.id);
		*/
	}
}