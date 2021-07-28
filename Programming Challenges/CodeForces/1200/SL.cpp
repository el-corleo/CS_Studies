/*
	THIS IS NOT MY SOLUTION. (Most comments are mine)
	
	It is a brute force solution to the ShowerLine.cpp problem that actually works
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
 
using namespace std;

// why 6 in length instead of 5?
int g[6][6];
 
int main()
{
	// load input into a 2d array
    int n = 5;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> g[i][j];
	// p appears to be the order, but why is it 6 in length instead of 5, considering the indexes start from zero?
	// pans seems to serve no obvious purpose
	
    int p[6], pans[6], ans = -1, tmp;
	// set initial order
    for(int i = 0 ; i < n ; ++i)
        p[i] = i;
    
    do
    {
		//Calculate total happiness
        //01234
        tmp = g[p[0]][p[1]] + g[p[1]][p[0]];
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];
        
        //1234
        tmp += g[p[1]][p[2]] + g[p[2]][p[1]];
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];
        
        //234
        tmp += g[p[2]][p[3]] + g[p[3]][p[2]];
        
        //34
        tmp += g[p[3]][p[4]] + g[p[4]][p[3]];
        
        if(tmp > ans)
        {
            ans = tmp;
            for(int i = 0 ; i < n ; ++i)
                pans[i] = p[i];
			// Line added to check the order that won
			// cout << p[0]+1 << "," << p[1]+1 << "," << p[2]+1 << "," << p[3]+1 << "," << p[4]+1 << endl;
        }
    }
	// rearrange elements in array to another permutation
    while(next_permutation(p, p+n));
    
    cout << ans << "\n";
    return 0;
}