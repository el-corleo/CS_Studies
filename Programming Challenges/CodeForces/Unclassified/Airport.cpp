/*
 * 
 
 troublesome inputs:
	40 10
	1 2 3 4 5 6 7 10 10 10
	
	10*3+9*3+8*3+7*4+6*5+5*6+4*7+3*8+2
	30+27+24+28+30+30+28+24+2
	90+27+48+56+2
	223
 
	610 33
	2 2 4 8 8 10 11 11 11 13 14 15 17 17 17 20 21 25 25 29 29 30 32 34 36 37 38 39 39 41 44 50 50 
 
 sum could be replaced with n*(n-1)/2
 */
#include <iostream>
#include <algorithm>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int sum(int start, int end=0)
{
	int sum = 0;
	while (start > end)
		sum += start--;
	return sum;
}

int main()
{
	// input
	int nPass, nPlane, nSeats = 0;
	std::cin >> nPass >> nPlane;
	int seats[nPlane];
	for (int i = 0; i < nPlane; i++)
	{ std::cin >> seats[i]; nSeats+= seats[i]; }
	
	// process
	int min = 0, max = 0, tmp_tot_pass_min = 0, tmp_tot_pass_max = 0;
	std::sort(seats, seats+nPlane);
	// more passengers than seats or both same
	if (nPass >= nSeats)
	{ 
		// min
		for (int i = 0; i < nPlane; i++)	min += sum(seats[i]);
		// max
		max = min;
	}
	else
	{
		// min
		for (int i = 0; i < nPlane; i++)
		{
			if (tmp_tot_pass_min <= nPass)
			{
				tmp_tot_pass_min += seats[i];
				if (tmp_tot_pass_min > nPass)	min += sum(seats[i], tmp_tot_pass_min-nPass);
				else							min += sum(seats[i]);
			} else
			{ break; }
		}
		
		// max
		int ind = nPlane-1;
		while (tmp_tot_pass_max < nPass)
		{			
			tmp_tot_pass_max++;
			// add dollar amount
			max += seats[ind]--;
			// change index
			if (ind == 0)							ind = (seats[ind] >= seats[nPlane-1]) ? ind : nPlane-1;
			else if (seats[ind-1] > seats[ind]) 	ind--;
			else if (seats[ind-1] == seats[ind])	ind = nPlane-1;
			else if (seats[nPlane-1] >= seats[ind])	ind = nPlane-1;
		}
	}
	
	// output
	Log(std::to_string(max) + " " + std::to_string(min));
	return 0;
}