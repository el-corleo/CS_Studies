public class Solution_4
{
	public static void main(String[] args)
	{
		System.out.println(countingValleys(8, "UDDDUDUU"));
		System.out.println(countingValleys(12, "DDUUDDUDUUUD"));
	}
	
	
    static int countingValleys(int n, String s) {
        int height = 0; // starts at sea level
        int valleys = 0; // tracks num of valleys traversed
        boolean isInValley = false; // prevents double counting valleys

        for (int i = 0; i < n; i++)
        {
            if (s.substring(i, i+1).equals("D"))
            {
                // check if height is below sea level
                // this goes before height decrement 
                // to avoid multi counting same valley
                isInValley = (height<0) ? true:false;
                height--;
                // when the isInValley boolean still 
                // hasn't registered the valley, but height
                // IS lower than sea level
                if (!isInValley && height < 0) valleys++; 
            }
            else
            {
                height++;
                isInValley = true;
            }
        }

        return valleys;
    }
}