/*
 * https://codeforces.com/problemset/problem/431/B
 
	Many students live in a dormitory. A dormitory is a whole new world of funny amusements and possibilities but it does have its drawbacks.

	There is only one shower and there are multiple students who wish to have a shower in the morning. That's why every morning there is a line of five people in front of the dormitory shower door. As soon as the shower opens, the first person from the line enters the shower. After a while the first person leaves the shower and the next person enters the shower. The process continues until everybody in the line has a shower.

	Having a shower takes some time, so the students in the line talk as they wait. At each moment of time the students talk in pairs: the (2_i-1)-th man in the line (for the current moment) talks with the (2_i)-th one.

	Let's look at this process in more detail. Let's number the people from 1 to 5. Let's assume that the line initially looks as 23154 (person number 2 stands at the beginning of the line). Then, before the shower opens, 2 talks with 3, 1 talks with 5, 4 doesn't talk with anyone. Then 2 enters the shower. While 2 has a shower, 3 and 1 talk, 5 and 4 talk too. Then, 3 enters the shower. While 3 has a shower, 1 and 5 talk, 4 doesn't talk to anyone. Then 1 enters the shower and while he is there, 5 and 4 talk. Then 5 enters the shower, and then 4 enters the shower.

	We know that if students i and j talk, then the i-th student's happiness increases by g_ij and the j-th student's happiness increases by g ji. Your task is to find such initial order of students in the line that the total happiness of all students will be maximum in the end. Please note that some pair of students may have a talk several times. In the example above students 1 and 5 talk while they wait for the shower to open and while 3 has a shower.

	Input
	The input consists of five lines, each line contains five space-separated integers: the j-th number in the i-th line shows g_ij (0≤g_ij≤105). It is guaranteed that g_ii=0 for all i.

	Assume that the students are numbered from 1 to 5.

	Output
	Print a single integer — the maximum possible total happiness of the students.
	
	SAMPLE:
	1.) input:	0 0 0 0 9
				0 0 0 0 0
				0 0 0 0 0
				0 0 0 0 0
				7 0 0 0 0
		output:	32
		[order: 23154]
	2.) input:	 0 43 21 18  2
				 3  0 21 11 65
				 5  2  0  1  4
				54 62 12  0 99
				87 64 81 33  0
		output:	620
		[order: 31452]
	
	Observations:
	- must find two highest pairs and put them together twice (i.e. in 3rd and 4th position && 4th and 5th position)
	- notice that the person in position four must have high totals with both three and five
	- 1st position will have lowest with everyone
	- 1st&2nd + 2(3rd&4th) + 2nd&3rd + 2(4th&5th)
	- 2nd&3rd total decides 3rd and 5th position
	
	- second sample
		1-1:0	2-2:0	3-3:0	4-4:0	5-5:0
		1-2:46	2-3:23	3-4:13	4-5:132
		1-3:26	2-4:73	3-5:85
		1-4:72	2-5:129
		1-5:89
	
	Troublesome input:
	 0 65 90  2 32
	69  0  9 97 67
	77 97  0 16 84
	18 50 94  0 63
	69 12 82 16  0
	[order: 42135]
	
		1-1:0	2-2:0	3-3:0	4-4:0	5-5:0
		1-2:134	2-3:106	3-4:110	4-5:79
		1-3:167	2-4:147	3-5:166
		1-4:20	2-5:79
		1-5:101
		
	0 4 2 4 9
	6 0 2 5 0
	2 5 0 6 3
	6 3 3 0 10
	0 3 1 3 0
	[order: 32145]
	
		1-1:0	2-2:0	3-3:0	4-4:0	5-5:0
		1-2:10	2-3:7	3-4:9	4-5:13
		1-3:4	2-4:8	3-5:4
		1-4:10	2-5:3
		1-5:9
		
	 0 70 10  0  0
	70  0 50 90  0
	10 50  0 80  0
	 0 90 80  0 100
	 0  0  0 100 0
	 [order: 31245]12345
	 
		1-1:0	2-2:0	3-3:0	4-4:0	5-5:0
		1-2:140	2-3:100	3-4:160	4-5:200
		1-3:20	2-4:180	3-5:0
		1-4:0	2-5:0
		1-5:0
		
	Lessons Learned:
	- Sometimes brute force [O(N!) in this case] is better, given a very small N
 */
#include <iostream>

const int I_ARR_ONES[] = {0, 1, 2, 3, 4};
const int I_ARR_TWOS[] = {1, 5, 6, 7, 8};
const int I_ARR_THREES[] = {2, 6, 9, 10, 11};
const int I_ARR_FOURS[] = {3, 7, 10, 12, 13};
const int I_ARR_FIVES[] = {4, 8, 11, 13, 14};

const int I_LEN_PAIRS = 15;

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

class Pair {
	public:
		int main;
		int sub;
		int hap_ind;
		
		Pair(int main, int sub, int hap_ind)
		{
			this->main = main;
			this->sub = sub;
			this->hap_ind = hap_ind;
		}
		
		bool operator !=(Pair &p)
		{
			return main != p.main || sub != p.sub;
		}
};

int high(const int (&i_arr_e)[5], Pair (&o_arr_pairs)[I_LEN_PAIRS], Pair &o_p_poss_hi_1, Pair &o_p_poss_hi_2, int i_high)
{
	for (int i : i_arr_e)
		for (int j : i_arr_e)
			if (o_arr_pairs[i] != o_arr_pairs[j] && (o_arr_pairs[i].hap_ind + o_arr_pairs[j].hap_ind > i_high))
			{
				i_high = o_arr_pairs[i].hap_ind + o_arr_pairs[j].hap_ind;
				o_p_poss_hi_1 = o_arr_pairs[i];
				o_p_poss_hi_2 = o_arr_pairs[j];
			}
		
	return i_high;
}

int main()
{
	// input
	Pair o_arr_hp_pairs[] = {
		Pair(1,1,0), Pair(1,2,0), Pair(1,3,0), Pair(1,4,0), Pair(1,5,0),
		Pair(2,2,0), Pair(2,3,0), Pair(2,4,0), Pair(2,5,0),
		Pair(3,3,0), Pair(3,4,0), Pair(3,5,0),
		Pair(4,4,0), Pair(4,5,0),
		Pair(5,5,0)
	};
	int n;
	// 1st
	for (int i = 0; i < 5; i++)
	{ std::cin >> n; o_arr_hp_pairs[I_ARR_ONES[i]].hap_ind += n; }
	// 2nd
	for (int i = 0; i < 5; i++)
	{ std::cin >> n; o_arr_hp_pairs[I_ARR_TWOS[i]].hap_ind += n; }
	// 3rd
	for (int i = 0; i < 5; i++)
	{ std::cin >> n; o_arr_hp_pairs[I_ARR_THREES[i]].hap_ind += n; }
	// 4th
	for (int i = 0; i < 5; i++)
	{ std::cin >> n; o_arr_hp_pairs[I_ARR_FOURS[i]].hap_ind += n; }
	// 5th
	for (int i = 0; i < 5; i++)
	{ std::cin >> n; o_arr_hp_pairs[I_ARR_FIVES[i]].hap_ind += n; }

	// process
	// determine order
	int i_arr_order[5];
	Pair *o_p_poss_hi_1=new Pair(0,0,0), *o_p_poss_hi_2=new Pair(0,0,0);
	int i_high = 0;
	// ones
	i_high = high(I_ARR_ONES, o_arr_hp_pairs, *o_p_poss_hi_1, *o_p_poss_hi_2, i_high);
	// twos
	i_high = high(I_ARR_TWOS, o_arr_hp_pairs, *o_p_poss_hi_1, *o_p_poss_hi_2, i_high);
	// threes
	i_high = high(I_ARR_THREES, o_arr_hp_pairs, *o_p_poss_hi_1, *o_p_poss_hi_2, i_high);
	// fours
	i_high = high(I_ARR_FOURS, o_arr_hp_pairs, *o_p_poss_hi_1, *o_p_poss_hi_2, i_high);
	// fives
	i_high = high(I_ARR_FIVES, o_arr_hp_pairs, *o_p_poss_hi_1, *o_p_poss_hi_2, i_high);

	// determine 1st
	i_arr_order[0] = (o_p_poss_hi_1->main == o_p_poss_hi_2->main || o_p_poss_hi_1->main == o_p_poss_hi_2->sub) ? o_p_poss_hi_1->main: o_p_poss_hi_1->sub;

	// 2nd & 3rd
	/*
	Makes incorrect decision for this input:
	
	0 70 10  0  0
	70  0 50 90  0
	10 50  0 80  0
	 0 90 80  0 100
	 0  0  0 100 0
		1-1:0	2-2:0	3-3:0	4-4:0	5-5:0
		1-2:140	2-3:100	3-4:160	4-5:200
		1-3:20	2-4:180	3-5:0
		1-4:0	2-5:0
		1-5:0
	[chosen optimal order: 31245] [actual optimal order: 12345]
	 
	This is because 2-4 connection is higher than 3-4 (i.e., 180>160)
	But it's wrong because 1-2 & 2-3 combo is much higher than 3-1 & 1-2 combo (240>160)
	This buries the meager difference from selecting the seemingly inferior 3-4 connection
	*/
	
	bool b_poss_1_hi = o_p_poss_hi_1->hap_ind > o_p_poss_hi_2->hap_ind;
	
	if (b_poss_1_hi)
	{
		i_arr_order[1] = (o_p_poss_hi_1->main == i_arr_order[0]) ? o_p_poss_hi_1->sub : o_p_poss_hi_1->main;
		i_arr_order[2] = (o_p_poss_hi_2->main == i_arr_order[0]) ? o_p_poss_hi_2->sub : o_p_poss_hi_2->main;
	} else
	{
		i_arr_order[1] = (o_p_poss_hi_2->main == i_arr_order[0]) ? o_p_poss_hi_2->sub : o_p_poss_hi_2->main;
		i_arr_order[2] = (o_p_poss_hi_1->main == i_arr_order[0]) ? o_p_poss_hi_1->sub : o_p_poss_hi_1->main;
	}
	
	// 2nd, 3rd, & penultimate
	int higher = 0;
	for (int i = 0; i <  I_LEN_PAIRS; i++)
	{
		if (!(o_arr_hp_pairs[i].main == i_arr_order[0] || o_arr_hp_pairs[i].sub == i_arr_order[0]))
		{
			if (!(o_arr_hp_pairs[i].main == i_arr_order[2] || o_arr_hp_pairs[i].sub == i_arr_order[2]))
			{
				if (o_arr_hp_pairs[i].main == i_arr_order[1] || o_arr_hp_pairs[i].sub == i_arr_order[1])
				{
					if (o_arr_hp_pairs[i].hap_ind > higher)
					{
						higher = o_arr_hp_pairs[i].hap_ind;
						i_arr_order[3] = (o_arr_hp_pairs[i].main==i_arr_order[1]) ? o_arr_hp_pairs[i].sub : o_arr_hp_pairs[i].main;
					}
				}
			}
			if (!(o_arr_hp_pairs[i].main == i_arr_order[1] || o_arr_hp_pairs[i].sub == i_arr_order[1]))
			{
				if (o_arr_hp_pairs[i].main == i_arr_order[2] || o_arr_hp_pairs[i].sub == i_arr_order[2])
				{
					if (o_arr_hp_pairs[i].hap_ind > higher)
					{
						higher = o_arr_hp_pairs[i].hap_ind;
						i_arr_order[3] = (o_arr_hp_pairs[i].main==i_arr_order[2]) ? o_arr_hp_pairs[i].sub : o_arr_hp_pairs[i].main;
						// swap so that formerly 3rd is now 2nd
						int tmp = i_arr_order[2];
						i_arr_order[2] = i_arr_order[1];
						i_arr_order[1] = tmp;
					}
				}
			}
		}
	}
	
	// final
	int i_missing_num = i_arr_order[0]+i_arr_order[1]+i_arr_order[2]+i_arr_order[3];
	i_arr_order[4] = 15-i_missing_num;
	
	// calculate total happiness based on order
	int result = 0;
	for (int i = 0; i < I_LEN_PAIRS; i++)
		if ((o_arr_hp_pairs[i].main == i_arr_order[1] && o_arr_hp_pairs[i].sub == i_arr_order[0]) 
			|| (o_arr_hp_pairs[i].main == i_arr_order[0] && o_arr_hp_pairs[i].sub == i_arr_order[1]))	result += 2*o_arr_hp_pairs[i].hap_ind;
		else if ((o_arr_hp_pairs[i].main == i_arr_order[2] && o_arr_hp_pairs[i].sub == i_arr_order[0]) 
			|| (o_arr_hp_pairs[i].main == i_arr_order[0] && o_arr_hp_pairs[i].sub == i_arr_order[2]))	result += 2*o_arr_hp_pairs[i].hap_ind;
		else if ((o_arr_hp_pairs[i].main == i_arr_order[3] && o_arr_hp_pairs[i].sub == i_arr_order[1]) 
			|| (o_arr_hp_pairs[i].main == i_arr_order[1] && o_arr_hp_pairs[i].sub == i_arr_order[3]))	result += o_arr_hp_pairs[i].hap_ind;
		else if ((o_arr_hp_pairs[i].main == i_arr_order[4] && o_arr_hp_pairs[i].sub == i_arr_order[3]) 
			|| (o_arr_hp_pairs[i].main == i_arr_order[3] && o_arr_hp_pairs[i].sub == i_arr_order[4]))	result += o_arr_hp_pairs[i].hap_ind;

	// output
	Log(result);
	
	return 0;
}