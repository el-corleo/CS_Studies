import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import utils.Scheduler;
import entities.Event;
import entities.FixedEvent;
import entities.SkillEvent;

public class Main
{
	private static Scanner sc;
	private final static String SUBJECTS_EVENTS_LIST_FILE;
	private final static String SCHEDULES_FILE;
	// change slashes depending on OS
	static {
		String os = System.getProperty("os.name");
		System.out.println(os);
		if (os.contains("Windows"))
		{
			SUBJECTS_EVENTS_LIST_FILE = "\\txt_files\\skills_and_fixed.txt";
			SCHEDULES_FILE = "\\txt_files\\schedules";
		} else
		{
			SUBJECTS_EVENTS_LIST_FILE = "/txt_files/skills_and_fixed.txt";
			SCHEDULES_FILE = "/txt_files/schedules";
		}
	}
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Determine current use case
		System.out.println("Create Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
		
		// Load appropriate file
		String input;
		while (!(input = sc.nextLine()).toLowerCase().equals("x"))
			if (input.toLowerCase().equals("c"))		createNewSchedule(1);
			else if (input.toLowerCase().equals("v"))	viewOldSchedule();
			else						System.out.println("Invalid Input [Main]");
		
		sc.close();
	}
	
	private static void createNewSchedule(int skip)
	{
		// Take filename as input to create new schedule
		// This file contains a specially formatted list of "Subjects to Study" and "Fixed Events"
		Event[][] schedule = Scheduler.create(SUBJECTS_EVENTS_LIST_FILE,skip);
		
		// Display
		display(schedule);
		boolean finished = false;
		while (!finished){
			System.out.println("Save [s], Try a new pattern [c], Previous pattern [p], or Back to Main [b], Exchange spots manually [e], Input event manually [m]?");
		
			String input = sc.nextLine();
			switch (input.toLowerCase())
			{
				case "s": try { save(schedule); } catch (Exception e) {} finally { return; }
				case "c": createNewSchedule(skip*2); break;
				case "p": createNewSchedule(((skip>1)? skip/2 : skip)); break;
				case "b": return;
				case "e": moveManually(schedule); break;
				case "m": inputEventManually(schedule); break;
				default: System.out.println("Invalid Input [Create New Schedule]"); break;
			}
		}
	}
	
	private static void viewOldSchedule()
	{
		// TODO enforce format
		System.out.println("What was Sunday's date? [YYYY-MM-DD]");
		String date = sc.nextLine();

		String filepath = new File("").getAbsolutePath()+SCHEDULES_FILE+date+".txt";

		try { 
			Scanner sc_2 = new Scanner(new File(filepath));

			Event[][] schedule = new Event[24][7];
			boolean found = false;
			
			// parser
			String line = sc_2.nextLine();
			// parse out events until second occurrence of date
			for(int i = 0; i < 24; i++)
			{
				String[] events = line.split(","); // splits line into events
				for (int j = 0; j < 7; j++)
				{
					if (events[j].equals("null")) continue; // if no event slotted for that time

					String[] fields = events[j].split(" "); //splits events into fields
					// is a skill
					if (Boolean.parseBoolean(fields[0]))
					{
						SkillEvent e = new SkillEvent(fields[1], fields[2], fields[3], Integer.parseInt(fields[4]), Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
						schedule[i][j] = e;
					}
					// is fixed 
					else
					{
						FixedEvent e = new FixedEvent(fields[1], fields[2], fields[3], Integer.parseInt(fields[4]), Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
						schedule[i][j] = e;
					}
				}
				if (sc_2.hasNext())	line = sc_2.nextLine();
			}
			display(schedule);
		} catch (Exception e) { System.out.println("Failed to load: " + filepath); }
	}

	// Helper Methods
	private static void display(Event[][] schedule)
	{
		// Display new schedule by day [24 x 7]
		// TODO: Can input a specific cell to see specs of event
		for (int i = 0; i < 24; i++)
		{
			if (i > 0) System.out.printf("%-5s", i+"H");
			for (int j = 0; j < 7; j++)
			{
				// print out days at top only once
				if (i == 0 && j == 0)
				{
					System.out.printf("%-5s", "");
					String day = "";
					for (int k = 0; k < 7; k++)
					{
						switch (k)
						{
							case 0: day = "Sunday";		break;
							case 1: day = "Monday";		break;
							case 2: day = "Tuesday";	break;
							case 3: day = "Wednesday";	break;
							case 4: day = "Thursday";	break;
							case 5: day = "Friday";		break;
							case 6: day = "Saturday";	break;
						}
						System.out.printf("%-10S", day);
					}
					System.out.println();
					System.out.printf("%-5s", i+"H");
				}
				// print out activity at correct timeslot on correct day
				if (schedule[i][j] != null)	System.out.printf("%-10s", schedule[i][j].getType());
				else				System.out.printf("%-10s", "");
			}
			System.out.println();
		}
	}

	private static void save(Event[][] schedule) throws IOException
	{
		// TODO: enforce format
		System.out.println("What is Sunday's date? [YYYY-MM-DD]");
		String date = sc.nextLine();
		
		String filepath = new File("").getAbsolutePath()+SCHEDULES_FILE+date+".txt";
		
        try (FileWriter fileWriter = new FileWriter(filepath, false)) {
			for (int i = 0; i < 24; i++)
			{
				String line = "";
				for (int j = 0; j < 7; j++)
					line += schedule[i][j]+",";
				fileWriter.write(line+"\n");
			}
			
			System.out.println("Save successful");
			System.out.println("\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
			fileWriter.close();
        } catch (Exception e) { System.out.println("Save unsuccessful"); System.out.println(); }
	}
	
	private static void moveManually(Event[][] schedule)
	{
		// Prompt user to insert space separated pairs to swap
		System.out.println("List hour [0-23] and day [0-7] indexes for as many pairs you want to swap (e.g., 11 0 11 1 <- moves Event at 11,0 to 11,1)\n-1 to stop");

		int hour_1, day_1, hour_2, day_2;
		while(sc.hasNext())
		{
			if ((hour_1 = sc.nextInt()) < 0) break; // breaks on sentinel value of -1
			day_1 = sc.nextInt();
			hour_2 = sc.nextInt();
			day_2 = sc.nextInt();
			
			Event tmp = schedule[hour_1][day_1];
			schedule[hour_1][day_1] = schedule[hour_2][day_2];
			schedule[hour_2][day_2] = tmp;
		}
		System.out.println("\n\nNew Schedule");
		display(schedule);
	}

	private static void inputEventManually(Event[][] schedule)
	{
		// Prompt user to insert space separated parameters for new event including start time and day
		System.out.println("List space-separated skill/fixed, category, subject, type, day, start_time, and duration");
		
		while (true)
		{
			String event = sc.nextLine();
			String[] fields = event.split(" ");
		
			// fixed
			if (fields[0].toLowerCase().equals("fixed"))
			{
				int day = Integer.parseInt(fields[4]);
				int start_time = Integer.parseInt(fields[5]);
				int duration = Integer.parseInt(fields[6]);
				Event e = new FixedEvent(fields[1],fields[2],fields[3],day,start_time,duration);
				for (int i = 0; i < duration; i++)
					schedule[start_time+i][day] = e;
			}
			// skill
			else
			{
				int day = Integer.parseInt(fields[4]);
				int start_time = Integer.parseInt(fields[5]);
				int duration = Integer.parseInt(fields[6]);
				Event e = new SkillEvent(fields[1],fields[2],fields[3],duration,-1,-1);
				for (int i = 0; i < duration; i++)
					schedule[start_time+i][day] = e;
			}
			
			display(schedule);
			
			System.out.println("\n\nFinished [y/n]");
			
			String ans = sc.nextLine();
			if (ans.toLowerCase().equals("y")) break;
		}
	}
}
