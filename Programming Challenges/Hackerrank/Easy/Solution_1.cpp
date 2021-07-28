// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numArray, numQueries;
    vector<vector<int>> arrays;

    cin >> numArray >> numQueries;

    // populate all arrays
    for (int i = 0; i < numArray; i++)
    {
        int arrayLength, value;
        cin >> arrayLength;
        vector<int> tempArr;

        // populate this line's array
        for (int j = 0; j < arrayLength; j++)
        {
            cin >> value;
            tempArr.push_back(value);
        }

        // add it to vector of arrays
        arrays.push_back(tempArr);
    }

    // queries
    for (int i = 0; i < numQueries; i++)
    {
        int arrayInd, elementInd;

        cin >> arrayInd >> elementInd;

        cout << arrays.at(arrayInd).at(elementInd) << endl;
    }

    return 0;
}