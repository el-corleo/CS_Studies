package entities;

public class Event
{
	private final String category, subject, type;
	private final int duration; // only by hours, no half hours
	private final boolean isSkill;
	
	public Event(boolean isSkill, String category, String subject, String type, int duration)
	{
		this.isSkill = isSkill;
		this.category = category;
		this.subject = subject;
		this.type = type;
		this.duration = duration;
	}
	
	public String getCategory()	{ return this.category; }
	public String getSubject() 	{ return this.subject; }
	public String getType() 	{ return this.type; }
	public int getDuration() 	{ return this.duration; }
	public boolean isSkill()	{ return this.isSkill; }
}