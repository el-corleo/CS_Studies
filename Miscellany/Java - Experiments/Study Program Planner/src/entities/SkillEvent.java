package entities;

public class SkillEvent extends Event implements Comparable<SkillEvent>
{
	private final int priority, frequency;
	
	public SkillEvent(String category, String subject, String type, int duration, int frequency, int priority)
	{
		super(true, category, subject, type, duration);
		this.frequency = frequency;
		this.priority = priority;
	}
	
	public int getPriority()	{ return this.priority; }
	public int getFrequency()	{ return this.frequency; }
	
	// Same order as constructor
	public String toString()	{ return isSkill() + " " + getCategory() + " " + getSubject() + " " + getType() + " " + getDuration() + " " + frequency + " " + priority; }
	
	@Override
	public int compareTo(SkillEvent that)
	{
		// greater than
		if (this.priority > that.priority)		return 1;
		// less than
		if (this.priority < that.priority)		return -1;
		// equal to
		if (this.frequency > that.frequency)	return 1;
		if (this.frequency < that.frequency)	return -1;
		// completely equal
		return 0;
	}
}