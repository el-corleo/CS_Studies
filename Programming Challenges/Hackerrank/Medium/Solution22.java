/*
* https://www.hackerrank.com/challenges/organizing-containers-of-balls
*/

import java.util.*;

public class Solution22
{
	public static void main(String[] args)
	{
		int[][] m_1 = {{1,3,1},{2,1,2},{3,3,3}};	
		int[][] m_2 = {{0,2,1},{1,1,1},{2,0,0}};
		int[][] m_3 = {{999336263, 998799923},
					   {998799923, 999763019}};
		int[][] m_4 = {{997612619, 934920795, 998879231, 999926463},
					   {960369681, 997828120, 999792735, 979622676},
					   {999013654, 998634077, 997988323, 958769423},
					   {997409523, 999301350, 940952923, 993020546}};
		int[][] m_5 = {{993263231, 806455183, 972467746, 761846174, 226680660, 667393859, 815298761, 790313908, 997845516}, {873142072, 579210472, 996344520, 999601755, 904458846, 663577990, 980240637, 713052540, 963408591}, {551159221, 873763794, 752756532, 798803609, 670921889, 995259612, 981339960, 763904498, 499472207}, {975980611, 999974039, 729219884, 834636710, 973988213, 969888254, 846967495, 687204298, 511348404}, {993232608, 998103218, 857820670, 995587240, 817798750, 773950980, 824882180, 797565274, 887424441}, {847857578, 768853671, 916073200, 982234748, 986511977, 733420232, 997714976, 819799716, 891570083}, {733197334, 985682497, 612123868, 971798655, 999905357, 710092446, 997494889, 683312998, 850074746}, {799093993, 543648222, 944524289, 814951921, 981087922, 997222915, 506561779, 997697933, 652807674}, {989362549, 973516812, 891706714, 786904549, 982329176, 376575034, 993535504, 984745483, 777613376}};
		
		int[][] m_x = {{1,1,0,0}, {1,0,1,0}, {0,1,1,0},{0,0,0,1}};
		
		System.out.println(organizingContainers(m_4));
	}
	
	static String organizingContainers(int[][] container)
	{
        long[] total_color = new long[container.length];
        long[] total_capacity = new long[container.length];

		// determine how many colors there are in each category
		// and capacity of each container
        for (int r = 0; r < container.length; r++)
            for (int c = 0; c < container.length; c++)
            {
                total_color[c] += container[r][c];
                total_capacity[r] += container[r][c]; 
            }
		
		Arrays.sort(total_color);
		Arrays.sort(total_capacity);
		
		// Check to see if any of the colors exceeds its container's capacity
		for (int i = 0; i < total_color.length; i++)
			if (total_color[i] > total_capacity[i]) return "Impossible";
		
		return "Possible";
    }
}