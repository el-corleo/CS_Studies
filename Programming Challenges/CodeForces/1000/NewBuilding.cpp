/*
	URL: https://codeforces.com/problemset/problem/1020/A

	DESCRIPTION:

	You are looking at the floor plan of the Summer Informatics School's new building. You were tasked with SIS logistics, so you really care about travel time between different locations: it is important to know how long it would take to get from the lecture room to the canteen, or from the gym to the server room.

The building consists of n towers, h floors each, where the towers are labeled from 1 to n, the floors are labeled from 1 to h. There is a passage between any two adjacent towers (two towers i and i + 1 for all i: 1 ≤ i ≤ n - 1) on every floor x, where a ≤ x ≤ b. It takes exactly one minute to walk between any two adjacent floors of a tower, as well as between any two adjacent towers, provided that there is a passage on that floor. It is not permitted to leave the building.

You have given k pairs of locations (ta, fa), (tb, fb): floor fa of tower ta and floor fb of tower tb. For each pair you need to determine the minimum walking time between these locations.

	Input

The first line of the input contains following integers:

    n: the number of towers in the building (1 ≤ n ≤ 108),
    h: the number of floors in each tower (1 ≤ h ≤ 108),
    a and b: the lowest and highest floor where it's possible to move between adjacent towers (1 ≤ a ≤ b ≤ h),
    k: total number of queries (1 ≤ k ≤ 104). 

Next k lines contain description of the queries. Each description consists of four integers ta, fa, tb, fb (1 ≤ ta, tb ≤ n, 1 ≤ fa, fb ≤ h). This corresponds to a query to find the minimum travel time between fa-th floor of the ta-th tower and fb-th floor of the tb-th tower.

	Output

For each query print a single integer: the minimum walking time between the locations in minutes.

	OBSERVATIONS:

		- 1 min / transition; cannot leave building, meaning must use inter-building passages

	MISTAKES:

		- Didn't consider case where both are below the lowest bridge
		- Didn't consider case where both are between lo & hi bridges

*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int abs_dist(int a, int b) { return (a-b < 0) ? (a-b)*-1 : (a-b); }

int min(int a, int b) { return (a < b) ? a : b; }

int main()
{
	int n_towers, h_floors, a_lo_bridge, b_hi_bridge, k_queries, ta_from_tower, fa_from_floor, tb_to_tower, fb_to_floor;
	std::cin >> n_towers >> h_floors >> a_lo_bridge >> b_hi_bridge >> k_queries;

	for (int query = 0; query < k_queries; query++)
	{
		std::cin >> ta_from_tower >> fa_from_floor >> tb_to_tower >> fb_to_floor;
		int time = 0, dist_start_to_bridge;
		bool from_to_both_below_or_above_bridge;

		// same tower
		if (ta_from_tower - tb_to_tower == 0)	time = abs_dist(fa_from_floor, fb_to_floor);
		// different towers but between highest and lowest bridges
		else if ((fa_from_floor >= a_lo_bridge && fa_from_floor <= b_hi_bridge) || (fb_to_floor >= a_lo_bridge && fb_to_floor <= b_hi_bridge))
		{
			time = abs_dist(ta_from_tower, tb_to_tower) + abs_dist(fa_from_floor, fb_to_floor);
		}
		// different towers
		else
		{
			// get to closest bridge
			time = dist_start_to_bridge = min(abs_dist(fa_from_floor, a_lo_bridge), abs_dist(fa_from_floor, b_hi_bridge));
			// cross to relevant tower
			time += abs_dist(ta_from_tower, tb_to_tower);
			// travel to relevant floor
			from_to_both_below_or_above_bridge = (fa_from_floor < a_lo_bridge && fb_to_floor < a_lo_bridge) || (fa_from_floor > b_hi_bridge && fb_to_floor > b_hi_bridge);

			if (from_to_both_below_or_above_bridge)
			{
				time += dist_start_to_bridge;
				// both above
				if (fa_from_floor > b_hi_bridge)	
					time += (fa_from_floor < fb_to_floor) ? +abs_dist(fa_from_floor, fb_to_floor) : -abs_dist(fa_from_floor, fb_to_floor);
				// both below
				else
					time += (fa_from_floor < fb_to_floor) ? -abs_dist(fa_from_floor, fb_to_floor) : +abs_dist(fa_from_floor, fb_to_floor);
					
			}
			else
			{
				time += abs_dist(fa_from_floor, fb_to_floor) - dist_start_to_bridge;
			}
		}

		print(time);
	}	

	return 0;
}
