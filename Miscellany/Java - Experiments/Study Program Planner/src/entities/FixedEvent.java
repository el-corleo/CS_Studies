package entities;

public class FixedEvent extends Event
{
	private final int day;
	private final int start_time;
	
	public FixedEvent(String category, String subject, String type, int day, int start_time, int duration)
	{
		super(false, category, subject, type, duration);
		this.day = day;
		this.start_time = start_time;
	}
	
	public int getDay()		{ return this.day; }
	public int getStartTime()	{ return this.start_time; }
	
	// Same order as constructor
	public String toString()	{ return isSkill() + " " + getCategory() + " " + getSubject() + " " + getType() + " " + day + " " + start_time + " " + getDuration(); }
}