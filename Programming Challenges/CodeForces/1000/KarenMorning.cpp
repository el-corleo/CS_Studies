/*

	URL: https://codeforces.com/problemset/problem/816/A

	DESCRIPTION:
	
It is currently hh:mm, given in a 24-hour format. 

As you know, Karen loves palindromes, and she believes that it is good luck 
to wake up when the time is a palindrome.

What is the minimum number of minutes she should sleep, such that, when she 
wakes up, the time is a palindrome?

Remember that a palindrome is a string that reads the same forwards and backwards. 
For instance, 05:39 is not a palindrome, because 05:39 backwards is 93:50. 
On the other hand, 05:50 is a palindrome, because 05:50 backwards is 05:50.

	INPUT:

The first and only line of input contains a single string in the format 
hh:mm (00 ≤ hh ≤ 23, 00 ≤ mm ≤ 59).

	OUPUT:

Output a single integer on a line by itself, the minimum number of minutes she 
should sleep, such that, when she wakes up, the time is a palindrome.

	SAMPLES:
	
	05:39
		11
		
	13:31
		0
		
	23:59
		1
		
	OBSERVATIONS:
	
	- Hours go from 00-23
		Thus, only 24 theoretical palindromes exist
			Really, 24 - |{19, 18, 17, 16, 9, 8, 7, 6}| or 16, because 09:90 etc. are impossible
		
	- Check if is palindrome
		return 0
	- Else, output min(absolute distance to next palindrome)
		e.g., 05:16 -> 34 (05:50)
		can only be later, as time only moves forward
		
	- Edge cases
		05:50 -- 10:01
		22:22 -- 00:00
		
	- Ideas
		Convert time to number bewteen 0-(60*24) for ease of abs distance calculation
			could keep all 20 palindromes in an ordered array
			
*/
#include <iostream>
#include <string>

void print(int mins)
{ std::cout << mins << std::endl; }

int dist(int converted_time, int palindrome_time)
{
	if (converted_time - palindrome_time < 0)
		return -(converted_time - palindrome_time);
	else
		return converted_time - palindrome_time;
}


int main()
{
	std::string clock_time;
	std::cin >> clock_time;
	int hour = std::stoi(clock_time.substr(0,2));
	int mins = std::stoi(clock_time.substr(3,5));
	int converted_time = (hour * 60) + mins;

	// +70
	int palindromes[] = {0, 70, 140, 210, 280, 350, 601, 671, 741,\
			     811, 881, 951, 1202, 1272, 1342, 1412, 1440};

	int closest_palindrome = 0;
	int shortest_distance = 1000;
	for (int time : palindromes)
		// is a palindrome or too close to midnight
		if (converted_time == time)	
		{ print(0); return 0; }
		// impossible to go back in time
		else if (converted_time > time)
		{ continue; }
		else
		{
			int distance = dist(converted_time, time);
			if (distance < shortest_distance)
				shortest_distance = distance;
		}
	
	
	print(shortest_distance);
	
	return 0;
}

