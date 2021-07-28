package utils;

import java.util.Scanner;
import java.io.File;
import entities.Event;
import entities.SkillEvent;
import entities.FixedEvent;

public class Scheduler
{
	private static final String LIST_START_DELIM = ".";
	private static final String FIXED_SKILL_DELIM = ":";
	private static final String END_ENTRY_DELIM = ";";
	private static final String COMPONENT_DELIM = ",";
	private static final int SKILL_ARR_COMPONENT_LEN = 6;
	private static final int FIXED_ARR_COMPONENT_LEN = 6;
	
	public static Event[][] create(String filename, int skip)
	{
		String filepath = new File("").getAbsolutePath()+filename;
		
		try { 
			// load
			Scanner sc = new Scanner(new File(filepath));
			String content = "";
			while(sc.hasNext()) content += sc.nextLine();
			sc.close();
			content = content.substring(content.indexOf(LIST_START_DELIM)+1); // parse to end of comments
			// parse
			String[] skill_events_str = content.substring(0,content.indexOf(FIXED_SKILL_DELIM)).split(END_ENTRY_DELIM);
			String[] fixed_events_str = content.substring(content.indexOf(FIXED_SKILL_DELIM)+1).split(END_ENTRY_DELIM);	
			// generate events
			Event[] skill_events_obj = new SkillEvent[skill_events_str.length];
			for (int i = 0; i < skill_events_str.length; i++)
			{
				String str = skill_events_str[i].substring(1);
				String[] components = str.split(COMPONENT_DELIM);
				skill_events_obj[i] = new SkillEvent(components[0],components[1],components[2],Integer.parseInt(components[3]),Integer.parseInt(components[4]),Integer.parseInt(components[5]));
				//System.out.println(skill_events_obj[i]);
			}
			Event[] fixed_events_obj = new FixedEvent[fixed_events_str.length];
			for (int i = 0; i < fixed_events_str.length; i++)
			{
				String str = fixed_events_str[i].substring(1);
				String[] components = str.split(COMPONENT_DELIM);
				fixed_events_obj[i] = new FixedEvent(components[0],components[1],components[2],Integer.parseInt(components[3]),Integer.parseInt(components[4]),Integer.parseInt(components[5]));
				//System.out.println(fixed_events_obj[i]);
			}
		
			// create schedule
			return schedule(skill_events_obj, fixed_events_obj, skip);

		} catch (Exception e) { System.out.println("Process failed when attempting to use: " + filepath); }
		
		return null;
	}
	
	private static Event[][] schedule(Event[] skills, Event[] fixed, int skip)
	{
		Event[][] schedule = new Event[24][7];
		
		// Fill in fixed events into event grid
		for (Event e : fixed)
		{
			int start_time = ((FixedEvent) e).getStartTime();
			int duration = ((FixedEvent) e).getDuration();
			int day = ((FixedEvent) e).getDay();
			while (duration > 0)	{ schedule[start_time+(--duration)][day] = e; }
		}
		// Take care of Aidos every 2 hour block [if the two hours prior are reserved for skills]
		//for (int day = 0; day < 7; day++)
		//	for (int hour = 11; hour < 21; hour++)
		//		if (schedule[hour][day] == null && schedule[hour-1][day] == null && schedule[hour-2][day] == null)
		//		{ schedule[hour][day] = new FixedEvent("Aidos","Duty","On_Call",day,hour,1); continue; } // must use underscore
			
		// Find space for skill events
		MaxPQ<SkillEvent> pq = new MaxPQ<SkillEvent>(skills.length);
		for(Event e : skills) pq.insert((SkillEvent) e);

		while (!pq.isEmpty())
		{
			SkillEvent e = pq.delMax();
			int day = 0, cycle = 0, freq = 0; // Cycle prevents infinite loops for impossible scheduling tasks
			for (freq = e.getFrequency(); freq > 0 && cycle < skip*2; )
			{
				for (int hour = 9; hour < 24; hour++)
				{
					// Same activity already on the same day
					// Change day, reset hour, and then continue loop
					if (schedule[hour][day] != null && schedule[hour][day].getType() == e.getType())
					{ break; }
				
					// No music before 1200 or after 2100
					if ((hour < 12 || hour > 20) && (e.getType().equals("Violin")||e.getType().equals("Piano")))
					{ continue; }
					
					// Check for available time slot
					boolean hasConflict = false;
					// Time slot occupied
					for (int dur = e.getDuration()-1; dur >= 0; dur--)
					{ if (schedule[hour+dur][day] != null)	hasConflict = true; }
				
					// Found a time slot
					if (!hasConflict)
					{
						for (int dur = e.getDuration()-1; dur >= 0; dur--)
						{ schedule[hour+dur][day] = e; }
						freq--;
						break;
					}
				}
				cycle = ((day+skip)>6) ? cycle+1 : cycle;
				day = (day+skip)%7;
			}
			// didn't find slot for all instances on first pass; try swapping
			if (freq != 0)
			{
				System.out.println(e.getType() + " has " + freq + " unaccounted for times.");	
			}
		}
	
		return schedule;
	}
}
