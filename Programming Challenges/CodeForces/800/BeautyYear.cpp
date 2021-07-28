/*
 * https://codeforces.com/contest/271/problem/A
 * troublesome inputs: 1000, 1999, 1998, 2017
 */
#include <iostream>
#include <time.h>

void inc(int (&a)[4], int ind)
{
	while (true)
	{
		// increment ones
		a[ind] = (++a[ind])%10;
		if (a[ind] == 0) inc(a, ind -1);
		bool repeat = false;
		for (int i = ind-1; i >= 0; i--)
			if (a[ind] == a[i])	repeat = true;
		if (repeat)	continue;
		else		break;
	}
}

void findRepeat(int (&a)[4])
{
	// compare
	for (int i = 0; i < 3;)
		for (int j = i+1; j < 4;)
			if (a[i] == a[j]) 
			{ 
				a[j] = (a[j]+1)%10;
				if (a[j] == 0) 
				{
					a[j-1] = (a[j-1]+1)%10;
					if (a[j-1] == 0 && (j-2) >= 0)
					{
						a[j-2] = (a[j-2]+1)%10;
						if (a[j-2] == 0 && (j-3) >= 0)
						{ a[j-1] = (a[j-1]+1)%10; }
					}
				}
				i = 0; 
				break;
			} else 
			{
				j++;
				if (j == 4) i++;
			}
}

void easyVersion(int (&a)[4])
{
	while (true)
	{
		if (a[0] == a[1] || a[0] == a[2] || a[0] == a[3]
			|| a[1] == a[2] || a[1] == a[3]
			|| a[2] == a[3])
		{
			// increment
			a[3] = (a[3]+1)%10;
			if (a[3] == 0)
			{
				a[2] = (a[2]+1)%10;
				if (a[2] == 0)
				{
					a[1] = (a[1]+1)%10;
					if (a[1] == 0)
					{
						a[0] = (a[0]+1)%10;
					}
				}
			}
		} else	break;
	}
}

void findLowest(int (&a)[4])
{
	a[3] = 0;
	easyVersion(a);
}

int main()
{
	int y;
	std::cin >> y;
	int y_arr[] = {y/1000, (y/100)%10, (y/10)%10, ((y%10)+1)%10};//+1 to choose the year itself
	int y_arr_cpy[] = {y/1000, (y/100)%10, (y/10)%10, (y%10)};
	
	clock_t start = clock(), diff;
	
	// overly complicated, but quicker (?)
	findRepeat(y_arr);
	if (y_arr[0] != y_arr_cpy[0] && y_arr[1] != y_arr_cpy[1] && y_arr[2] != y_arr_cpy[2])
		findLowest(y_arr);
	
	//easyVersion(y_arr); // naive but effective
	
	//inc(y_arr, 3); // buggy
	
	
	diff = clock() - start;

	int msec = diff;
	std::cout << diff << std::endl;
	std::cout << y_arr[0] << y_arr[1] << y_arr[2] << y_arr[3] << std::endl;
	return 0;
}